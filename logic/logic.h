#pragma once

#include "../parser/type.h"
#include "../parser/scope.h"

namespace shimmr {
    namespace logic {

        class Value {
        protected:
            const std::shared_ptr<shimmr::type::TypeSystem> sys;
            Value(std::shared_ptr<shimmr::type::TypeSystem>);
        public:
            virtual std::shared_ptr<shimmr::type::Type> type() const = 0;
        };

        class LiteralValue : public Value {
        private:
            const std::shared_ptr<shimmr::type::TypeValue> _value;
        public:
            LiteralValue(std::shared_ptr<shimmr::type::TypeSystem>, std::shared_ptr<shimmr::type::TypeValue>);
            virtual std::shared_ptr<shimmr::type::Type> type() const;
        };

        class VariableValue : public Value {
        private:
            const std::shared_ptr<shimmr::type::Type> _type;
            const std::string _id;
            const std::set<std::string> _specifiers;
        public:
            VariableValue(std::shared_ptr<shimmr::type::TypeSystem>, std::shared_ptr<shimmr::type::Type>, const std::string&);
            VariableValue(std::shared_ptr<shimmr::type::TypeSystem>, std::shared_ptr<shimmr::type::Type>, const std::string&, const std::set<std::string>&);
            virtual std::shared_ptr<shimmr::type::Type> type() const;
        };

        class Statement {
        };

        class Predicate : public Statement {
        private:
            const std::string _id;
            const std::vector<std::shared_ptr<Value >> _values;
        public:
            Predicate(const std::string&, const std::vector<std::shared_ptr<Value >> &);
            ~Predicate();
        };

        class Implication : public Statement {
        private:
            std::vector<std::shared_ptr<Statement >> _premises;
            std::vector<std::shared_ptr<Statement >> _consequences;
        public:
            Implication(const std::vector<std::shared_ptr<Statement >> &, const std::vector<std::shared_ptr<Statement >> &);
            ~Implication();
            std::vector<std::shared_ptr<Statement >> &premises();
            std::vector<std::shared_ptr<Statement >> &consequences();
        };

        class Disjunction : public Statement {
        private:
            std::vector<std::shared_ptr<Statement >> _elems;
        public:
            Disjunction(const std::vector<std::shared_ptr<Statement >> &);
            ~Disjunction();
        };

        class OneOf : public Statement {
        private:
            std::vector<std::shared_ptr<Statement >> _elems;
            std::shared_ptr<VariableValue> _quant;
        public:
            OneOf(const std::vector<std::shared_ptr<Statement >> &, const std::shared_ptr<VariableValue>);
            ~OneOf();
        };

        class Weight : public Statement {
        private:
            std::vector<std::shared_ptr<Statement >> _elems;
            std::shared_ptr<Value> _weight;
        public:
            Weight(const std::vector<std::shared_ptr<Statement >> &, const std::shared_ptr<Value>);
            ~Weight();
        };
    }
}