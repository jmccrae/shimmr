#include "scope_inferrer.h"

#include <algorithm>

using namespace std;

namespace shimmr {

	ScopeInferrer::ScopeInferrer(void) : root(Scope::root())
	{
		current = root.get();
	}


	ScopeInferrer::~ScopeInferrer(void)
	{
	}

	shared_ptr<Scope> ScopeInferrer::infer(Program *p) {
		ScopeInferrer *inferrer = new ScopeInferrer();
		p->accept(inferrer);
		auto rv = inferrer->root;
		delete inferrer;
		return rv;
	}


	void ScopeInferrer::visitStatements(Statements *p) {
		ListStatement *ls = p->liststatement_;
		while(ls != nullptr) {
			ls->statement_->accept(this);
			ls = ls->liststatement_;
		}
	}

	void ScopeInferrer::visitStatementBlockStat(StatementBlockStat *p) {
		auto childScope = current->makeChildScope(p);
		current = childScope.get();
		ListStatement *ls = p->liststatement_;
		while(ls != nullptr) {
			ls->statement_->accept(this);
			ls = ls->liststatement_;
		}
		current = childScope->parent;
	}

	void ScopeInferrer::visitListStatement(ListStatement *p) {
		// Skipped
	}

	void ScopeInferrer::visitDeclStat(DeclStat *p) {
		p->decl_->accept(this);
	}

	void ScopeInferrer::visitSimpleDecl(SimpleDecl *p) {
		string varName(p->ident_);
		auto elem = make_shared<ScopeElement>(current,nullptr,p);
		current->assign(elem,varName);
		p->exp_->accept(this);
	}

	void ScopeInferrer::visitTypedDecl(TypedDecl *p) {
		string varName(p->ident_);
		p->type_->accept(this);
		auto type = typeStack.top();
		typeStack.pop();
		auto elem = make_shared<ScopeElement>(current,type,p);
		current->assign(elem,varName);
		p->exp_->accept(this);
	}

	void ScopeInferrer::visitSimpleDeclWith(SimpleDeclWith *p) {
		string varName(p->ident_);
		auto elem = make_shared<ScopeElement>(current,nullptr,p);
		current->assign(elem,varName);
		p->exp_1->accept(this);
		p->exp_2->accept(this);
	}

	void ScopeInferrer::visitTypedDeclWith(TypedDeclWith *p) {
		string varName(p->ident_);
		p->type_->accept(this);
		auto type = typeStack.top();
		typeStack.pop();
		auto elem = make_shared<ScopeElement>(current,type,p);
		current->assign(elem,varName);
		p->exp_1->accept(this);
		p->exp_2->accept(this);
	}

	void ScopeInferrer::visitBareDecl(BareDecl *p) {
		string varName(p->ident_);
		p->type_->accept(this);
		auto type = typeStack.top();
		typeStack.pop();
		auto elem = make_shared<ScopeElement>(current,type,p);
		current->assign(elem,varName);
	}

	void ScopeInferrer::visitEFuncDecl(EFuncDecl *p) {
		string varName(p->ident_);
		auto elem = make_shared<ScopeElement>(current,nullptr,p);
		current->assign(elem,varName);

		auto s = current->makeChildScope(p);
		current = s.get();
		p->listargument_->accept(this);
		p->statementblock_->accept(this);
		current = current->parent;
	}

	void ScopeInferrer::visitEFuncDeclWithType(EFuncDeclWithType *p) {
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
		auto elem = make_shared<ScopeElement>(current,type,p);
		current->assign(elem,varName);

		auto s = current->makeChildScope(p);
		current = s.get();
		p->listargument_->accept(this);
		p->statementblock_->accept(this);
		current = current->parent;
	}

	void ScopeInferrer::visitForStatement(ForStatement *p) {
		p->exp_->accept(this);
		auto s = current->makeChildScope(p);
		current = s.get();
		p->statementblock_->accept(this);
		current = current->parent;
	}

