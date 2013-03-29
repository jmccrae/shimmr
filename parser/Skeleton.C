/*** BNFC-Generated Visitor Design Pattern Skeleton. ***/
/* This implements the common visitor design pattern.
   Note that this method uses Visitor-traversal of lists, so
   List->accept() does NOT traverse the list. This allows different
   algorithms to use context information differently. */

#include "Skeleton.H"

void Skeleton::visitProgram(Program* program) {} //abstract class

void Skeleton::visitStatements(Statements* statements)
{
  /* Code For Statements Goes Here */

  if (statements->liststatement_) {statements->liststatement_->accept(this);}
}

void Skeleton::visitStatementBlock(StatementBlock* statementblock) {} //abstract class

void Skeleton::visitStatementBlockStat(StatementBlockStat* statementblockstat)
{
  /* Code For StatementBlockStat Goes Here */

  if (statementblockstat->liststatement_) {statementblockstat->liststatement_->accept(this);}
}

void Skeleton::visitListStatement(ListStatement* liststatement)
{
  while(liststatement!= 0)
  {
    /* Code For ListStatement Goes Here */
    liststatement->statement_->accept(this);
    liststatement = liststatement->liststatement_;
  }
}

void Skeleton::visitStatement(Statement* statement) {} //abstract class

void Skeleton::visitDeclStat(DeclStat* declstat)
{
  /* Code For DeclStat Goes Here */

  declstat->decl_->accept(this);
}

void Skeleton::visitForStatement(ForStatement* forstatement)
{
  /* Code For ForStatement Goes Here */

  visitIdent(forstatement->ident_);
  forstatement->exp_->accept(this);
  forstatement->statementblock_->accept(this);
}

void Skeleton::visitIfStatement(IfStatement* ifstatement)
{
  /* Code For IfStatement Goes Here */

  ifstatement->exp_->accept(this);
  ifstatement->statementblock_->accept(this);
}

void Skeleton::visitIfElseStatement(IfElseStatement* ifelsestatement)
{
  /* Code For IfElseStatement Goes Here */

  ifelsestatement->exp_->accept(this);
  ifelsestatement->statementblock_->accept(this);
  ifelsestatement->elseblock_->accept(this);
}

void Skeleton::visitSomeStatement(SomeStatement* somestatement)
{
  /* Code For SomeStatement Goes Here */

  visitIdent(somestatement->ident_);
  somestatement->exp_->accept(this);
  somestatement->statementblock_->accept(this);
}

void Skeleton::visitSomeElseStatement(SomeElseStatement* someelsestatement)
{
  /* Code For SomeElseStatement Goes Here */

  visitIdent(someelsestatement->ident_);
  someelsestatement->exp_->accept(this);
  someelsestatement->statementblock_->accept(this);
  someelsestatement->elseblock_->accept(this);
}

void Skeleton::visitConditionalStatement(ConditionalStatement* conditionalstatement)
{
  /* Code For ConditionalStatement Goes Here */

  conditionalstatement->lexpr_->accept(this);
  conditionalstatement->exp_1->accept(this);
  conditionalstatement->exp_2->accept(this);
}

void Skeleton::visitAbsoluteStatement(AbsoluteStatement* absolutestatement)
{
  /* Code For AbsoluteStatement Goes Here */

  absolutestatement->lexpr_->accept(this);
  absolutestatement->exp_->accept(this);
}

void Skeleton::visitExpAsStatement(ExpAsStatement* expasstatement)
{
  /* Code For ExpAsStatement Goes Here */

  expasstatement->exp_->accept(this);
}

void Skeleton::visitDecl(Decl* decl) {} //abstract class

void Skeleton::visitSimpleDecl(SimpleDecl* simpledecl)
{
  /* Code For SimpleDecl Goes Here */

  visitIdent(simpledecl->ident_);
  simpledecl->exp_->accept(this);
}

void Skeleton::visitTypedDecl(TypedDecl* typeddecl)
{
  /* Code For TypedDecl Goes Here */

  typeddecl->type_->accept(this);
  visitIdent(typeddecl->ident_);
  typeddecl->exp_->accept(this);
}

void Skeleton::visitSimpleDeclWith(SimpleDeclWith* simpledeclwith)
{
  /* Code For SimpleDeclWith Goes Here */

  visitIdent(simpledeclwith->ident_);
  simpledeclwith->exp_1->accept(this);
  simpledeclwith->exp_2->accept(this);
}

