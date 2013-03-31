#include "type.h"

#include <algorithm>

using namespace std;

namespace shimmrType {

	Type::Type(TypeSystem *s) : sys(s)
	{
	}


	Type::~Type(void)
	{
	}
	
	const shared_ptr<Type> Type::or(const shared_ptr<Type> t) const {
		if(t->isError()) {
			return t;
		} else {
			return sys->makeUnion(asUnion(),t->asUnion());
		}
	}

	bool Type::isSuperclassOf(const shared_ptr<Type> t) const {
		return false;
	}

	bool Type::isEqual(const shared_ptr<Type> t) const {
		return t->symbol().compare(symbol()) == 0;
	}

	bool Type::isError() const {
		return false;
	}

	bool Type::isCollection() const {
		return false;
	}

	bool Type::isSet() const {
		return false;
	}

	bool Type::isRange() const {
		return false;
	}

	bool Type::isFunction() const {
		return false;
	}
	
	bool Type::canMerge(const shared_ptr<Type> t) const {
		return isSuperclassOf(t) || t->isSuperclassOf(sys->get(symbol()));
	}

	shared_ptr<Type> Type::merge(const std::shared_ptr<Type> t) const {
		auto this_ptr = sys->get(symbol());
		if(isSuperclassOf(t)) {
			return this_ptr;
		} else if(t->isSuperclassOf(this_ptr)) {
			return t;
		} else {
			return nullptr;
		}
	}
	
	shared_ptr<set<string>> Type::asUnion() const {
		auto s = make_shared<set<string>>();
		s->insert(symbol());
		return s;
	}
		
	shared_ptr<Type> Type::contentType() const {
		return nullptr;
	}

	shared_ptr<Type> Type::indexType() const {
		return nullptr;
	}

	PrimitiveType::PrimitiveType(TypeSystem *s,const string& n) : Type(s), name(n) {
	}

	PrimitiveType::~PrimitiveType() {

	}

	const string& PrimitiveType::symbol() const {
		return name;
	}
	
	const string& AnythingType::symbol() const {
		static string name("Anything");
		return name;
	}

	bool AnythingType::isSuperclassOf(const shared_ptr<Type> t) const {
		return t->symbol().compare("Anything") != 0;
	}

	NumericType::NumericType(TypeSystem* s) : PrimitiveType(s,"Numeric") {
	}

	bool NumericType::isSuperclassOf(const shared_ptr<Type> t) const {
		if(t->symbol().compare("Int") == 0 || t->symbol().compare("Float") == 0 || t->isRange()) {
			return true;
		} else if(t->isSet()) {
			return sys->Int->isSuperclassOf(t) || sys->Float->isSuperclassOf(t);
		} else {
			return false;
		}
	}

	IntType::IntType(TypeSystem *s) : PrimitiveType(s,"Int") {
	}

	bool IntType::isSuperclassOf(const shared_ptr<Type> t) const {
		if(t->isRange()) {
			return true;
		} else if(t->isSet()) {
			auto t2 = (SetType*)t.get();
			for(auto it = t2->values.begin(); it != t2->values.end(); ++it) {
				if((*it)->type() != tvtInt) {
					return false;
				}
			}
			return true;
		} else {
			return false;
		}
	}

	FloatType::FloatType(TypeSystem* s) : PrimitiveType(s,"Float") {
	}

	bool FloatType::isSuperclassOf(const shared_ptr<Type> t) const {
		if(t->isSet()) {
			auto t2 = (SetType*)t.get();
			for(auto it = t2->values.begin(); it != t2->values.end(); ++it) {
				if((*it)->type() != tvtFloat) {
					return false;
				}
			}
			return true;
		} else {
			return false;
		}
	}

	StringType::StringType(TypeSystem* s) : PrimitiveType(s,"String") {
	}

	bool StringType::isSuperclassOf(const shared_ptr<Type> t) const {
		if(t->isSet()) {
			auto t2 = (SetType*)t.get();
			for(auto it = t2->values.begin(); it != t2->values.end(); ++it) {
				if((*it)->type() != tvtString) {
					return false;
				}
			}
			return true;
		} else {
			return false;
		}
	}