	void ScopeInferrer::visitIfStatement(IfStatement *p) {
		p->exp_->accept(this);
		auto s = current->makeChildScope(p);
		current = s.get();
		p->statementblock_->accept(this);
		current = current->parent;
	}

	void ScopeInferrer::visitIfElseStatement(IfElseStatement *p) {
		p->exp_->accept(this);
		auto s = current->makeChildScope(p);
		current = s.get();
		p->statementblock_->accept(this);
		current = current->parent;
		p->elseblock_->accept(this);
	}

	void ScopeInferrer::visitElseIfBlock(ElseIfBlock *p) {
		p->exp_->accept(this);
		auto s = current->makeChildScope(p);
		current = s.get();
		p->statementblock_->accept(this);
		current = current->parent;

	}

	void ScopeInferrer::visitElseIf2Block(ElseIf2Block *p) {
		p->exp_->accept(this);
		auto s = current->makeChildScope(p);
		current = s.get();
		p->statementblock_->accept(this);
		current = current->parent;
		p->elseblock_->accept(this);

	}

	void ScopeInferrer::visitElseBlockStat(ElseBlockStat *p) {
		auto s = current->makeChildScope(p);
		current = s.get();
		p->statementblock_->accept(this);
		current = current->parent;
	}

	void ScopeInferrer::visitElseFailStat(ElseFailStat *p) {

	}

	void ScopeInferrer::visitSomeStatement(SomeStatement *p) {
		p->exp_->accept(this);
		auto s = current->makeChildScope(p);
		current = s.get();
		p->statementblock_->accept(this);
		current = current->parent;
	}

	void ScopeInferrer::visitSomeElseStatement(SomeElseStatement *p) {
		p->exp_->accept(this);
		auto s = current->makeChildScope(p);
		current = s.get();
		p->statementblock_->accept(this);
		current = current->parent;
		p->elseblock_->accept(this);

	}

	void ScopeInferrer::visitConditionalStatement(ConditionalStatement *p) {
		p->exp_1->accept(this);
		p->exp_2->accept(this);
	}

	void ScopeInferrer::visitAbsoluteStatement(AbsoluteStatement *p) {
		p->exp_->accept(this);
	}

	void ScopeInferrer::visitExpAsStatement(ExpAsStatement *p) {
		p->exp_->accept(this);

	}

	void ScopeInferrer::visitEOr(EOr *p) {
		p->exp_1->accept(this);
		p->exp_2->accept(this);

	}

	void ScopeInferrer::visitEAnd(EAnd *p) {
		
		p->exp_1->accept(this);
		p->exp_2->accept(this);
	}

	void ScopeInferrer::visitEEquals(EEquals *p) {
		
		p->exp_1->accept(this);
		p->exp_2->accept(this);
	}

	void ScopeInferrer::visitENEq(ENEq *p) {
		
		p->exp_1->accept(this);
		p->exp_2->accept(this);
	}

	void ScopeInferrer::visitELeq(ELeq *p) {
		
		p->exp_1->accept(this);
		p->exp_2->accept(this);
	}

	void ScopeInferrer::visitEGeq(EGeq *p) {
		
		p->exp_1->accept(this);
		p->exp_2->accept(this);
	}

	void ScopeInferrer::visitELessThan(ELessThan *p) {
		p->exp_1->accept(this);
		p->exp_2->accept(this);

	}

	void ScopeInferrer::visitEGreaterThan(EGreaterThan *p) {
		
		p->exp_1->accept(this);
		p->exp_2->accept(this);
	}

	void ScopeInferrer::visitEAdd(EAdd *p) {
		
		p->exp_1->accept(this);
		p->exp_2->accept(this);
	}

	void ScopeInferrer::visitESub(ESub *p) {
		
		p->exp_1->accept(this);
		p->exp_2->accept(this);
	}

	void ScopeInferrer::visitEMul(EMul *p) {
		
		p->exp_1->accept(this);
		p->exp_2->accept(this);
	}

