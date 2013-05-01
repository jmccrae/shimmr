#include "type_checker.h"

#include <sstream>
#include <assert.h>
#include <algorithm>
#include <limits.h>

using namespace std;

namespace shimmr {

	TypeChecker::TypeChecker(shared_ptr<Scope> s) : root(s), sys(new shimmrType::TypeSystem()) {
		current = s.get();
	}

	TypeChecker::~TypeChecker() {
	}

	shared_ptr<shimmrType::Type> TypeChecker::check(Program *p, shared_ptr<Scope> s) {
		auto checker = new TypeChecker(s);
		p->accept(checker);
		auto t = checker->typeStack.top();
		delete checker;
		return t;
	}

	shared_ptr<shimmrType::Type> TypeChecker::visitForType(Visitable *p) {
		p->accept(this);
		auto type = typeStack.top();
		typeStack.pop();
		return type;
	}
		
	std::vector<std::shared_ptr<shimmrType::Type>> TypeChecker::visitForTypeList(Visitable *p) {
		int i = typeStack.size();
		p->accept(this);
		const int end = typeStack.size();
		vector<shared_ptr<shimmrType::Type>> typeList;
		for(; i < end; i++) {
			typeList.push_back(typeStack.top());
			typeStack.pop();
		}
		reverse(typeList.begin(),typeList.end());
		return typeList;
	}
	
	void TypeChecker::checkSOE(const int lineNo, shared_ptr<shimmrType::Type> t1, shared_ptr<shimmrType::Type> t2, std::string msg) {
		if(!t1->isError() && !t2->isError() && !t1->isSuperclassOrEqual(t2)) {
			string m(msg);
			auto err = sys->makeError(lineNo,m);
			follow(err);
		}
	}

	void TypeChecker::checkCollection(const int lineNo, shared_ptr<shimmrType::Type> t) {
		if(!t->isError() && !t->isCollection()) {
			string msg("Iteration over non-collection type");
			msg.append(t->symbol());
			auto err = sys->makeError(lineNo,msg);
			follow(err);
		}
	}

	void TypeChecker::checkFunction(const int lineNo, shared_ptr<shimmrType::Type> t) {
		if(!t->isError() && !t->isFunction()) {
			string msg("Invocation of non-function type");
			msg.append(t->symbol());
			auto err = sys->makeError(lineNo,msg);
			follow(err);
		}
	}

	void TypeChecker::follow(shared_ptr<shimmrType::Type> t) {
		if(typeStack.top()->isError()) {
			if(t->isError()) {
				auto newErr = typeStack.top()->unify(t);
				typeStack.pop();
				typeStack.push(newErr);
			} else {
				// no-op
			}
		} else {
			typeStack.pop();
			typeStack.push(t);
		}
	}

	void TypeChecker::visitStatements(Statements *p) {
		p->liststatement_->accept(this);
	}

	void TypeChecker::visitStatementBlockStat(StatementBlockStat *p) {
		auto childScope = current->children[p];
		current = childScope.get();

		p->liststatement_->accept(this);

		current = current->parent;
	}

	void TypeChecker::visitListStatement(ListStatement *p) {
		typeStack.push(sys->Unit);
		for(auto it = p->begin(); it != p->end(); ++it) {
			follow(visitForType(*it));
		}
	}

	void TypeChecker::visitDeclStat(DeclStat *p) {
		p->decl_->accept(this);
	}

	void TypeChecker::visitSimpleDecl(SimpleDecl *p) {
		auto type = visitForType(p->exp_);
		
		string varName(p->ident_);
		auto elem = current->resolve(varName);
		elem->updateType(type);
		
		typeStack.push(type);
		follow(sys->Unit);
	}

	void TypeChecker::visitTypedDecl(TypedDecl *p) {
		auto type = visitForType(p->exp_);

		string varName(p->ident_);
		auto elem = current->resolve(varName);
		
		typeStack.push(type);

		checkSOE(p->line_number,elem->type(),type,
			"Variable declared as " + elem->type()->symbol() + " but assigned in initialization as " + type->symbol());

		follow(sys->Unit);
	}

