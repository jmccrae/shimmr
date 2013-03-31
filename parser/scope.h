#pragma once

#include <map>
#include <string>
#include <memory>
#include <vector>
#include <set>
#include <functional>
#include "type.h"
#include "Absyn.H"

namespace shimmr {
	class Scope;

	class ScopeElement {
	private:
		std::shared_ptr<shimmrType::Type> _type;
	protected:
		Scope *scope;
		ScopeElement(Scope *);
	public:
		Visitable *const declarationPoint;
		ScopeElement(Scope *, std::shared_ptr<shimmrType::Type>, Visitable *);
		virtual std::shared_ptr<shimmrType::Type> type();
		virtual void updateType(std::shared_ptr<shimmrType::Type>);
		virtual bool isScopeValid();
		virtual bool isDefined() { return true; }
	};
	
	class UndefinedScopeElement : public ScopeElement {
	public:
		const std::string _name;
		UndefinedScopeElement(Scope*, const std::string &n);
		std::shared_ptr<shimmrType::Type> type();
		virtual bool isDefined() { return false; }
	};

	class DuplicateDeclaration : public ScopeElement {
	public:
		std::shared_ptr<ScopeElement> first;
		std::shared_ptr<ScopeElement> second;
		DuplicateDeclaration(Scope*, std::shared_ptr<ScopeElement> f,  std::shared_ptr<ScopeElement> s);
		std::shared_ptr<shimmrType::Type> type();
		virtual bool isScopeValid();
		virtual bool isDefined() { return false; }
	};
	
	class Scope 
	{
	private:
		std::set<std::string> activeValues;
		Scope(Scope *p);
	public:
		std::shared_ptr<shimmrType::TypeSystem> typeSystem;
		Scope *parent;
		std::map<std::string,std::shared_ptr<ScopeElement>> scopeElements;
		std::map<Visitable*,std::shared_ptr<Scope>> children;
		std::shared_ptr<Scope> makeChildScope(Visitable*);
		std::shared_ptr<ScopeElement> resolve(const std::string& name);
		void assign(std::shared_ptr<ScopeElement> elem, const std::string& name);
		static std::shared_ptr<Scope> root();
		virtual bool isScopeValid();
		// Active variables are used to avoid recursive definitions
		bool isActive(const std::string& name);
		void setActive(const std::string& name);
		void setInactive(const std::string& name);
	private:
		void prelude();
		void operator=(Scope const&) { }
	};


}

