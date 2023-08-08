#include "Expr.h"



bool queryExpr::isSellect() {
    return sellect;
}

bool queryExpr::isCollect() {
    return collect;
}

Type queryExpr::type() {
    return sellect ? Type::instance : Type::instance_list;
}