/*** BNFC-Generated Pretty Printer and Abstract Syntax Viewer ***/

#include "Printer.H"

//You may wish to change render
void PrintAbsyn::render(Char c)
{
  if (c == '{')
  {
     bufAppend('\n');
     indent();
     bufAppend(c);
     _n_ = _n_ + 2;
     bufAppend('\n');
     indent();
  }
  else if (c == '(' || c == '[')
     bufAppend(c);
  else if (c == ')' || c == ']')
  {
     backup();
     bufAppend(c);
     bufAppend(' ');
  }
  else if (c == '}')
  {
     _n_ = _n_ - 2;
     backup();
     backup();
     bufAppend(c);
     bufAppend('\n');
     indent();
  }
  else if (c == ',')
  {
     backup();
     bufAppend(c);
     bufAppend(' ');
  }
  else if (c == ';')
  {
     backup();
     bufAppend(c);
     bufAppend('\n');
     indent();
  }
  else if (c == 0) return;
  else
  {
     bufAppend(c);
     bufAppend(' ');
  }
}
void PrintAbsyn::render(String s)
{
  if(strlen(s) > 0)
  {
    bufAppend(s);
    bufAppend(' ');
  }
}
void PrintAbsyn::indent()
{
  int n = _n_;
  while (n > 0)
  {
    bufAppend(' ');
    n--;
  }
}
void PrintAbsyn::backup()
{
  if (buf_[cur_ - 1] == ' ')
  {
    buf_[cur_ - 1] = 0;
    cur_--;
  }
}
PrintAbsyn::PrintAbsyn(void)
{
  _i_ = 0; _n_ = 0;
  buf_ = 0;
  bufReset();
}

PrintAbsyn::~PrintAbsyn(void)
{
}

char* PrintAbsyn::print(Visitable *v)
{
  _i_ = 0; _n_ = 0;
  bufReset();
  v->accept(this);
  return buf_;
}
void PrintAbsyn::visitProgram(Program*p) {} //abstract class

