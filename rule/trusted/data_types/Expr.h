#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include <string>

class Instance;
class Entity;

namespace RuleLanguage
{
    
enum Type {
    NUMBER = 0,
    BOOLEAN,
    STRING,
    LIST,
    DATE,
    INSTANCELIST,
    INSTANCE
};

enum LogicalOperator {
    NOT = 0,
    AND,
    OR,
    LOGICAL_NON
};

enum ArithmeticOperator {
    MULTIPLY = 0,
    DIVIDE,
    MODULO,
    PLUS,
    MINUS,
    ARITH_NON
};

enum QueryOperator {
    SELECT = 0,
    COLLECT,
    QUERY_NON
};

enum RelationOperator {
    EQUALS = 0,
    NOT_EQUALS,
    LESS_THAN,
    LESS_OR_EQUALS,
    GREATER,
    GREATER_OR_EQUALS,
    RELATION_NON
};

class Expr {
    public:
        Expr() = default;
        ~Expr() = default;
        virtual Type type() = 0;
};

class numberExpr : public Expr {
    public:
        numberExpr() = default;
        ~numberExpr() = default;
        Type type() {
            return Type::NUMBER;
        }

        bool isNegative() {
            return negative;
        }

        void setNegative() {
            negative = true;
        }

        void setOperator(ArithmeticOperator op) {
            operand = op;
        }

        void setLeftExpr(numberExpr* expr) {
            left_expr = expr;
        }

        void setRightExpr(numberExpr* expr) {
            right_expr = expr;
        }

        void setValue(int64_t value) {
            this->value = value;
        }

        void setInstance(Instance* instance) {
            this->instance = instance;
        }

    private:
        bool negative;
        /* TODO: use big number to instead*/
        int64_t value;
        ArithmeticOperator operand;
        numberExpr *left_expr;
        numberExpr *right_expr;
        Instance* instance;
};

class booleanExpr : public Expr {
    
    private:
        Expr* expr;
        bool literalValue;
        Instance* instance;
    
    public:
        booleanExpr() = default;
        ~booleanExpr() = default;
        Type type() {
            return Type::BOOLEAN;
        }

        void setValue(bool value) {
            literalValue = value;
        }

        void setExpr(Expr* expr) {
            this->expr = expr;
        }

        void setInstance(Instance* instance) {
            this->instance = instance;
        }
};

class logicalExpr : public Expr {
    public:
        logicalExpr() = default;
        ~logicalExpr() = default;
        Type type() {
            return Type::BOOLEAN;
        }

        void setOperator(LogicalOperator op) {
            operand = op;
        }

        void setLeftExpr(Expr* expr) {
            left_expr = expr;
        }

        void setRightExpr(Expr* expr) {
            right_expr = expr;
        }

        void setBooleanExpr(booleanExpr* expr) {
            boolean_expr = expr;
        }

    private:
        LogicalOperator operand;
        booleanExpr* boolean_expr;
        Expr* left_expr;
        Expr* right_expr;
};


class relationExpr : public Expr {
    private:
        numberExpr* first_expr;
        std::vector<numberExpr*> numbers;
        std::vector<RelationOperator> operators;

    public:
        relationExpr() = default;
        ~relationExpr() = default;
        Type type() {
            return Type::BOOLEAN;
        }

        void setFirstExpr(numberExpr* expr) {
            first_expr = expr;
        }

        void addNumberExpr(numberExpr* expr) {
            numbers.push_back(expr);
        }

        void addOperator(RelationOperator op) {
            operators.push_back(op);
        }
};

class listExpr : public Expr {

};

class basicCondExpr : public Expr {
    private:
        relationExpr* rExpr;
        listExpr* lExpr;
        LogicalOperator operand;
    public:
        basicCondExpr() = default;
        ~basicCondExpr() = default;
        Type type() override {
            return Type::BOOLEAN;
        }

        void setListExpr(listExpr* expr) {
            lExpr = expr;
        }

        void setRelationExpr(relationExpr* expr) {
            rExpr = expr;
        }

        void setOperator(LogicalOperator op) {
            operand = op;
        }

};

class conditionExpr : public Expr {
    private:
        basicCondExpr* basic_expr;
        std::vector<basicCondExpr*> basicExprs;

    public:
        conditionExpr() = default;
        ~conditionExpr() = default;
        Type type() override {
            return Type::BOOLEAN;
        }

        void setBasicExpr(basicCondExpr* expr) {
            basic_expr = expr;
        }

        void addExpr(basicCondExpr* expr) {
            basicExprs.push_back(expr);
        }
};

class queryExpr : public Expr {
    
    private:
        bool sellect;
        bool collect;
        Instance* instance;
        Entity* entity;
        conditionExpr* expr;
    
    public:
        queryExpr() = default;
        ~queryExpr() = default;
        bool isSellect();
        bool isCollect();
        Type type();

        void setSellect(bool value) {
            sellect = value;
        }

        void setCollect(bool value) {
            collect = value;
        }

        void setInstance(Instance* instance) {
            this->instance = instance;
        }

        void setEntity(Entity* entity) {
            this->entity = entity;
        }

        void setExpr(conditionExpr* expr) {
            this->expr = expr;
        }

};

class literal : public Expr {
    private:
        Type literalType;

        std::string stringValue;
        bool booleanValue;
        uint64_t uNumberValue;
        int64_t sNumberValue;
        std::string dateValue;

    public:
        literal() = default;
        ~literal() = default;
        Type type();
};

} // namespace RuleLanguage