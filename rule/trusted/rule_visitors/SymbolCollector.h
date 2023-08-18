// LICENSE: Apache 2.0
// https://github.com/RegTech-OXH/compliance-engine
//
// Author:
//
// This file declares SymbolCollector class.

#pragma once

#include <map>
#include <vector>
#include <string>
#include <regex>

#include "RuleEnclave_t.h" /* sgx generated proxy header */

#include "antlr4-runtime.h"
#include "trusted/data_types/Entity.h"
#include "trusted/data_types/EntitySet.h"
#include "trusted/data_types/Instance.h"
#include "common/data_types/rule_check/ErrorType.h"
#include "rule_enclave/EntityQuery.pb.h"

#include "BaseVisitor.h"

#include "trusted/data_types/RequestContext.h"
#include "trusted/antlr4_generated/RuleParserBaseVisitor.h"
#include "trusted/antlr4_generated/RuleLexer.h"

// using namespace std;
// using namespace antlr4;

// `SymbolCollector` extends BaseVisitor with additional utility functions

using InstanceMap = std::map<std::string, std::shared_ptr<Instance>>;
using RuleStmts = std::vector<std::unique_ptr<RuleLanguage::Expr>>;

class ExecuteRule {
    public:
        std::string rule_name;
        ExecuteRule* true_branch;
        ExecuteRule* false_branch;
        ~ExecuteRule() {
            if (true_branch) {
                delete(true_branch);
            }

            if (false_branch) {
                delete(false_branch);
            }
        }
};

class SymbolCollector : public BaseVisitor
{
private:
    // map from entity name (aka id) to entity request
    std::map<std::string, std::shared_ptr<Entity>> entity_map_;
    InstanceMap instance_map_;
    std::map<std::string, InstanceMap> rule_instance_map_;
    std::map<std::string, RuleStmts> rule_stmt_map_;

    std::unique_ptr<ExecuteRule> execute_root;
    std::shared_ptr<Instance> input_instance_;
    std::shared_ptr<Instance> output_instance_;

    // record current context of rule
    std::string curr_rule_name_;

public:
    SymbolCollector() = default;
    ~SymbolCollector();

    /* Data Member Getters */
    const std::vector<Entity> get_entity_list() const;

    RequestContext *const get_request_context();

private:
    /* Internal Handler Member Functions */
    void KeepTrackOfNewEntity(const std::string &entity_name, std::string &attribute_name, RuleLanguage::Type type);
    void KeepTrackOfNewInstance(const std::string &instance_name, std::string &entity_name);
    void KeepTrackOfNewInstance(const std::string &instance_name, RuleLanguage::Expr* expr);

    void setCurrRuleName (std::string &rule_name);

    /* Functions used to generate semantic model */
    
    std::shared_ptr<Instance> getInstance(std::string name, RuleLanguage::Type type);
    std::shared_ptr<Entity> getEntity(std::string name);
    std::shared_ptr<Instance> handleSelectorIdent(RuleParser::SelectorIdentContext *context, RuleLanguage::Type type);

    Attribute*  createAttribute(std::string name, RuleLanguage::Type type);
    RuleLanguage::logicalExpr* handleLogicalExpr(RuleParser::LogicalExprContext *context);
    RuleLanguage::booleanExpr* handleBooleanExpr(RuleParser::BooleanExprContext *context);
    RuleLanguage::numberExpr* handleNumberExpr(RuleParser::NumberExprContext *context);
    RuleLanguage::queryExpr* handleQueryExpr(RuleParser::QueryExprContext *context);
    RuleLanguage::conditionExpr* handleConditionExpr(RuleParser::ConditionExprContext *context);
    RuleLanguage::basicCondExpr* handleBasicCondExpr(RuleParser::BasicCondExprContext *context);
    RuleLanguage::relationExpr* handleRelationExpr(RuleParser::RelationExprContext *context);
    RuleLanguage::listExpr* handleListExpr(RuleParser::ListExprContext *context);

    ExecuteRule* handleExecuteRuleDef(RuleParser::ExecuteRuleDefContext* context);
    ExecuteRule* handleExecutionTrueStmt(RuleParser::ExecutionTrueStmtContext* context);
    ExecuteRule* handleExecutionFalseStmt(RuleParser::ExecutionFalseStmtContext* context);

    ObjectAttribute* handleOutputObject(RuleParser::OutputObjectContext* context);
    Attribute* handleOutputDecl(RuleParser::OutputDeclContext* context);

    RuleLanguage::ArithmeticOperator getOperator(RuleParser::NumberExprContext* context);
    RuleLanguage::LogicalOperator getLogicalOperator(RuleParser::LogicalOperatorContext *context);
    RuleLanguage::RelationOperator getRelationOperator(RuleParser::RelationOperatorContext *context);
    RuleLanguage::Type getAttributeTypeFromDef(RuleParser::TypeAnnoContext* context);

    bool getQueryOperator(RuleParser::QueryExprContext *context, RuleLanguage::queryExpr *expr);
    bool generateExecuteTree(RuleParser::ExecuteRuleDefContext* context);


    

public:
    /* override function from RuleParser  */

    // handle Entity block
    virtual antlrcpp::Any visitEntityDecl(RuleParser::EntityDeclContext *context) override;

    // handle input block
    virtual antlrcpp::Any visitInputBlock(RuleParser::InputBlockContext *context) override;

    // handle output block
    virtual antlrcpp::Any visitOutputBlock(RuleParser::OutputBlockContext *context) override;

    // handle rule block
    virtual antlrcpp::Any visitBasicRule(RuleParser::BasicRuleContext *context) override;

    virtual antlrcpp::Any visitDefinitionStmt(RuleParser::DefinitionStmtContext *context) override;

    virtual antlrcpp::Any visitLogicalExpr(RuleParser::LogicalExprContext *context) override;

    virtual antlrcpp::Any visitRelationExpr(RuleParser::RelationExprContext *context) override;

    // handle execution block
    virtual antlrcpp::Any visitExecutionStmt(RuleParser::ExecutionStmtContext *context) override;

    // TODO: support all kinds of expr  
    // virtual antlrcpp::Any visitListExpr(RuleParser::ListExprContext *context) override;
    // virtual antlrcpp::Any visitAggregationExpr(RuleParser::AggregationExprContext *context) override;
};