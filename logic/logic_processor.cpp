#include "logic_processor.h"

using namespace std;

namespace shimmrLogic
{

LogicProcessor::LogicProcessor()
{
}

LogicProcessor::~LogicProcessor()
{
}


std::shared_ptr<Value> LogicProcessor::visitForValue(Visitable *p, int flags) {
	p->accept(this);
	auto v = valueStack.top();
	valueStack.pop();
	return v;
}

void LogicProcessor::emitClause(shared_ptr<Predicate> values) {
	
}

void LogicProcessor::emitWeightedClause(shared_ptr<Value> weight, shared_ptr<Predicate> values) {
	
}

 void LogicProcessor::visitStatements(Statements *p) {
	 p->liststatement_->accept(this);
 }
 
 void LogicProcessor::visitStatementBlockStat(StatementBlockStat *p){
	 p->liststatement_->accept(this);
 }
 
 void LogicProcessor::visitListStatement(ListStatement *p){
	 for(auto stat : *p) {
		 stat->accept(this);
	 }
 }
 
 void LogicProcessor::visitDeclStat(DeclStat *p){
	 p->decl_->accept(this);
 }
 
 void LogicProcessor::visitSimpleDecl(SimpleDecl *p){
	 vector<shared_ptr<Value>> values;
	 values.push_back(make_shared<VariableValue>(sys,scope,p->ident_));
	 values.push_back(visitForValue(p->exp_));
	 string eq("=");
	 auto pred = make_shared<Predicate>(eq,values);
	 vector<shared_ptr<Predicate>> c;
	 c.push_back(pred);
	 clauseStack.push(make_shared<Clause>(context,c,false));
 }
 
 void LogicProcessor::visitTypedDecl(TypedDecl *p){
	 // Type for p->ident_ == p->type_
	 // p->exp_
	 auto expValue = visitForValue(p->exp_);
	 vector<shared_ptr<Value>> expValueVector;
	 expValueVector.push_back(expValue);
	 // p->ident_ = valueOf(p->exp_)
	 string resolvedName = scope->resolveName(p->ident_);
	 auto predicate = make_shared<Predicate>(resolvedName,expValueVector);
	 emitClause(predicate);
 }
 
 void LogicProcessor::visitSimpleDeclWith(SimpleDeclWith *p){
	 // p->exp_1
	 auto expValue = visitForValue(p->exp_1);
	 vector<shared_ptr<Value>> expValueVector;
	 expValueVector.push_back(p->exp_1);
	 // p->exp_2
	 auto weightValue = visitForValue(p->exp_2);
	 // p->ident_ = valueOf(p->exp_1) : p->exp_2
	 string resolveName = scope->resolveName(p->ident_);
	 auto predicate = make_shared<Predicate>(resolvedName,expValueVector);
	 emitWeightedClause(weightValue,predicate);
}
 
 void LogicProcessor::visitTypedDeclWith(TypedDeclWith *p){
	 // p->exp_1
	 auto expValue = visitForValue(p->exp_1);
	 vector<shared_ptr<Value>> expValueVector;
	 expValueVector.push_back(p->exp_1);
	 // p->exp_2
	 auto weightValue = visitForValue(p->exp_2);
	 // p->ident_ = valueOf(p->exp_1) : p->exp_2
	 string resolveName = scope->resolveName(p->ident_);
	 auto predicate = make_shared<Predicate>(resolvedName,expValueVector);
	 emitWeightedClause(weightValue,predicate);
 }
 
 void LogicProcessor::visitBareDecl(BareDecl *p){
	 // Type for p->ident_ == p->type_
	 // No clauses
 }
 
 void LogicProcessor::visitEFuncDecl(EFuncDecl *p){
	 // p(args...) == valueOf(p->statementblock_)
	 // p->statementblock_
 }
 
 void LogicProcessor::visitEFuncDeclWithType(EFuncDeclWithType *p){
	 // Type of p(args...) == p->type_
	 // p(args...) == valueOf(p->statementblock_)
	 // p->statementblock_
 }
 
