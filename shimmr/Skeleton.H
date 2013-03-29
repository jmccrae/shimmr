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
  void visitDecl(Decl* decl); /* abstract class */
  void visitSimpleDecl(SimpleDecl* simpledecl);
  void visitTypedDecl(TypedDecl* typeddecl);
  void visitSimpleDeclWith(SimpleDeclWith* simpledeclwith);
  void visitTypedDeclWith(TypedDeclWith* typeddeclwith);
  void visitBareDecl(BareDecl* baredecl);
  void visitElseBlock(ElseBlock* elseblock); /* abstract class */
  void visitElseIfBlock(ElseIfBlock* elseifblock);
  void visitElseIf2Block(ElseIf2Block* elseif2block);
  void visitElseBlockStat(ElseBlockStat* elseblockstat);
  void visitExp(Exp* exp); /* abstract class */
  void visitEFuncDecl(EFuncDecl* efuncdecl);
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
  void visitIntType(IntType* inttype);
  void visitFloatType(FloatType* floattype);
  void visitStringType(StringType* stringtype);
  void visitBoolType(BoolType* booltype);
  void visitAnythingType(AnythingType* anythingtype);
  void visitNothingType(NothingType* nothingtype);
  void visitUnitType(UnitType* unittype);
  void visitVectorType(VectorType* vectortype);


  void visitIdent(String s);
  void visitInteger(Integer i);
  void visitDouble(Double d);
  void visitChar(Char c);
  void visitString(String s);
};

#endif

