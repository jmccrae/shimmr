#pragma once

#include "../parser/type.h"

namespace shimmrLogic {

	class Value {
	protected:
		const std::shared_ptr<shimmrType::TypeSystem> sys;
		Value(std::shared_ptr<shimmrType::TypeSystem>);
	public:
		virtual std::shared_ptr<shimmrType::Type> type() const = 0;
	};

	class StringValue : public Value {
	private:
		const std::string _value;
		std::shared_ptr<shimmrType::Type> _type;
	public:
		StringValue(std::shared_ptr<shimmrType::TypeSystem>,std::string&);
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
	public:
		Clause(std::vector<std::shared_ptr<Predicate>>&,std::vector<std::shared_ptr<Predicate>>&);
		~Clause();
	};

}
