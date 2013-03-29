#include "scope_inferer.h"

#include <algorithm>

using namespace std;

namespace shimmr {

	ScopeInferer::ScopeInferer(void) : root(Scope::root())
	{
		current = root.get();
	}


	ScopeInferer::~ScopeInferer(void)
	{
	}

	shared_ptr<Scope> ScopeInferer::infer(Program *p) {
		ScopeInferer *inferer = new ScopeInferer();
		p->accept(inferer);
		auto rv = inferer->root;
		delete inferer;
		return rv;
	}


	void ScopeInferer::visitStatements(Statements *p) {
		ListStatement *ls = p->liststatement_;
		while(ls->liststatement_ != nullptr) {
			ls->statement_->accept(this);
			ls = ls->liststatement_;
		}
	}

	void ScopeInferer::visitStatementBlockStat(StatementBlockStat *p) {
		auto childScope = current->makeChildScope();
		current = childScope.get();
		ListStatement *ls = p->liststatement_;
		while(ls->liststatement_ != nullptr) {
			ls->statement_->accept(this);
			ls = ls->liststatement_;
		}
		current = childScope->parent;
	}

	void ScopeInferer::visitListStatement(ListStatement *p) {
		// Skipped
	}

	void ScopeInferer::visitDeclStat(DeclStat *p) {
		p->decl_->accept(this);
	}

	void ScopeInferer::visitSimpleDecl(SimpleDecl *p) {
		string varName(p->ident_);
		shared_ptr<DeclarationPoint> dp(new DeclDP(p));
		auto elem = make_shared<ScopeElement>(current,nullptr,dp);
		current->assign(elem,varName);
		p->exp_->accept(this);
	}

	void ScopeInferer::visitTypedDecl(TypedDecl *p) {
		string varName(p->ident_);
		p->type_->accept(this);
		auto type = typeStack.top();
		typeStack.pop();
		shared_ptr<DeclarationPoint> dp(new DeclDP(p));
		auto elem = make_shared<ScopeElement>(current,type,dp);
		current->assign(elem,varName);
		p->exp_->accept(this);
	}

	void ScopeInferer::visitSimpleDeclWith(SimpleDeclWith *p) {
		string varName(p->ident_);
		shared_ptr<DeclarationPoint> dp(new DeclDP(p));
		auto elem = make_shared<ScopeElement>(current,nullptr,dp);
		current->assign(elem,varName);
		p->exp_1->accept(this);
		p->exp_2->accept(this);
	}

	void ScopeInferer::visitTypedDeclWith(TypedDeclWith *p) {
		string varName(p->ident_);
		p->type_->accept(this);
		auto type = typeStack.top();
		typeStack.pop();
		shared_ptr<DeclarationPoint> dp(new DeclDP(p));
		auto elem = make_shared<ScopeElement>(current,type,dp);
		current->assign(elem,varName);
		p->exp_1->accept(this);
		p->exp_2->accept(this);
	}

	void ScopeInferer::visitBareDecl(BareDecl *p) {
		string varName(p->ident_);
		p->type_->accept(this);
		auto type = typeStack.top();
		typeStack.pop();
		shared_ptr<DeclarationPoint> dp(new DeclDP(p));
		auto elem = make_shared<ScopeElement>(current,type,dp);
		current->assign(elem,varName);
	}

	void ScopeInferer::visitEFuncDecl(EFuncDecl *p) {
		string varName(p->ident_);
		shared_ptr<DeclarationPoint> dp(new DeclDP(p));
		auto elem = make_shared<ScopeElement>(current,nullptr,dp);
		current->assign(elem,varName);

		auto s = current->makeChildScope();
		current = s.get();
		p->listargument_->accept(this);
		p->statementblock_->accept(this);
		current = current->parent;
	}

	void ScopeInferer::visitEFuncDeclWithType(EFuncDeclWithType *p) {
		string varName(p->ident_);
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

		auto s = current->makeChildScope();
		current = s.get();
		p->listargument_->accept(this);
		p->statementblock_->accept(this);
		current = current->parent;
	}

