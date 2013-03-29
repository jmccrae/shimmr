#ifndef PRINTER_HEADER
#define PRINTER_HEADER

#include "Absyn.H"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Certain applications may improve performance by changing the buffer size */
#define BUFFER_INITIAL 2000
/* You may wish to change _L_PAREN or _R_PAREN */
#define _L_PAREN '('
#define _R_PAREN ')'

class PrintAbsyn : public Visitor
{
 protected:
  int _n_, _i_;
  /* The following are simple heuristics for rendering terminals */
  /* You may wish to change them */
  void render(Char c);
  void render(String s);
  void indent(void);
  void backup(void);
 public:
  PrintAbsyn(void);
  ~PrintAbsyn(void);
  char* print(Visitable* v);

  void visitProgram(Program *p); /* abstract class */
  void visitStatements(Statements *p);
  void visitStatementBlock(StatementBlock *p); /* abstract class */
  void visitStatementBlockStat(StatementBlockStat *p);
  void visitListStatement(ListStatement* p);
  void visitStatement(Statement *p); /* abstract class */
  void visitDeclStat(DeclStat *p);
  void visitForStatement(ForStatement *p);
  void visitIfStatement(IfStatement *p);
  void visitIfElseStatement(IfElseStatement *p);
  void visitSomeStatement(SomeStatement *p);
  void visitSomeElseStatement(SomeElseStatement *p);
  void visitConditionalStatement(ConditionalStatement *p);
  void visitAbsoluteStatement(AbsoluteStatement *p);
  void visitExpAsStatement(ExpAsStatement *p);
  void visitDecl(Decl *p); /* abstract class */
  void visitSimpleDecl(SimpleDecl *p);
  void visitTypedDecl(TypedDecl *p);
  void visitSimpleDeclWith(SimpleDeclWith *p);
  void visitTypedDeclWith(TypedDeclWith *p);
  void visitBareDecl(BareDecl *p);
  void visitEFuncDecl(EFuncDecl *p);
  void visitEFuncDeclWithType(EFuncDeclWithType *p);
  void visitElseBlock(ElseBlock *p); /* abstract class */
  void visitElseIfBlock(ElseIfBlock *p);
  void visitElseIf2Block(ElseIf2Block *p);
  void visitElseBlockStat(ElseBlockStat *p);
  void visitElseFailStat(ElseFailStat *p);
  void visitExp(Exp *p); /* abstract class */
  void visitEOr(EOr *p);
  void visitEAnd(EAnd *p);
  void visitEEquals(EEquals *p);
  void visitENEq(ENEq *p);
  void visitELeq(ELeq *p);
  void visitEGeq(EGeq *p);
  void visitELessThan(ELessThan *p);
  void visitEGreaterThan(EGreaterThan *p);
  void visitEAdd(EAdd *p);
  void visitESub(ESub *p);
  void visitEMul(EMul *p);
  void visitEDiv(EDiv *p);
  void visitENot(ENot *p);
  void visitEIdent(EIdent *p);
  void visitEFuncCall(EFuncCall *p);
  void visitEInt(EInt *p);
  void visitEFloat(EFloat *p);
  void visitEString(EString *p);
  void visitArgument(Argument *p); /* abstract class */
  void visitArgumentDef(ArgumentDef *p);
  void visitListArgument(ListArgument* p);
  void visitListExp(ListExp* p);
  void visitType(Type *p); /* abstract class */
  void visitEType(EType *p);
  void visitVectorType(VectorType *p);
  void visitRangeType(RangeType *p);
  void visitSetType(SetType *p);
  void visitSetTypeElem(SetTypeElem *p); /* abstract class */
  void visitEIntSTE(EIntSTE *p);
  void visitEFloatSTE(EFloatSTE *p);
  void visitEStringSTE(EStringSTE *p);
  void visitListSetTypeElem(ListSetTypeElem* p);
  void visitLExpr(LExpr *p); /* abstract class */
  void visitVarAsLExpr(VarAsLExpr *p);
  void visitVectorAsLExpr(VectorAsLExpr *p);

  void visitInteger(Integer i);
  void visitDouble(Double d);
  void visitChar(Char c);
  void visitString(String s);
  void visitIdent(String s);
 protected:
  void inline bufAppend(const char* s)
  {
    int len = strlen(s);
    while (cur_ + len > buf_size)
    {
      buf_size *= 2; /* Double the buffer size */
      resizeBuffer();
    }
    for(int n = 0; n < len; n++)
    {
      buf_[cur_ + n] = s[n];
    }
    cur_ += len;
    buf_[cur_] = 0;
  }
  void inline bufAppend(const char c)
  {
    if (cur_ == buf_size)
    {
      buf_size *= 2; /* Double the buffer size */
      resizeBuffer();
    }
    buf_[cur_] = c;
    cur_++;
    buf_[cur_] = 0;
  }
  void inline bufReset(void)
  {
    cur_ = 0;
    buf_size = BUFFER_INITIAL;
    resizeBuffer();
    memset(buf_, 0, buf_size);
  }
  void inline resizeBuffer(void)
  {
    char* temp = (char*) malloc(buf_size);
    if (!temp)
    {
      fprintf(stderr, "Error: Out of memory while attempting to grow buffer!\n");
      exit(1);
    }
    if (buf_)
    {
      strcpy(temp, buf_);
      free(buf_);
    }
    buf_ = temp;
  }
  char *buf_;
  int cur_, buf_size;
};