void PrintAbsyn::visitStatements(Statements* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  if(p->liststatement_) {_i_ = 0; p->liststatement_->accept(this);}
  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitStatementBlock(StatementBlock*p) {} //abstract class

void PrintAbsyn::visitStatementBlockStat(StatementBlockStat* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render('{');
  if(p->liststatement_) {_i_ = 0; p->liststatement_->accept(this);}  render('}');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitListStatement(ListStatement *liststatement)
{
  while(liststatement!= 0)
  {
    if (liststatement->liststatement_ == 0)
    {
      liststatement->statement_->accept(this);

      liststatement = 0;
    }
    else
    {
      liststatement->statement_->accept(this);
      render(';');
      liststatement = liststatement->liststatement_;
    }
  }
}

void PrintAbsyn::visitStatement(Statement*p) {} //abstract class

void PrintAbsyn::visitDeclStat(DeclStat* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->decl_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitForStatement(ForStatement* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("for");
  render('(');
  visitIdent(p->ident_);
  render("in");
  _i_ = 0; p->exp_->accept(this);
  render(')');
  _i_ = 0; p->statementblock_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitIfStatement(IfStatement* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("if");
  render('(');
  _i_ = 0; p->exp_->accept(this);
  render(')');
  _i_ = 0; p->statementblock_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitIfElseStatement(IfElseStatement* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("if");
  render('(');
  _i_ = 0; p->exp_->accept(this);
  render(')');
  _i_ = 0; p->statementblock_->accept(this);
  _i_ = 0; p->elseblock_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitSomeStatement(SomeStatement* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("some");
  render('(');
  visitIdent(p->ident_);
  render("in");
  _i_ = 0; p->exp_->accept(this);
  render(')');
  _i_ = 0; p->statementblock_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitSomeElseStatement(SomeElseStatement* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("some");
  render('(');
  visitIdent(p->ident_);
  render("in");
  _i_ = 0; p->exp_->accept(this);
  render(')');
  _i_ = 0; p->statementblock_->accept(this);
  _i_ = 0; p->elseblock_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitConditionalStatement(ConditionalStatement* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  visitIdent(p->ident_);
  render('=');
  _i_ = 0; p->exp_1->accept(this);
  render("with");
  _i_ = 0; p->exp_2->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitDecl(Decl*p) {} //abstract class

void PrintAbsyn::visitSimpleDecl(SimpleDecl* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("val");
  visitIdent(p->ident_);
  render('=');
  _i_ = 0; p->exp_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitTypedDecl(TypedDecl* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("val");
  _i_ = 0; p->type_->accept(this);
  visitIdent(p->ident_);
  render('=');
  _i_ = 0; p->exp_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitSimpleDeclWith(SimpleDeclWith* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("val");
  visitIdent(p->ident_);
  render('=');
  _i_ = 0; p->exp_1->accept(this);
  render("with");
  _i_ = 0; p->exp_2->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitTypedDeclWith(TypedDeclWith* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("val");
  _i_ = 0; p->type_->accept(this);
  visitIdent(p->ident_);
  render('=');
  _i_ = 0; p->exp_1->accept(this);
  render("with");
  _i_ = 0; p->exp_2->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitBareDecl(BareDecl* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("val");
  _i_ = 0; p->type_->accept(this);
  visitIdent(p->ident_);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitElseBlock(ElseBlock*p) {} //abstract class

void PrintAbsyn::visitElseIfBlock(ElseIfBlock* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("else");
  render("if");
  render('(');
  _i_ = 0; p->exp_->accept(this);
  render(')');
  _i_ = 0; p->statementblock_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitElseIf2Block(ElseIf2Block* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("else");
  render("if");
  render('(');
  _i_ = 0; p->exp_->accept(this);
  render(')');
  _i_ = 0; p->statementblock_->accept(this);
  _i_ = 0; p->elseblock_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitElseBlockStat(ElseBlockStat* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("else");
  _i_ = 0; p->statementblock_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitExp(Exp*p) {} //abstract class

void PrintAbsyn::visitEFuncDecl(EFuncDecl* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("def");
  render('(');
  if(p->listargument_) {_i_ = 0; p->listargument_->accept(this);}  render(')');
  _i_ = 0; p->statementblock_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEOr(EOr* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->exp_1->accept(this);
  render("||");
  _i_ = 1; p->exp_2->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEAnd(EAnd* p)
{
  int oldi = _i_;
  if (oldi > 1) render(_L_PAREN);

  _i_ = 1; p->exp_1->accept(this);
  render("&&");
  _i_ = 2; p->exp_2->accept(this);

  if (oldi > 1) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEEquals(EEquals* p)
{
  int oldi = _i_;
  if (oldi > 2) render(_L_PAREN);

  _i_ = 2; p->exp_1->accept(this);
  render("==");
  _i_ = 3; p->exp_2->accept(this);

  if (oldi > 2) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitENEq(ENEq* p)
{
  int oldi = _i_;
  if (oldi > 2) render(_L_PAREN);

  _i_ = 2; p->exp_1->accept(this);
  render("!=");
  _i_ = 3; p->exp_2->accept(this);

  if (oldi > 2) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitELeq(ELeq* p)
{
  int oldi = _i_;
  if (oldi > 3) render(_L_PAREN);

  _i_ = 3; p->exp_1->accept(this);
  render("<=");
  _i_ = 4; p->exp_2->accept(this);

  if (oldi > 3) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEGeq(EGeq* p)
{
  int oldi = _i_;
  if (oldi > 3) render(_L_PAREN);

  _i_ = 3; p->exp_1->accept(this);
  render(">=");
  _i_ = 4; p->exp_2->accept(this);

  if (oldi > 3) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitELessThan(ELessThan* p)
{
  int oldi = _i_;
  if (oldi > 3) render(_L_PAREN);

  _i_ = 3; p->exp_1->accept(this);
  render('<');
  _i_ = 4; p->exp_2->accept(this);

  if (oldi > 3) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEGreaterThan(EGreaterThan* p)
{
  int oldi = _i_;
  if (oldi > 3) render(_L_PAREN);

  _i_ = 3; p->exp_1->accept(this);
  render('>');
  _i_ = 4; p->exp_2->accept(this);

  if (oldi > 3) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEAdd(EAdd* p)
{
  int oldi = _i_;
  if (oldi > 4) render(_L_PAREN);

  _i_ = 4; p->exp_1->accept(this);
  render('+');
  _i_ = 5; p->exp_2->accept(this);

  if (oldi > 4) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitESub(ESub* p)
{
  int oldi = _i_;
  if (oldi > 4) render(_L_PAREN);

  _i_ = 4; p->exp_1->accept(this);
  render('-');
  _i_ = 5; p->exp_2->accept(this);

  if (oldi > 4) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEMul(EMul* p)
{
  int oldi = _i_;
  if (oldi > 5) render(_L_PAREN);

  _i_ = 5; p->exp_1->accept(this);
  render('*');
  _i_ = 6; p->exp_2->accept(this);

  if (oldi > 5) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEDiv(EDiv* p)
{
  int oldi = _i_;
  if (oldi > 5) render(_L_PAREN);

  _i_ = 5; p->exp_1->accept(this);
  render('/');
  _i_ = 6; p->exp_2->accept(this);

  if (oldi > 5) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitENot(ENot* p)
{
  int oldi = _i_;
  if (oldi > 6) render(_L_PAREN);

  render('!');
  _i_ = 7; p->exp_->accept(this);

  if (oldi > 6) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEIdent(EIdent* p)
{
  int oldi = _i_;
  if (oldi > 7) render(_L_PAREN);

  visitIdent(p->ident_);

  if (oldi > 7) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEFuncCall(EFuncCall* p)
{
  int oldi = _i_;
  if (oldi > 7) render(_L_PAREN);

  visitIdent(p->ident_);
  render('(');
  if(p->listexp_) {_i_ = 0; p->listexp_->accept(this);}  render(')');

  if (oldi > 7) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEInt(EInt* p)
{
  int oldi = _i_;
  if (oldi > 8) render(_L_PAREN);

  visitInteger(p->integer_);

  if (oldi > 8) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEFloat(EFloat* p)
{
  int oldi = _i_;
  if (oldi > 8) render(_L_PAREN);

  visitDouble(p->double_);

  if (oldi > 8) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEString(EString* p)
{
  int oldi = _i_;
  if (oldi > 8) render(_L_PAREN);

  visitString(p->string_);

  if (oldi > 8) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitArgument(Argument*p) {} //abstract class

void PrintAbsyn::visitArgumentDef(ArgumentDef* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->type_->accept(this);
  visitIdent(p->ident_);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitListArgument(ListArgument *listargument)
{
  while(listargument!= 0)
  {
    if (listargument->listargument_ == 0)
    {
      listargument->argument_->accept(this);

      listargument = 0;
    }
    else
    {
      listargument->argument_->accept(this);
      render(',');
      listargument = listargument->listargument_;
    }
  }
}

void PrintAbsyn::visitListExp(ListExp *listexp)
{
  while(listexp!= 0)
  {
    if (listexp->listexp_ == 0)
    {
      listexp->exp_->accept(this);

      listexp = 0;
    }
    else
    {
      listexp->exp_->accept(this);
      render(',');
      listexp = listexp->listexp_;
    }
  }
}

void PrintAbsyn::visitType(Type*p) {} //abstract class

void PrintAbsyn::visitIntType(IntType* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("Int");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitFloatType(FloatType* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("Float");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitStringType(StringType* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("String");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitBoolType(BoolType* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("Bool");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitAnythingType(AnythingType* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("Anything");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitNothingType(NothingType* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("Nothing");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitUnitType(UnitType* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("Unit");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitVectorType(VectorType* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->type_->accept(this);
  render('[');
  render(']');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitInteger(Integer i)
{
  char tmp[16];
  sprintf(tmp, "%d", i);
  bufAppend(tmp);
}
void PrintAbsyn::visitDouble(Double d)
{
  char tmp[16];
  sprintf(tmp, "%g", d);
  bufAppend(tmp);
}
void PrintAbsyn::visitChar(Char c)
{
  bufAppend('\'');
  bufAppend(c);
  bufAppend('\'');
}
void PrintAbsyn::visitString(String s)
{
  bufAppend('\"');
  bufAppend(s);
  bufAppend('\"');
}
void PrintAbsyn::visitIdent(String s)
{
  render(s);
}

ShowAbsyn::ShowAbsyn(void)
{
  buf_ = 0;
  bufReset();
}

ShowAbsyn::~ShowAbsyn(void)
{
}

char* ShowAbsyn::show(Visitable *v)
{
  bufReset();
  v->accept(this);
  return buf_;
}
void ShowAbsyn::visitProgram(Program* p) {} //abstract class

void ShowAbsyn::visitStatements(Statements* p)
{
  bufAppend('(');
  bufAppend("Statements");
  bufAppend(' ');
  bufAppend('[');
  if (p->liststatement_)  p->liststatement_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitStatementBlock(StatementBlock* p) {} //abstract class

void ShowAbsyn::visitStatementBlockStat(StatementBlockStat* p)
{
  bufAppend('(');
  bufAppend("StatementBlockStat");
  bufAppend(' ');
  bufAppend('[');
  if (p->liststatement_)  p->liststatement_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitListStatement(ListStatement *liststatement)
{
  while(liststatement!= 0)
  {
    if (liststatement->liststatement_)
    {
      liststatement->statement_->accept(this);
      bufAppend(", ");
      liststatement = liststatement->liststatement_;
    }
    else
    {
      liststatement->statement_->accept(this);
      liststatement = 0;
    }
  }
}

void ShowAbsyn::visitStatement(Statement* p) {} //abstract class

void ShowAbsyn::visitDeclStat(DeclStat* p)
{
  bufAppend('(');
  bufAppend("DeclStat");
  bufAppend(' ');
  bufAppend('[');
  if (p->decl_)  p->decl_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitForStatement(ForStatement* p)
{
  bufAppend('(');
  bufAppend("ForStatement");
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(' ');
  bufAppend('[');
  if (p->exp_)  p->exp_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->statementblock_)  p->statementblock_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitIfStatement(IfStatement* p)
{
  bufAppend('(');
  bufAppend("IfStatement");
  bufAppend(' ');
  bufAppend('[');
  if (p->exp_)  p->exp_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->statementblock_)  p->statementblock_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitIfElseStatement(IfElseStatement* p)
{
  bufAppend('(');
  bufAppend("IfElseStatement");
  bufAppend(' ');
  bufAppend('[');
  if (p->exp_)  p->exp_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->statementblock_)  p->statementblock_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->elseblock_)  p->elseblock_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitSomeStatement(SomeStatement* p)
{
  bufAppend('(');
  bufAppend("SomeStatement");
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(' ');
  bufAppend('[');
  if (p->exp_)  p->exp_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->statementblock_)  p->statementblock_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitSomeElseStatement(SomeElseStatement* p)
{
  bufAppend('(');
  bufAppend("SomeElseStatement");
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(' ');
  bufAppend('[');
  if (p->exp_)  p->exp_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->statementblock_)  p->statementblock_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->elseblock_)  p->elseblock_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitConditionalStatement(ConditionalStatement* p)
{
  bufAppend('(');
  bufAppend("ConditionalStatement");
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitDecl(Decl* p) {} //abstract class

void ShowAbsyn::visitSimpleDecl(SimpleDecl* p)
{
  bufAppend('(');
  bufAppend("SimpleDecl");
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(' ');
  bufAppend('[');
  if (p->exp_)  p->exp_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitTypedDecl(TypedDecl* p)
{
  bufAppend('(');
  bufAppend("TypedDecl");
  bufAppend(' ');
  bufAppend('[');
  if (p->type_)  p->type_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(' ');
  bufAppend('[');
  if (p->exp_)  p->exp_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitSimpleDeclWith(SimpleDeclWith* p)
{
  bufAppend('(');
  bufAppend("SimpleDeclWith");
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitTypedDeclWith(TypedDeclWith* p)
{
  bufAppend('(');
  bufAppend("TypedDeclWith");
  bufAppend(' ');
  bufAppend('[');
  if (p->type_)  p->type_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitBareDecl(BareDecl* p)
{
  bufAppend('(');
  bufAppend("BareDecl");
  bufAppend(' ');
  bufAppend('[');
  if (p->type_)  p->type_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(')');
}
void ShowAbsyn::visitElseBlock(ElseBlock* p) {} //abstract class

void ShowAbsyn::visitElseIfBlock(ElseIfBlock* p)
{
  bufAppend('(');
  bufAppend("ElseIfBlock");
  bufAppend(' ');
  bufAppend('[');
  if (p->exp_)  p->exp_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->statementblock_)  p->statementblock_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitElseIf2Block(ElseIf2Block* p)
{
  bufAppend('(');
  bufAppend("ElseIf2Block");
  bufAppend(' ');
  bufAppend('[');
  if (p->exp_)  p->exp_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->statementblock_)  p->statementblock_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->elseblock_)  p->elseblock_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitElseBlockStat(ElseBlockStat* p)
{
  bufAppend('(');
  bufAppend("ElseBlockStat");
  bufAppend(' ');
  bufAppend('[');
  if (p->statementblock_)  p->statementblock_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitExp(Exp* p) {} //abstract class

void ShowAbsyn::visitEFuncDecl(EFuncDecl* p)
{
  bufAppend('(');
  bufAppend("EFuncDecl");
  bufAppend(' ');
  bufAppend('[');
  if (p->listargument_)  p->listargument_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->statementblock_)  p->statementblock_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitEOr(EOr* p)
{
  bufAppend('(');
  bufAppend("EOr");
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitEAnd(EAnd* p)
{
  bufAppend('(');
  bufAppend("EAnd");
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitEEquals(EEquals* p)
{
  bufAppend('(');
  bufAppend("EEquals");
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitENEq(ENEq* p)
{
  bufAppend('(');
  bufAppend("ENEq");
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitELeq(ELeq* p)
{
  bufAppend('(');
  bufAppend("ELeq");
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitEGeq(EGeq* p)
{
  bufAppend('(');
  bufAppend("EGeq");
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitELessThan(ELessThan* p)
{
  bufAppend('(');
  bufAppend("ELessThan");
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitEGreaterThan(EGreaterThan* p)
{
  bufAppend('(');
  bufAppend("EGreaterThan");
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitEAdd(EAdd* p)
{
  bufAppend('(');
  bufAppend("EAdd");
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitESub(ESub* p)
{
  bufAppend('(');
  bufAppend("ESub");
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitEMul(EMul* p)
{
  bufAppend('(');
  bufAppend("EMul");
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitEDiv(EDiv* p)
{
  bufAppend('(');
  bufAppend("EDiv");
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitENot(ENot* p)
{
  bufAppend('(');
  bufAppend("ENot");
  bufAppend(' ');
  bufAppend('[');
  if (p->exp_)  p->exp_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitEIdent(EIdent* p)
{
  bufAppend('(');
  bufAppend("EIdent");
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(')');
}
void ShowAbsyn::visitEFuncCall(EFuncCall* p)
{
  bufAppend('(');
  bufAppend("EFuncCall");
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(' ');
  bufAppend('[');
  if (p->listexp_)  p->listexp_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitEInt(EInt* p)
{
  bufAppend('(');
  bufAppend("EInt");
  bufAppend(' ');
  visitInteger(p->integer_);
  bufAppend(')');
}
void ShowAbsyn::visitEFloat(EFloat* p)
{
  bufAppend('(');
  bufAppend("EFloat");
  bufAppend(' ');
  visitDouble(p->double_);
  bufAppend(')');
}
void ShowAbsyn::visitEString(EString* p)
{
  bufAppend('(');
  bufAppend("EString");
  bufAppend(' ');
  visitString(p->string_);
  bufAppend(')');
}
void ShowAbsyn::visitArgument(Argument* p) {} //abstract class

void ShowAbsyn::visitArgumentDef(ArgumentDef* p)
{
  bufAppend('(');
  bufAppend("ArgumentDef");
  bufAppend(' ');
  bufAppend('[');
  if (p->type_)  p->type_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(')');
}
void ShowAbsyn::visitListArgument(ListArgument *listargument)
{
  while(listargument!= 0)
  {
    if (listargument->listargument_)
    {
      listargument->argument_->accept(this);
      bufAppend(", ");
      listargument = listargument->listargument_;
    }
    else
    {
      listargument->argument_->accept(this);
      listargument = 0;
    }
  }
}

void ShowAbsyn::visitListExp(ListExp *listexp)
{
  while(listexp!= 0)
  {
    if (listexp->listexp_)
    {
      listexp->exp_->accept(this);
      bufAppend(", ");
      listexp = listexp->listexp_;
    }
    else
    {
      listexp->exp_->accept(this);
      listexp = 0;
    }
  }
}

void ShowAbsyn::visitType(Type* p) {} //abstract class

void ShowAbsyn::visitIntType(IntType* p)
{
  bufAppend("IntType");
}
void ShowAbsyn::visitFloatType(FloatType* p)
{
  bufAppend("FloatType");
}
void ShowAbsyn::visitStringType(StringType* p)
{
  bufAppend("StringType");
}
void ShowAbsyn::visitBoolType(BoolType* p)
{
  bufAppend("BoolType");
}
void ShowAbsyn::visitAnythingType(AnythingType* p)
{
  bufAppend("AnythingType");
}
void ShowAbsyn::visitNothingType(NothingType* p)
{
  bufAppend("NothingType");
}
void ShowAbsyn::visitUnitType(UnitType* p)
{
  bufAppend("UnitType");
}
void ShowAbsyn::visitVectorType(VectorType* p)
{
  bufAppend('(');
  bufAppend("VectorType");
  bufAppend(' ');
  bufAppend('[');
  if (p->type_)  p->type_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitInteger(Integer i)
{
  char tmp[16];
  sprintf(tmp, "%d", i);
  bufAppend(tmp);
}
void ShowAbsyn::visitDouble(Double d)
{
  char tmp[16];
  sprintf(tmp, "%g", d);
  bufAppend(tmp);
}
void ShowAbsyn::visitChar(Char c)
{
  bufAppend('\'');
  bufAppend(c);
  bufAppend('\'');
}
void ShowAbsyn::visitString(String s)
{
  bufAppend('\"');
  bufAppend(s);
  bufAppend('\"');
}
void ShowAbsyn::visitIdent(String s)
{
  bufAppend('\"');
  bufAppend(s);
  bufAppend('\"');
}