	UnionType::UnionType(TypeSystem *s,const shared_ptr<set<string>> set1, const shared_ptr<set<string>> set2) : Type(s), members() {
		auto typeNames = make_shared<set<string>>();
		typeNames->insert(set1->begin(),set1->end());
		typeNames->insert(set2->begin(),set2->end());
		auto types = make_shared<vector<shared_ptr<Type>>>();
		for(auto i = typeNames->begin(); i != typeNames->end(); ++i) {
			types->push_back(s->get(*i));
		}

		for(auto i1 = types->begin(); i1 != types->end(); ++i1) {
			bool isMerged = false;
			for(auto i2 = members.begin(); i2 != members.end(); ++i2) {
				if((*i2)->canMerge(*i1)) {
					isMerged = true;
					*i2 = (*i2)->merge(*i1);
					break;
				}
			}
			if(!isMerged) {
				members.push_back(*i1);
			}
		}
		if(members.empty()) {
			_symbol.append("$EMPTY$");
		} else {
			auto i1 = members.begin();
			_symbol.append((*i1)->symbol());
			++i1;
			for(; i1 != members.end(); ++i1) {
				_symbol.append("|");
				_symbol.append((*i1)->symbol());
			}
		}
	}

	UnionType::~UnionType() {
	}

	const string& UnionType::symbol() const {
		return _symbol;
	}

	shared_ptr<set<string>> UnionType::asUnion() const {
		auto s = make_shared<set<string>>();
		for(auto type = members.begin(); type != members.end(); ++type) {
			s->insert((*type)->symbol());
		}
		return s;
	}

	
	VectorType::VectorType(TypeSystem* s,const shared_ptr<Type> c, const shared_ptr<Type> i) : Type(s), content(c), index(i) {
		_symbol.append(c->symbol());
		_symbol.append("[");
		_symbol.append(i->symbol());
		_symbol.append("]");
	}

	VectorType::~VectorType() {
	}

	const std::string& VectorType::symbol() const {
		return _symbol;
	}

	bool VectorType::isCollection() const {
		return true;
	}

	shared_ptr<Type> VectorType::contentType() const {
		return content;
	}

	shared_ptr<Type> VectorType::indexType() const {
		return index;
	}

	ErrorType::ErrorType(TypeSystem*s,const string& msg) : Type(s) {
		messages.push_back(msg);
	}

	
	ErrorType::~ErrorType() {
	}

	const string ErrorType::ERR("Error");

	const string& ErrorType::symbol() const {
		return ERR;
	}

	shared_ptr<set<string>> ErrorType::asUnion() const {
		auto s = make_shared<set<string>>();
		return s;
	}
	
	ErrorType::ErrorType(TypeSystem*s,const vector<const string>& s1,const vector<const string>& s2) : Type(s) {
		for(auto i = s1.begin(); i != s1.end(); ++i) {
			messages.push_back(*i);
		}
		for(auto i = s2.begin(); i != s2.end(); ++i) {
			messages.push_back(*i);
		}
	}

	ErrorType::ErrorType(TypeSystem*s,const vector<const string>& s1) : Type(s) {
		for(auto i = s1.begin(); i != s1.end(); ++i) {
			messages.push_back(*i);
		}
	}

	const shared_ptr<Type> ErrorType::or(const shared_ptr<Type> t) const {
		if(t->isError()) {
			auto et = (ErrorType*)t.get();
			auto net = new ErrorType(sys,messages,et->messages);
			shared_ptr<ErrorType> sp(net);
			return sp;
		} else {
			auto net = new ErrorType(sys,messages);
			shared_ptr<ErrorType> sp(net);
			return sp;
		}
	}

	bool ErrorType::isSuperclassOf(const shared_ptr<Type>) const {
		return false;
	}

	bool ErrorType::isEqual(const shared_ptr<Type>) const {
		return false;
	}

	bool ErrorType::isError() const {
		return true;
	}

	shared_ptr<Type> ErrorType::contentType() const {
		return sys->get(symbol());
	}

	shared_ptr<Type> ErrorType::indexType() const {
		return sys->get(symbol());
	}
	
	bool compareTypeValue(const std::shared_ptr<TypeValue> &s, const std::shared_ptr<TypeValue>&t) {
		return s->symbol().compare(t->symbol()) < 0;
	}
	
	SetType::SetType(TypeSystem*s,const set<const shared_ptr<TypeValue>, decltype(compareTypeValue)*>& vs) : Type(s), values(vs) {
		if(!vs.empty()) {
			auto iterator = vs.begin();
			_symbol.append("{");
			_symbol.append((*iterator)->symbol());
			for(++iterator; iterator != vs.end(); ++iterator) {
				_symbol.append(",");
				_symbol.append((*iterator)->symbol());
			}
			_symbol.append("}");
		}
	}