void Skeleton::visitTypedDeclWith(TypedDeclWith* typeddeclwith)
{
  /* Code For TypedDeclWith Goes Here */

  typeddeclwith->type_->accept(this);
  visitIdent(typeddeclwith->ident_);
  typeddeclwith->exp_1->accept(this);
  typeddeclwith->exp_2->accept(this);
}

void Skeleton::visitBareDecl(BareDecl* baredecl)
{
  /* Code For BareDecl Goes Here */

  baredecl->type_->accept(this);
  visitIdent(baredecl->ident_);
}

void Skeleton::visitEFuncDecl(EFuncDecl* efuncdecl)
{
  /* Code For EFuncDecl Goes Here */

  visitIdent(efuncdecl->ident_);
  if (efuncdecl->listargument_) {efuncdecl->listargument_->accept(this);}
  efuncdecl->statementblock_->accept(this);
}

void Skeleton::visitEFuncDeclWithType(EFuncDeclWithType* efuncdeclwithtype)
{
  /* Code For EFuncDeclWithType Goes Here */

  efuncdeclwithtype->type_->accept(this);
  visitIdent(efuncdeclwithtype->ident_);
  if (efuncdeclwithtype->listargument_) {efuncdeclwithtype->listargument_->accept(this);}
  efuncdeclwithtype->statementblock_->accept(this);
}

void Skeleton::visitElseBlock(ElseBlock* elseblock) {} //abstract class

void Skeleton::visitElseIfBlock(ElseIfBlock* elseifblock)
{
  /* Code For ElseIfBlock Goes Here */

  elseifblock->exp_->accept(this);
  elseifblock->statementblock_->accept(this);
}

void Skeleton::visitElseIf2Block(ElseIf2Block* elseif2block)
{
  /* Code For ElseIf2Block Goes Here */

  elseif2block->exp_->accept(this);
  elseif2block->statementblock_->accept(this);
  elseif2block->elseblock_->accept(this);
}

void Skeleton::visitElseBlockStat(ElseBlockStat* elseblockstat)
{
  /* Code For ElseBlockStat Goes Here */

  elseblockstat->statementblock_->accept(this);
}

void Skeleton::visitElseFailStat(ElseFailStat* elsefailstat)
{
  /* Code For ElseFailStat Goes Here */

}

void Skeleton::visitExp(Exp* exp) {} //abstract class

void Skeleton::visitEOr(EOr* eor)
{
  /* Code For EOr Goes Here */

  eor->exp_1->accept(this);
  eor->exp_2->accept(this);
}

void Skeleton::visitEAnd(EAnd* eand)
{
  /* Code For EAnd Goes Here */

  eand->exp_1->accept(this);
  eand->exp_2->accept(this);
}

void Skeleton::visitEEquals(EEquals* eequals)
{
  /* Code For EEquals Goes Here */

  eequals->exp_1->accept(this);
  eequals->exp_2->accept(this);
}

void Skeleton::visitENEq(ENEq* eneq)
{
  /* Code For ENEq Goes Here */

  eneq->exp_1->accept(this);
  eneq->exp_2->accept(this);
}

void Skeleton::visitELeq(ELeq* eleq)
{
  /* Code For ELeq Goes Here */

  eleq->exp_1->accept(this);
  eleq->exp_2->accept(this);
}

void Skeleton::visitEGeq(EGeq* egeq)
{
  /* Code For EGeq Goes Here */

  egeq->exp_1->accept(this);
  egeq->exp_2->accept(this);
}

void Skeleton::visitELessThan(ELessThan* elessthan)
{
  /* Code For ELessThan Goes Here */

  elessthan->exp_1->accept(this);
  elessthan->exp_2->accept(this);
}

void Skeleton::visitEGreaterThan(EGreaterThan* egreaterthan)
{
  /* Code For EGreaterThan Goes Here */

  egreaterthan->exp_1->accept(this);
  egreaterthan->exp_2->accept(this);
}

void Skeleton::visitEAdd(EAdd* eadd)
{
  /* Code For EAdd Goes Here */

  eadd->exp_1->accept(this);
  eadd->exp_2->accept(this);
}

void Skeleton::visitESub(ESub* esub)
{
  /* Code For ESub Goes Here */

  esub->exp_1->accept(this);
  esub->exp_2->accept(this);
}

void Skeleton::visitEMul(EMul* emul)
{
  /* Code For EMul Goes Here */

  emul->exp_1->accept(this);
  emul->exp_2->accept(this);
}

void Skeleton::visitEDiv(EDiv* ediv)
{
  /* Code For EDiv Goes Here */

  ediv->exp_1->accept(this);
  ediv->exp_2->accept(this);
}

