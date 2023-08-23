#include "Instance.h"
#include "RuleEnclave_t.h"

std::string ObjectAttribute::dump() {
    return instance_value->dump();
}

std::string Instance::dump() {    
    if (instance_kind == InstanceKind::EXPR) {
        return name + ": " + expr->dump();
    }
    if (instance_kind == InstanceKind::UNIQUE_ENTITY ) {
        std::string instance_str = name + "{  \n";
        for (auto attribute : attribute_list) {
            instance_str = instance_str + attribute.second->dump() + "\n";
        }
        instance_str += "}\n";
        return instance_str;
    }
    if (instance_kind == InstanceKind::SYMBOL) {
        return name;
    }

    if (instance_kind == InstanceKind::SPECIFIC_ATTRIBUTE) {
        std::string instance_str = name + ".";
        for (auto attribute : attribute_list) {
            instance_str = instance_str + attribute.second->dump();
        }
        return instance_str;
    }

    return "error!";
}