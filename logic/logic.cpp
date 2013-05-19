#include "logic.h"

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

        VariableValue::VariableValue(shared_ptr<shimmr::type::TypeSystem> s, shared_ptr<shimmr::type::Type> t, const string& id) :
        Value(s), _type(t), _id(id) {

        }

        VariableValue::VariableValue(shared_ptr<shimmr::type::TypeSystem> s, shared_ptr<shimmr::type::Type> t, const string& id, const set<string>& sp) :
        Value(s), _type(t), _id(id), _specifiers(sp) {

        }

        shared_ptr<shimmr::type::Type> VariableValue::type() const {
            return _type;
        }

        Predicate::Predicate(const string& s, const vector<shared_ptr<Value >> &v) : _id(s), _values(v) {

        }

        Predicate::~Predicate() {

        }

        Implication::Implication(const vector<shared_ptr<Statement >> &p, const vector<shared_ptr<Statement >> &c) :
        _premises(p), _consequences(c) {

        }

        Implication::~Implication() {

        }

        vector<shared_ptr<Statement >> &Implication::premises() {
            return _premises;
        }

        vector<shared_ptr<Statement >> &Implication::consequences() {
            return _consequences;
        }

        Disjunction::Disjunction(const vector<shared_ptr<Statement >> &s) :
        _elems(s) {

        }

        Disjunction::~Disjunction() {
        }

        OneOf::OneOf(const vector<shared_ptr<Statement >> &s, const shared_ptr<VariableValue> v) :
        _elems(s), _quant(v) {

        }

        OneOf::~OneOf() {
        }

        Weight::Weight(const vector<shared_ptr<Statement >> &s, const shared_ptr<Value> w) :
        _elems(s), _weight(w) {
        }

        Weight::~Weight() {

        }
    }
}