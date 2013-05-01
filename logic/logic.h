#pragma once

#include "../parser/type.h"
#include "../parser/scope.h"

namespace shimmrLogic {

	class Value {
	protected:
		const std::shared_ptr<shimmrType::TypeSystem> sys;
		Value(std::shared_ptr<shimmrType::TypeSystem>);
	public:
		virtual std::shared_ptr<shimmrType::Type> type() const = 0;
	};

	class LiteralValue : public Value {
	private:
		const std::shared_ptr<shimmrType::TypeValue> _value;
	public:
		LiteralValue(std::shared_ptr<shimmrType::TypeSystem>,std::shared_ptr<shimmrType::TypeValue>);
		virtual std::shared_ptr<shimmrType::Type> type() const;
	};
	
	class VariableValue : public Value {
	private:
		const std::shared_ptr<shimmrType::Type> _type;
		const std::string _id;
	public:
		VariableValue(std::shared_ptr<shimmrType::TypeSystem>,std::shared_ptr<shimmrType::Type>, const std::string&);
		virtual std::shared_ptr<shimmrType::Type> type() const;
	};
	
	
	class Predicate {
	private:
		const std::string _id;
		const std::vector<std::shared_ptr<Value>> _values;
	public:
		Predicate(std::string&, std::vector<std::shared_ptr<Value>>&);
		~Predicate();
	};

	class Clause {
	private:
		std::vector<std::shared_ptr<Predicate>> _premises;
		std::vector<std::shared_ptr<Predicate>> _consequences;
		const bool exclusive;
	public:
		Clause(std::vector<std::shared_ptr<Predicate>>&,std::vector<std::shared_ptr<Predicate>>&, bool exclusive);
		~Clause();
		bool isExclusive();
		std::vector<std::shared_ptr<Predicate>>& premises();
		std::vector<std::shared_ptr<Predicate>>& consequences();
	};

}
