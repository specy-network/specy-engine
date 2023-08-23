#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include <string>

class Instance;
class Entity;
class Attribute;

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
        virtual std::string dump() = 0;
};

class numberExpr : public Expr {
    public:
        numberExpr() = default;
        ~numberExpr() = default;
        Type type() override {
            return Type::NUMBER;
        }

        bool isNegative() {
            return negative;
        }

        void setNegative() {
            negative = true;
        }

        void setOperator(ArithmeticOperator op) {
            arith_operator = op;
        }

        void setLeftExpr(numberExpr* expr) {
            left_expr.reset(expr);
        }

        void setRightExpr(numberExpr* expr) {
            right_expr.reset(expr);
        }

        void setValue(int64_t value) {
            this->value = value;
        }

        void setInstance(std::shared_ptr<Instance>& instance) {
            this->instance = instance;
        }

        std::string dump() override;

    private:
        bool negative;
        /* TODO: use big number to instead*/
        int64_t value;
        ArithmeticOperator arith_operator;
        std::unique_ptr<numberExpr> left_expr;
        std::unique_ptr<numberExpr> right_expr;
        std::shared_ptr<Instance> instance;
};

class relationExpr : public Expr {
    private:
        std::unique_ptr<numberExpr> first_expr;
        std::vector<std::unique_ptr<numberExpr>> numbers;
        std::vector<RelationOperator> operators;

    public:
        relationExpr() = default;
        ~relationExpr() = default;
        std::string dump() override;
        Type type() {
            return Type::BOOLEAN;
        }

        void setFirstExpr(numberExpr* expr) {
            first_expr.reset(expr);
        }

        void addNumberExpr(numberExpr* expr) {
            std::unique_ptr<numberExpr> expr_ptr(expr);
            numbers.push_back(std::move(expr_ptr));
        }

        void addOperator(RelationOperator op) {
            operators.push_back(op);
        }
};

class listExpr : public Expr {

};

class booleanExpr : public Expr {
    
    private:
        std::unique_ptr<Expr> expr;
        bool literalValue;
        std::shared_ptr<Instance> instance;
    
    public:
        booleanExpr() = default;
        ~booleanExpr() = default;
        std::string dump() override;
        Type type() {
            return Type::BOOLEAN;
        }

        void setValue(bool value) {
            literalValue = value;
        }

        void setExpr(Expr* expr) {
            this->expr.reset(expr);
        }

        void setInstance(std::shared_ptr<Instance> instance) {
            this->instance = instance;
        }
};

class logicalExpr : public Expr {
    public:
        logicalExpr() = default;
        ~logicalExpr() = default;
        std::string dump() override;
        Type type() {
            return Type::BOOLEAN;
        }

        void setOperator(LogicalOperator op) {
            logical_operator = op;
        }

        void setLeftExpr(Expr* expr) {
            left_expr.reset(expr);
        }

        void setRightExpr(Expr* expr) {
            right_expr.reset(expr);
        }

        void setBooleanExpr(booleanExpr* expr) {
            boolean_expr.reset(expr);
        }

    private:
        LogicalOperator logical_operator;
        std::unique_ptr<booleanExpr> boolean_expr;
        std::unique_ptr<Expr> left_expr;
        std::unique_ptr<Expr> right_expr;
};


class basicCondExpr : public Expr {
    private:
        std::unique_ptr<relationExpr> rExpr;
        std::unique_ptr<listExpr> lExpr;
        LogicalOperator logical_operator;
    public:
        basicCondExpr() = default;
        ~basicCondExpr() = default;
        std::string dump() override;
        Type type() override {
            return Type::BOOLEAN;
        }

        void setListExpr(listExpr* expr) {
            lExpr.reset(expr);
        }

        void setRelationExpr(relationExpr* expr) {
            rExpr.reset(expr);
        }

        void setOperator(LogicalOperator op) {
            logical_operator = op;
        }

};

class conditionExpr : public Expr {
    private:
        std::unique_ptr<basicCondExpr> basic_expr;
        std::vector<std::unique_ptr<basicCondExpr>> basicExprs;

    public:
        conditionExpr() = default;
        ~conditionExpr() = default;
        std::string dump() override;
        Type type() override {
            return Type::BOOLEAN;
        }

        void setBasicExpr(basicCondExpr* expr) {
            basic_expr.reset(expr);
        }

        void addExpr(basicCondExpr* expr) {
            std::unique_ptr<basicCondExpr> expr_ptr(expr);
            basicExprs.push_back(std::move(expr_ptr));
        }
};

class queryExpr : public Expr {
    
    private:
        bool select;
        bool collect;
        // Instance* instance;
        // Entity* entity;
        // conditionExpr* expr;

        std::shared_ptr<Instance> instance;
        std::shared_ptr<Entity> entity;
        std::unique_ptr<conditionExpr> expr;
    
    public:
        queryExpr() = default;
        ~queryExpr() = default;
        std::string dump() override;
        bool isSelect();
        bool isCollect();
        Type type();

        void setSelect(bool value) {
            select = value;
        }

        void setCollect(bool value) {
            collect = value;
        }

        void setInstance(std::shared_ptr<Instance>& instance) {
            this->instance = instance;
        }

        void setEntity(std::shared_ptr<Entity>& entity) {
            this->entity = entity;
        }

        void setExpr(conditionExpr* expr) {
            this->expr.reset(expr);
        }

        std::shared_ptr<Entity> getEntity() {
            return entity;
        }

        std::shared_ptr<Instance> getInstance() {
            return instance;
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

std::string TypeToString(Type type);
std::string LogicalOperatorToString(LogicalOperator op);
std::string ArithmeticOperatorToString(ArithmeticOperator op);
std::string QueryOperatorToString(QueryOperator op);
std::string RelationOperatorToString(RelationOperator op);

} // namespace RuleLanguage