	SetType::~SetType() { }

	const string& SetType::symbol() const {
		return _symbol;
	}

	bool SetType::canMerge(const shared_ptr<Type> t) const {
		if(t->isSet()) {
			return true;
		} else if(t->isRange()) {
			return true;
		} else if(t->symbol().compare("Int")) {
			for(auto it = values.begin(); it != values.end(); ++it) {
				if((*it)->type() != tvtInt) {
					return false;
				}
			}
			return true;
		} else if(t->symbol().compare("Float")) {
			for(auto it = values.begin(); it != values.end(); ++it) {
				if((*it)->type() != tvtFloat) {
					return false;
				}
			}
			return true;
		} else if(t->symbol().compare("String")) {
			for(auto it = values.begin(); it != values.end(); ++it) {
				if((*it)->type() != tvtString) {
					return false;
				}
			}
			return true;
		} else {
			return false;
		}
	}

	shared_ptr<Type> SetType::merge(const shared_ptr<Type> t) const {
		if(t->isSet()) {
			set<const shared_ptr<TypeValue>, decltype(compareTypeValue)*> unionValues(compareTypeValue);
			auto t2 = (SetType*)t.get();
			for(auto it = values.begin(); it != values.end(); ++it) {
				unionValues.insert(*it);
			}
			for(auto it = t2->values.begin(); it != t2->values.end(); ++it) {
				unionValues.insert(*it);
			}
			return sys->makeSet(unionValues);
		} else if(t->isRange()) {
			if(t->isSuperclassOf(sys->get(symbol()))) {
				return t;
			}
			auto t2 = (RangeType*)t.get();
			set<const shared_ptr<TypeValue>, decltype(compareTypeValue)*> unionValues(compareTypeValue);
			for(auto it = values.begin(); it != values.end(); ++it) {
				unionValues.insert(*it);
			}
			for(int i = t2->lb; i <= t2->ub; i++) {
				unionValues.insert(make_shared<IntTypeValue>(i));
			}
			return sys->makeSet(unionValues);
		} else if(t->symbol().compare("String") == 0) {
			// Assume validity has already been checked by canMerge
			return t;
		} else if(t->symbol().compare("Int") == 0) {
			// Assume validity has already been checked by canMerge
			return t;
		} else if(t->symbol().compare("Float") == 0) {
			// Assume validity has already been checked by canMerge
			return t;
		} else {
			return nullptr;
		}
	}

	bool SetType::isSuperclassOf(const shared_ptr<Type> t) const {
		if(t->isSet()) {
			auto t2 = (SetType*)t.get();
			if(values.size() <= t2->values.size()) {
				return false;
			}
			set<string> valueSymbols;
			for(auto it = values.begin(); it != values.end(); ++it) {
				valueSymbols.insert((*it)->symbol());
			}
			for(auto it = t2->values.begin(); it != t2->values.end(); ++it) {
				if(valueSymbols.find((*it)->symbol()) == valueSymbols.end()) {
					return false;
				}
			}
			return true;
		} else if(t->isRange()) {
			auto t2 = (RangeType*)t.get();
			if(values.size() < t2->ub - t2->lb + 1) {
				return false;
			}
			int found = 0;
			for(auto it = values.begin(); it != values.end(); ++it) {
				if((*it)->type() == tvtInt &&
					(*it)->intValue() >= t2->lb &&
					(*it)->intValue() <= t2->ub) {
						found++;
				}
			}
			return found == t2->ub - t2->lb + 1;
		}  else {
			return false;
		}
	}

	bool SetType::isEqual(const shared_ptr<Type> t) const {
		if(t->isSet()) {
			auto t2 = (SetType*)t.get();
			if(values.size() != t2->values.size()) {
				return false;
			}
			set<string> valueSymbols;
			for(auto it = values.begin(); it != values.end(); ++it) {
				valueSymbols.insert((*it)->symbol());
			}
			for(auto it = t2->values.begin(); it != t2->values.end(); ++it) {
				if(valueSymbols.find((*it)->symbol()) == valueSymbols.end()) {
					return false;
				}
			}
			return true;
		} else if(t->isRange()) {
			return false;
		} else {
			return false;
		}
	}
	
	bool SetType::isSet() const {
		return true;
	}
	
	bool SetType::isCollection() const {
		return true;
	}

