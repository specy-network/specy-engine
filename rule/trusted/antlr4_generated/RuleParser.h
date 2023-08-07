
// Generated from RuleParser.g4 by ANTLR 4.9.1

#pragma once


#include "antlr4-runtime.h"




class  RuleParser : public antlr4::Parser {
public:
  enum {
    TASK = 1, ENTITIES = 2, RULES = 3, INPUT = 4, OUTPUT = 5, EXECUTION = 6, 
    REFERENCES = 7, ENTITY = 8, UNIQUE = 9, ARTICLE = 10, RULE = 11, NUMBER = 12, 
    STRING = 13, BOOLEAN = 14, DATE = 15, SET = 16, LIST = 17, YEAR = 18, 
    MONTH = 19, DAY = 20, HOUR = 21, MINUTE = 22, SECOND = 23, ALIAS = 24, 
    STATE = 25, EVENT = 26, TRUE = 27, FALSE = 28, SELECT = 29, COLLECT = 30, 
    CHECK = 31, ELSE = 32, IF = 33, THEN = 34, L_PAREN = 35, R_PAREN = 36, 
    L_CURLY = 37, R_CURLY = 38, L_BRACKET = 39, R_BRACKET = 40, ASSIGN = 41, 
    COMMA = 42, SEMI = 43, COLON = 44, DOT = 45, LOGICAL_OR = 46, LOGICAL_AND = 47, 
    LOGICAL_NOT = 48, SET_IN = 49, SET_NOT_IN = 50, SET_UNION = 51, SET_INTERSECT = 52, 
    EQUALS = 53, NOT_EQUALS = 54, LESS_THAN = 55, LESS_OR_EQUALS = 56, GREATER_THAN = 57, 
    GREATER_OR_EQUALS = 58, PLUS = 59, MINUS = 60, MULTIPLY = 61, DIVIDE = 62, 
    MODULO = 63, IS = 64, WITHIN = 65, BEFORE = 66, AFTER = 67, FOLLOW = 68, 
    ACCUMULATE = 69, COUNT = 70, ON = 71, PROVIDED = 72, WHERE = 73, DECIMAL_LIT = 74, 
    DECIMAL_FLOAT_LIT = 75, DATE_LIT = 76, TIME_LIT = 77, RUNE_LIT = 78, 
    BYTE_VALUE = 79, OCTAL_BYTE_VALUE = 80, HEX_BYTE_VALUE = 81, LITTLE_U_VALUE = 82, 
    BIG_U_VALUE = 83, RAW_STRING_LIT = 84, INTERPRETED_STRING_LIT = 85, 
    IDENTIFIER = 86, WS = 87, COMMENT = 88, TERMINATOR = 89, LINE_COMMENT = 90
  };

  enum {
    RuleRoot = 0, RuleTaskDecl = 1, RuleInputBlock = 2, RuleOutputBlock = 3, 
    RuleEntitiesBlock = 4, RuleEntityList = 5, RuleEntityDecl = 6, RuleEntityName = 7, 
    RuleAttributeList = 8, RuleAttributeDecl = 9, RuleAttributeName = 10, 
    RuleTypeAnno = 11, RuleBasicType = 12, RuleCompositeType = 13, RuleListType = 14, 
    RuleExecutionBlock = 15, RuleExecutionStmt = 16, RuleExecutionTrueStmt = 17, 
    RuleExecutionFalseStmt = 18, RuleRulesBlock = 19, RuleRuleList = 20, 
    RuleBasicRule = 21, RuleRuleName = 22, RuleRuleStmtList = 23, RuleRuleStmt = 24, 
    RuleSimpleStmt = 25, RuleComplexStmt = 26, RuleListStmt = 27, RuleListExpr = 28, 
    RuleRelationStmt = 29, RuleRelationExpr = 30, RuleNumberExpr = 31, RuleSelectorIdent = 32, 
    RuleAggregationExpr = 33, RuleBooleanExpr = 34, RuleBooleanLiteral = 35, 
    RuleLogicalStmt = 36, RuleLogicalExpr = 37, RuleDefinitionStmt = 38, 
    RuleInstanceName = 39, RuleQueryExpr = 40, RuleExpr = 41, RuleAssignStmt = 42, 
    RuleAssignExpr = 43, RuleIfStmt = 44, RuleSequentialStmt = 45, RuleSequentialExpr = 46, 
    RuleDateStmt = 47, RuleDateExpr = 48, RuleTimeStmt = 49, RuleTimeExpr = 50, 
    RuleEos = 51
  };

