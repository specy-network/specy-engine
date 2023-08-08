#pragma once
#include <iostream>

enum Type {
    number = 0,
    boolean,
    string,
    list,
    date,
    instance_list,
    instance
};

class Expr {
    public:
        Expr() = default;
        ~Expr() = default;
        virtual Type type() = 0;   
};

class logicalExpr : public Expr {
    public:
        logicalExpr() = default;
        ~logicalExpr() = default;
        Type type() {
            return Type::boolean;
        }
};

class numberExpr : public Expr {
    public:
        numberExpr() = default;
        ~numberExpr() = default;
        Type type() {
            return Type::number;
        }
};

class booleanExpr : public Expr {
    public:
        booleanExpr() = default;
        ~booleanExpr() = default;
        Type type() {
            return Type::boolean;
        }
};

class queryExpr : public Expr {
    
    private:
        bool sellect;
        bool collect;
    
    public:
        queryExpr() = default;
        ~queryExpr() = default;
        bool isSellect();
        bool isCollect();
        Type type();

};