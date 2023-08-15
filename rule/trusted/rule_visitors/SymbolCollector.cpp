// LICENSE: Apache 2.0
// https://github.com/RegTech-OXH/compliance-engine
//
// Author:
//
// This file implements SymbolCollector class.

#include "SymbolCollector.h"

using namespace std;
using namespace antlr4;
using namespace rule_check_proto;

SymbolCollector::~SymbolCollector()
{
    // De-allocate collected entity pointers
    for (const auto &entity_pair : this->entity_map_)
    {
        delete entity_pair.second;
    }
    this->entity_map_.clear();

}

/* Internal Handler Member Functions */

Attribute* SymbolCollector::createAttribute(std::string name, RuleLanguage::Type type) {

    Attribute* ans = nullptr;

    switch (type)
    {
    case RuleLanguage::Type::NUMBER:
        ans = new NumberAttribute(name, type);
        break;

    case RuleLanguage::Type::BOOLEAN:
        ans = new BooleanAttribute(name, type);
        break;

    case RuleLanguage::Type::STRING:
        ans = new StringAttribute(name, type);
        break;

    case RuleLanguage::Type::INSTANCE:
        ans = new ObjectAttribute(name, type);
        break;
    
    default:
        break;
    }

    return ans;
}


// mark entity as request needed, only concern specific attribute name
void SymbolCollector::KeepTrackOfNewEntity(const string &entity_name, string &attribute_name, RuleLanguage::Type type)
{
    ocall_print_string((string("KeepTrackOfNewEntity: ") +
                        entity_name + string("[") +
                        attribute_name + string("]")).c_str(), __FILE__, __LINE__);
    
    auto attribute = createAttribute(attribute_name, type);
    if (attribute == nullptr) {
        ocall_print_string((string("Error: attribute type not support! ")).c_str(), __FILE__, __LINE__);
        return;
    }

    // decide on whether entity exists
    if (this->entity_map_.find(entity_name) == this->entity_map_.end())
    {
        // NOTE: `entity` is deleted with `SymbolCollector` destructor
        Entity *entity = new Entity(entity_name);
        entity->setUnique(false);
        entity->addAttribute(attribute_name, attribute);
        this->entity_map_[entity_name] = entity;
    }
    else
    {
        Entity *entity = this->entity_map_[entity_name];
        entity->addAttribute(attribute_name, attribute);
    }
}

void SymbolCollector::KeepTrackOfNewInstance(const std::string &instance_name, std::string &entity_name) {
    ocall_print_string((string("KeepTrackOfNewInstance: ") +
                        instance_name + string(" related to ") +
                        entity_name).c_str(), __FILE__, __LINE__);
    if (instance_map_.find(instance_name) == instance_map_.end()) {
        Instance* instance = new Instance(instance_name);

        if (!entity_name.empty()) {
            instance->setUniqueEntityName(entity_name);
            instance->addAttributes(entity_map_[entity_name]->get_attribute_list());
        }

        instance_map_.insert({instance_name, instance});
    } else {
        ocall_print_string((string("Error: ") +
                        instance_name + string(" has been defined! ")).c_str(), __FILE__, __LINE__);
    }
}

void SymbolCollector::KeepTrackOfNewInstance(const std::string &instance_name, RuleLanguage::Expr* expr) {
    ocall_print_string((string("KeepTrackOfNewInstance: ") +
                        instance_name + string(" related to expr")).c_str(), __FILE__, __LINE__);
    
    auto instance_map = rule_instance_map_[curr_rule_name_];
    
    if (instance_map.find(instance_name) == instance_map.end()) {
        Instance* instance = new Instance(instance_name);
        instance->setExpr(expr);
        instance_map.insert({instance_name, instance});
    } else {
        ocall_print_string((string("Error: ") +
                        instance_name + string(" has been defined! ")).c_str(), __FILE__, __LINE__);
    }
}

/* Overridden Visitor Member Functions */
antlrcpp::Any SymbolCollector::visitEntityDecl(RuleParser::EntityDeclContext *context)
{
    ocall_print_string(("enter visitEntityDecl: " + context->getText()).c_str(), __FILE__, __LINE__);

    // check if we encounter a set entity declaration
   
    string entity_name = context->entityName()->getText();
    const auto& attributes = context->attributeList()->attributeDecl();
    for (auto attribute : attributes) {
        string attribute_name = attribute->attributeName()->getText();
        auto attribute_type = getAttributeTypeFromDef(attribute->typeAnno());
        KeepTrackOfNewEntity(entity_name, attribute_name, attribute_type);
    }

    if (context->UNIQUE()) {
        entity_map_[entity_name]->setUnique(true);
        string instance_name = entity_name;
        KeepTrackOfNewInstance(instance_name, entity_name);
    }

    return nullptr;
}

