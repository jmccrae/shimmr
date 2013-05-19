#pragma once

#include <string>
#include <set>
#include <memory>
#include <map>
#include <vector>

namespace shimmr {
	namespace type {

	class TypeSystem;
	class TypeValue;

	class Type
	{
	protected:
		TypeSystem* sys;
		Type(TypeSystem*);
	public:
		~Type(void);
		virtual const std::string& symbol() const = 0;
		virtual const std::shared_ptr<Type> unify(const std::shared_ptr<Type>) const;
		virtual bool isSuperclassOf(const std::shared_ptr<Type>) const;
		inline bool isSuperclassOrEqual(const std::shared_ptr<Type> t) const { return isEqual(t) || isSuperclassOf(t); }
		virtual bool isEqual(const std::shared_ptr<Type>) const;
		virtual bool isError() const;
		virtual bool isCollection() const;
		virtual bool isSet() const;
		virtual bool isRange() const;
		virtual bool isFunction() const;
		virtual std::shared_ptr<std::set<std::string>> asUnion() const;
		virtual bool canMerge(const std::shared_ptr<Type>) const;
		virtual std::shared_ptr<Type> merge(const std::shared_ptr<Type>) const;
		virtual std::shared_ptr<Type> contentType() const;
		virtual std::shared_ptr<Type> indexType() const;
	};

	bool operator<(const Type&, const Type&);

	class PrimitiveType : public Type {
		friend TypeSystem;
	private:
		const std::string name;
	protected:
		PrimitiveType(TypeSystem*,const std::string& n);
	public:
		~PrimitiveType();
		const std::string& symbol() const;
	};

	class AnythingType : public Type {
		friend TypeSystem;
	private:
		AnythingType(TypeSystem*s) : Type(s) { }
	public:
		const std::string& symbol() const;
		virtual bool isSuperclassOf(const std::shared_ptr<Type>) const;
	};

	class NumericType : public PrimitiveType {
		friend TypeSystem;
	private:
		NumericType(TypeSystem*);
	public:
		virtual bool isSuperclassOf(const std::shared_ptr<Type>) const;
	};

	class IntType : public PrimitiveType {
		friend TypeSystem;
	private:
		IntType(TypeSystem*);
	public:
		virtual bool isSuperclassOf(const std::shared_ptr<Type>) const;
	};

	class FloatType : public PrimitiveType {
		friend TypeSystem;
	public:
		FloatType(TypeSystem*);
		virtual bool isSuperclassOf(const std::shared_ptr<Type>) const;
	};

	class StringType : public PrimitiveType {
		friend TypeSystem;
	public:
		StringType(TypeSystem*);
		virtual bool isSuperclassOf(const std::shared_ptr<Type>) const;
	};


	class UnionType : public Type {
		friend TypeSystem;
	private:
		std::string _symbol;
		std::vector<std::shared_ptr<Type>> members;
		UnionType(TypeSystem*,const std::shared_ptr<std::set<std::string>>, const std::shared_ptr<std::set<std::string>>);
	public:
		~UnionType();
		virtual const std::string& symbol() const;
		virtual std::shared_ptr<std::set<std::string>> asUnion() const;
	};

	class VectorType : public Type {
		friend TypeSystem;
	private:
		std::shared_ptr<Type> content;
		std::shared_ptr<Type> index;
		std::string _symbol;
		VectorType(TypeSystem*,const std::shared_ptr<Type>, const std::shared_ptr<Type>);
	public:
		~VectorType();
		virtual const std::string& symbol() const;
		virtual bool isCollection() const;
		virtual std::shared_ptr<Type> contentType() const;
		virtual std::shared_ptr<Type> indexType() const;
	};

	class ErrorType : public Type {
		friend TypeSystem;
	private:
		static const std::string ERR;
		std::vector<std::string> messages;
		ErrorType(TypeSystem*,const std::vector<std::string>&,const std::vector<std::string>&);
		ErrorType(TypeSystem*,const std::vector<std::string>&);
		ErrorType(TypeSystem*,const std::string& msg);
	public:
		~ErrorType();
		virtual const std::string& symbol() const;
		virtual std::shared_ptr<std::set<std::string>> asUnion() const;
		virtual const std::shared_ptr<Type> unify(const std::shared_ptr<Type>) const;
		virtual bool isSuperclassOf(const std::shared_ptr<Type>) const;
		virtual bool isEqual(const std::shared_ptr<Type>) const;
		virtual bool isError() const;
		virtual std::shared_ptr<Type> contentType() const;
		virtual std::shared_ptr<Type> indexType() const;
	};

	enum LiteralType { tvtInt, tvtFloat, tvtString, tvtSpecial };

	class TypeValue {
	public:
		virtual const std::string& symbol() const = 0;
		virtual const std::shared_ptr<Type> type(std::shared_ptr<TypeSystem>) const = 0;
		virtual const LiteralType litType() const = 0;
		virtual const std::string& stringValue() const;
		virtual const int intValue() const;
		virtual const double floatValue() const;
	};