	void TypeChecker::visitSimpleDeclWith(SimpleDeclWith *p) {
		
		auto type1 = visitForType(p->exp_1);

		typeStack.push(type1);

		auto type2 = visitForType(p->exp_2);

		follow(type2);

		string varName(p->ident_);
		auto elem = current->resolve(varName);
		elem->updateType(type1);

		checkSOE(p->line_number,sys->Numeric,type2,"With clause has non-numeric value");

		follow(sys->Unit);
	}

	void TypeChecker::visitTypedDeclWith(TypedDeclWith *p) {
		auto type1 = visitForType(p->exp_1);

		typeStack.push(type1);
				
		string varName(p->ident_);
		auto elem = current->resolve(varName);

		checkSOE(p->line_number,elem->type(),type1,
			"Variable declared as " + elem->type()->symbol() + " but assigned in initialization as " + type1->symbol());

		auto type2 = visitForType(p->exp_2);

		follow(type2);

		checkSOE(p->line_number,sys->Numeric,type2,"With clause has non-numeric value");

		follow(sys->Unit);
	}

	void TypeChecker::visitBareDecl(BareDecl *p) {
		typeStack.push(sys->Unit);
	}

	void TypeChecker::visitEFuncDecl(EFuncDecl *p) {
		// Change scope
		auto s = current->children[p];
		current = s.get();

		auto argList = visitForTypeList(p->listargument_);

		auto retType = visitForType(p->statementblock_);

		auto funcType = sys->makeFunction(retType,argList);

		string varName(p->ident_);
		auto elem = current->resolve(varName);
		elem->updateType(funcType);

		typeStack.push(funcType);
		follow(sys->Unit);

		current = current->parent;
	}

	void TypeChecker::visitEFuncDeclWithType(EFuncDeclWithType *p) {
		auto s = current->children[p];
		current = s.get();

		auto declRetType = visitForType(p->type_);

		auto argList = visitForTypeList(p->listargument_);

		auto retType = visitForType(p->statementblock_);

		auto funcType = sys->makeFunction(retType,argList);

		typeStack.push(funcType);
		
		string varName(p->ident_);
		auto elem = current->resolve(varName);

		checkSOE(p->line_number,declRetType,retType,
			"Function declared as " + elem->type()->symbol() + " but return type was " + retType->symbol());

		follow(sys->Unit);

		current = current->parent;
	}

	void TypeChecker::visitForStatement(ForStatement *p) {
		auto expType = visitForType(p->exp_);

		typeStack.push(expType);

		checkCollection(p->line_number,expType);
		
		auto s = current->children[p];
		current = s.get();
		
		string varName(p->ident_);
		auto elem = current->resolve(varName);
		elem->updateType(expType->contentType());

		auto resultType = visitForType(p->statementblock_);
		follow(resultType);

		follow(sys->makeVector(resultType,expType->indexType()));

		current = current->parent;
	}

	void TypeChecker::visitIfStatement(IfStatement *p) {
		auto expType = visitForType(p->exp_);
		typeStack.push(expType);

		checkSOE(p->line_number,
			sys->Bool,
			expType,
			"Condition in if statement was not a Bool");

		auto s = current->children[p];
		current = s.get();

		auto statType = visitForType(p->statementblock_);
		follow(statType->unify(sys->Null));

		current = current->parent;
	}

	void TypeChecker::visitIfElseStatement(IfElseStatement *p) {
		auto expType = visitForType(p->exp_);
		typeStack.push(expType);

		checkSOE(p->line_number,
			sys->Bool,
			expType,
			"Condition in if statement was not a Bool");

		auto s = current->children[p];
		current = s.get();

		auto statType = visitForType(p->statementblock_);
		current = current->parent;

		auto elseType = visitForType(p->elseblock_);
		follow(statType->unify(elseType));

	}

