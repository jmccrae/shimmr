#ifndef SKELETON_HEADER
#define SKELETON_HEADER
/* You might want to change the above name. */

#include "Absyn.H"

class Skeleton : public Visitor
{
public:
  void visitProgram(Program* p);
  void visitStatementBlock(StatementBlock* p);
  void visitStatement(Statement* p);
  void visitDecl(Decl* p);
  void visitElseBlock(ElseBlock* p);
  void visitExp(Exp* p);
  void visitArgument(Argument* p);
  void visitType(Type* p);
  void visitSetTypeElem(SetTypeElem* p);
  void visitStatements(Statements* p);
  void visitStatementBlockStat(StatementBlockStat* p);
  void visitDeclStat(DeclStat* p);
  void visitSimpleDecl(SimpleDecl* p);
  void visitTypedDecl(TypedDecl* p);
  void visitSimpleDeclWith(SimpleDeclWith* p);
  void visitTypedDeclWith(TypedDeclWith* p);
  void visitBareDecl(BareDecl* p);
  void visitEFuncDecl(EFuncDecl* p);
  void visitEFuncDeclWithType(EFuncDeclWithType* p);
  void visitForStatement(ForStatement* p);
  void visitIfStatement(IfStatement* p);
  void visitIfElseStatement(IfElseStatement* p);
  void visitElseIfBlock(ElseIfBlock* p);
  void visitElseIf2Block(ElseIf2Block* p);
  void visitElseBlockStat(ElseBlockStat* p);
  void visitElseFailStat(ElseFailStat* p);
  void visitSomeStatement(SomeStatement* p);
  void visitSomeElseStatement(SomeElseStatement* p);
  void visitConditionalStatement(ConditionalStatement* p);
  void visitExpAsStatement(ExpAsStatement* p);
  void visitEOr(EOr* p);
  void visitEAnd(EAnd* p);
  void visitEEquals(EEquals* p);
  void visitENEq(ENEq* p);
  void visitELeq(ELeq* p);
  void visitEGeq(EGeq* p);
  void visitELessThan(ELessThan* p);
  void visitEGreaterThan(EGreaterThan* p);
  void visitEAdd(EAdd* p);
  void visitESub(ESub* p);
  void visitEMul(EMul* p);
  void visitEDiv(EDiv* p);
  void visitENot(ENot* p);
  void visitEIdent(EIdent* p);
  void visitEVector(EVector* p);
  void visitEFuncCall(EFuncCall* p);
  void visitArgumentDef(ArgumentDef* p);
  void visitERange(ERange* p);
  void visitESet(ESet* p);
  void visitEInt(EInt* p);
  void visitEFloat(EFloat* p);
  void visitEString(EString* p);
  void visitEType(EType* p);
  void visitVectorType(VectorType* p);
  void visitRangeType(RangeType* p);
  void visitSetType(SetType* p);
  void visitEIntSTE(EIntSTE* p);
  void visitEFloatSTE(EFloatSTE* p);
  void visitEStringSTE(EStringSTE* p);
  void visitListStatement(ListStatement* p);
  void visitListArgument(ListArgument* p);
  void visitListExp(ListExp* p);
  void visitListSetTypeElem(ListSetTypeElem* p);

  void visitInteger(Integer x);
  void visitChar(Char x);
  void visitDouble(Double x);
  void visitString(String x);
  void visitIdent(Ident x);

};

#endif
