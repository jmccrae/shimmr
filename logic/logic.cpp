#include "logic.h"

using namespace std;

namespace shimmrLogic {

	Value::Value(shared_ptr<shimmrType::TypeSystem> s) : sys(s) {

	}

	LiteralValue::LiteralValue(shared_ptr<shimmrType::TypeSystem> s, shared_ptr<shimmrType::TypeValue> v) : Value(s), _value(v) {
		
	}
	
	shared_ptr<shimmrType::Type> LiteralValue::type() const {
		return _value->type(sys);
	}
	
	VariableValue::VariableValue(shared_ptr<shimmrType::TypeSystem> s, shared_ptr<shimmrType::Type> t, const string& id) : Value(s),_type(t),_id(id) {
		
	}
	
	shared_ptr<shimmrType::Type> VariableValue::type() const {
		return _type;
	}

	Predicate::Predicate(string& s, vector<shared_ptr<Value>>& v) : _id(s), _values(v) {

	}

	Predicate::~Predicate() {

	}

	Clause::Clause(vector<shared_ptr<Predicate>>& p, vector<shared_ptr<Predicate>>& c, bool x) : _premises(p), _consequences(c), exclusive(x) {

	}

	Clause::~Clause() {

	}

	bool Clause::isExclusive() {
		return exclusive;
	}
		
	vector<shared_ptr<Predicate>>& Clause::premises() {
		return _premises;
	}
	
	vector<shared_ptr<Predicate>>& Clause::consequences() {
		return _consequences;
	}

}