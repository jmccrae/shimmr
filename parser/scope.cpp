#include "scope.h"

#include <sstream>

using namespace std;

namespace shimmr {
	Scope::Scope(Scope *p) : parent(p) {
		static int scope_counter = 0;
		if(p) {
			typeSystem = p->typeSystem;
			fSpecifiers.insert(p->fSpecifiers.begin(),p->fSpecifiers.end());
			lSpecifiers.insert(p->lSpecifiers.begin(),p->lSpecifiers.end());
			id = ++scope_counter;
		} else {
			typeSystem = make_shared<shimmr::type::TypeSystem>();
			id = scope_counter = 0;
		}
	}

	std::shared_ptr<Scope> Scope::makeChildScope(Visitable *v) {
		auto scope = new Scope(this);
		shared_ptr<Scope> sp(scope);
		children[v] = sp;
		return sp;
	}

	std::shared_ptr<ScopeElement> Scope::resolve(const std::string& name) {
		Scope *p = this;
		while(p) {
			if(p->scopeElements.find(name) != p->scopeElements.end()) {
				return p->scopeElements[name];
			}
			p = p->parent;
		}
		return std::make_shared<UndefinedScopeElement>(this,name);
	}
	
	string Scope::resolveName(const std::string& name) {
		Scope *p = this;
		while(p) {
			if(p->scopeElements.find(name) != p->scopeElements.end()) {
				stringstream n;
				n << name << "@" << p->id;
				return n.str();
			}
			p = p->parent;
		}
		return "ERR_UNDEF";
	}

	void Scope::assign(std::shared_ptr<ScopeElement> elem, const std::string& name) {
		Scope *p = this;
		while(p) {
			if(p->scopeElements.find(name) != p->scopeElements.end()) {
				scopeElements[name] = std::make_shared<DuplicateDeclaration>(this,p->scopeElements[name],elem);
				return;
			}
			p = p->parent;
		}
		scopeElements[name] = elem;
	}

	std::shared_ptr<Scope> Scope::root() {
		auto scope = new Scope(nullptr);
		shared_ptr<Scope> sp(scope);
		sp->prelude();
		return sp;
	}

	void Scope::prelude() {
		assign(make_shared<ScopeElement>(this,typeSystem->Bool,nullptr,false),"true");
		assign(make_shared<ScopeElement>(this,typeSystem->Bool,nullptr,false),"false");
		assign(make_shared<ScopeElement>(this,typeSystem->Null,nullptr,false),"null");
		assign(make_shared<ScopeElement>(this,typeSystem->Unit,nullptr,false),"noop");
	}

	bool Scope::isActive(const std::string& name) {
		return activeValues.find(name) != activeValues.end();
	}

	void Scope::setActive(const std::string& name) {
		activeValues.insert(name);
	}

	void Scope::setInactive(const std::string& name) {
		activeValues.erase(name);
	}

	bool Scope::isScopeValid() {
		for(auto it = scopeElements.begin(); it != scopeElements.end(); ++it) {
			if(!(*it).second->isScopeValid()) {
				return false;
			}
		}
		for(auto it = children.begin(); it != children.end(); ++it) {
			if(!(*it).second->isScopeValid()) {
				return false;
			}
		}
		return true;
	}

	void Scope::addFunctionArg(const string& name) {
		fSpecifiers.insert(name);
	}

	void Scope::addIteratorArg(const string& name) {
		lSpecifiers.insert(name);
	}

	set<string>& Scope::functionArgs() {
		return fSpecifiers;
	}

	set<string>& ScopeElement::functionArgs() {
		if(isFunctionArg) {
			return scope->parent->functionArgs();
		} else {
			return scope->functionArgs();
		}
	}

	set<string>& Scope::iteratorArgs() {
		return lSpecifiers;
	}

	set<string>& ScopeElement::iteratorArgs() {
		return scope->iteratorArgs();
	}

	ScopeElement::ScopeElement(Scope *s, shared_ptr<shimmr::type::Type> t, Visitable *v, bool fa) : scope(s), _type(t), declarationPoint(v), isFunctionArg(fa) {
	}

	ScopeElement::ScopeElement(Scope *s) : scope(s), _type(nullptr), declarationPoint(nullptr), isFunctionArg(false) {
	}

	shared_ptr<shimmr::type::Type> ScopeElement::type() {
		return _type;
	}

	void ScopeElement::updateType(shared_ptr<shimmr::type::Type> t) {
		_type = t;
	}
	
	bool ScopeElement::isScopeValid() {
		return _type == nullptr || !_type->isError();
	}

	UndefinedScopeElement::UndefinedScopeElement(Scope* scope, const std::string &n) : ScopeElement(scope), _name(n) {
	}

	shared_ptr<shimmr::type::Type> UndefinedScopeElement::type() {
		std::string msg("Undefined reference to id: ");
		msg.append(_name);
		return scope->typeSystem->makeError(-1,msg);
	}


	DuplicateDeclaration::DuplicateDeclaration(Scope *scope, shared_ptr<ScopeElement> f,  shared_ptr<ScopeElement> s) : ScopeElement(scope), first(f), second(s) {
	}

	shared_ptr<shimmr::type::Type> DuplicateDeclaration::type() {
		std::string msg("Multiple declarations as [");
		msg.append(first->type()->symbol() + "," + second->type()->symbol());
		msg.append("]");
		return scope->typeSystem->makeError(-1,msg);
	}

	bool DuplicateDeclaration::isScopeValid() {
		return false;
	}
}