	void ScopeInferrer::visitEDiv(EDiv *p) {
		
		p->exp_1->accept(this);
		p->exp_2->accept(this);
	}

	void ScopeInferrer::visitENot(ENot *p) {
		
		p->exp_->accept(this);
	}

	void ScopeInferrer::visitEIdent(EIdent *p) {

	}

	void ScopeInferrer::visitEFuncCall(EFuncCall *p) {
		p->listexp_->accept(this);
	}

	void ScopeInferrer::visitArgumentDef(ArgumentDef *p) {
		string varName(p->ident_);
		p->type_->accept(this);
		auto type = typeStack.top();
		typeStack.pop();
		auto elem = make_shared<ScopeElement>(current,type,p);
		current->assign(elem,varName);
	}

	void ScopeInferrer::visitListArgument(ListArgument *p) {
		p->argument_->accept(this);
		if(p->listargument_ != nullptr) {
			p->listargument_->accept(this);
		}
	}

	void ScopeInferrer::visitEInt(EInt *p) {

	}

	void ScopeInferrer::visitEFloat(EFloat *p) {

	}

	void ScopeInferrer::visitEString(EString *p) {

	}

	void ScopeInferrer::visitListExp(ListExp *p) {
		p->exp_->accept(this);
		if(p->listexp_ != nullptr) {
			p->listexp_->accept(this);
		}
	}

	void ScopeInferrer::visitEType(EType *p) {
		auto type = current->typeSystem->get(p->ident_);
		if(type) {
			typeStack.push(type);
		} else {
			string errMsg("Undefined type: ");
			errMsg.append(p->ident_);
			typeStack.push(current->typeSystem->makeError(errMsg));
		}
	}

	void ScopeInferrer::visitVectorType(VectorType *p) {
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

	void ScopeInferrer::visitRangeType(RangeType *p) {
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

	void ScopeInferrer::visitSetType(SetType *p) {
		p->listsettypeelem_->accept(this);
	}

	void ScopeInferrer::visitEIntSTE(EIntSTE *p) {
		auto ste = make_shared<shimmrType::IntTypeValue>(p->integer_);
		typeValueStack.push(ste);
	}

	void ScopeInferrer::visitEFloatSTE(EFloatSTE *p) {
		auto ste = make_shared<shimmrType::FloatTypeValue>(p->double_);
		typeValueStack.push(ste);
	}

	void ScopeInferrer::visitEStringSTE(EStringSTE *p) {
		string val(p->string_);
		auto ste = make_shared<shimmrType::StringTypeValue>(val);
		typeValueStack.push(ste);
	}

	void ScopeInferrer::visitListSetTypeElem(ListSetTypeElem *p) {
		p->settypeelem_->accept(this);
		if(p->listsettypeelem_ != nullptr) {
			p->listsettypeelem_->accept(this);
		}
	}

	void ScopeInferrer::visitVarAsLExpr(VarAsLExpr *p) {

	}

	void ScopeInferrer::visitVectorAsLExpr(VectorAsLExpr *p) {

	}

	void ScopeInferrer::visitProgram(Program *p) {

	}

	void ScopeInferrer::visitStatementBlock(StatementBlock *p) {

	}

	void ScopeInferrer::visitStatement(Statement *p) {

	}

	void ScopeInferrer::visitDecl(Decl *p) {

	}

	void ScopeInferrer::visitElseBlock(ElseBlock *p) {

	}

	void ScopeInferrer::visitExp(Exp *p) {

	}

	void ScopeInferrer::visitArgument(Argument *p) {

	}

	void ScopeInferrer::visitType(Type *p) {

	}

	void ScopeInferrer::visitSetTypeElem(SetTypeElem *p) {

	}

	void ScopeInferrer::visitLExpr(LExpr *p) {

	}


	void ScopeInferrer::visitInteger(Integer i) {

	}

	void ScopeInferrer::visitDouble(Double d) {

	}

	void ScopeInferrer::visitChar(Char c) {

	}

	void ScopeInferrer::visitString(String s) {

	}
}