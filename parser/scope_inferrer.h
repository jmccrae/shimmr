#pragma once

#include "scope.h"

#include <stack>

namespace shimmr {
	class ScopeInferrer : public Visitor
	{
	private:
		std::shared_ptr<Scope> root;
		Scope *current;
		std::stack<std::shared_ptr<shimmr::type::Type>> typeStack;
		std::stack<std::shared_ptr<shimmr::type::TypeValue>> typeValueStack;
		ScopeInferrer(void);
	public:
		~ScopeInferrer(void);
		static std::shared_ptr<Scope> infer(Visitable *p);

		virtual void visitStatements(Statements *p);
		virtual void visitStatementBlockStat(StatementBlockStat *p);
		virtual void visitListStatement(ListStatement *p);
		virtual void visitDeclStat(DeclStat *p);
		virtual void visitSimpleDecl(SimpleDecl *p);
		virtual void visitTypedDecl(TypedDecl *p);
		virtual void visitSimpleDeclWith(SimpleDeclWith *p);
		virtual void visitTypedDeclWith(TypedDeclWith *p);
		virtual void visitBareDecl(BareDecl *p);
		virtual void visitEFuncDecl(EFuncDecl *p);
		virtual void visitEFuncDeclWithType(EFuncDeclWithType *p);
		virtual void visitForStatement(ForStatement *p);
		virtual void visitIfStatement(IfStatement *p);
		virtual void visitIfElseStatement(IfElseStatement *p);
		virtual void visitElseIfBlock(ElseIfBlock *p);
		virtual void visitElseIf2Block(ElseIf2Block *p);
		virtual void visitElseBlockStat(ElseBlockStat *p);
		virtual void visitElseFailStat(ElseFailStat *p);
		virtual void visitSomeStatement(SomeStatement *p);
		virtual void visitSomeElseStatement(SomeElseStatement *p);
		virtual void visitConditionalStatement(ConditionalStatement *p);
		virtual void visitExpAsStatement(ExpAsStatement *p);
		virtual void visitEOr(EOr *p);
		virtual void visitEAnd(EAnd *p);
		virtual void visitEEquals(EEquals *p);
		virtual void visitENEq(ENEq *p);
		virtual void visitELeq(ELeq *p);
		virtual void visitEGeq(EGeq *p);
		virtual void visitELessThan(ELessThan *p);
		virtual void visitEGreaterThan(EGreaterThan *p);
		virtual void visitEAdd(EAdd *p);
		virtual void visitESub(ESub *p);
		virtual void visitEMul(EMul *p);
		virtual void visitEDiv(EDiv *p);
		virtual void visitENot(ENot *p);
		virtual void visitEIdent(EIdent *p);
		virtual void visitEFuncCall(EFuncCall *p);
		virtual void visitArgumentDef(ArgumentDef *p);
		virtual void visitERange(ERange *p);
		virtual void visitESet(ESet *p);
		virtual void visitListArgument(ListArgument *p);
		virtual void visitEInt(EInt *p);
		virtual void visitEFloat(EFloat *p);
		virtual void visitEString(EString *p);
		virtual void visitListExp(ListExp *p);
		virtual void visitEType(EType *p);
		virtual void visitVectorType(VectorType *p);
		virtual void visitRangeType(RangeType *p);
		virtual void visitSetType(SetType *p);
		virtual void visitEIntSTE(EIntSTE *p);
		virtual void visitEFloatSTE(EFloatSTE *p);
		virtual void visitEStringSTE(EStringSTE *p);
		virtual void visitListSetTypeElem(ListSetTypeElem *p);
		virtual void visitProgram(Program *p);
		virtual void visitStatementBlock(StatementBlock *p);
		virtual void visitStatement(Statement *p);
		virtual void visitDecl(Decl *p);
		virtual void visitElseBlock(ElseBlock *p);
		virtual void visitExp(Exp *p);
		virtual void visitArgument(Argument *p);
		virtual void visitType(Type *p);
		virtual void visitSetTypeElem(SetTypeElem *p);
		virtual void visitIdent(Ident);
		virtual void visitEVector(EVector *p);

		virtual void visitInteger(Integer i);
		virtual void visitDouble(Double d);
		virtual void visitChar(Char c);
		virtual void visitString(String s);

	};
}