  explicit RuleParser(antlr4::TokenStream *input);
  ~RuleParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class RootContext;
  class TaskDeclContext;
  class InputBlockContext;
  class OutputBlockContext;
  class EntitiesBlockContext;
  class EntityListContext;
  class EntityDeclContext;
  class EntityNameContext;
  class AttributeListContext;
  class AttributeDeclContext;
  class AttributeNameContext;
  class TypeAnnoContext;
  class BasicTypeContext;
  class CompositeTypeContext;
  class ListTypeContext;
  class ExecutionBlockContext;
  class ExecutionStmtContext;
  class ExecutionTrueStmtContext;
  class ExecutionFalseStmtContext;
  class RulesBlockContext;
  class RuleListContext;
  class BasicRuleContext;
  class RuleNameContext;
  class RuleStmtListContext;
  class RuleStmtContext;
  class SimpleStmtContext;
  class ComplexStmtContext;
  class ListStmtContext;
  class ListExprContext;
  class RelationStmtContext;
  class RelationExprContext;
  class NumberExprContext;
  class SelectorIdentContext;
  class AggregationExprContext;
  class BooleanExprContext;
  class BooleanLiteralContext;
  class LogicalStmtContext;
  class LogicalExprContext;
  class DefinitionStmtContext;
  class InstanceNameContext;
  class QueryExprContext;
  class ExprContext;
  class AssignStmtContext;
  class AssignExprContext;
  class IfStmtContext;
  class SequentialStmtContext;
  class SequentialExprContext;
  class DateStmtContext;
  class DateExprContext;
  class TimeStmtContext;
  class TimeExprContext;
  class EosContext; 

  class  RootContext : public antlr4::ParserRuleContext {
  public:
    RootContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TaskDeclContext *taskDecl();
    EntitiesBlockContext *entitiesBlock();
    RulesBlockContext *rulesBlock();
    ExecutionBlockContext *executionBlock();
    antlr4::tree::TerminalNode *EOF();
    InputBlockContext *inputBlock();
    OutputBlockContext *outputBlock();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RootContext* root();

