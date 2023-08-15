#include "Expr.h"

using namespace RuleLanguage;

bool queryExpr::isSellect() {
    return sellect;
}

bool queryExpr::isCollect() {
    return collect;
}

Type queryExpr::type() {
    return sellect ? Type::INSTANCE : Type::INSTANCELIST;
}