#include "logic.h"

using namespace std;

namespace shimmrLogic {

	Value::Value(shared_ptr<shimmrType::TypeSystem> s) : sys(s) {

	}

	StringValue::StringValue(shared_ptr<shimmrType::TypeSystem> s, string& v) : Value(s), _value(v) {
		std::set<const std::shared_ptr<shimmrType::TypeValue>, decltype(shimmrType::compareTypeValue)*> values(shimmrType::compareTypeValue);
		values.insert(make_shared<shimmrType::StringTypeValue>(v));
		_type = sys->makeSet(values);
	}

	shared_ptr<shimmrType::Type> StringValue::type() const {
		return _type;
	}

	Predicate::Predicate(string& s, vector<shared_ptr<Value>>& v) : _id(s), _values(v) {

	}

	Predicate::~Predicate() {

	}

	Clause::Clause(vector<shared_ptr<Predicate>>& p, vector<shared_ptr<Predicate>>& c) : _premises(p), _consequences(c) {

	}

	Clause::~Clause() {

	}

}