 void LogicProcessor::visitForStatement(ForStatement *p){
	 // x \in p->exp_ => p->statementblock_
 }
 
 void LogicProcessor::visitIfStatement(IfStatement *p){
	 // p->exp_ => p->statementblock_
 }
 
 void LogicProcessor::visitIfElseStatement(IfElseStatement *p){
	 // p->exp_ => p->statementblock_ v p->elseblock_
 }
 
 void LogicProcessor::visitElseIfBlock(ElseIfBlock *p){
	 // p ^ p->exp_ => p->statementblock_ 
 }
 
 void LogicProcessor::visitElseIf2Block(ElseIf2Block *p){
	 // p ^ p->exp_ => p->statementblock_1 v p->elseblock_
 }
 
 void LogicProcessor::visitElseBlockStat(ElseBlockStat *p){
	 // p => p->statementblock_
 }
 
 void LogicProcessor::visitElseFailStat(ElseFailStat *p){
	 // p => F
 }
 
 void LogicProcessor::visitSomeStatement(SomeStatement *p){
	 // unique(x \in p->exp_)
	 // x \in p->exp_ => p->statementblock_
 }
 
 void LogicProcessor::visitSomeElseStatement(SomeElseStatement *p){
	 // unique(x \in p->exp_) v p->elseblock_
	 // x \in p->exp_ => p->statementblock_
 }
 
 void LogicProcessor::visitConditionalStatement(ConditionalStatement *p){
	 // p->exp_1 : p->exp_2
 }
 
 void LogicProcessor::visitExpAsStatement(ExpAsStatement *p){
	 // p->exp_
 }
 
 void LogicProcessor::visitEOr(EOr *p){
	 // p->exp_1 v p->exp_2
 }
 
 void LogicProcessor::visitEAnd(EAnd *p){
	 // p->exp_1
	 // p->exp_2
 }
 
 void LogicProcessor::visitEEquals(EEquals *p){
	 // valueOf(p->exp_1) == valueOf(p->exp_2)
	 // p->exp_1
	 // p->exp_2
 }
 
 void LogicProcessor::visitENEq(ENEq *p){
	 // valueOf(p->exp_1) == valueOf(p->exp_2) => F
	 // p->exp_1
	 // p->exp_2
 }
 
 void LogicProcessor::visitELeq(ELeq *p){
	 // valueOf(p->exp_1) <= valueOf(p->exp_2)
	 // p->exp_1
	 // p->exp_2
 }
 
 void LogicProcessor::visitEGeq(EGeq *p){
	 // valueOf(p->exp_1) >= valueOf(p->exp_2)
	 // p->exp_1
	 // p->exp_2
 }
 
 void LogicProcessor::visitELessThan(ELessThan *p){
	 // valueOf(p->exp_1) < valueOf(p->exp_2)
	 // p->exp_1
	 // p->exp_2
 }
 
 void LogicProcessor::visitEGreaterThan(EGreaterThan *p){
	 // valueOf(p->exp_1) > valueOf(p->exp_2)
	 // p->exp_1
	 // p->exp_2
 }
 
 void LogicProcessor::visitEAdd(EAdd *p){
	 // valueOf(p) == valueOf(p->exp_1) + valueOf(p->exp_2)
	 // p->exp_1
	 // p->exp_2
 }
 
 void LogicProcessor::visitESub(ESub *p){
	 // valueOf(p) == valueOf(p->exp_1) - valueOf(p->exp_2)
	 // p->exp_1
	 // p->exp_2
 }
 
 void LogicProcessor::visitEMul(EMul *p){
	 // valueOf(p) == valueOf(p->exp_1) * valueOf(p->exp_2)
	 // p->exp_1
	 // p->exp_2
 }
 
 void LogicProcessor::visitEDiv(EDiv *p){
	 // valueOf(p) == valueOf(p->exp_1) / valueOf(p->exp_2)
	 // p->exp_1
	 // p->exp_2
 }
 