	shared_ptr<Type> SetType::contentType() const {
		return sys->get(_symbol);
	}

	shared_ptr<Type> SetType::indexType() const {
		return sys->get(_symbol);
	}

	
	RangeType::RangeType(TypeSystem*s,const int lowerBound, const int upperBound) : Type(s), lb(lowerBound), ub(upperBound) {
		_symbol.append(to_string(lowerBound));
		_symbol.append(":");
		_symbol.append(to_string(upperBound));
	}

	RangeType::~RangeType() {
	}

	const string& RangeType::symbol() const {
		return _symbol;
	}

	bool RangeType::canMerge(const shared_ptr<Type> t) const {
		if(t->isSet()) {
			return true;
		} else if(t->isRange()) {
			auto t2 = (RangeType*)t.get();
			return t2->lb <= ub + 1 && t2->ub >= lb - 1;
		} else if(t->symbol().compare("Int") == 0) {
			return true;
		} else {
			return false;
		}
	}

	shared_ptr<Type> RangeType::merge(const shared_ptr<Type> t) const {
		if(t->isSet()) {
			return t->merge(sys->get(_symbol));
		} else if(t->isRange()) {
			auto t2 = (RangeType*)t.get();
			return sys->makeRange(min(lb,t2->lb),max(ub,t2->ub));
		} else if(t->symbol().compare("Int") == 0) {
			return t;
		} else {
			return nullptr;
		}
	};
		
	bool RangeType::isSuperclassOf(const std::shared_ptr<Type> t) const {
		if(t->isRange()) {
			auto t2 = (RangeType*)t.get();
			return t2->lb >= lb && t2->ub <= ub && !(t2->lb == lb && t2->ub == ub);
		} else if(t->isSet()) {
			auto t2 = (SetType*)t.get();
			for(auto it = t2->values.begin(); it != t2->values.end(); ++it) {
				if((*it)->type() != tvtInt ||
					(*it)->intValue() < lb ||
					(*it)->intValue() > ub) {
						return false;
				}
			}
			return true;
		} else {
			return false;
		}
	}
		
	bool RangeType::isEqual(const shared_ptr<Type> t) const {
		if(t->isRange()) {
			auto t2 = (RangeType*)t.get();
			return t2->lb == lb && t2->ub == ub;
		} else {
			return false;
		}
	}

	bool RangeType::isRange() const {
		return true;
	}

	bool RangeType::isCollection() const {
		return true;
	}

	shared_ptr<Type> RangeType::contentType() const {
		return sys->get(_symbol);
	}

	shared_ptr<Type> RangeType::indexType() const {
		return sys->get(_symbol);
	}

	const string& TypeValue::stringValue() const {
		static string s("");
		return s;
	}

	const int TypeValue::intValue() const {
		return 0;
	}

	const double TypeValue::floatValue() const {
		return 0.0;
	}

	StringTypeValue::StringTypeValue(const std::string& s) : val(s), sym("\""+s+"\"") {
	}

	StringTypeValue::~StringTypeValue() {
	}

	const std::string& StringTypeValue::symbol() const {
		return sym;
	}

	const TypeValueType StringTypeValue::type() const {
		return tvtString;
	}

	const std::string& StringTypeValue::stringValue() const {
		return val;
	}

	IntTypeValue::IntTypeValue(const int i) : val(i), sym(to_string(i)) {
	}

	IntTypeValue::~IntTypeValue() {
	}

	const std::string& IntTypeValue::symbol() const {
		return sym;
	}

	const TypeValueType IntTypeValue::type() const {
		return tvtInt;
	}

	const int IntTypeValue::intValue() const {
		return val;
	}

	FloatTypeValue::FloatTypeValue(const double i) : val(i), sym(to_string(i)) {
	}

	FloatTypeValue::~FloatTypeValue() {
	}

	const std::string& FloatTypeValue::symbol() const {
		return sym;
	}

	const TypeValueType FloatTypeValue::type() const {
		return tvtFloat;
	}

	const double FloatTypeValue::floatValue() const {
		return val;
	}

	FunctionType::FunctionType(TypeSystem* s,const std::shared_ptr<Type> r,const std::vector<std::shared_ptr<Type>>& a) :
		Type(s), _returnType(r), _argTypes(a) {
		_symbol.append("(");
		if(!a.empty()) {
			auto it = a.begin();
			_symbol.append((*it)->symbol());
			for(++it; it != a.end(); ++it) {
				_symbol.append(",");
				_symbol.append((*it)->symbol());
			}
		}
		_symbol.append(")=>");
		_symbol.append(r->symbol());
	}
		