	void ScopeInferer::visitForStatement(ForStatement *p) {
		p->exp_->accept(this);
		auto s = current->makeChildScope();
		current = s.get();
		p->statementblock_->accept(this);
		current = current->parent;
	}

	void ScopeInferer::visitIfStatement(IfStatement *p) {
		p->exp_->accept(this);
		auto s = current->makeChildScope();
		current = s.get();
		p->statementblock_->accept(this);
		current = current->parent;
	}

	void ScopeInferer::visitIfElseStatement(IfElseStatement *p) {
		p->exp_->accept(this);
		auto s = current->makeChildScope();
		current = s.get();
		p->statementblock_->accept(this);
		current = current->parent;
		p->elseblock_->accept(this);
	}

	void ScopeInferer::visitElseIfBlock(ElseIfBlock *p) {
		p->exp_->accept(this);
		auto s = current->makeChildScope();
		current = s.get();
		p->statementblock_->accept(this);
		current = current->parent;

	}

	void ScopeInferer::visitElseIf2Block(ElseIf2Block *p) {
		p->exp_->accept(this);
		auto s = current->makeChildScope();
		current = s.get();
		p->statementblock_->accept(this);
		current = current->parent;
		p->elseblock_->accept(this);

	}

	void ScopeInferer::visitElseBlockStat(ElseBlockStat *p) {
		auto s = current->makeChildScope();
		current = s.get();
		p->statementblock_->accept(this);
		current = current->parent;
	}

	void ScopeInferer::visitElseFailStat(ElseFailStat *p) {

	}

	void ScopeInferer::visitSomeStatement(SomeStatement *p) {
		p->exp_->accept(this);
		auto s = current->makeChildScope();
		current = s.get();
		p->statementblock_->accept(this);
		current = current->parent;
	}

	void ScopeInferer::visitSomeElseStatement(SomeElseStatement *p) {
		p->exp_->accept(this);
		auto s = current->makeChildScope();
		current = s.get();
		p->statementblock_->accept(this);
		current = current->parent;
		p->elseblock_->accept(this);

	}

	void ScopeInferer::visitConditionalStatement(ConditionalStatement *p) {
		p->exp_1->accept(this);
		p->exp_2->accept(this);
	}

	void ScopeInferer::visitAbsoluteStatement(AbsoluteStatement *p) {
		p->exp_->accept(this);
	}

	void ScopeInferer::visitExpAsStatement(ExpAsStatement *p) {
		p->exp_->accept(this);

	}

	void ScopeInferer::visitEOr(EOr *p) {
		p->exp_1->accept(this);
		p->exp_2->accept(this);

	}

	void ScopeInferer::visitEAnd(EAnd *p) {
		
		p->exp_1->accept(this);
		p->exp_2->accept(this);
	}

	void ScopeInferer::visitEEquals(EEquals *p) {
		
		p->exp_1->accept(this);
		p->exp_2->accept(this);
	}

	void ScopeInferer::visitENEq(ENEq *p) {
		
		p->exp_1->accept(this);
		p->exp_2->accept(this);
	}

	void ScopeInferer::visitELeq(ELeq *p) {
		
		p->exp_1->accept(this);
		p->exp_2->accept(this);
	}

	void ScopeInferer::visitEGeq(EGeq *p) {
		
		p->exp_1->accept(this);
		p->exp_2->accept(this);
	}

	void ScopeInferer::visitELessThan(ELessThan *p) {
		p->exp_1->accept(this);
		p->exp_2->accept(this);

	}

	void ScopeInferer::visitEGreaterThan(EGreaterThan *p) {
		
		p->exp_1->accept(this);
		p->exp_2->accept(this);
	}

	void ScopeInferer::visitEAdd(EAdd *p) {
		
		p->exp_1->accept(this);
		p->exp_2->accept(this);
	}

	void ScopeInferer::visitESub(ESub *p) {
		
		p->exp_1->accept(this);
		p->exp_2->accept(this);
	}

	void ScopeInferer::visitEMul(EMul *p) {
		
		p->exp_1->accept(this);
		p->exp_2->accept(this);
	}