void SymbolCollector::setCurrRuleName (std::string &rule_name) {
    curr_rule_name_ = rule_name;
}

antlrcpp::Any SymbolCollector::visitBasicRule(RuleParser::BasicRuleContext *context)
{
    ocall_print_string(("enter visitBasicRule: " + context->getText()).c_str(), __FILE__, __LINE__);
    string rule_name = context->ruleName()->getText();
    setCurrRuleName(rule_name);
    InstanceMap m;
    rule_instance_map_[rule_name] = m;
    RuleStmts s;
    rule_stmt_map_[rule_name] = s;

    return nullptr;
}

Instance* SymbolCollector::handleSelectorIdent(RuleParser::SelectorIdentContext *context, RuleLanguage::Type type) {

    string instance_name = context->entityName()->getText();
    string attribute_name = context->attributeName()->getText();

    if (instance_map_.find(instance_name) == instance_map_.end()) {
        ocall_print_string((string("Error: undefined instance! ")).c_str(), __FILE__, __LINE__);
        return nullptr;
    }

    auto instance = instance_map_[instance_name];
    if (instance->hasAttribute(attribute_name, type)) {
        return instance;
    }
    return nullptr;
}


RuleLanguage::booleanExpr* SymbolCollector::handleBooleanExpr(RuleParser::BooleanExprContext *context) {
    
    if (context == nullptr) {
        ocall_print_string((string("Error: Parser Error! ")).c_str(), __FILE__, __LINE__);
        return nullptr;
    }

    if (context->booleanExpr()) {
        return handleBooleanExpr(context->booleanExpr());
    }
    
    if (context->booleanLiteral()) {
        RuleLanguage::booleanExpr* expr = new RuleLanguage::booleanExpr();
        if (context->booleanLiteral()->getText().compare("true") == 0) {
            expr->setValue(true);
        } else if (context->booleanLiteral()->getText().compare("false") == 0) {
            expr->setValue(false);
        } else {
            ocall_print_string((string("Error: illegal input! ")).c_str(), __FILE__, __LINE__);
            return nullptr;
        }
        return expr;
    }
    
    if (context->selectorIdent()) {
        auto instance = handleSelectorIdent(context->selectorIdent(), RuleLanguage::Type::BOOLEAN);
        
        if (instance != nullptr) {
            RuleLanguage::booleanExpr* expr = new RuleLanguage::booleanExpr();
            expr->setInstance(instance);
            return expr;
        }

        ocall_print_string((string("Error: illegal selectorIdent! ")).c_str(), __FILE__, __LINE__);
        return nullptr;
    }

    if (context->relationExpr()) {
        auto rExpr = handleRelationExpr(context->relationExpr());
        if (rExpr == nullptr) {
            return nullptr;
        }
        RuleLanguage::booleanExpr* expr = new RuleLanguage::booleanExpr();
        expr->setExpr(rExpr);
        return expr;
    }

    // TODO
    // if (context->listExpr())

    ocall_print_string((string("Error: illegal syntax! ")).c_str(), __FILE__, __LINE__);
    return nullptr;

}

RuleLanguage::logicalExpr* SymbolCollector::handleLogicalExpr(RuleParser::LogicalExprContext *context) {
    if (context == nullptr) {
        ocall_print_string((string("Error: Parser Error! ")).c_str(), __FILE__, __LINE__);
        return nullptr;
    }

    if (context->booleanExpr()) {
        RuleLanguage::logicalExpr *expr = new RuleLanguage::logicalExpr();
        expr->setBooleanExpr(handleBooleanExpr(context->booleanExpr()));
        return expr;
    }
    
    if (context->LOGICAL_NOT()) {
        RuleLanguage::logicalExpr *expr = new RuleLanguage::logicalExpr();
        expr->setOperator(RuleLanguage::LogicalOperator::NOT);
        auto rExpr = handleLogicalExpr(context->logicalExpr(0));
        if (rExpr == nullptr) {
            ocall_print_string((string("Error: illegal input! ")).c_str(), __FILE__, __LINE__);
            return nullptr;
        }
        expr->setRightExpr(rExpr);
        return expr;
    } else if (context->LOGICAL_AND() || context->LOGICAL_OR()) {
        RuleLanguage::logicalExpr *expr = new RuleLanguage::logicalExpr();
        auto op = context->LOGICAL_AND() != nullptr ?  RuleLanguage::LogicalOperator::AND : RuleLanguage::LogicalOperator::OR;
        expr->setOperator(op);
        if (context->logicalExpr().size() == 2) {
            expr->setLeftExpr(handleLogicalExpr(context->logicalExpr(0)));
            expr->setLeftExpr(handleLogicalExpr(context->logicalExpr(1)));
            return expr;
        } else {
            delete(expr);
            ocall_print_string((string("Error: illegal syntax! ")).c_str(), __FILE__, __LINE__);
            return nullptr;
        }

    } else {
        ocall_print_string((string("Error: illegal syntax! ")).c_str(), __FILE__, __LINE__);
        return nullptr;
    }

}

