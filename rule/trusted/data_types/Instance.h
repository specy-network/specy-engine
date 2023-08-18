#pragma once
#include "Expr.h"
#include <string>
#include <map>

class Instance;

class Attribute {
    private:
        std::string name;
        RuleLanguage::Type type;

    public:
        Attribute() = default;
        ~Attribute() = default;
        Attribute(std::string attribute_name, RuleLanguage::Type attribute_type) : name(attribute_name), type(attribute_type) {}
        bool isAttributeType(RuleLanguage::Type type) {
            return type == this->type;
        }

        std::string getName() {
            return name;
        }
};

class NumberAttribute : public Attribute {
    private:
        int64_t number_value;

    public:
        NumberAttribute() = default;
        NumberAttribute(std::string name, RuleLanguage::Type type) : Attribute(name, type) {}
        NumberAttribute(std::string name, RuleLanguage::Type type, int64_t value) : Attribute(name, type), number_value(value) {}
        ~NumberAttribute() = default;

        int64_t value() {
            return number_value;
        }
};

class BooleanAttribute : public Attribute {
    private:
        bool boolean_value;
    
    public:
        BooleanAttribute() = default;
        BooleanAttribute(std::string name, RuleLanguage::Type type) : Attribute(name, type) {}
        BooleanAttribute(std::string name, RuleLanguage::Type type, bool value) : Attribute(name, type), boolean_value(value) {}
        ~BooleanAttribute() = default;

        bool value() {
            return boolean_value;
        }
};

class StringAttribute : public Attribute {
    private:
        std::string string_value;

    public:
        StringAttribute() = default;
        StringAttribute(std::string name, RuleLanguage::Type type) : Attribute(name, type) {}
        StringAttribute(std::string name, RuleLanguage::Type type, std::string value) : Attribute(name, type), string_value(value) {}
        ~StringAttribute() = default;

        std::string value() {
            return string_value;
        }
};

class ObjectAttribute : public Attribute {
    private:
        std::unique_ptr<Instance> instance_value;
    
    public:
        ObjectAttribute() = default;
        ObjectAttribute(std::string name, RuleLanguage::Type type) : Attribute(name, type) {}
        ObjectAttribute(std::string name, RuleLanguage::Type type, Instance* value) : Attribute(name, type) {
            instance_value.reset(value);
        }
        ~ObjectAttribute() = default;

        Instance* value() {
            return instance_value.get();
        }
};

class Instance {

    private:
        std::string name;
        std::unique_ptr<RuleLanguage::Expr> expr;
        std::string unique_entity_name;
        std::map<std::string, std::shared_ptr<Attribute>> attribute_list;

    public:
        Instance() = default;
        Instance(const std::string& instanceName) : name(instanceName) {}

        ~Instance() = default;

        RuleLanguage::Type type() {
            if (expr != nullptr) {
                return expr->type();
            }

            if (!unique_entity_name.empty()) {
                return RuleLanguage::Type::INSTANCE;
            }
        }

        bool isUniqueEntityInstance() {
            return !unique_entity_name.empty();
        }

        void setExpr(RuleLanguage::Expr* expr) {
            this->expr.reset(expr);
        }

        void setUniqueEntityName(std::string& name) {
            unique_entity_name = name;
        }

        void addAttributes(const std::map<std::string, std::shared_ptr<Attribute>>& attributes) {
            attribute_list.insert(attributes.begin(), attributes.end());
        }

        void addAttribute(std::string name, std::shared_ptr<Attribute>& attribute) {
            attribute_list[name] = attribute;
        }

        bool hasAttribute(const std::string attribute_name, RuleLanguage::Type type) {
            if (attribute_list.find(attribute_name) != attribute_list.end()) {
                auto attribute = attribute_list[attribute_name];
                if (attribute->isAttributeType(type)) {
                    return true;
                }
            }
            return false;
        }


};