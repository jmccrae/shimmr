#pragma once

#include <string>
#include <set>
#include <memory>
#include <map>
#include <vector>

namespace shimmrType {

	class TypeSystem;

	class Type
	{
	public:
		Type(void);
		~Type(void);
		virtual const std::string& symbol() const = 0;
		virtual const Type* or(const Type *, TypeSystem *) const;
		virtual bool isSuperclassOf(const Type *, const TypeSystem *) const;
		virtual bool isEqual(const Type *, const TypeSystem *) const;
		virtual bool isError() const;
		virtual bool isCollection() const;
		virtual bool isNumeric() const;
		virtual std::shared_ptr<std::set<std::string>> asUnion() const;
	};

	bool operator<(const Type&, const Type&);

	class PrimitiveType : public Type {
	private:
		const std::string name;
	public:
		PrimitiveType(const std::string& n);
		~PrimitiveType();
		const std::string& symbol() const;
		bool isNumeric() const;
	};

	class AnythingType : public Type {
	private:
		AnythingType() { }
		AnythingType(const AnythingType&);
		void operator=(const AnythingType&);
	public:
		static AnythingType& instance();
		const std::string& symbol() const;
		virtual bool isSuperclassOf(const Type *, const TypeSystem *) const;
	};

	class UnionType : public Type {
	private:
		std::vector<const Type *> members;
	public:
		UnionType(const Type*,const Type*,const TypeSystem*);
		~UnionType();
		virtual const std::string& symbol() const;
		virtual std::shared_ptr<std::set<std::string>> asUnion() const;
	};

	class TypeSystem {
	private:
		std::map<const std::string,const Type*> typeTable;
	public:
		TypeSystem();
		~TypeSystem();
		const Type* get(const std::string& name) const;
		const Type* registerType(const Type *t);
		const Type *Int;
		const Type *Float;
		const Type *Bool;
		const Type *Null;
		const Type *String;
		const Type *Unit;
		const Type *Anything;
	};

}