	void TypeChecker::visitElseIfBlock(ElseIfBlock *p) {
		auto expType = visitForType(p->exp_);
		typeStack.push(expType);

		checkSOE(p->line_number,
			sys->Bool,
			expType,
			"Condition in if statement was not a Bool");

		auto s = current->children[p];
		current = s.get();

		auto statType = visitForType(p->statementblock_);
		follow(statType->unify(sys->Null));

		current = current->parent;
	}

	void TypeChecker::visitElseIf2Block(ElseIf2Block *p) {
		auto expType = visitForType(p->exp_);
		typeStack.push(expType);

		checkSOE(p->line_number,
			sys->Bool,
			expType,
			"Condition in if statement was not a Bool");

		auto s = current->children[p];
		current = s.get();

		auto statType = visitForType(p->statementblock_);
		current = current->parent;
		auto elseType = visitForType(p->elseblock_);
		follow(statType->unify(elseType));


	}

	void TypeChecker::visitElseBlockStat(ElseBlockStat *p) {
		auto s = current->children[p];
		current = s.get();

		auto type = visitForType(p->statementblock_);
		typeStack.push(type);
		
		current = current->parent;
	}

	void TypeChecker::visitElseFailStat(ElseFailStat *p) {
		auto symbols = make_shared<set<string>>();
		typeStack.push(sys->makeUnion(symbols,symbols));
	}

	void TypeChecker::visitSomeStatement(SomeStatement *p) {
		auto expType = visitForType(p->exp_);
		typeStack.push(expType);

		checkCollection(p->line_number,
			expType);

		auto s = current->children[p];
		current = s.get();

		string varName(p->ident_);
		auto elem = current->resolve(varName);
		elem->updateType(expType->contentType());

		auto statType = visitForType(p->statementblock_);
		follow(statType);
		
		follow(expType->contentType()->unify(sys->Null));

		current = current->parent;
	}

	void TypeChecker::visitSomeElseStatement(SomeElseStatement *p) {
		auto expType = visitForType(p->exp_);
		typeStack.push(expType);

		checkCollection(p->line_number,
			expType);

		auto s = current->children[p];
		current = s.get();

		string varName(p->ident_);
		auto elem = current->resolve(varName);
		elem->updateType(expType->contentType());

		auto statType = visitForType(p->statementblock_);
		follow(statType);

		auto elseType = visitForType(p->elseblock_);
		follow(elseType);

		follow(expType->contentType()->unify(elseType));

		current = current->parent;

	}

	void TypeChecker::visitConditionalStatement(ConditionalStatement *p) {

		auto type2 = visitForType(p->exp_2);
		typeStack.push(type2);

		checkSOE(p->line_number,
			sys->Numeric,
			type2,
			"Conditional statement has non-numeric with clause");
		
		auto type1 = visitForType(p->exp_1);

		follow(type1->unify(sys->Null));
	}

	void TypeChecker::visitExpAsStatement(ExpAsStatement *p) {
		auto type = visitForType(p->exp_);
		typeStack.push(type);

	}

	void TypeChecker::visitEOr(EOr *p) {
		auto type1 = visitForType(p->exp_1);
		typeStack.push(type1);

		checkSOE(p->line_number,
			sys->Bool,
			type1,
			"Left-side of || not a Bool");

		auto type2 = visitForType(p->exp_2);
		follow(type2);

		checkSOE(p->line_number,
			sys->Bool,
			type2,
			"Right-side of || not a Bool");

		follow(sys->Bool);
	}

	void TypeChecker::visitEAnd(EAnd *p) {
		auto type1 = visitForType(p->exp_1);
		typeStack.push(type1);

		checkSOE(p->line_number,
			sys->Bool,
			type1,
			"Left-side of && not a Bool");

		auto type2 = visitForType(p->exp_2);
		follow(type2);

		checkSOE(p->line_number,
			sys->Bool,
			type2,
			"Right-side of && not a Bool");

		follow(sys->Bool);
	}

