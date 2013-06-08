#pragma once

#include <map>
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
				virtual const std::string toString() const = 0;
		};

		typedef std::vector<std::shared_ptr<Value>> ValueList;
		typedef std::shared_ptr<Value> ValuePtr;

		class LiteralValue : public Value {
			private:
				const std::shared_ptr<shimmr::type::TypeValue> _value;
			public:
				LiteralValue(std::shared_ptr<shimmr::type::TypeSystem>, std::shared_ptr<shimmr::type::TypeValue>);
				virtual std::shared_ptr<shimmr::type::Type> type() const;
				virtual const std::string toString() const;
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
				virtual const std::string toString() const;
		};

		class Disjunction;
		class Predicate;
		class Statement;
		class OneOf;

		typedef std::shared_ptr<Statement> StatementPtr;
		typedef std::shared_ptr<std::vector<std::shared_ptr<Disjunction>>> DisjunctionListPtr;
		typedef std::vector<std::shared_ptr<Disjunction>> DisjunctionList;

		class CNF {
		private:
			int counter;
			std::map<std::string,std::shared_ptr<Value>> weights;
			DisjunctionListPtr disjunctions;
			std::vector<std::shared_ptr<OneOf>> oneofs;
		public:
			CNF();
			std::shared_ptr<Predicate> makeWtAnon(std::shared_ptr<Value>);
			std::shared_ptr<Predicate> makeAnon();
			DisjunctionListPtr visit(std::shared_ptr<Statement>);
		};

		typedef CNF* CNFPtr;

		class Statement {
			public:
				virtual const std::string toString() const = 0;
				virtual DisjunctionListPtr cnf(CNFPtr) = 0;
				virtual bool isOneOf() { return false; }
		};
		typedef std::vector<std::shared_ptr<Statement>> StatementList;

		class Predicate : public Statement {
			public:
				const std::string _id;
				ValueList _values;
				const bool _negative;
				Predicate(const std::string&, const ValueList &);
				Predicate(const std::string&);
				Predicate(const std::string&, const ValuePtr);
				Predicate(const std::string&, const ValuePtr, const ValuePtr);
				Predicate(const std::string&, const ValuePtr, const ValuePtr, const ValuePtr);
				Predicate(const bool, const std::string&, const ValueList &);
				~Predicate();
				virtual const std::string toString() const;
				DisjunctionListPtr cnf(CNFPtr);
				std::shared_ptr<Predicate> negate();
		};

		class Implication : public Statement {
			private:
				StatementList _premises;
				StatementList _consequences;
			public:
				Implication(const StatementList &, const StatementList &);
				~Implication();
				StatementList &premises();
				StatementList &consequences();
				virtual const std::string toString() const;
				DisjunctionListPtr cnf(CNFPtr);
		};

		class Alternative : public Statement {
			private:
				StatementList _s1, _s2;
			public:
				Alternative(const StatementList &, const StatementList &);
				~Alternative();
				virtual const std::string toString() const;
				DisjunctionListPtr cnf(CNFPtr);
		};

		class OneOfCNF {
		public:
			DisjunctionListPtr disjunctions;
			std::shared_ptr<OneOf> oneof;
		};

		class OneOf : public Statement {
			private:
				StatementList _elems;
				StatementList _alt;
				std::shared_ptr<VariableValue> _quant;
			public:
				OneOf(const StatementList &, const StatementList&, const std::shared_ptr<VariableValue>);
				~OneOf();
				virtual const std::string toString() const;
				DisjunctionListPtr cnf(CNFPtr);
				OneOfCNF cnf2(CNFPtr);
				bool isOneOf() { return true; }
		};

		class Weight : public Statement {
			private:
				StatementList _elems;
				std::shared_ptr<Value> _weight;
			public:
				Weight(const StatementList &, const std::shared_ptr<Value>);
				~Weight();
				virtual const std::string toString() const;
				DisjunctionListPtr cnf(CNFPtr);
		};

		class Disjunction {
			private:
				std::vector<std::shared_ptr<Predicate>> _predicate;
			public:
				Disjunction();
				Disjunction(std::shared_ptr<Predicate>);
				Disjunction(const Disjunction&);
				Disjunction(const Disjunction&, const Disjunction&);
				void add(std::shared_ptr<Predicate>);
				const std::vector<std::shared_ptr<Predicate>>& predicates();
				DisjunctionListPtr negate();
		};
	}
}