 void LogicProcessor::visitENot(ENot *p){
	 // p->exp_ => F
 }
 
 void LogicProcessor::visitEIdent(EIdent *p){
	 // p
 }
 
 void LogicProcessor::visitEFuncCall(EFuncCall *p){
	 // p(p->args_)
	 // p->args_*
 }
 
 void LogicProcessor::visitArgumentDef(ArgumentDef *p){
	 // EMPTY
 }
 
 void LogicProcessor::visitERange(ERange *p){
	 // valueOf(p) == range(p->integer_1,p->integer_2)
 }
 
 void LogicProcessor::visitESet(ESet *p){
	 // valueOf(p) == set(p->listsettypeelem_)
 }
 
 void LogicProcessor::visitListArgument(ListArgument *p){
	 // EMPTY
 }
 
 void LogicProcessor::visitEInt(EInt *p){
	 // valueOf(p) == p->integer_
	 auto value = make_shared<LiteralValue>(sys, make_shared<shimmrType::IntTypeValue>(p->integer_));
	 valueStack.push(value);
 }
 
 void LogicProcessor::visitEFloat(EFloat *p){
	 // valueOf(p) == p->double_
	 auto value = make_shared<LiteralValue>(sys, make_shared<shimmrType::FloatTypeValue>(p->double_));
	 valueStack.push(value);
 }
 
 void LogicProcessor::visitEString(EString *p){
	 // valueOf(p) == p->string_
	 auto value = make_shared<LiteralValue>(sys, make_shared<shimmrType::StringTypeValue>(p->string_));
	 valueStack.push(value); }
 
 void LogicProcessor::visitListExp(ListExp *p){
	 // for(p2 in p) yield {
	 //   valueOf(p2)
	 // }
	 // for(p2 in p) {
	 //   p2
	 // }
 }
 
 void LogicProcessor::visitEType(EType *p){
	 // EMPTY
 }
 
 void LogicProcessor::visitVectorType(VectorType *p){
	 // EMPTY
 }
 
 void LogicProcessor::visitRangeType(RangeType *p){
	 // EMPTY
 }
 
 void LogicProcessor::visitSetType(SetType *p){
	 // EMPTY
 }
 
 void LogicProcessor::visitEIntSTE(EIntSTE *p){
	 // yield p->integer_
 }
 
 void LogicProcessor::visitEFloatSTE(EFloatSTE *p){
	 // yield p->double_
 }
 
 void LogicProcessor::visitEStringSTE(EStringSTE *p){
	 // yield p->string_
 }
 
 void LogicProcessor::visitListSetTypeElem(ListSetTypeElem *p){
	 // yield p*
 }
 
 void LogicProcessor::visitProgram(Program *p){
	 // EMPTY
 }
 
 void LogicProcessor::visitStatementBlock(StatementBlock *p){
	 // EMPTY
 }
 
 void LogicProcessor::visitStatement(Statement *p){
	 // EMPTY
 }
 
 void LogicProcessor::visitDecl(Decl *p){
	 
 }
 
 void LogicProcessor::visitElseBlock(ElseBlock *p){
	 
 }
 
 void LogicProcessor::visitExp(Exp *p){
	 
 }
 
 void LogicProcessor::visitArgument(Argument *p){
	 
 }
 
 void LogicProcessor::visitType(Type *p){
	 
 }
 
 void LogicProcessor::visitSetTypeElem(SetTypeElem *p){
	 
 }
 
 void LogicProcessor::visitIdent(Ident){
	 
 }
 
 void LogicProcessor::visitEVector(EVector *p){
	 
 }
 

 void LogicProcessor::visitInteger(Integer i){
	 
 }
 
 void LogicProcessor::visitDouble(Double d){
	 
 }
 
 void LogicProcessor::visitChar(Char c){
	 
 }
 
 void LogicProcessor::visitString(String s){
	 
 }
 

}