	void TypeChecker::visitEEquals(EEquals *p) {
		auto type1 = visitForType(p->exp_1);
		typeStack.push(type1);

		auto type2 = visitForType(p->exp_2);
		follow(type2);

		checkSOE(p->line_number,
			type1,
			type2,
			"Assignment does not conform to type bounds");

		follow(sys->Bool);
	}

	void TypeChecker::visitENEq(ENEq *p) {
		auto type1 = visitForType(p->exp_1);
		typeStack.push(type1);

		auto type2 = visitForType(p->exp_2);
		follow(type2);

		checkSOE(p->line_number,
			type1,
			type2,
			"Assignment does not conform to type bounds");

		follow(sys->Bool);
	}

	void TypeChecker::visitELeq(ELeq *p) {
		auto type1 = visitForType(p->exp_1);
		typeStack.push(type1);

		checkSOE(p->line_number,
			sys->Numeric,
			type1,
			"Left side of <= not numeric");

		auto type2 = visitForType(p->exp_2);
		follow(type2);

		checkSOE(p->line_number,
			sys->Numeric,
			type2,
			"Right side of <= not numeric");

		follow(sys->Bool);
	}

	void TypeChecker::visitEGeq(EGeq *p) {
		auto type1 = visitForType(p->exp_1);
		typeStack.push(type1);

		checkSOE(p->line_number,
			sys->Numeric,
			type1,
			"Left side of >= not numeric");

		auto type2 = visitForType(p->exp_2);
		follow(type2);

		checkSOE(p->line_number,
			sys->Numeric,
			type2,
			"Right side of >= not numeric");

		follow(sys->Bool);
	}

	void TypeChecker::visitELessThan(ELessThan *p) {
		auto type1 = visitForType(p->exp_1);
		typeStack.push(type1);

		checkSOE(p->line_number,
			sys->Numeric,
			type1,
			"Left side of < not numeric");

		auto type2 = visitForType(p->exp_2);
		follow(type2);

		checkSOE(p->line_number,
			sys->Numeric,
			type2,
			"Right side of < not numeric");

		follow(sys->Bool);

	}

	void TypeChecker::visitEGreaterThan(EGreaterThan *p) {
		auto type1 = visitForType(p->exp_1);
		typeStack.push(type1);

		checkSOE(p->line_number,
			sys->Numeric,
			type1,
			"Left side of > not numeric");

		auto type2 = visitForType(p->exp_2);
		follow(type2);

		checkSOE(p->line_number,
			sys->Numeric,
			type2,
			"Right side of > not numeric");

		follow(sys->Bool);
	}