void Skeleton::visitENot(ENot* enot)
{
  /* Code For ENot Goes Here */

  enot->exp_->accept(this);
}

void Skeleton::visitEIdent(EIdent* eident)
{
  /* Code For EIdent Goes Here */

  visitIdent(eident->ident_);
}

void Skeleton::visitEFuncCall(EFuncCall* efunccall)
{
  /* Code For EFuncCall Goes Here */

  visitIdent(efunccall->ident_);
  if (efunccall->listexp_) {efunccall->listexp_->accept(this);}
}

void Skeleton::visitEInt(EInt* eint)
{
  /* Code For EInt Goes Here */

  visitInteger(eint->integer_);
}

void Skeleton::visitEFloat(EFloat* efloat)
{
  /* Code For EFloat Goes Here */

  visitDouble(efloat->double_);
}

void Skeleton::visitEString(EString* estring)
{
  /* Code For EString Goes Here */

  visitString(estring->string_);
}

void Skeleton::visitArgument(Argument* argument) {} //abstract class

void Skeleton::visitArgumentDef(ArgumentDef* argumentdef)
{
  /* Code For ArgumentDef Goes Here */

  argumentdef->type_->accept(this);
  visitIdent(argumentdef->ident_);
}

void Skeleton::visitListArgument(ListArgument* listargument)
{
  while(listargument!= 0)
  {
    /* Code For ListArgument Goes Here */
    listargument->argument_->accept(this);
    listargument = listargument->listargument_;
  }
}

void Skeleton::visitListExp(ListExp* listexp)
{
  while(listexp!= 0)
  {
    /* Code For ListExp Goes Here */
    listexp->exp_->accept(this);
    listexp = listexp->listexp_;
  }
}

void Skeleton::visitType(Type* type) {} //abstract class

void Skeleton::visitEType(EType* etype)
{
  /* Code For EType Goes Here */

  visitIdent(etype->ident_);
}

void Skeleton::visitVectorType(VectorType* vectortype)
{
  /* Code For VectorType Goes Here */

  vectortype->type_1->accept(this);
  vectortype->type_2->accept(this);
}

void Skeleton::visitRangeType(RangeType* rangetype)
{
  /* Code For RangeType Goes Here */

  visitInteger(rangetype->integer_1);
  visitInteger(rangetype->integer_2);
}

void Skeleton::visitSetType(SetType* settype)
{
  /* Code For SetType Goes Here */

  if (settype->listsettypeelem_) {settype->listsettypeelem_->accept(this);}
}

void Skeleton::visitSetTypeElem(SetTypeElem* settypeelem) {} //abstract class

void Skeleton::visitEIntSTE(EIntSTE* eintste)
{
  /* Code For EIntSTE Goes Here */

  visitInteger(eintste->integer_);
}

void Skeleton::visitEFloatSTE(EFloatSTE* efloatste)
{
  /* Code For EFloatSTE Goes Here */

  visitDouble(efloatste->double_);
}

void Skeleton::visitEStringSTE(EStringSTE* estringste)
{
  /* Code For EStringSTE Goes Here */

  visitString(estringste->string_);
}

void Skeleton::visitListSetTypeElem(ListSetTypeElem* listsettypeelem)
{
  while(listsettypeelem!= 0)
  {
    /* Code For ListSetTypeElem Goes Here */
    listsettypeelem->settypeelem_->accept(this);
    listsettypeelem = listsettypeelem->listsettypeelem_;
  }
}

void Skeleton::visitLExpr(LExpr* lexpr) {} //abstract class

void Skeleton::visitVarAsLExpr(VarAsLExpr* varaslexpr)
{
  /* Code For VarAsLExpr Goes Here */

  visitIdent(varaslexpr->ident_);
}

void Skeleton::visitVectorAsLExpr(VectorAsLExpr* vectoraslexpr)
{
  /* Code For VectorAsLExpr Goes Here */

  vectoraslexpr->lexpr_->accept(this);
  if (vectoraslexpr->listexp_) {vectoraslexpr->listexp_->accept(this);}
}

void Skeleton::visitIdent(Ident i)
{
  /* Code for Ident Goes Here */
}
void Skeleton::visitInteger(Integer i)
{
  /* Code for Integers Goes Here */
}
void Skeleton::visitDouble(Double d)
{
  /* Code for Doubles Goes Here */
}
void Skeleton::visitChar(Char c)
{
  /* Code for Chars Goes Here */
}
void Skeleton::visitString(String s)
{
  /* Code for Strings Goes Here */
}

