#include "type.h"

namespace shimmrType {

	Type::Type(void)
	{
	}


	Type::~Type(void)
	{
	}
	
	const Type* Type::or(const Type *t, TypeSystem *s) const {
		return s->registerType(new UnionType(this,t,s));
	}

	bool Type::isSuperclassOf(const Type *t, const TypeSystem *s) const {
		return false;
	}

	bool Type::isEqual(const Type *t, const TypeSystem *s) const {
		return t->symbol().compare(symbol()) == 0;
	}

	bool Type::isError() const {
		return false;
	}

	bool Type::isCollection() const {
		return false;
	}

	bool Type::isNumeric() const {
		return false;
	}
	
	std::shared_ptr<std::set<std::string>> Type::asUnion() const {
		static auto set = std::make_shared<std::set<std::string>>();
		if(set->empty()) {
			set->insert(symbol());
		}
		return set;
	}

	PrimitiveType::PrimitiveType(const std::string& n) : name(n) {
	}

	PrimitiveType::~PrimitiveType() {

	}

	const std::string& PrimitiveType::symbol() const {
		return name;
	}

	bool PrimitiveType::isNumeric() const {
		return name.compare("Float") == 0 || name.compare("Int") == 0;
	}

	AnythingType& AnythingType::instance() {
		static AnythingType instance;
		return instance;
	}

	const std::string& AnythingType::symbol() const {
		static std::string name("Anything");
		return name;
	}

	bool AnythingType::isSuperclassOf(const Type *t, const TypeSystem *s) const {
		return true;
	}

	UnionType::UnionType(const Type *t1, const Type *t2, const TypeSystem* s) : members() {
		auto set1 = t1->asUnion();
		for(auto i = set1->begin(); i != set1->end(); ++i) {
			auto t = s->get(*i);
			if(t) {
				members.push_back(t);
			}
		}
		auto set2 = t2->asUnion();
		for(auto i = set2->begin(); i != set2->end(); ++i) {
			auto t = s->get(*i);
			if(t) {
				members.push_back(t);
			}
		}

		for(auto i1 = members.begin(); i1 != members.end(); ++i1) {
			for(auto i2 = ++i1; i2 != members.end(); ++i2) {
				if((*i2)->isSuperclassOf(*i1,s)) {
					members.erase(i1);
					break;
				}
			}
		}
	}

	UnionType::~UnionType() {
	}

	const std::string& UnionType::symbol() const {
		static std::string symbol;
		if(symbol.length() != 0) {
			return symbol;
		} else {
			auto i1 = members.begin();
			symbol.append((*i1)->symbol());
			++i1;
			for(; i1 != members.end(); ++i1) {
				symbol.append("|");
				symbol.append((*i1)->symbol());
			}
		}
		return symbol;
	}

	std::shared_ptr<std::set<std::string>> UnionType::asUnion() const {
		static auto set = std::make_shared<std::set<std::string>>();
		if(set->empty()) {
			for(auto type = members.begin(); type != members.end(); ++type) {
				set->insert((*type)->symbol());
			}
		}
		return set;
	}
	
	TypeSystem::TypeSystem() : typeTable(),
		Int(new PrimitiveType("Int")),
		Float(new PrimitiveType("Float")),
		Bool(new PrimitiveType("Bool")),
		Null(new PrimitiveType("Null")),
		String(new PrimitiveType("String")),
		Unit(new PrimitiveType("Unit")),
		Anything(&AnythingType::instance())
	{ 
		typeTable["Int"] = Int;
		typeTable["Float"] = Float;
		typeTable["Bool"] = Bool;
		typeTable["Null"] = Null;
		typeTable["String"] = String;
		typeTable["Unit"] = Unit;
		typeTable["Anything"] = Anything;
	}

	TypeSystem::~TypeSystem() {
		for(auto i = typeTable.begin(); i != typeTable.end(); ++i) {
			delete (*i).second;
		}
	}

	const Type* TypeSystem::get(const std::string& name) const {
		auto t = typeTable.find(name);
		if(t != typeTable.end()) {
			return t->second;
		} else {
			return nullptr;
		}
	}

	const Type* TypeSystem::registerType(const Type *t) {
		auto t2 = get(t->symbol());
		if(t2) {
			typeTable.insert(std::pair<const std::string,const Type*>(t->symbol(),t));
			return t;
		} else {
			delete t;
			return t2;
		}
	}
}