	shared_ptr<shimmrType::Type> inferNumericResult(shared_ptr<shimmrType::TypeSystem> sys,
		shared_ptr<shimmrType::Type> t1,
		shared_ptr<shimmrType::Type> t2,
		function<int (int,int)> iTransform,
		function<double (double,double)> dTransform) {

		if(t1->isError() && t2->isError()) {
			return t1->unify(t2);
		} else if(t1->isError()) {
			return t1;
		} else if(t2->isError()) {
			return t2;
		} else if(t1->isEqual(sys->Numeric)) {
			return t1;
		} else if(t2->isEqual(sys->Numeric)) {
			return t2;
		} else if(t1->isEqual(sys->Float)) {
			return t1;
		} else if(t2->isEqual(sys->Float)) {
			return t2;
		} else if(t1->isEqual(sys->Int)) {
			return t1;
		} else if(t2->isEqual(sys->Int)) {
			return t2;
		} else if(t1->isRange()) {
			if(t2->isRange()) {
				auto _t1 = (shimmrType::RangeType*)t1.get();
				auto _t2 = (shimmrType::RangeType*)t2.get();
				int lb = min(min(iTransform(_t1->lb,_t2->lb),
					iTransform(_t1->lb,_t2->ub)),
					min(iTransform(_t1->ub,_t2->lb),
					iTransform(_t1->ub,_t2->ub)));
				int ub = max(max(iTransform(_t1->lb,_t2->lb),
					iTransform(_t1->lb,_t2->ub)),
					max(iTransform(_t1->ub,_t2->lb),
					iTransform(_t1->ub,_t2->ub)));
				return sys->makeRange(lb,ub);
			} else if(t2->isSet()) {
				auto _t1 = (shimmrType::RangeType*)t1.get();
				auto _t2 = (shimmrType::SetType*)t2.get();
				std::set<std::shared_ptr<shimmrType::TypeValue>, decltype(shimmrType::compareTypeValue)*> values(shimmrType::compareTypeValue);
				for(auto it = _t2->values.begin(); it != _t2->values.end(); ++it) {
					for(int i = _t1->lb; i <= _t1->ub; i++) {
						if((*it)->litType() == shimmrType::tvtFloat) {
							auto v = make_shared<shimmrType::FloatTypeValue>(dTransform(i,(*it)->floatValue()));
							values.insert(v);
						} else if((*it)->litType() == shimmrType::tvtInt) {
							auto v = make_shared<shimmrType::IntTypeValue>(iTransform(i,(*it)->intValue()));
							values.insert(v);
						} else {
							return sys->makeError(-1, "[INTERNAL] String found in supposedly numeric set");
						}
					}
				}
				return sys->makeSet(values);
			} else {
				return sys->makeError(-1, "[INTERNAL] t1 range, t2 not a set or range");
			}
		} else if(t1->isSet()) {
			if(t2->isRange()) {
				auto _t1 = (shimmrType::SetType*)t1.get();
				auto _t2 = (shimmrType::RangeType*)t2.get();
				std::set<std::shared_ptr<shimmrType::TypeValue>, decltype(shimmrType::compareTypeValue)*> values(shimmrType::compareTypeValue);
				for(auto it = _t1->values.begin(); it != _t1->values.end(); ++it) {
					for(int i = _t2->lb; i <= _t2->ub; i++) {
						if((*it)->litType() == shimmrType::tvtFloat) {
							auto v = make_shared<shimmrType::FloatTypeValue>(dTransform((*it)->floatValue(),i));
							values.insert(v);
						} else if((*it)->litType() == shimmrType::tvtInt) {
							auto v = make_shared<shimmrType::IntTypeValue>(iTransform((*it)->intValue(),i));
							values.insert(v);
						} else {
							return sys->makeError(-1, "[INTERNAL] String found in supposedly numeric set");
						}
					}
				}
				return sys->makeSet(values);
			} else if(t2->isSet()) {
				
				auto _t1 = (shimmrType::SetType*)t1.get();
				auto _t2 = (shimmrType::SetType*)t2.get();
				std::set<std::shared_ptr<shimmrType::TypeValue>, decltype(shimmrType::compareTypeValue)*> values(shimmrType::compareTypeValue);
				for(auto it1 = _t1->values.begin(); it1 != _t1->values.end(); ++it1) {
					for(auto it2 = _t2->values.begin(); it2 != _t2->values.end(); ++it2) {
						if((*it1)->litType() == shimmrType::tvtFloat && (*it2)->litType() == shimmrType::tvtFloat) {
							auto v = make_shared<shimmrType::FloatTypeValue>(dTransform((*it1)->floatValue(),(*it2)->floatValue()));
							values.insert(v);
						} else if((*it1)->litType() == shimmrType::tvtFloat && (*it2)->litType() == shimmrType::tvtInt) {
							auto v = make_shared<shimmrType::FloatTypeValue>(dTransform((*it1)->floatValue(),(*it2)->intValue()));
							values.insert(v);
						} else if((*it1)->litType() == shimmrType::tvtInt && (*it2)->litType() == shimmrType::tvtFloat) {
							auto v = make_shared<shimmrType::FloatTypeValue>(dTransform((*it1)->intValue(),(*it2)->floatValue()));
							values.insert(v);
						} else if((*it1)->litType() == shimmrType::tvtInt && (*it2)->litType() == shimmrType::tvtInt) {
							auto v = make_shared<shimmrType::FloatTypeValue>(iTransform((*it1)->intValue(),(*it2)->intValue()));
							values.insert(v);
						} else {
							return sys->makeError(-1, "[INTERNAL] String found in supposedly numeric set");
						}
					}
				}
				return sys->makeSet(values);
			} else {
				return sys->makeError(-1, "[INTERNAL] t1 range, t2 not a set or range");
			}
		} else {
			return sys->makeError(-1,"[INTERNAL] not a recognized numeric");
		}
	}

