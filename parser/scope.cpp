#include "scope.h"

using namespace std;

namespace shimmr {
	Scope::Scope(Scope *p) : parent(p) {
		if(p) {
			typeSystem = p->typeSystem;
		} else {
			typeSystem = make_shared<shimmrType::TypeSystem>();
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
		return sp;
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

	ScopeElement::ScopeElement(Scope *s, shared_ptr<shimmrType::Type> t, Visitable *v) : scope(s), _type(t), declarationPoint(v) {
	}

	ScopeElement::ScopeElement(Scope *s) : scope(s), _type(nullptr), declarationPoint(nullptr) {
	}

	shared_ptr<shimmrType::Type> ScopeElement::type() {
		return _type;
	}

	void ScopeElement::updateType(shared_ptr<shimmrType::Type> t) {
		_type = t;
	}
	
	bool ScopeElement::isScopeValid() {
		return _type == nullptr || !_type->isError();
	}

	UndefinedScopeElement::UndefinedScopeElement(Scope* scope, const std::string &n) : ScopeElement(scope), _name(n) {
	}

	shared_ptr<shimmrType::Type> UndefinedScopeElement::type() {
		std::string msg("Undefined reference to id: ");
		msg.append(_name);
		return scope->typeSystem->makeError(-1,msg);
	}


	DuplicateDeclaration::DuplicateDeclaration(Scope *scope, shared_ptr<ScopeElement> f,  shared_ptr<ScopeElement> s) : ScopeElement(scope), first(f), second(s) {
	}

	shared_ptr<shimmrType::Type> DuplicateDeclaration::type() {
		std::string msg("Multiple declarations as [");
		msg.append(first->type()->symbol() + "," + second->type()->symbol());
		msg.append("]");
		return scope->typeSystem->makeError(-1,msg);
	}

	bool DuplicateDeclaration::isScopeValid() {
		return false;
	}
}