  class  TaskDeclContext : public antlr4::ParserRuleContext {
  public:
    TaskDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TASK();
    std::vector<antlr4::tree::TerminalNode *> IDENTIFIER();
    antlr4::tree::TerminalNode* IDENTIFIER(size_t i);
    std::vector<antlr4::tree::TerminalNode *> DOT();
    antlr4::tree::TerminalNode* DOT(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TaskDeclContext* taskDecl();

  class  InputBlockContext : public antlr4::ParserRuleContext {
  public:
    InputBlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INPUT();
    antlr4::tree::TerminalNode *L_CURLY();
    AttributeListContext *attributeList();
    antlr4::tree::TerminalNode *R_CURLY();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InputBlockContext* inputBlock();

  class  OutputBlockContext : public antlr4::ParserRuleContext {
  public:
    OutputBlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OUTPUT();
    antlr4::tree::TerminalNode *L_CURLY();
    AttributeListContext *attributeList();
    antlr4::tree::TerminalNode *R_CURLY();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OutputBlockContext* outputBlock();

  class  EntitiesBlockContext : public antlr4::ParserRuleContext {
  public:
    EntitiesBlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ENTITIES();
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *L_CURLY();
    EntityListContext *entityList();
    antlr4::tree::TerminalNode *R_CURLY();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EntitiesBlockContext* entitiesBlock();

  class  EntityListContext : public antlr4::ParserRuleContext {
  public:
    EntityListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> ENTITY();
    antlr4::tree::TerminalNode* ENTITY(size_t i);
    std::vector<EntityDeclContext *> entityDecl();
    EntityDeclContext* entityDecl(size_t i);
    std::vector<antlr4::tree::TerminalNode *> UNIQUE();
    antlr4::tree::TerminalNode* UNIQUE(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EntityListContext* entityList();

  class  EntityDeclContext : public antlr4::ParserRuleContext {
  public:
    EntityDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    EntityNameContext *entityName();
    antlr4::tree::TerminalNode *L_CURLY();
    AttributeListContext *attributeList();
    antlr4::tree::TerminalNode *R_CURLY();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EntityDeclContext* entityDecl();

  class  EntityNameContext : public antlr4::ParserRuleContext {
  public:
    EntityNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EntityNameContext* entityName();

  class  AttributeListContext : public antlr4::ParserRuleContext {
  public:
    AttributeListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<AttributeDeclContext *> attributeDecl();
    AttributeDeclContext* attributeDecl(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AttributeListContext* attributeList();

  class  AttributeDeclContext : public antlr4::ParserRuleContext {
  public:
    AttributeDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AttributeNameContext *attributeName();
    antlr4::tree::TerminalNode *IS();
    TypeAnnoContext *typeAnno();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AttributeDeclContext* attributeDecl();

  class  AttributeNameContext : public antlr4::ParserRuleContext {
  public:
    AttributeNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AttributeNameContext* attributeName();

  class  TypeAnnoContext : public antlr4::ParserRuleContext {
  public:
    TypeAnnoContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    CompositeTypeContext *compositeType();
    BasicTypeContext *basicType();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeAnnoContext* typeAnno();

  class  BasicTypeContext : public antlr4::ParserRuleContext {
  public:
    BasicTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NUMBER();
    antlr4::tree::TerminalNode *STRING();
    antlr4::tree::TerminalNode *DATE();
    antlr4::tree::TerminalNode *BOOLEAN();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BasicTypeContext* basicType();

  class  CompositeTypeContext : public antlr4::ParserRuleContext {
  public:
    CompositeTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ListTypeContext *listType();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CompositeTypeContext* compositeType();

  class  ListTypeContext : public antlr4::ParserRuleContext {
  public:
    ListTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LIST();
    antlr4::tree::TerminalNode *L_BRACKET();
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *R_BRACKET();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ListTypeContext* listType();

  class  ExecutionBlockContext : public antlr4::ParserRuleContext {
  public:
    ExecutionBlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EXECUTION();
    antlr4::tree::TerminalNode *L_CURLY();
    ExecutionStmtContext *executionStmt();
    antlr4::tree::TerminalNode *R_CURLY();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExecutionBlockContext* executionBlock();

  class  ExecutionStmtContext : public antlr4::ParserRuleContext {
  public:
    ExecutionStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CHECK();
    antlr4::tree::TerminalNode *RULE();
    antlr4::tree::TerminalNode *IDENTIFIER();
    ExecutionTrueStmtContext *executionTrueStmt();
    ExecutionFalseStmtContext *executionFalseStmt();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExecutionStmtContext* executionStmt();

  class  ExecutionTrueStmtContext : public antlr4::ParserRuleContext {
  public:
    ExecutionTrueStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TRUE();
    antlr4::tree::TerminalNode *IDENTIFIER();
    ExecutionTrueStmtContext *executionTrueStmt();
    ExecutionFalseStmtContext *executionFalseStmt();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExecutionTrueStmtContext* executionTrueStmt();

  class  ExecutionFalseStmtContext : public antlr4::ParserRuleContext {
  public:
    ExecutionFalseStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FALSE();
    antlr4::tree::TerminalNode *IDENTIFIER();
    ExecutionTrueStmtContext *executionTrueStmt();
    ExecutionFalseStmtContext *executionFalseStmt();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExecutionFalseStmtContext* executionFalseStmt();

  class  RulesBlockContext : public antlr4::ParserRuleContext {
  public:
    RulesBlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RULES();
    antlr4::tree::TerminalNode *L_CURLY();
    RuleListContext *ruleList();
    antlr4::tree::TerminalNode *R_CURLY();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RulesBlockContext* rulesBlock();

  class  RuleListContext : public antlr4::ParserRuleContext {
  public:
    RuleListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<BasicRuleContext *> basicRule();
    BasicRuleContext* basicRule(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RuleListContext* ruleList();

  class  BasicRuleContext : public antlr4::ParserRuleContext {
  public:
    BasicRuleContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RULE();
    RuleNameContext *ruleName();
    antlr4::tree::TerminalNode *L_CURLY();
    RuleStmtListContext *ruleStmtList();
    antlr4::tree::TerminalNode *R_CURLY();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BasicRuleContext* basicRule();

  class  RuleNameContext : public antlr4::ParserRuleContext {
  public:
    RuleNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RuleNameContext* ruleName();

  class  RuleStmtListContext : public antlr4::ParserRuleContext {
  public:
    RuleStmtListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<RuleStmtContext *> ruleStmt();
    RuleStmtContext* ruleStmt(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RuleStmtListContext* ruleStmtList();

  class  RuleStmtContext : public antlr4::ParserRuleContext {
  public:
    RuleStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SimpleStmtContext *simpleStmt();
    ComplexStmtContext *complexStmt();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RuleStmtContext* ruleStmt();

  class  SimpleStmtContext : public antlr4::ParserRuleContext {
  public:
    SimpleStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ListStmtContext *listStmt();
    RelationStmtContext *relationStmt();
    LogicalStmtContext *logicalStmt();
    DefinitionStmtContext *definitionStmt();
    AssignStmtContext *assignStmt();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SimpleStmtContext* simpleStmt();

  class  ComplexStmtContext : public antlr4::ParserRuleContext {
  public:
    ComplexStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IfStmtContext *ifStmt();
    SequentialStmtContext *sequentialStmt();
    DateStmtContext *dateStmt();
    TimeStmtContext *timeStmt();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ComplexStmtContext* complexStmt();

  class  ListStmtContext : public antlr4::ParserRuleContext {
  public:
    ListStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ListExprContext *listExpr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ListStmtContext* listStmt();

  class  ListExprContext : public antlr4::ParserRuleContext {
  public:
    ListExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *L_PAREN();
    ListExprContext *listExpr();
    antlr4::tree::TerminalNode *R_PAREN();
    SelectorIdentContext *selectorIdent();
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *SET_IN();
    antlr4::tree::TerminalNode *SET_NOT_IN();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ListExprContext* listExpr();

  class  RelationStmtContext : public antlr4::ParserRuleContext {
  public:
    RelationStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    RelationExprContext *relationExpr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RelationStmtContext* relationStmt();

  class  RelationExprContext : public antlr4::ParserRuleContext {
  public:
    RelationExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *L_PAREN();
    RelationExprContext *relationExpr();
    antlr4::tree::TerminalNode *R_PAREN();
    std::vector<NumberExprContext *> numberExpr();
    NumberExprContext* numberExpr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> EQUALS();
    antlr4::tree::TerminalNode* EQUALS(size_t i);
    std::vector<antlr4::tree::TerminalNode *> NOT_EQUALS();
    antlr4::tree::TerminalNode* NOT_EQUALS(size_t i);
    std::vector<antlr4::tree::TerminalNode *> LESS_THAN();
    antlr4::tree::TerminalNode* LESS_THAN(size_t i);
    std::vector<antlr4::tree::TerminalNode *> LESS_OR_EQUALS();
    antlr4::tree::TerminalNode* LESS_OR_EQUALS(size_t i);
    std::vector<antlr4::tree::TerminalNode *> GREATER_THAN();
    antlr4::tree::TerminalNode* GREATER_THAN(size_t i);
    std::vector<antlr4::tree::TerminalNode *> GREATER_OR_EQUALS();
    antlr4::tree::TerminalNode* GREATER_OR_EQUALS(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RelationExprContext* relationExpr();

  class  NumberExprContext : public antlr4::ParserRuleContext {
  public:
    NumberExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *L_PAREN();
    std::vector<NumberExprContext *> numberExpr();
    NumberExprContext* numberExpr(size_t i);
    antlr4::tree::TerminalNode *R_PAREN();
    SelectorIdentContext *selectorIdent();
    antlr4::tree::TerminalNode *DECIMAL_LIT();
    antlr4::tree::TerminalNode *DECIMAL_FLOAT_LIT();
    AggregationExprContext *aggregationExpr();
    antlr4::tree::TerminalNode *MULTIPLY();
    antlr4::tree::TerminalNode *DIVIDE();
    antlr4::tree::TerminalNode *MODULO();
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NumberExprContext* numberExpr();
  NumberExprContext* numberExpr(int precedence);
  class  SelectorIdentContext : public antlr4::ParserRuleContext {
  public:
    SelectorIdentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    EntityNameContext *entityName();
    antlr4::tree::TerminalNode *DOT();
    AttributeNameContext *attributeName();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SelectorIdentContext* selectorIdent();

  class  AggregationExprContext : public antlr4::ParserRuleContext {
  public:
    AggregationExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ACCUMULATE();
    NumberExprContext *numberExpr();
    antlr4::tree::TerminalNode *ON();
    EntityNameContext *entityName();
    antlr4::tree::TerminalNode *PROVIDED();
    std::vector<SelectorIdentContext *> selectorIdent();
    SelectorIdentContext* selectorIdent(size_t i);
    antlr4::tree::TerminalNode *WHERE();
    BooleanExprContext *booleanExpr();
    antlr4::tree::TerminalNode *DATE_LIT();
    antlr4::tree::TerminalNode *WITHIN();
    antlr4::tree::TerminalNode *TIME_LIT();
    std::vector<antlr4::tree::TerminalNode *> LOGICAL_AND();
    antlr4::tree::TerminalNode* LOGICAL_AND(size_t i);
    antlr4::tree::TerminalNode *BEFORE();
    antlr4::tree::TerminalNode *AFTER();
    antlr4::tree::TerminalNode *COUNT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AggregationExprContext* aggregationExpr();

  class  BooleanExprContext : public antlr4::ParserRuleContext {
  public:
    BooleanExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *L_PAREN();
    BooleanExprContext *booleanExpr();
    antlr4::tree::TerminalNode *R_PAREN();
    BooleanLiteralContext *booleanLiteral();
    SelectorIdentContext *selectorIdent();
    ListExprContext *listExpr();
    RelationExprContext *relationExpr();
    LogicalExprContext *logicalExpr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BooleanExprContext* booleanExpr();

  class  BooleanLiteralContext : public antlr4::ParserRuleContext {
  public:
    BooleanLiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TRUE();
    antlr4::tree::TerminalNode *FALSE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BooleanLiteralContext* booleanLiteral();

  class  LogicalStmtContext : public antlr4::ParserRuleContext {
  public:
    LogicalStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LogicalExprContext *logicalExpr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LogicalStmtContext* logicalStmt();

  class  LogicalExprContext : public antlr4::ParserRuleContext {
  public:
    LogicalExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LOGICAL_NOT();
    std::vector<BooleanExprContext *> booleanExpr();
    BooleanExprContext* booleanExpr(size_t i);
    BooleanLiteralContext *booleanLiteral();
    antlr4::tree::TerminalNode *LOGICAL_AND();
    antlr4::tree::TerminalNode *L_PAREN();
    antlr4::tree::TerminalNode *R_PAREN();
    ListExprContext *listExpr();
    RelationExprContext *relationExpr();
    antlr4::tree::TerminalNode *LOGICAL_OR();
    LogicalExprContext *logicalExpr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LogicalExprContext* logicalExpr();
  LogicalExprContext* logicalExpr(int precedence);
  class  DefinitionStmtContext : public antlr4::ParserRuleContext {
  public:
    DefinitionStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    InstanceNameContext *instanceName();
    antlr4::tree::TerminalNode *ASSIGN();
    ExprContext *expr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DefinitionStmtContext* definitionStmt();

  class  InstanceNameContext : public antlr4::ParserRuleContext {
  public:
    InstanceNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InstanceNameContext* instanceName();

  class  QueryExprContext : public antlr4::ParserRuleContext {
  public:
    QueryExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    EntityNameContext *entityName();
    antlr4::tree::TerminalNode *WHERE();
    BooleanExprContext *booleanExpr();
    antlr4::tree::TerminalNode *SELECT();
    antlr4::tree::TerminalNode *COLLECT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  QueryExprContext* queryExpr();

  class  ExprContext : public antlr4::ParserRuleContext {
  public:
    ExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LogicalExprContext *logicalExpr();
    NumberExprContext *numberExpr();
    BooleanExprContext *booleanExpr();
    QueryExprContext *queryExpr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExprContext* expr();

  class  AssignStmtContext : public antlr4::ParserRuleContext {
  public:
    AssignStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OUTPUT();
    antlr4::tree::TerminalNode *ASSIGN();
    antlr4::tree::TerminalNode *L_CURLY();
    std::vector<AssignExprContext *> assignExpr();
    AssignExprContext* assignExpr(size_t i);
    antlr4::tree::TerminalNode *R_CURLY();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AssignStmtContext* assignStmt();

  class  AssignExprContext : public antlr4::ParserRuleContext {
  public:
    AssignExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AttributeNameContext *attributeName();
    antlr4::tree::TerminalNode *COLON();
    ExprContext *expr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AssignExprContext* assignExpr();

  class  IfStmtContext : public antlr4::ParserRuleContext {
  public:
    IfStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IF();
    BooleanExprContext *booleanExpr();
    antlr4::tree::TerminalNode *THEN();
    std::vector<antlr4::tree::TerminalNode *> L_CURLY();
    antlr4::tree::TerminalNode* L_CURLY(size_t i);
    std::vector<RuleStmtListContext *> ruleStmtList();
    RuleStmtListContext* ruleStmtList(size_t i);
    std::vector<antlr4::tree::TerminalNode *> R_CURLY();
    antlr4::tree::TerminalNode* R_CURLY(size_t i);
    antlr4::tree::TerminalNode *ELSE();
    IfStmtContext *ifStmt();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IfStmtContext* ifStmt();

  class  SequentialStmtContext : public antlr4::ParserRuleContext {
  public:
    SequentialStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SequentialExprContext *sequentialExpr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SequentialStmtContext* sequentialStmt();

  class  SequentialExprContext : public antlr4::ParserRuleContext {
  public:
    SequentialExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<EntityNameContext *> entityName();
    EntityNameContext* entityName(size_t i);
    antlr4::tree::TerminalNode *BEFORE();
    antlr4::tree::TerminalNode *AFTER();
    antlr4::tree::TerminalNode *FOLLOW();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SequentialExprContext* sequentialExpr();

  class  DateStmtContext : public antlr4::ParserRuleContext {
  public:
    DateStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DateExprContext *dateExpr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DateStmtContext* dateStmt();

  class  DateExprContext : public antlr4::ParserRuleContext {
  public:
    DateExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BooleanExprContext *booleanExpr();
    antlr4::tree::TerminalNode *DATE_LIT();
    antlr4::tree::TerminalNode *BEFORE();
    antlr4::tree::TerminalNode *AFTER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DateExprContext* dateExpr();

  class  TimeStmtContext : public antlr4::ParserRuleContext {
  public:
    TimeStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TimeExprContext *timeExpr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TimeStmtContext* timeStmt();

  class  TimeExprContext : public antlr4::ParserRuleContext {
  public:
    TimeExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BooleanExprContext *booleanExpr();
    antlr4::tree::TerminalNode *WITHIN();
    antlr4::tree::TerminalNode *TIME_LIT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TimeExprContext* timeExpr();

  class  EosContext : public antlr4::ParserRuleContext {
  public:
    EosContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEMI();
    antlr4::tree::TerminalNode *TERMINATOR();
    antlr4::tree::TerminalNode *EOF();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EosContext* eos();


  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;
  bool numberExprSempred(NumberExprContext *_localctx, size_t predicateIndex);
  bool logicalExprSempred(LogicalExprContext *_localctx, size_t predicateIndex);

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