	void TypeChecker::visitEAdd(EAdd *p) {
		auto type1 = visitForType(p->exp_1);
		typeStack.push(type1);

		checkSOE(p->line_number,
			sys->Numeric,
			type1,
			"Non-numeric value on left side of +");

		auto type2 = visitForType(p->exp_2);
		follow(type2);

		checkSOE(p->line_number,
			sys->Numeric,
			type2,
			"Non-numeric value on right side of +");

		auto combinedType = inferNumericResult(sys,
			type1,type2,
			[](int x, int y) { return x + y; },
			[](double x, double y) { return x + y; });

		follow(combinedType);
	}

	void TypeChecker::visitESub(ESub *p) {
		auto type1 = visitForType(p->exp_1);
		typeStack.push(type1);

		checkSOE(p->line_number,
			sys->Numeric,
			type1,
			"Non-numeric value on left side of -");

		auto type2 = visitForType(p->exp_2);
		follow(type2);

		checkSOE(p->line_number,
			sys->Numeric,
			type2,
			"Non-numeric value on right side of -");

		auto combinedType = inferNumericResult(sys,
			type1,type2,
			[](int x, int y) { return x - y; },
			[](double x, double y) { return x - y; });

		follow(combinedType);
	}

	void TypeChecker::visitEMul(EMul *p) {
		auto type1 = visitForType(p->exp_1);
		typeStack.push(type1);

		checkSOE(p->line_number,
			sys->Numeric,
			type1,
			"Non-numeric value on left side of *");

		auto type2 = visitForType(p->exp_2);
		follow(type2);

		checkSOE(p->line_number,
			sys->Numeric,
			type2,
			"Non-numeric value on right side of *");

		auto combinedType = inferNumericResult(sys,
			type1,type2,
			[](int x, int y) { return x * y; },
			[](double x, double y) { return x * y; });

		follow(combinedType);
	}

	void TypeChecker::visitEDiv(EDiv *p) {
		auto type1 = visitForType(p->exp_1);
		typeStack.push(type1);

		checkSOE(p->line_number,
			sys->Numeric,
			type1,
			"Non-numeric value on left side of /");

		auto type2 = visitForType(p->exp_2);
		follow(type2);

		checkSOE(p->line_number,
			sys->Numeric,
			type2,
			"Non-numeric value on right side of /");

		auto combinedType = inferNumericResult(sys,
			type1,type2,
			[](int x, int y) { return y == 0 ? (x < 0 ? INT_MIN : INT_MAX) : x / y; },
			[](double x, double y) { return x / y; });

		follow(combinedType);
	}

	void TypeChecker::visitENot(ENot *p) {
		auto type = visitForType(p->exp_);
		typeStack.push(type);

		checkSOE(p->line_number,
			sys->Bool,
			type,
			"Negation of non-Bool value");
	}

	void TypeChecker::visitEIdent(EIdent *p) {
		string varName(p->ident_);
		auto elem = current->resolve(varName);

		if(!elem->isDefined()) {
			auto err = sys->makeError(p->line_number,"Unknown identifier: " + varName);
			typeStack.push(err);
		} else {
			if(elem->type() == nullptr) {
				elem->declarationPoint->accept(this);
				typeStack.pop();
			}
			assert(elem->type() != nullptr);
			typeStack.push(elem->type());
		}
	}