class ShowAbsyn : public Visitor
{
 public:
  ShowAbsyn(void);
  ~ShowAbsyn(void);
  char* show(Visitable* v);

  void visitProgram(Program *p); /* abstract class */
  void visitStatements(Statements *p);
  void visitStatementBlock(StatementBlock *p); /* abstract class */
  void visitStatementBlockStat(StatementBlockStat *p);
  void visitListStatement(ListStatement* p);
  void visitStatement(Statement *p); /* abstract class */
  void visitDeclStat(DeclStat *p);
  void visitForStatement(ForStatement *p);
  void visitIfStatement(IfStatement *p);
  void visitIfElseStatement(IfElseStatement *p);
  void visitSomeStatement(SomeStatement *p);
  void visitSomeElseStatement(SomeElseStatement *p);
  void visitConditionalStatement(ConditionalStatement *p);
  void visitAbsoluteStatement(AbsoluteStatement *p);
  void visitExpAsStatement(ExpAsStatement *p);
  void visitDecl(Decl *p); /* abstract class */
  void visitSimpleDecl(SimpleDecl *p);
  void visitTypedDecl(TypedDecl *p);
  void visitSimpleDeclWith(SimpleDeclWith *p);
  void visitTypedDeclWith(TypedDeclWith *p);
  void visitBareDecl(BareDecl *p);
  void visitEFuncDecl(EFuncDecl *p);
  void visitEFuncDeclWithType(EFuncDeclWithType *p);
  void visitElseBlock(ElseBlock *p); /* abstract class */
  void visitElseIfBlock(ElseIfBlock *p);
  void visitElseIf2Block(ElseIf2Block *p);
  void visitElseBlockStat(ElseBlockStat *p);
  void visitElseFailStat(ElseFailStat *p);
  void visitExp(Exp *p); /* abstract class */
  void visitEOr(EOr *p);
  void visitEAnd(EAnd *p);
  void visitEEquals(EEquals *p);
  void visitENEq(ENEq *p);
  void visitELeq(ELeq *p);
  void visitEGeq(EGeq *p);
  void visitELessThan(ELessThan *p);
  void visitEGreaterThan(EGreaterThan *p);
  void visitEAdd(EAdd *p);
  void visitESub(ESub *p);
  void visitEMul(EMul *p);
  void visitEDiv(EDiv *p);
  void visitENot(ENot *p);
  void visitEIdent(EIdent *p);
  void visitEFuncCall(EFuncCall *p);
  void visitEInt(EInt *p);
  void visitEFloat(EFloat *p);
  void visitEString(EString *p);
  void visitArgument(Argument *p); /* abstract class */
  void visitArgumentDef(ArgumentDef *p);
  void visitListArgument(ListArgument* p);
  void visitListExp(ListExp* p);
  void visitType(Type *p); /* abstract class */
  void visitEType(EType *p);
  void visitVectorType(VectorType *p);
  void visitRangeType(RangeType *p);
  void visitSetType(SetType *p);
  void visitSetTypeElem(SetTypeElem *p); /* abstract class */
  void visitEIntSTE(EIntSTE *p);
  void visitEFloatSTE(EFloatSTE *p);
  void visitEStringSTE(EStringSTE *p);
  void visitListSetTypeElem(ListSetTypeElem* p);
  void visitLExpr(LExpr *p); /* abstract class */
  void visitVarAsLExpr(VarAsLExpr *p);
  void visitVectorAsLExpr(VectorAsLExpr *p);

  void visitInteger(Integer i);
  void visitDouble(Double d);
  void visitChar(Char c);
  void visitString(String s);
  void visitIdent(String s);
 protected:
  void inline bufAppend(const char* s)
  {
    int len = strlen(s);
    while (cur_ + len > buf_size)
    {
      buf_size *= 2; /* Double the buffer size */
      resizeBuffer();
    }
    for(int n = 0; n < len; n++)
    {
      buf_[cur_ + n] = s[n];
    }
    cur_ += len;
    buf_[cur_] = 0;
  }
  void inline bufAppend(const char c)
  {
    if (cur_ == buf_size)
    {
      buf_size *= 2; /* Double the buffer size */
      resizeBuffer();
    }
    buf_[cur_] = c;
    cur_++;
    buf_[cur_] = 0;
  }
  void inline bufReset(void)
  {
    cur_ = 0;
    buf_size = BUFFER_INITIAL;
    resizeBuffer();
    memset(buf_, 0, buf_size);
  }
  void inline resizeBuffer(void)
  {
    char* temp = (char*) malloc(buf_size);
    if (!temp)
    {
      fprintf(stderr, "Error: Out of memory while attempting to grow buffer!\n");
      exit(1);
    }
    if (buf_)
    {
      strcpy(temp, buf_);
      free(buf_);
    }
    buf_ = temp;
  }
  char *buf_;
  int cur_, buf_size;
};



#endif

