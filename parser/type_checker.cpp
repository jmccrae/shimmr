#include "type_checker.h"

#include <sstream>

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

	void TypeChecker::visitStatements(Statements *p) {
		ListStatement *ls = p->liststatement_;
		auto type = sys->Unit;
		while(ls != nullptr) {
			ls->statement_->accept(this);
			ls = ls->liststatement_;
			if(type->isError()) {
				type = type->or(typeStack.top());
			} else {
				type = typeStack.top();
			}
			typeStack.pop();
		}
		typeStack.push(type);
	}

	void TypeChecker::visitStatementBlockStat(StatementBlockStat *p) {
		auto childScope = current->children[p];
		auto type = sys->Unit;
		current = childScope.get();
		ListStatement *ls = p->liststatement_;
		while(ls != nullptr) {
			ls->statement_->accept(this);
			ls = ls->liststatement_;
			if(type->isError()) {
				type = type->or(typeStack.top());
			} else {
				type = typeStack.top();
			}
			typeStack.pop();
		}
		typeStack.push(type);
		current = childScope->parent;
	}

	void TypeChecker::visitListStatement(ListStatement *p) {
		// Skipped
	}

	void TypeChecker::visitDeclStat(DeclStat *p) {
		p->decl_->accept(this);
	}

	void TypeChecker::visitSimpleDecl(SimpleDecl *p) {

		p->exp_->accept(this);
		auto type = typeStack.top();
		typeStack.pop();
		
		string varName(p->ident_);
		auto elem = current->resolve(varName);
		elem->updateType(type);
		
		typeStack.push(sys->Unit);
	}

	void TypeChecker::visitTypedDecl(TypedDecl *p) {
		p->exp_->accept(this);
		auto type = typeStack.top();
		typeStack.pop();

		string varName(p->ident_);
		auto elem = current->resolve(varName);
		if(elem->type()->isSuperclassOrEqual(type)) {
			// valid assignment
			typeStack.push(sys->Unit);
		} else {
			ostringstream msg;
			msg << "Variable " << varName << " declared as " << elem->type()->symbol() << " but assigned in initialization as " << type->symbol();
			auto err = sys->makeError(msg.str());
			typeStack.push(err);
		}
	}

	void TypeChecker::visitSimpleDeclWith(SimpleDeclWith *p) {
		p->exp_1->accept(this);
		auto type1 = typeStack.top();
		typeStack.pop();

		p->exp_2->accept(this);
		auto type2 = typeStack.top();
		typeStack.pop();

		string varName(p->ident_);
		auto elem = current->resolve(varName);
		if(sys->Numeric->isSuperclassOrEqual(type2)) {
			elem->updateType(type1);
			typeStack.push(sys->Unit);
		} else {
			ostringstream msg;
			msg << "Variable " << varName << " declaration has non-numeric  with clause";
			auto err = sys->makeError(msg.str());
			typeStack.push(err);
		}
	}

	void TypeChecker::visitTypedDeclWith(TypedDeclWith *p) {
		p->exp_1->accept(this);
		auto type1 = typeStack.top();
		typeStack.pop();

		p->exp_2->accept(this);
		auto type2 = typeStack.top();
		typeStack.pop();

		string varName(p->ident_);
		auto elem = current->resolve(varName);
		if(sys->Numeric->isSuperclassOrEqual(type2)) {
			if(elem->type()->isSuperclassOrEqual(type1)) {
				// Valid
				typeStack.push(sys->Unit);
			} else {
				ostringstream msg;
				msg << "Variable " << varName << " declared as " << elem->type()->symbol() << " but assigned in initialization as " << type1->symbol();
				auto err = sys->makeError(msg.str());
				typeStack.push(err);
			}
		} else {
			ostringstream msg;
			msg << "Variable " << varName << " declaration has non-numeric  with clause";
			auto err = sys->makeError(msg.str());
			typeStack.push(err);
		}
	}

	void TypeChecker::visitBareDecl(BareDecl *p) {
		// Ignored (type already decided by scope inferrer
	}

	void TypeChecker::visitEFuncDecl(EFuncDecl *p) {
		/*string varName(p->ident_);
		shared_ptr<DeclarationPoint> dp(new DeclDP(p));
		auto elem = make_shared<ScopeElement>(current,nullptr,dp);
		current->assign(elem,varName);

		auto s = current->children[p];
		current = s.get();
		p->listargument_->accept(this);
		p->statementblock_->accept(this);
		current = current->parent;*/
	}

	void TypeChecker::visitEFuncDeclWithType(EFuncDeclWithType *p) {
		/*string varName(p->ident_);
		p->type_->accept(this);
		auto retType = typeStack.top();
		typeStack.pop();
		int i = typeStack.size();
		p->listargument_->accept(this);
		vector<shared_ptr<shimmrType::Type>> argList;
		int end = typeStack.size();
		for(; i < end; i++) {
			argList.push_back(typeStack.top());
			typeStack.pop();
		}
		reverse(argList.begin(),argList.end());
		auto type = current->typeSystem->makeFunction(retType,argList);
		shared_ptr<DeclarationPoint> dp(new DeclDP(p));
		auto elem = make_shared<ScopeElement>(current,type,dp);
		current->assign(elem,varName);

		auto s = current->children[p];
		current = s.get();
		p->listargument_->accept(this);
		p->statementblock_->accept(this);
		current = current->parent;*/
	}

	void TypeChecker::visitForStatement(ForStatement *p) {
		/*p->exp_->accept(this);
		auto s = current->children[p];
		current = s.get();
		p->statementblock_->accept(this);
		current = current->parent;*/
	}

	void TypeChecker::visitIfStatement(IfStatement *p) {
		p->exp_->accept(this);
		auto s = current->children[p];
		current = s.get();
		p->statementblock_->accept(this);
		current = current->parent;
	}

	void TypeChecker::visitIfElseStatement(IfElseStatement *p) {
		p->exp_->accept(this);
		auto s = current->children[p];
		current = s.get();
		p->statementblock_->accept(this);
		current = current->parent;
		p->elseblock_->accept(this);
	}

	void TypeChecker::visitElseIfBlock(ElseIfBlock *p) {
		p->exp_->accept(this);
		auto s = current->children[p];
		current = s.get();
		p->statementblock_->accept(this);
		current = current->parent;

	}

	void TypeChecker::visitElseIf2Block(ElseIf2Block *p) {
		p->exp_->accept(this);
		auto s = current->children[p];
		current = s.get();
		p->statementblock_->accept(this);
		current = current->parent;
		p->elseblock_->accept(this);

	}

	void TypeChecker::visitElseBlockStat(ElseBlockStat *p) {
		auto s = current->children[p];
		current = s.get();
		p->statementblock_->accept(this);
		current = current->parent;
	}

	void TypeChecker::visitElseFailStat(ElseFailStat *p) {

	}

	void TypeChecker::visitSomeStatement(SomeStatement *p) {
		p->exp_->accept(this);
		auto s = current->children[p];
		current = s.get();
		p->statementblock_->accept(this);
		current = current->parent;
	}

	void TypeChecker::visitSomeElseStatement(SomeElseStatement *p) {
		p->exp_->accept(this);
		auto s = current->children[p];
		current = s.get();
		p->statementblock_->accept(this);
		current = current->parent;
		p->elseblock_->accept(this);

	}

	void TypeChecker::visitConditionalStatement(ConditionalStatement *p) {
		p->exp_1->accept(this);
		p->exp_2->accept(this);
	}

	void TypeChecker::visitAbsoluteStatement(AbsoluteStatement *p) {
		p->exp_->accept(this);
	}

	void TypeChecker::visitExpAsStatement(ExpAsStatement *p) {
		p->exp_->accept(this);

	}

	void TypeChecker::visitEOr(EOr *p) {
		p->exp_1->accept(this);
		p->exp_2->accept(this);

	}

	void TypeChecker::visitEAnd(EAnd *p) {
		
		p->exp_1->accept(this);
		p->exp_2->accept(this);
	}

	void TypeChecker::visitEEquals(EEquals *p) {
		
		p->exp_1->accept(this);
		p->exp_2->accept(this);
	}

	void TypeChecker::visitENEq(ENEq *p) {
		
		p->exp_1->accept(this);
		p->exp_2->accept(this);
	}

	void TypeChecker::visitELeq(ELeq *p) {
		
		p->exp_1->accept(this);
		p->exp_2->accept(this);
	}

	void TypeChecker::visitEGeq(EGeq *p) {
		
		p->exp_1->accept(this);
		p->exp_2->accept(this);
	}

	void TypeChecker::visitELessThan(ELessThan *p) {
		p->exp_1->accept(this);
		p->exp_2->accept(this);

	}

	void TypeChecker::visitEGreaterThan(EGreaterThan *p) {
		
		p->exp_1->accept(this);
		p->exp_2->accept(this);
	}

	void TypeChecker::visitEAdd(EAdd *p) {
		
		p->exp_1->accept(this);
		p->exp_2->accept(this);
	}

	void TypeChecker::visitESub(ESub *p) {
		
		p->exp_1->accept(this);
		p->exp_2->accept(this);
	}

	void TypeChecker::visitEMul(EMul *p) {
		
		p->exp_1->accept(this);
		p->exp_2->accept(this);
	}

	void TypeChecker::visitEDiv(EDiv *p) {
		
		p->exp_1->accept(this);
		p->exp_2->accept(this);
	}

	void TypeChecker::visitENot(ENot *p) {
		
		p->exp_->accept(this);
	}

	void TypeChecker::visitEIdent(EIdent *p) {

	}

	void TypeChecker::visitEFuncCall(EFuncCall *p) {
		p->listexp_->accept(this);
	}

	void TypeChecker::visitArgumentDef(ArgumentDef *p) {
		/*string varName(p->ident_);
		p->type_->accept(this);
		auto type = typeStack.top();
		typeStack.pop();
		shared_ptr<DeclarationPoint> dp(new ArgDP(p));
		auto elem = make_shared<ScopeElement>(current,type,dp);
		current->assign(elem,varName);*/
	}

	void TypeChecker::visitListArgument(ListArgument *p) {
		p->argument_->accept(this);
		if(p->listargument_ != nullptr) {
			p->listargument_->accept(this);
		}
	}

	void TypeChecker::visitEInt(EInt *p) {

	}

	void TypeChecker::visitEFloat(EFloat *p) {

	}

	void TypeChecker::visitEString(EString *p) {

	}

	void TypeChecker::visitListExp(ListExp *p) {
		p->exp_->accept(this);
		if(p->listexp_ != nullptr) {
			p->listexp_->accept(this);
		}
	}

	void TypeChecker::visitEType(EType *p) {
		auto type = current->typeSystem->get(p->ident_);
		if(type) {
			typeStack.push(type);
		} else {
			string errMsg("Undefined type: ");
			errMsg.append(p->ident_);
			typeStack.push(current->typeSystem->makeError(errMsg));
		}
	}

	void TypeChecker::visitVectorType(VectorType *p) {
		p->type_1->accept(this);
		auto cType = typeStack.top();
		typeStack.pop();
		if(!cType->isError()) {
			p->type_2->accept(this);
			auto iType = typeStack.top();
			typeStack.pop();
			if(!iType->isError()) {
				auto type = current->typeSystem->makeVector(cType,iType);
				typeStack.push(type);
			} else {
				typeStack.push(iType);
			}
		} else {
			typeStack.push(cType);
		}
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
			auto type = current->typeSystem->makeError(msg);
			typeStack.push(type);
		}
	}

	void TypeChecker::visitSetType(SetType *p) {
		p->listsettypeelem_->accept(this);
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
		p->settypeelem_->accept(this);
		if(p->listsettypeelem_ != nullptr) {
			p->listsettypeelem_->accept(this);
		}
	}

	void TypeChecker::visitVarAsLExpr(VarAsLExpr *p) {

	}

	void TypeChecker::visitVectorAsLExpr(VectorAsLExpr *p) {

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

	void TypeChecker::visitLExpr(LExpr *p) {

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