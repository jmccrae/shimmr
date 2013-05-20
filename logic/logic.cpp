#include "logic.h"
#include <sstream>

using namespace std;

namespace shimmr {
    namespace logic {

        Value::Value(shared_ptr<shimmr::type::TypeSystem> s) : sys(s) {

        }

        LiteralValue::LiteralValue(shared_ptr<shimmr::type::TypeSystem> s, shared_ptr<shimmr::type::TypeValue> v) : Value(s), _value(v) {

        }

        shared_ptr<shimmr::type::Type> LiteralValue::type() const {
            return _value->type(sys);
        }

		const string& LiteralValue::toString() const {
			return _value->symbol();
		}

        VariableValue::VariableValue(shared_ptr<shimmr::type::TypeSystem> s, shared_ptr<shimmr::type::Type> t, const string& id) :
        Value(s), _type(t), _id(id) {

        }

        VariableValue::VariableValue(shared_ptr<shimmr::type::TypeSystem> s, shared_ptr<shimmr::type::Type> t, const string& id, const set<string>& sp) :
        Value(s), _type(t), _id(id), _specifiers(sp) {

        }

		const string& VariableValue::toString() const {
			return _id;
		}

        shared_ptr<shimmr::type::Type> VariableValue::type() const {
            return _type;
        }

        Predicate::Predicate(const string& s, const vector<shared_ptr<Value >> &v) : _id(s), _values(v) {
			stringstream ss;
			ss << _id << "(";
			int i = 1;
			for(auto v2 : _values) {
				ss << v2->toString();
				if(i != _values.size()) {
					ss << ",";
				}
				i++;
			}
			ss << ")";
			_symbol = ss.str();
        }

        Predicate::~Predicate() {

        }

		const string& Predicate::toString() const {
			return _symbol;
		}

        Implication::Implication(const vector<shared_ptr<Statement >> &p, const vector<shared_ptr<Statement >> &c) :
        _premises(p), _consequences(c) {
			stringstream ss;
			int i = 1;
			for(auto p2 : _premises) {
				ss << p2->toString();
				if(i != _premises.size()) {
					ss << " ^ ";
				}
				i++;
			}
			ss << " -> ";
			i = 1;
			for(auto c2 : _consequences) {
				ss << c2->toString();
				if(i != _consequences.size()) {
					ss << " ^ ";
				}
				i++;
			}
			_symbol = ss.str();
        }

        Implication::~Implication() {

        }

        vector<shared_ptr<Statement >> &Implication::premises() {
            return _premises;
        }

        vector<shared_ptr<Statement >> &Implication::consequences() {
            return _consequences;
        }

		const string& Implication::toString() const {
			return _symbol;
		}

        Disjunction::Disjunction(const StatementList& s1, const StatementList& s2) :
        _s1(s1),_s2(s2) {
			stringstream ss;
			ss << "(";
			int i = 1;
			for(auto s1i : s1) {
				ss << s1i->toString();
				if(i != s1.size()) {
					ss << " ^ ";
				}
				i++;
			}
			ss << ") v (";
			for(auto s1i : s1) {
				ss << s1i->toString();
				if(i != s1.size()) {
					ss << " ^ ";
				}
				i++;
			}
			ss << ")";
			_symbol = ss.str();
        }

        Disjunction::~Disjunction() {
        }

		const string& Disjunction::toString() const {
			return _symbol;
		}

        OneOf::OneOf(const vector<shared_ptr<Statement >> &s, const vector<shared_ptr<Statement>>& a, const shared_ptr<VariableValue> v) :
        _elems(s), _alt(a), _quant(v) {
			stringstream ss;
			ss << "O[" << v->toString() << "](";
			int i = 1;
			for(auto si : s) {
				ss << si->toString();
				if(i != s.size()) {
					ss << " ^ ";
				}
				i++;
			}
			ss << ") o (";
			i = 1;
			for(auto ai : a) {
				ss << ai->toString();
				if(i != a.size()) {
					ss << " ^ ";
				}
				i++;
			}
			ss << ")";
			_symbol = ss.str();

        }

        OneOf::~OneOf() {
        }

		const string& OneOf::toString() const {
			return _symbol;
		}

        Weight::Weight(const vector<shared_ptr<Statement >> &s, const shared_ptr<Value> w) :
        _elems(s), _weight(w) {
			stringstream ss;
			ss << "(";
			int i = 1;
			for(auto si : s) {
				ss << si->toString();
				if(i != s.size()) {
					ss << " ^ ";
				}
				i++;
			}
			ss << ") with " << w->toString();
			_symbol = ss.str();
        }

        Weight::~Weight() {

        }

		const string& Weight::toString() const {
			return _symbol;
		}
    }
}