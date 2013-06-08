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

		const string LiteralValue::toString() const {
			return _value->symbol();
		}

		VariableValue::VariableValue(shared_ptr<shimmr::type::TypeSystem> s, shared_ptr<shimmr::type::Type> t, const string& id) :
			Value(s), _type(t), _id(id) {

			}

		VariableValue::VariableValue(shared_ptr<shimmr::type::TypeSystem> s, shared_ptr<shimmr::type::Type> t, const string& id, const set<string>& sp) :
			Value(s), _type(t), _id(id), _specifiers(sp) {

			}

		const string VariableValue::toString() const {
			stringstream ss;
			ss << _id;
			if(!_specifiers.empty()) {
				ss << "[";
				int i = 1;
				for(auto it : _specifiers) {
					ss << it;
					if(i != _specifiers.size()) {
						ss << ",";
					}
					i++;
				}
				ss << "]";
			}
			return ss.str();
		}

		shared_ptr<shimmr::type::Type> VariableValue::type() const {
			return _type;
		}

		CNF::CNF() {

		}

		shared_ptr<Predicate> CNF::makeWtAnon(shared_ptr<Value> v) {
			stringstream ss;
			ss << "@wt" << (counter++);
			return make_shared<Predicate>(ss.str());
		}

		DisjunctionListPtr CNF::visit(StatementPtr statement) {
			if(statement->isOneOf()) {
				auto os = statement->cnf(this);
				auto dl = make_shared<DisjunctionList>();
				for(auto o : *os) {				
					stringstream ss;
					ss << "@oneof" << (counter++);
					auto p = make_shared<Predicate>(ss.str());
					o->add(p->negate());
					
					disjunctions->push_back(o);
					auto d = make_shared<Disjunction>();
					d->add(p);
					dl->push_back(d);
				}
				return dl;
			} else {
				return statement->cnf(this);
			}
		}

		Predicate::Predicate(const string& s, const vector<shared_ptr<Value >> &v) : _id(s), _values(v), _negative(false) {
		}

		const string Predicate::toString() const {
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
			return ss.str();
		}

		Predicate::Predicate(const string& s) : _id(s), _negative(false) {
		}

		Predicate::Predicate(const string& s, ValuePtr p) : _id(s), _negative(false) {
			_values.push_back(p);
		}

		Predicate::Predicate(const string& s, ValuePtr p1, ValuePtr p2) : _id(s), _negative(false) {
			_values.push_back(p1);
			_values.push_back(p2);
		}

		Predicate::Predicate(const string& s, ValuePtr p1, ValuePtr p2, ValuePtr p3) : _id(s), _negative(false) {
			_values.push_back(p1);
			_values.push_back(p2);
			_values.push_back(p3);
		}

		Predicate::Predicate(const bool n, const string& s, const ValueList& vl) : _negative(n),_id(s),_values(vl) {
		}

		Predicate::~Predicate() {

		}

		DisjunctionListPtr Predicate::cnf(CNFPtr p) {
			auto stats = make_shared<DisjunctionList>();
			auto disj = make_shared<Disjunction>();
			disj->add(make_shared<Predicate>(_negative,_id,_values));
			stats->push_back(disj);
			return stats;
		}

		shared_ptr<Predicate> Predicate::negate() {
			return make_shared<Predicate>(!_negative,_id,_values);
		}

		Implication::Implication(const vector<shared_ptr<Statement >> &p, const vector<shared_ptr<Statement >> &c) :
			_premises(p), _consequences(c) {
			}

		const string Implication::toString() const {
			stringstream ss;
			int i = 1;
			ss << "(";
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
			ss << ")";
			return ss.str();
		}

		Implication::~Implication() {

		}

		vector<shared_ptr<Statement >> &Implication::premises() {
			return _premises;
		}

		vector<shared_ptr<Statement >> &Implication::consequences() {
			return _consequences;
		}

		DisjunctionListPtr Implication::cnf(CNFPtr cnf) {
			auto stats = make_shared<DisjunctionList>();
			for(auto p : _premises) {
				auto pns = p->cnf(cnf);
				for(auto pn : *pns) {
					auto np = pn->negate();
					stats->insert(stats->end(),np->begin(),np->end());
				}
			}
			for(auto c : _consequences) {
				auto cd = c->cnf(cnf);
				stats->insert(stats->end(),cd->begin(),cd->end());
			}
			return stats;
		}

		Alternative::Alternative(const StatementList& s1, const StatementList& s2) :
			_s1(s1),_s2(s2) {
			}

		const string Alternative::toString() const {
			stringstream ss;
			ss << "(";
			int i = 1;
			for(auto s1i : _s1) {
				ss << s1i->toString();
				if(i != _s1.size()) {
					ss << " ^ ";
				}
				i++;
			}
			ss << ") v (";
			i = 1;
			for(auto s1i : _s2) {
				ss << s1i->toString();
				if(i != _s2.size()) {
					ss << " ^ ";
				}
				i++;
			}
			ss << ")";
			return ss.str();
		}

		Alternative::~Alternative() {
		}

		DisjunctionListPtr Alternative::cnf(CNFPtr p) {
			auto dlp = make_shared<DisjunctionList>();
			for(auto s1 : _s1) {
				auto dlp1 = s1->cnf(p);
				for(auto d1 : *dlp1) {
					for(auto s2 : _s2) {
						auto dlp2 = s2->cnf(p);
						for(auto d2 : *dlp2) {
							auto d = make_shared<Disjunction>();
							for(auto e1 : d1->predicates()) {
								d->add(e1);
							}
							for(auto e2 : d2->predicates()) {
								d->add(e2);
							}
							dlp->push_back(d);
						}
					}
				}
			}
			return dlp;
		}
		
		DisjunctionListPtr makeNegativeCNF(DisjunctionList& dls, DisjunctionList::iterator it) {
			if(it == dls.end()) {
				return make_shared<DisjunctionList>();
			} else {
				auto negative = (*it)->negate();
				DisjunctionListPtr dp = makeNegativeCNF(dls,++it);
			        auto dl = make_shared<DisjunctionList>();	
				for(auto disj2 : *negative) {
					for(auto disj1 : *dp) {
						dl->push_back(make_shared<Disjunction>(*disj1,*disj2));
					}
				}
			}
		}
	

		OneOf::OneOf(const vector<shared_ptr<Statement >> &s, const vector<shared_ptr<Statement>>& a, const shared_ptr<VariableValue> v) :
			_elems(s), _alt(a), _quant(v) {
			}

		const string OneOf::toString() const {
			stringstream ss;
			ss << "O[" << _quant->toString() << "](";
			int i = 1;
			for(auto si : _elems) {
				ss << si->toString();
				if(i != _elems.size()) {
					ss << " ^ ";
				}
				i++;
			}
			ss << ") o (";
			i = 1;
			for(auto ai : _alt) {
				ss << ai->toString();
				if(i != _alt.size()) {
					ss << " ^ ";
				}
				i++;
			}
			ss << ")";
			return ss.str();

		}

		OneOf::~OneOf() {
		}


		DisjunctionListPtr OneOf::cnf(CNFPtr p) {
			DisjunctionList dls;
			for(auto elem : _elems) {
				auto c = elem->cnf(cnf);
				dls.insert(dls.begin(),c->begin(),c->end());
			}
			auto dis = makeNegativeCNF(dls,dls.begin());
			auto d = make_shared<Disjunction>();
			d->add(cnf->makeWtAnon(_weight));
			dis->push_back(d);
			return dis;
		}

		Weight::Weight(const vector<shared_ptr<Statement >> &s, const shared_ptr<Value> w) :
			_elems(s), _weight(w) {
			}

		const string Weight::toString() const {
			stringstream ss;
			ss << "(";
			int i = 1;
			for(auto si : _elems) {
				ss << si->toString();
				if(i != _elems.size()) {
					ss << " ^ ";
				}
				i++;
			}
			ss << ") with " << _weight->toString();
			return ss.str();
		}

		Weight::~Weight() {

		}

		DisjunctionListPtr Weight::cnf(CNFPtr cnf) {
			DisjunctionList dls;
			for(auto elem : _elems) {
				auto c = elem->cnf(cnf);
				dls.insert(dls.begin(),c->begin(),c->end());
			}
			auto dis = makeNegativeCNF(dls,dls.begin());
			auto d = make_shared<Disjunction>();
			d->add(cnf->makeWtAnon(_weight));
			dis->push_back(d);
			return dis;
		}
		
		Disjunction::Disjunction() {
		}

		Disjunction::Disjunction(shared_ptr<Predicate> p) {
			_predicate.push_back(p);
		}

		Disjunction::Disjunction(const Disjunction& d) :
			_predicate(d._predicate) {

		}

		Disjunction::Disjunction(const Disjunction&d1, const Disjunction& d2) : _predicate(d1._predicate) {
			_predicate.insert(_predicate.end(),d2._predicate.begin(),d2._predicate.end());
		}


		void Disjunction::add(shared_ptr<Predicate> p) {
			_predicate.push_back(p);
		}

		const vector<shared_ptr<Predicate>>& Disjunction::predicates() {
			return _predicate;
		}

		DisjunctionListPtr Disjunction::negate() {
			auto neg = make_shared<DisjunctionList>();
			for(auto it : _predicate) {
				neg->push_back(make_shared<Disjunction>(it));
			}
			return neg;
		}
	}
}