RuleLanguage::ArithmeticOperator SymbolCollector::getOperator(RuleParser::NumberExprContext* context) {
    if (context->MULTIPLY() != nullptr) {
        return RuleLanguage::ArithmeticOperator::MULTIPLY;
    }

    if (context->MODULO() != nullptr) {
        return RuleLanguage::ArithmeticOperator::MODULO;
    }

    if (context->DIVIDE() != nullptr) {
        return RuleLanguage::ArithmeticOperator::DIVIDE;
    }

    if (context->PLUS() != nullptr) {
        return RuleLanguage::ArithmeticOperator::PLUS;
    }

    if (context->MINUS() != nullptr) {
        return RuleLanguage::ArithmeticOperator::MINUS;
    }
    return RuleLanguage::ArithmeticOperator::ARITH_NON;
}

RuleLanguage::numberExpr* SymbolCollector::handleNumberExpr(RuleParser::NumberExprContext *context) {
    auto number_exprs = context->numberExpr();
    if (number_exprs.size() == 1) {
        auto expr = handleNumberExpr(number_exprs[0]);
        if (context->MINUS()) {
            expr->setNegative();
        }
        return expr;
    }

    if (number_exprs.size() == 2) {
        auto op = getOperator(context);

        if (op == RuleLanguage::ArithmeticOperator::ARITH_NON) {
            ocall_print_string((string("Error: illegal syntax! ")).c_str(), __FILE__, __LINE__);
            return nullptr;
        }

        auto left_expr = handleNumberExpr(number_exprs[0]);
        auto right_expr = handleNumberExpr(number_exprs[1]);

        if (left_expr == nullptr || right_expr == nullptr) {
            ocall_print_string((string("Error: illegal syntax! ")).c_str(), __FILE__, __LINE__);
            return nullptr;
        }
        auto expr = new RuleLanguage::numberExpr();
        expr->setLeftExpr(left_expr);
        expr->setRightExpr(right_expr);
        expr->setOperator(op);
        return expr;
    }

    if (context->selectorIdent()) {
        auto instance = handleSelectorIdent(context->selectorIdent(), RuleLanguage::Type::NUMBER);
        if (instance != nullptr) {
            auto expr = new RuleLanguage::numberExpr();
            expr->setInstance(instance);
            return expr;
        }
    }

    if (context->DECIMAL_LIT()) {
        string decimal_string = context->DECIMAL_LIT()->getText();
        std::remove(decimal_string.begin(), decimal_string.end(), ',');

        int64_t decimal_value = stoll(decimal_string);
        if (decimal_value < 0) {
            ocall_print_string((string("Error: illegal syntax! Exceed int64 type")).c_str(), __FILE__, __LINE__);
            return nullptr;
        }
        auto expr = new RuleLanguage::numberExpr();
        expr->setValue(decimal_value);
        return expr;
    }

    if (context->DECIMAL_FLOAT_LIT()) {
        ocall_print_string((string("Error: illegal syntax! Float not support!")).c_str(), __FILE__, __LINE__);
        return nullptr;
    }

    ocall_print_string((string("Error: illegal syntax! ")).c_str(), __FILE__, __LINE__);
    return nullptr;

}

bool SymbolCollector::getQueryOperator(RuleParser::QueryExprContext *context, RuleLanguage::queryExpr *expr) {
    auto sellect_value = context->SELECT() != nullptr ? true : false;
    auto collect_value = context->COLLECT() != nullptr ? true : false;

    // query Expr must has one of sellect and collect
    if (!sellect_value && !collect_value) {
        ocall_print_string((string("Error: illegal syntax! query expr should be sellect or collect")).c_str(), __FILE__, __LINE__);
        return false;
    }

    expr->setSellect(sellect_value);
    expr->setCollect(collect_value);
    return true;
}