	const std::string& FunctionType::symbol() const {
		return _symbol;
	}

	bool FunctionType::isFunction() const {
		return true;
	}

	const shared_ptr<Type> FunctionType::returnType() const {
		return _returnType;
	}

	const vector<shared_ptr<Type>>& FunctionType::argTypes() const {
		return _argTypes;
	}

	TypeSystem::TypeSystem() : typeTable(),
		Int(new IntType(this)),
		Float(new FloatType(this)),
		Numeric(new NumericType(this)),
		Bool(new PrimitiveType(this,"Bool")),
		Null(new PrimitiveType(this,"Null")),
		String(new PrimitiveType(this,"String")),
		Unit(new PrimitiveType(this,"Unit")),
		Anything(new AnythingType(this))
	{ 
		typeTable.insert(pair<const string,const shared_ptr<Type>>("Int",Int));
		typeTable.insert(pair<const string,const shared_ptr<Type>>("Float",Float));
		typeTable.insert(pair<const string,const shared_ptr<Type>>("Bool",Bool));
		typeTable.insert(pair<const string,const shared_ptr<Type>>("Null",Null));
		typeTable.insert(pair<const string,const shared_ptr<Type>>("String",String));
		typeTable.insert(pair<const string,const shared_ptr<Type>>("Unit",Unit));
		typeTable.insert(pair<const string,const shared_ptr<Type>>("Numeric",Numeric));
		typeTable.insert(pair<const string,const shared_ptr<Type>>("Anything",Anything));
	}

	TypeSystem::~TypeSystem() {

	}

	const shared_ptr<Type> TypeSystem::get(const string& name) const {
		auto t = typeTable.find(name);
		if(t != typeTable.end()) {
			return t->second;
		} else {
			return nullptr;
		}
	}

	const shared_ptr<Type> TypeSystem::registerType(const shared_ptr<Type>t) {
		auto s = t->symbol();
		auto t2 = get(t->symbol());
		if(!t2) {
			typeTable.insert(pair<const string,const shared_ptr<Type>>(t->symbol(),t));
			return t;
		} else {
			return t2;
		}
	}
		
	const shared_ptr<Type> TypeSystem::makeUnion(const shared_ptr<set<string>> s, const shared_ptr<set<string>> t) {
		auto ut = new UnionType(this,s,t);
		const shared_ptr<Type> sp(ut);
		return registerType(sp);
	}

	const shared_ptr<Type> TypeSystem::makeError(const int linenumber, const string& msg) {
		auto et = new ErrorType(this,"Line " + to_string(linenumber) + ": " + msg);
		const shared_ptr<Type> sp(et);
		return sp;
	}

	const shared_ptr<Type> TypeSystem::makeSet(const set<const shared_ptr<TypeValue>, decltype(compareTypeValue)*>& s) {
		auto st = new SetType(this,s);
		const shared_ptr<Type> sp(st);
		return registerType(sp);
	}

	const shared_ptr<Type> TypeSystem::makeRange(const int lowerBound, const  int upperBound) {
		auto rt = new RangeType(this,lowerBound,upperBound);
		const shared_ptr<Type> sp(rt);
		return registerType(sp);
	}

	const shared_ptr<Type> TypeSystem::makeVector(const shared_ptr<Type> content, const shared_ptr<Type> index) {
		if(content->isError() && index->isError()) {
			return content->or(index);
		} else if(content->isError()) {
			return content;
		} else if(index->isError()) {
			return index;
		} else {
			auto ut = new VectorType(this,content,index);
			const shared_ptr<Type> sp(ut);
			return registerType(sp);
		}
	}

	const shared_ptr<Type> TypeSystem::makeFunction(const shared_ptr<Type> returnType, const vector<shared_ptr<Type>>& args) {
		shared_ptr<Type> err = Unit;
		for(auto t : args) {
			if(t->isError()) {
				err = err->or(t);
			}
		}
		if(returnType->isError() && err->isError()) {
			return returnType->or(err);
		} else if(returnType->isError()) {
			return returnType;
		} else if(err->isError()) {
			return err;
		} else {
			auto ft = new FunctionType(this,returnType,args);
			const shared_ptr<Type> sp(ft);
			return registerType(sp);
		}
	}
}