	void TypeChecker::visitEFuncCall(EFuncCall *p) {
		string varName(p->ident_);
		auto elem = current->resolve(varName);

		if(!elem->isDefined()) {
			auto err = sys->makeError(p->line_number,"Unknown identifier: " + varName);
			typeStack.push(err);
		} else {
			if(elem->type() == nullptr) {
				elem->declarationPoint->accept(this);
				typeStack.pop();
			}
			typeStack.push(sys->Unit);

			assert(elem->type() != nullptr);
			
			checkFunction(p->line_number,elem->type());

			auto ft = (shimmrType::FunctionType*)elem->type().get();

			auto declArgTypes = ft->argTypes();

			auto argTypes = visitForTypeList(p->listexp_);
			
			if(declArgTypes.size() != argTypes.size()) {
				auto err = sys->makeError(p->line_number,"Number of arguments differ from declaration");
				follow(err);
			} else {
				auto it1 = declArgTypes.begin();
				auto it2 = argTypes.begin();
				while(it1 != declArgTypes.end() && it2 != argTypes.end()) {
					checkSOE(p->line_number,
						*it1,
						*it2,
						"Argument does not correspond to type bound");
					++it1;
					++it2;
				}
				follow(ft->returnType());
			}
		}
	}

	void TypeChecker::visitArgumentDef(ArgumentDef *p) {

	}

	void TypeChecker::visitListArgument(ListArgument *p) {
		
	}
		
	void TypeChecker::visitERange(ERange *p) {
		if(p->integer_1 > p->integer_2) {
			typeStack.push(sys->makeError(p->line_number,"Range has smaller lower bound than upper bound"));
		} else {
			auto range = sys->makeRange(p->integer_1,p->integer_2);
			typeStack.push(sys->makeVector(range,range));
		}
	}
		
	void TypeChecker::visitESet(ESet *p) {
		int i = typeValueStack.size();
		p->listsettypeelem_->accept(this);
		int e = typeValueStack.size();
		std::set<std::shared_ptr<shimmrType::TypeValue>, decltype(shimmrType::compareTypeValue)*> values(shimmrType::compareTypeValue);
		for(; i < e; i++) {
			values.insert(typeValueStack.top());
			typeValueStack.pop();
		}
		auto set = sys->makeSet(values);
		typeStack.push(sys->makeVector(set,set));
	}

	void TypeChecker::visitEInt(EInt *p) {
		typeStack.push(sys->makeRange(p->integer_,p->integer_));
	}

	void TypeChecker::visitEFloat(EFloat *p) {
		std::set<std::shared_ptr<shimmrType::TypeValue>, decltype(shimmrType::compareTypeValue)*> values(shimmrType::compareTypeValue);
		values.insert(make_shared<shimmrType::FloatTypeValue>(p->double_));
		typeStack.push(sys->makeSet(values));
	}

	void TypeChecker::visitEString(EString *p) {
		std::set<std::shared_ptr<shimmrType::TypeValue>, decltype(shimmrType::compareTypeValue)*> values(shimmrType::compareTypeValue);
		string val(p->string_);
		values.insert(make_shared<shimmrType::StringTypeValue>(p->string_));
		typeStack.push(sys->makeSet(values));
	}

	void TypeChecker::visitListExp(ListExp *p) {
		for(auto it = p->begin(); it != p->end(); ++it) {
			(*it)->accept(this);
		}
	}

	void TypeChecker::visitEType(EType *p) {
		if(sys->Anything->symbol().compare(p->ident_) == 0) {
			typeStack.push(sys->Anything);
		} else if(sys->Bool->symbol().compare(p->ident_) == 0) {
			typeStack.push(sys->Bool);
		} else if(sys->Float->symbol().compare(p->ident_) == 0) {
			typeStack.push(sys->Float);
		} else if(sys->Int->symbol().compare(p->ident_) == 0) {
			typeStack.push(sys->Int);
		} else if(sys->Null->symbol().compare(p->ident_) == 0) {
			typeStack.push(sys->Null);
		} else if(sys->Numeric->symbol().compare(p->ident_) == 0) {
			typeStack.push(sys->Numeric);
		} else if(sys->String->symbol().compare(p->ident_) == 0) {
			typeStack.push(sys->String);
		} else if(sys->Unit->symbol().compare(p->ident_) == 0) {
			typeStack.push(sys->Unit);
		} else {
			typeStack.push(sys->makeError(p->line_number,"Unrecognized type identifier: " + p->ident_));
		}
	}

