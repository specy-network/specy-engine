#pragma once
#include "Expr.h"
#include <string>

class Instance {

    private:
        std::string name;
        Expr* expr;

    public:
        Instance() = default;
        Instance(std::string& instanceName, Expr* instanceExpr) : name(instanceName), expr(instanceExpr) {}
        ~Instance() {
            free(expr);
        }
        Type type() {
            return expr->type();
        }

};