Instance* SymbolCollector::getInstance(string name, RuleLanguage::Type type ) {
    if (instance_map_.find(name) == instance_map_.end()) {
        return nullptr;
    }
    auto instance = instance_map_[name];
    if (instance->type() != type) {
        return nullptr;
    }
    return instance;
}

Entity* SymbolCollector::getEntity(string name) {
    if (entity_map_.find(name) == entity_map_.end()) {
        return nullptr;
    }

    auto entity = entity_map_[name];
    if (entity->isUnique()) {
        return nullptr;
    }

    return entity;
}

RuleLanguage::Type SymbolCollector::getAttributeTypeFromDef(RuleParser::TypeAnnoContext* context) {
    
    // TODO: Instance should record entity 
    if (context->compositeType()) {
        return RuleLanguage::Type::INSTANCE;
    }

    if (context->basicType()->NUMBER()) {
        return RuleLanguage::Type::NUMBER;
    }

    if (context->basicType()->BOOLEAN()) {
        return RuleLanguage::Type::BOOLEAN;
    }

    if (context->basicType()->DATE()) {
        return RuleLanguage::Type::DATE;
    }

    if (context->basicType()->STRING()) {
        return RuleLanguage::Type::STRING;
    }
}

RuleLanguage::LogicalOperator SymbolCollector::getLogicalOperator(RuleParser::LogicalOperatorContext *context) {
    if (context->LOGICAL_AND()) {
        return RuleLanguage::LogicalOperator::AND;
    }

    if (context->LOGICAL_OR()) {
        return RuleLanguage::LogicalOperator::OR;
    }

    return RuleLanguage::LogicalOperator::LOGICAL_NON;
}

RuleLanguage::conditionExpr* SymbolCollector::handleConditionExpr(RuleParser::ConditionExprContext *context) {
    auto basic_cond_exprs = context->basicCondExpr();
    if (basic_cond_exprs.empty()) {
        ocall_print_string((string("Error: illegal syntax! ")).c_str(), __FILE__, __LINE__);
        return nullptr;
    }

    auto expr = new RuleLanguage::conditionExpr();
    auto first_expr = handleBasicCondExpr(basic_cond_exprs[0]);
    if (first_expr == nullptr) {
        ocall_print_string((string("Error: illegal syntax! ")).c_str(), __FILE__, __LINE__);
        return nullptr;
    }
    expr->setBasicExpr(first_expr);

    auto operators = context->logicalOperator();
    for (int i = 1; i < basic_cond_exprs.size(); i++) {
        auto bc_expr = handleBasicCondExpr(basic_cond_exprs[i]);
        auto op = getLogicalOperator(operators[i - 1]);
        bc_expr->setOperator(op);
        expr->addExpr(bc_expr);
    }

    return expr;
}



RuleLanguage::queryExpr* SymbolCollector::handleQueryExpr(RuleParser::QueryExprContext *context) {
    RuleLanguage::queryExpr *expr = new RuleLanguage::queryExpr();
    if (!getQueryOperator(context, expr)) {
        ocall_print_string((string("Error: illegal syntax! ")).c_str(), __FILE__, __LINE__);
        delete(expr);
        return nullptr;
    }

    auto entity_name = context->entityName()->getText();
    auto entity = getEntity(entity_name);
    auto instance = getInstance(entity_name, RuleLanguage::Type::INSTANCELIST);

    if (entity == nullptr && instance == nullptr) {
        ocall_print_string((string("Error: undefined entity or type miss match! ")).c_str(), __FILE__, __LINE__);
        delete(expr);
        return nullptr;
    }

    expr->setEntity(entity);
    expr->setInstance(instance);


    auto condExpr = handleConditionExpr(context->conditionExpr());
    if (condExpr == nullptr && context->WHERE() == nullptr) {
        ocall_print_string((string("Error: illegal syntax! ")).c_str(), __FILE__, __LINE__);
        return nullptr;
    }

    expr->setExpr(condExpr);
    return expr;
}