	void ScopeInferer::visitEDiv(EDiv *p) {
		
		p->exp_1->accept(this);
		p->exp_2->accept(this);
	}

	void ScopeInferer::visitENot(ENot *p) {
		
		p->exp_->accept(this);
	}

	void ScopeInferer::visitEIdent(EIdent *p) {

	}

	void ScopeInferer::visitEFuncCall(EFuncCall *p) {
		p->listexp_->accept(this);
	}

	void ScopeInferer::visitArgumentDef(ArgumentDef *p) {
		string varName(p->ident_);
		p->type_->accept(this);
		auto type = typeStack.top();
		typeStack.pop();
		shared_ptr<DeclarationPoint> dp(new ArgDP(p));
		auto elem = make_shared<ScopeElement>(current,type,dp);
		current->assign(elem,varName);
	}

	void ScopeInferer::visitListArgument(ListArgument *p) {
		p->argument_->accept(this);
		if(p->listargument_ != nullptr) {
			p->listargument_->accept(this);
		}
	}

	void ScopeInferer::visitEInt(EInt *p) {

	}

	void ScopeInferer::visitEFloat(EFloat *p) {

	}

	void ScopeInferer::visitEString(EString *p) {

	}

	void ScopeInferer::visitListExp(ListExp *p) {
		p->exp_->accept(this);
		if(p->listexp_ != nullptr) {
			p->listexp_->accept(this);
		}
	}

	void ScopeInferer::visitEType(EType *p) {
		auto type = current->typeSystem->get(p->ident_);
		if(type) {
			typeStack.push(type);
		} else {
			string errMsg("Undefined type: ");
			errMsg.append(p->ident_);
			typeStack.push(current->typeSystem->makeError(errMsg));
		}
	}

	void ScopeInferer::visitVectorType(VectorType *p) {
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

	void ScopeInferer::visitRangeType(RangeType *p) {
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

	void ScopeInferer::visitSetType(SetType *p) {
		p->listsettypeelem_->accept(this);
	}

	void ScopeInferer::visitEIntSTE(EIntSTE *p) {
		auto ste = make_shared<shimmrType::IntTypeValue>(p->integer_);
		typeValueStack.push(ste);
	}

	void ScopeInferer::visitEFloatSTE(EFloatSTE *p) {
		auto ste = make_shared<shimmrType::FloatTypeValue>(p->double_);
		typeValueStack.push(ste);
	}

	void ScopeInferer::visitEStringSTE(EStringSTE *p) {
		string val(p->string_);
		auto ste = make_shared<shimmrType::StringTypeValue>(val);
		typeValueStack.push(ste);
	}

	void ScopeInferer::visitListSetTypeElem(ListSetTypeElem *p) {
		p->settypeelem_->accept(this);
		if(p->listsettypeelem_ != nullptr) {
			p->listsettypeelem_->accept(this);
		}
	}

	void ScopeInferer::visitVarAsLExpr(VarAsLExpr *p) {

	}

	void ScopeInferer::visitVectorAsLExpr(VectorAsLExpr *p) {

	}

	void ScopeInferer::visitProgram(Program *p) {

	}

	void ScopeInferer::visitStatementBlock(StatementBlock *p) {

	}

	void ScopeInferer::visitStatement(Statement *p) {

	}

	void ScopeInferer::visitDecl(Decl *p) {

	}

	void ScopeInferer::visitElseBlock(ElseBlock *p) {

	}

	void ScopeInferer::visitExp(Exp *p) {

	}

	void ScopeInferer::visitArgument(Argument *p) {

	}

	void ScopeInferer::visitType(Type *p) {

	}

	void ScopeInferer::visitSetTypeElem(SetTypeElem *p) {

	}

	void ScopeInferer::visitLExpr(LExpr *p) {

	}


	void ScopeInferer::visitInteger(Integer i) {

	}

	void ScopeInferer::visitDouble(Double d) {

	}

	void ScopeInferer::visitChar(Char c) {

	}

	void ScopeInferer::visitString(String s) {

	}
}