	class StringTypeValue : public TypeValue {
	private:
		const std::string val;
		const std::string sym;
	public:
		StringTypeValue(const std::string&);
		~StringTypeValue();
		virtual const std::string& symbol() const;
		virtual const std::shared_ptr<Type> type(std::shared_ptr<TypeSystem>) const;
		virtual const std::string& stringValue() const;
		virtual const LiteralType litType() const;
	};

	class IntTypeValue : public TypeValue {
	private:
		const int val;
		const std::string sym;
	public:
		IntTypeValue(const int);
		~IntTypeValue();
		virtual const std::string& symbol() const;
		virtual const std::shared_ptr<Type> type(std::shared_ptr<TypeSystem>) const;
		virtual const int intValue() const;
		virtual const LiteralType litType() const;
	};

	class FloatTypeValue : public TypeValue {
	private:
		const double val;
		const std::string sym;
	public:
		FloatTypeValue(const double);
		~FloatTypeValue();
		virtual const std::string& symbol() const;
		virtual const std::shared_ptr<Type> type(std::shared_ptr<TypeSystem>) const;
		virtual const double floatValue() const;
		virtual const LiteralType litType() const;
	};
	
	class UnitTypeValue : public TypeValue {
	public:
		UnitTypeValue();
		~UnitTypeValue();
		virtual const std::string&symbol() const;
		virtual const std::shared_ptr<Type> type(std::shared_ptr<TypeSystem>) const;
		virtual const LiteralType litType() const;
	};

	bool compareTypeValue(const std::shared_ptr<TypeValue> &s, const std::shared_ptr<TypeValue>&t);

	typedef std::set<std::shared_ptr<TypeValue>, decltype(compareTypeValue)*> TypeValueSet;

	class SetType : public Type {
		friend TypeSystem;
	private:
		std::string _symbol;
		SetType(TypeSystem*,const TypeValueSet&);
	public:
		const std::set<std::shared_ptr<TypeValue>, decltype(compareTypeValue)*> values;
		~SetType();
		virtual const std::string& symbol() const;
		virtual bool isSuperclassOf(const std::shared_ptr<Type>) const;
		virtual bool isEqual(const std::shared_ptr<Type>) const;
		virtual bool isSet() const;
		virtual bool canMerge(const std::shared_ptr<Type>) const;
		virtual std::shared_ptr<Type> merge(const std::shared_ptr<Type>) const;
	};

	class RangeType : public Type {
		friend TypeSystem;
	private:
		std::string _symbol;
		RangeType(TypeSystem*,const int lb, const int ub);
	public:
		const int lb, ub;
		~RangeType();
		virtual const std::string& symbol() const;
		virtual bool isSuperclassOf(const std::shared_ptr<Type>) const;
		virtual bool isEqual(const std::shared_ptr<Type>) const;
		virtual bool isRange() const;
		virtual bool canMerge(const std::shared_ptr<Type>) const;
		virtual std::shared_ptr<Type> merge(const std::shared_ptr<Type>) const;
	};

	class FunctionType : public Type {
		friend TypeSystem;
	private:
		std::string _symbol;
		std::shared_ptr<Type> _returnType;
		std::vector<std::shared_ptr<Type>> _argTypes;
		FunctionType(TypeSystem*,const std::shared_ptr<Type>,const std::vector<std::shared_ptr<Type>>&);
	public:
		virtual bool isFunction() const;
		virtual const std::string& symbol() const;
		virtual const std::shared_ptr<Type> returnType() const;
		virtual const std::vector<std::shared_ptr<Type>>& argTypes() const ;
	};

	class TypeSystem {
	private:
		std::map<const std::string,const std::shared_ptr<Type>> typeTable;
		const std::shared_ptr<Type> registerType(const std::shared_ptr<Type>);
	public:
		TypeSystem();
		~TypeSystem();
		const std::shared_ptr<Type> get(const std::string& name) const;
		const std::shared_ptr<Type> Int;
		const std::shared_ptr<Type> Numeric;
		const std::shared_ptr<Type> Float;
		const std::shared_ptr<Type> Bool;
		const std::shared_ptr<Type> Null;
		const std::shared_ptr<Type> String;
		const std::shared_ptr<Type> Unit;
		const std::shared_ptr<Type> Anything;
		const std::shared_ptr<Type> makeUnion(const std::shared_ptr<std::set<std::string>>, const std::shared_ptr<std::set<std::string>>);
		const std::shared_ptr<Type> makeError(const int, const std::string&);
		const std::shared_ptr<Type> makeSet(const std::set<std::shared_ptr<TypeValue>, decltype(compareTypeValue)*>&);
		const std::shared_ptr<Type> makeRange(const int,const int);
		const std::shared_ptr<Type> makeVector(const std::shared_ptr<Type>, const std::shared_ptr<Type>);
		const std::shared_ptr<Type> makeFunction(const std::shared_ptr<Type>, const std::vector<std::shared_ptr<Type>>&);
	};
	}
}