RuleLanguage::basicCondExpr* SymbolCollector::handleBasicCondExpr(RuleParser::BasicCondExprContext *context) {
    if (context->relationExpr()) {
        auto expr = new RuleLanguage::basicCondExpr();
        expr->setRelationExpr(handleRelationExpr(context->relationExpr()));
        return expr;
    }

    if (context->listExpr()) {
        auto expr = new RuleLanguage::basicCondExpr();
        expr->setListExpr(handleListExpr(context->listExpr()));
        return expr;
    }

    return nullptr;
}

RuleLanguage::RelationOperator SymbolCollector::getRelationOperator(RuleParser::RelationOperatorContext *context) {
    if (context->EQUALS()) {
        return RuleLanguage::RelationOperator::EQUALS;
    }

    if (context->NOT_EQUALS()) {
        return RuleLanguage::RelationOperator::NOT_EQUALS;
    }

    if (context->LESS_THAN()) {
        return RuleLanguage::RelationOperator::LESS_THAN;
    }

    if (context->LESS_OR_EQUALS()) {
        return RuleLanguage::RelationOperator::LESS_OR_EQUALS;
    }

    if (context->GREATER_OR_EQUALS()) {
        return RuleLanguage::RelationOperator::GREATER_OR_EQUALS;
    }

    if (context->GREATER_THAN()) {
        return RuleLanguage::RelationOperator::GREATER;
    }

    return RuleLanguage::RelationOperator::RELATION_NON;
}

RuleLanguage::relationExpr* SymbolCollector::handleRelationExpr(RuleParser::RelationExprContext *context) {
    if (context->relationExpr()) {
        return handleRelationExpr(context->relationExpr());
    }
    auto numbers = context->numberExpr();
    auto operators = context->relationOperator();

    if (numbers.size() < 2) {
        ocall_print_string((string("Error: illegal syntax! ")).c_str(), __FILE__, __LINE__);
        return nullptr;
    }

    auto expr = new RuleLanguage::relationExpr();
    auto first_number_expr = handleNumberExpr(numbers[0]);
    expr->setFirstExpr(first_number_expr);

    for (int i = 1; i < numbers.size(); i++) {
        expr->addNumberExpr(handleNumberExpr(numbers[i]));
        expr->addOperator(getRelationOperator(operators[i - 1]));
    }

    return expr;
    
}

RuleLanguage::listExpr* SymbolCollector::handleListExpr(RuleParser::ListExprContext *context) {
    ocall_print_string((string("Error: list Expr is not support yet! ")).c_str(), __FILE__, __LINE__);
    return nullptr;
}



antlrcpp::Any SymbolCollector::visitDefinitionStmt(RuleParser::DefinitionStmtContext *context)
{
    string instance_name = context->instanceName()->getText();
    auto exprCtx = context->expr();
    if (exprCtx->logicalExpr()) {
        auto logical_expr = handleLogicalExpr(exprCtx->logicalExpr());
        KeepTrackOfNewInstance(instance_name, logical_expr);
    } else if (exprCtx->numberExpr()) {
        auto number_expr = handleNumberExpr(exprCtx->numberExpr());
        KeepTrackOfNewInstance(instance_name, number_expr);
    } else if (exprCtx->queryExpr()) {
        auto query_expr = handleQueryExpr(exprCtx->queryExpr());
        KeepTrackOfNewInstance(instance_name, query_expr);
    }

    return nullptr;
}


antlrcpp::Any SymbolCollector::visitLogicalExpr(RuleParser::LogicalExprContext *context)
{
    auto expr = handleLogicalExpr(context);
    auto rule_stmt_list = rule_stmt_map_[curr_rule_name_];
    rule_stmt_list.push_back(expr);

    return nullptr;
}

antlrcpp::Any SymbolCollector::visitRelationExpr(RuleParser::RelationExprContext *context)
{
    auto expr = handleRelationExpr(context);
    auto rule_stmt_list = rule_stmt_map_[curr_rule_name_];
    rule_stmt_list.push_back(expr);

    return nullptr;
}

/* Data Member Getters */
const vector<Entity> SymbolCollector::get_entity_list() const
{
    vector<Entity> entity_list;
    for (const auto &entity_pair : this->entity_map_)
    {
        entity_list.push_back(*(entity_pair.second));
    }

    return entity_list;
}

ExecuteRule* SymbolCollector::handleExecuteRuleDef(RuleParser::ExecuteRuleDefContext* context) {
    auto rule = new ExecuteRule();
    rule->rule_name = context->ruleName()->getText();

    if (context->executionTrueStmt()) {
        auto tbranch = handleExecutionTrueStmt(context->executionTrueStmt());
        if (tbranch == nullptr) {
            return nullptr;
        }
        rule->true_branch = tbranch;
    }
    
    if (context->executionFalseStmt()) {
        auto fbranch = handleExecutionFalseStmt(context->executionFalseStmt());
        if (fbranch == nullptr) {
            return nullptr;
        }
        rule->false_branch = fbranch;
    }

    return rule;
}

