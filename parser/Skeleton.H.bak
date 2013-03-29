#ifndef SKELETON_HEADER
#define SKELETON_HEADER
/* You might want to change the above name. */

#include "Absyn.H"

class Skeleton : public Visitor
{
 public:

  void visitProgram(Program* program); /* abstract class */
  void visitStatements(Statements* statements);
  void visitStatementBlock(StatementBlock* statementblock); /* abstract class */
  void visitStatementBlockStat(StatementBlockStat* statementblockstat);
  void visitListStatement(ListStatement* liststatement);  void visitStatement(Statement* statement); /* abstract class */
  void visitDeclStat(DeclStat* declstat);
  void visitForStatement(ForStatement* forstatement);
  void visitIfStatement(IfStatement* ifstatement);
  void visitIfElseStatement(IfElseStatement* ifelsestatement);
  void visitSomeStatement(SomeStatement* somestatement);
  void visitSomeElseStatement(SomeElseStatement* someelsestatement);
  void visitConditionalStatement(ConditionalStatement* conditionalstatement);
  void visitAbsoluteStatement(AbsoluteStatement* absolutestatement);
  void visitExpAsStatement(ExpAsStatement* expasstatement);
  void visitDecl(Decl* decl); /* abstract class */
  void visitSimpleDecl(SimpleDecl* simpledecl);
  void visitTypedDecl(TypedDecl* typeddecl);
  void visitSimpleDeclWith(SimpleDeclWith* simpledeclwith);
  void visitTypedDeclWith(TypedDeclWith* typeddeclwith);
  void visitBareDecl(BareDecl* baredecl);
  void visitEFuncDecl(EFuncDecl* efuncdecl);
  void visitEFuncDeclWithType(EFuncDeclWithType* efuncdeclwithtype);
  void visitElseBlock(ElseBlock* elseblock); /* abstract class */
  void visitElseIfBlock(ElseIfBlock* elseifblock);
  void visitElseIf2Block(ElseIf2Block* elseif2block);
  void visitElseBlockStat(ElseBlockStat* elseblockstat);
  void visitElseFailStat(ElseFailStat* elsefailstat);
  void visitExp(Exp* exp); /* abstract class */
  void visitEOr(EOr* eor);
  void visitEAnd(EAnd* eand);
  void visitEEquals(EEquals* eequals);
  void visitENEq(ENEq* eneq);
  void visitELeq(ELeq* eleq);
  void visitEGeq(EGeq* egeq);
  void visitELessThan(ELessThan* elessthan);
  void visitEGreaterThan(EGreaterThan* egreaterthan);
  void visitEAdd(EAdd* eadd);
  void visitESub(ESub* esub);
  void visitEMul(EMul* emul);
  void visitEDiv(EDiv* ediv);
  void visitENot(ENot* enot);
  void visitEIdent(EIdent* eident);
  void visitEFuncCall(EFuncCall* efunccall);
  void visitEInt(EInt* eint);
  void visitEFloat(EFloat* efloat);
  void visitEString(EString* estring);
  void visitArgument(Argument* argument); /* abstract class */
  void visitArgumentDef(ArgumentDef* argumentdef);
  void visitListArgument(ListArgument* listargument);  void visitListExp(ListExp* listexp);  void visitType(Type* type); /* abstract class */
  void visitEType(EType* etype);
  void visitVectorType(VectorType* vectortype);
  void visitRangeType(RangeType* rangetype);
  void visitSetType(SetType* settype);
  void visitSetTypeElem(SetTypeElem* settypeelem); /* abstract class */
  void visitEIntSTE(EIntSTE* eintste);
  void visitEFloatSTE(EFloatSTE* efloatste);
  void visitEStringSTE(EStringSTE* estringste);
  void visitListSetTypeElem(ListSetTypeElem* listsettypeelem);  void visitLExpr(LExpr* lexpr); /* abstract class */
  void visitVarAsLExpr(VarAsLExpr* varaslexpr);
  void visitVectorAsLExpr(VectorAsLExpr* vectoraslexpr);


  void visitIdent(String s);
  void visitInteger(Integer i);
  void visitDouble(Double d);
  void visitChar(Char c);
  void visitString(String s);
};

#endif