	void TypeChecker::visitVectorType(VectorType *p) {
		auto iType = visitForType(p->type_1);
		auto cType = visitForType(p->type_2);
		typeStack.push(sys->makeVector(iType,cType));
	}

	void TypeChecker::visitRangeType(RangeType *p) {
		if(p->integer_1 <= p->integer_2) {
			auto type = current->typeSystem->makeRange(p->integer_1,p->integer_2);
			typeStack.push(type);
		} else {
			string msg("Invalid range from ");
			msg.append(to_string(p->integer_1));
			msg.append(" to ");
			msg.append(to_string(p->integer_2));
			auto type = current->typeSystem->makeError(p->line_number,msg);
			typeStack.push(type);
		}
	}

	void TypeChecker::visitSetType(SetType *p) {
		int i = typeValueStack.size();
		p->listsettypeelem_->accept(this);
		int e = typeValueStack.size();
		std::set<std::shared_ptr<shimmrType::TypeValue>, decltype(shimmrType::compareTypeValue)*> values(shimmrType::compareTypeValue);
		for(; i < e; i++) {
			values.insert(typeValueStack.top());
			typeValueStack.pop();
		}
		typeStack.push(current->typeSystem->makeSet(values));
	}

	void TypeChecker::visitEIntSTE(EIntSTE *p) {
		auto ste = make_shared<shimmrType::IntTypeValue>(p->integer_);
		typeValueStack.push(ste);
	}

	void TypeChecker::visitEFloatSTE(EFloatSTE *p) {
		auto ste = make_shared<shimmrType::FloatTypeValue>(p->double_);
		typeValueStack.push(ste);
	}

	void TypeChecker::visitEStringSTE(EStringSTE *p) {
		string val(p->string_);
		auto ste = make_shared<shimmrType::StringTypeValue>(val);
		typeValueStack.push(ste);
	}

	void TypeChecker::visitListSetTypeElem(ListSetTypeElem *p) {
		for(auto it = p->begin(); it != p->end(); ++it) {
			(*it)->accept(this);
		}
	}

	void TypeChecker::visitEVector(EVector *p) {
		string varName(p->ident_);
		auto elem = current->resolve(varName);

		auto t = elem->type();

		typeStack.push(t);

		if(p->listexp_->empty()) {
			follow(sys->makeError(p->line_number,"Empty index list"));
		}

		for(auto it = p->listexp_->rbegin(); it != p->listexp_->rend(); ++it)  {
			checkCollection(p->line_number,t);
			auto type = visitForType(*it);
			follow(type);

			checkSOE(p->line_number,
				t->indexType(),
				type,
				"Vector index does not conform to type bounds");

			if(t->isCollection()) {
				t = t->contentType();
			} else {
				break;
			}
		}

		follow(t);
	}

	
	void TypeChecker::visitIdent(Ident p) {

	}

	
	void TypeChecker::visitProgram(Program *p) {

	}

	void TypeChecker::visitStatementBlock(StatementBlock *p) {

	}

	void TypeChecker::visitStatement(Statement *p) {

	}

	void TypeChecker::visitDecl(Decl *p) {

	}

	void TypeChecker::visitElseBlock(ElseBlock *p) {

	}

	void TypeChecker::visitExp(Exp *p) {

	}

	void TypeChecker::visitArgument(Argument *p) {

	}

	void TypeChecker::visitType(Type *p) {

	}

	void TypeChecker::visitSetTypeElem(SetTypeElem *p) {

	}

	void TypeChecker::visitInteger(Integer i) {

	}

	void TypeChecker::visitDouble(Double d) {

	}

	void TypeChecker::visitChar(Char c) {

	}

	void TypeChecker::visitString(String s) {

	}
}