ExecuteRule* SymbolCollector::handleExecutionTrueStmt(RuleParser::ExecutionTrueStmtContext* context) {
    if (context->ruleName()) {
        auto rule = new ExecuteRule();
        rule->rule_name = context->ruleName()->getText();
        return rule;
    }

    if (context->executeRuleDef()) {
        return handleExecuteRuleDef(context->executeRuleDef());
    }

    return nullptr;
}

ExecuteRule* SymbolCollector::handleExecutionFalseStmt(RuleParser::ExecutionFalseStmtContext* context) {
    if (context->ruleName()) {
        auto rule = new ExecuteRule();
        rule->rule_name = context->ruleName()->getText();
        return rule;
    }

    if (context->executeRuleDef()) {
        return handleExecuteRuleDef(context->executeRuleDef());
    }

    return nullptr;
}

bool SymbolCollector::generateExecuteTree(RuleParser::ExecuteRuleDefContext* context) {
    
    if (context->executionTrueStmt()) {
        auto true_rule = handleExecutionTrueStmt(context->executionTrueStmt());
        if (true_rule == nullptr) {
            return false;
        }
        execute_root->true_branch = true_rule;
    }
    
    if (context->executionFalseStmt()) {
        auto false_rule = handleExecutionFalseStmt(context->executionFalseStmt());
        if (false_rule == nullptr) {
            return false;
        }
        execute_root->false_branch = false_rule;
    }

    return true;
}

antlrcpp::Any SymbolCollector::visitExecutionStmt(RuleParser::ExecutionStmtContext *context) {
    auto ruleDef = context->executeRuleDef();

    execute_root = new ExecuteRule();
    execute_root->rule_name = ruleDef->ruleName()->getText();
    generateExecuteTree(ruleDef);

    return nullptr;
}

antlrcpp::Any SymbolCollector::visitInputBlock(RuleParser::InputBlockContext *context) {
    auto attributes = context->attributeList()->attributeDecl();
    if (attributes.size() == 0) {
        return nullptr;
    }

    input_instance_ = new Instance("input");

    for (auto attribute : attributes) {
        auto attribute_name = attribute->attributeName()->getText();
        auto attribute_type = getAttributeTypeFromDef(attribute->typeAnno());
        input_instance_->addAttribute(attribute_name, createAttribute(attribute_name, attribute_type));
    }

    return nullptr;
}

ObjectAttribute* SymbolCollector::handleOutputObject(RuleParser::OutputObjectContext* context) {
    auto object_name = context->objectName()->getText();
    auto decls = context->outputDecl();
    auto instance_value = new Instance(object_name);

    for (auto decl : decls) {
        auto decl_attribute = handleOutputDecl(decl);
        if (decl_attribute == nullptr) {
            ocall_print_string((string("Error: illegal syntax! ")).c_str(), __FILE__, __LINE__);
            return nullptr;
        }
        instance_value->addAttribute(decl_attribute->getName(), decl_attribute);
    }

    auto object = new ObjectAttribute(object_name, RuleLanguage::Type::INSTANCE, instance_value);
    return object;
}

Attribute* SymbolCollector::handleOutputDecl(RuleParser::OutputDeclContext* context) {
    
    if (context->outputAttribute()) {
        auto attribute = context->outputAttribute();
        auto attribute_name = attribute->attributeName()->getText();
        auto attribute_type = getAttributeTypeFromDef(attribute->typeAnno());
        return createAttribute(attribute_name, attribute_type);
    }

    if (context->outputObject()) {
        return handleOutputObject(context->outputObject());
    }
}

antlrcpp::Any SymbolCollector::visitOutputBlock(RuleParser::OutputBlockContext *context) {
    auto output_decls = context->outputDecl();
    output_instance_ = new Instance("output");

    for (auto output_decl : output_decls) {
        auto attribute = handleOutputDecl(output_decl);
        if (attribute == nullptr) {
            ocall_print_string((string("Error: illegal syntax! ")).c_str(), __FILE__, __LINE__);
            return nullptr;
        }
        output_instance_->addAttribute(attribute->getName(), attribute);
    }

    return nullptr;
}



