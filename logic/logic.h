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
			virtual const std::string& toString() const = 0;
        };

		typedef std::vector<std::shared_ptr<Value>> ValueList;

        class LiteralValue : public Value {
        private:
            const std::shared_ptr<shimmr::type::TypeValue> _value;
        public:
            LiteralValue(std::shared_ptr<shimmr::type::TypeSystem>, std::shared_ptr<shimmr::type::TypeValue>);
            virtual std::shared_ptr<shimmr::type::Type> type() const;
			virtual const std::string& toString() const;
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
			virtual const std::string& toString() const;
        };

        class Statement {
		public:
			virtual const std::string& toString() const = 0;
        };
		typedef std::vector<std::shared_ptr<Statement>> StatementList;

        class Predicate : public Statement {
        private:
            const std::string _id;
            const ValueList _values;
			std::string _symbol;
        public:
			Predicate(const std::string&, const ValueList &);
            ~Predicate();
			virtual const std::string& toString() const;
        };

        class Implication : public Statement {
        private:
            StatementList _premises;
            StatementList _consequences;
			std::string _symbol;
        public:
			Implication(const StatementList &, const StatementList &);
            ~Implication();
            StatementList &premises();
            StatementList &consequences();
			virtual const std::string& toString() const;
        };

        class Disjunction : public Statement {
        private:
            StatementList _s1, _s2;
			std::string _symbol;
        public:
            Disjunction(const StatementList &, const StatementList &);
            ~Disjunction();
			virtual const std::string& toString() const;
        };

        class OneOf : public Statement {
        private:
            StatementList _elems;
			StatementList _alt;
            std::shared_ptr<VariableValue> _quant;
			std::string _symbol;
        public:
            OneOf(const StatementList &, const StatementList&, const std::shared_ptr<VariableValue>);
            ~OneOf();
			virtual const std::string& toString() const;
        };

        class Weight : public Statement {
        private:
            StatementList _elems;
            std::shared_ptr<Value> _weight;
			std::string _symbol;
        public:
            Weight(const StatementList &, const std::shared_ptr<Value>);
            ~Weight();
			virtual const std::string& toString() const;
        };
    }
}