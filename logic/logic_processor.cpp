#include "logic_processor.h"

#include <sstream>

using namespace std;

// TODO: Scoping

namespace shimmrLogic
{

LogicProcessor::LogicProcessor(std::shared_ptr<shimmrType::TypeSystem> s,std::shared_ptr<shimmr::Scope> t, std::map<Visitable*,std::shared_ptr<shimmrType::Type>>& et) :
	sys(s), topScope(t), expressionTypes(et)
{
	unit = make_shared<LiteralValue>(s,make_shared<shimmrType::UnitTypeValue>());
	anonCounter = 1;
}

LogicProcessor::~LogicProcessor()
{
}


string LogicProcessor::IN("@in");
string LogicProcessor::IDX("@idx");
string LogicProcessor::SOME("@some");
string LogicProcessor::NONE("@none");

shared_ptr<Value> LogicProcessor::visitForValue(Visitable *p) {
	p->accept(this);
	auto v = valueStack.top();
	valueStack.pop();
	return v;
}

shared_ptr<Predicate> LogicProcessor::visitForPredicate(Visitable *p) {
	p->accept(this);
	auto p2 = predicateStack.top();
	predicateStack.pop();
	return p2;
}

pair<shared_ptr<Value>,shared_ptr<Predicate>> LogicProcessor::visit(Visitable *p) {
	p->accept(this);
	auto v = valueStack.top();
	auto pr = predicateStack.top();
	valueStack.pop();
	predicateStack.pop();
	return make_pair(v,pr);
}


void LogicProcessor::emitClause(vector<shared_ptr<Predicate>>& values) {
	
}

void LogicProcessor::emitWeightedClause(shared_ptr<Value> weight, vector<shared_ptr<Predicate>>& values) {
	
}

vector<shared_ptr<Predicate>> LogicProcessor::singlePredicate(shared_ptr<Predicate> p) {
	vector<shared_ptr<Predicate>> v;
	v.push_back(p);
	return v;
}

void LogicProcessor::returnValue(shared_ptr<Value> v) {
	valueStack.push(v);
}

void LogicProcessor::returnPredicate(shared_ptr<Predicate> p) {
	predicateStack.push(p);
}

shared_ptr<Value> LogicProcessor::anonVariable(shared_ptr<shimmrType::Type> t) {
	stringstream ss;
	ss << "?" << anonCounter++;
	return make_shared<VariableValue>(sys,t,ss.str());
}

 void LogicProcessor::visitStatements(Statements *p) {
	 p->liststatement_->accept(this);
 }
 
 void LogicProcessor::visitStatementBlockStat(StatementBlockStat *p){
	 shared_ptr<shimmr::Scope> child = scope()->children.find(p)->second;
	 scopeStack.push(child);
	 p->liststatement_->accept(this);
	 scopeStack.pop();
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
	 // p->exp_
	 auto expValue = visitForValue(p->exp_);
	 vector<shared_ptr<Value>> expValueVector;
	 expValueVector.push_back(expValue);
	 // p->ident_ = valueOf(p->exp_)
	 string resolvedName = scope()->resolveName(p->ident_);
	 auto predicate = make_shared<Predicate>(resolvedName,expValueVector);
	 emitClause(singlePredicate(predicate));
	 returnValue(unit);
 }
 
 void LogicProcessor::visitTypedDecl(TypedDecl *p){
	 // Type for p->ident_ == p->type_
	 // p->exp_
	 auto expValue = visitForValue(p->exp_);
	 vector<shared_ptr<Value>> expValueVector;
	 expValueVector.push_back(expValue);
	 // p->ident_ = valueOf(p->exp_)
	 string resolvedName = scope()->resolveName(p->ident_);
	 auto predicate = make_shared<Predicate>(resolvedName,expValueVector);
	 emitClause(singlePredicate(predicate));
	 returnValue(unit);
 }
 
 void LogicProcessor::visitSimpleDeclWith(SimpleDeclWith *p){
	 // p->exp_1
	 auto expValue = visitForValue(p->exp_1);
	 vector<shared_ptr<Value>> expValueVector;
	 expValueVector.push_back(expValue);
	 // p->exp_2
	 auto weightValue = visitForValue(p->exp_2);
	 // p->ident_ = valueOf(p->exp_1) : p->exp_2
	 string resolvedName = scope()->resolveName(p->ident_);
	 auto predicate = make_shared<Predicate>(resolvedName,expValueVector);
	 emitWeightedClause(weightValue,singlePredicate(predicate));
	 returnValue(unit);
}
 
 void LogicProcessor::visitTypedDeclWith(TypedDeclWith *p){
	 // p->exp_1
	 auto expValue = visitForValue(p->exp_1);
	 vector<shared_ptr<Value>> expValueVector;
	 expValueVector.push_back(expValue);
	 // p->exp_2
	 auto weightValue = visitForValue(p->exp_2);
	 // p->ident_ = valueOf(p->exp_1) : p->exp_2
	 string resolvedName = scope()->resolveName(p->ident_);
	 auto predicate = make_shared<Predicate>(resolvedName,expValueVector);
	 emitWeightedClause(weightValue,singlePredicate(predicate));
	 returnValue(unit);
 }
 
 void LogicProcessor::visitBareDecl(BareDecl *p){
	 // Type for p->ident_ == p->type_
	 // No clauses
	 valueStack.push(make_shared<LiteralValue>(sys,make_shared<shimmrType::UnitTypeValue>()));
 }
 
 void LogicProcessor::visitEFuncDecl(EFuncDecl *p){
	 // Firstly create the predicate corresponding to calling this elemetn
	 auto name = scope()->resolveName(p->ident_);
	 vector<shared_ptr<Value>> argValues;
	 for(auto argument : *p->listargument_) {
		 argument->accept(this);
		 auto value = argumentNames[0];
		 argValues.push_back(make_shared<VariableValue>(sys,scope()->resolve(value)->type(),value));
		 argumentNames.clear();
	 }
	 auto predicate = make_shared<Predicate>(name,argValues);
	 // Add this predicate to the LHS of all rules descendent from this point
	 context.push_back(predicate);
	 // Enter child scope and visit statement block
	 auto child = scope()->children.find(p)->second;
	 scopeStack.push(child);
	 auto expValue = visitForValue(p->statementblock_);
	 scopeStack.pop();
	 // Create return value predicate
	 string returnName("!" + name);
	 vector<shared_ptr<Value>> returnArgValues;
	 returnArgValues.push_back(expValue);
	 auto retPredicate = make_shared<Predicate>(returnName,returnArgValues);
	 // Emit return value predicate
	 emitClause(singlePredicate(retPredicate));
	 // Remove this as condition from LHS
	 context.pop_back();

	 returnValue(unit);
 }
 
 void LogicProcessor::visitEFuncDeclWithType(EFuncDeclWithType *p){
	 // Firstly create the predicate corresponding to calling this elemetn
	 auto name = scope()->resolveName(p->ident_);
	 vector<shared_ptr<Value>> argValues;
	 for(auto argument : *p->listargument_) {
		 argument->accept(this);
		 auto value = argumentNames[0];
		 argValues.push_back(make_shared<VariableValue>(sys,scope()->resolve(value)->type(),value));
		 argumentNames.clear();
	 }
	 auto predicate = make_shared<Predicate>(name,argValues);
	 // Add this predicate to the LHS of all rules descendent from this point
	 context.push_back(predicate);
	 // Enter child scope and visit statement block
	 auto child = scope()->children.find(p)->second;
	 scopeStack.push(child);
	 auto expValue = visitForValue(p->statementblock_);
	 scopeStack.pop();
	 // Create return value predicate
	 string returnName("!" + name);
	 vector<shared_ptr<Value>> returnArgValues;
	 returnArgValues.push_back(expValue);
	 auto retPredicate = make_shared<Predicate>(returnName,returnArgValues);
	 // Emit return value predicate
	 emitClause(singlePredicate(retPredicate));
	 // Remove this as condition from LHS
	 context.pop_back();

	 returnValue(unit);
 }
 
 void LogicProcessor::visitForStatement(ForStatement *p){
	 // x \in p->exp_ => p->statementblock_
	 auto setValue = visitForValue(p->exp_);
	 vector<shared_ptr<Value>> setValues;

	 auto child = scope()->children.find(p)->second;
	 scopeStack.push(child);

	 auto counterValue = make_shared<VariableValue>(sys,scope()->resolve(p->ident_)->type(),scope()->resolveName(p->ident_));
	 setValues.push_back(counterValue);
	 setValues.push_back(setValue);
	 auto setPredicate = make_shared<Predicate>(IN,setValues);
	 context.push_back(setPredicate);

	 auto statValue = visitForValue(p->statementblock_);

	 scopeStack.pop();

	 auto anonValue = anonVariable(expressionTypes.find(p)->second);

	 // Rule of form: @in(i,range) -> @idx(anon,i,s)
	 vector<shared_ptr<Value>> collBuildValues;
	 collBuildValues.push_back(anonValue);
	 collBuildValues.push_back(counterValue);
	 collBuildValues.push_back(statValue);
	 emitClause(singlePredicate(make_shared<Predicate>(IDX,collBuildValues)));

	 context.pop_back();

	 returnValue(anonValue);
 }
 
 void LogicProcessor::visitIfStatement(IfStatement *p){
	 
	 auto conditionPredicate = visitForPredicate(p);
	 context.push_back(conditionPredicate);

	 auto child = scope()->children.find(p)->second;
	 scopeStack.push(child);
	 
	 auto expPred = visit(p->statementblock_);

	 scopeStack.pop();
	 
	 auto anon = anonVariable(expressionTypes.find(p)->second);

	 // cond -> @some(anon,exp)
	 vector<shared_ptr<Value>> someValues;
	 someValues.push_back(anon);
	 someValues.push_back(expPred.first);

	 emitClause(singlePredicate(make_shared<Predicate>(SOME,someValues)));

	 context.pop_back();

	 // @none(anon) v cond
	 vector<shared_ptr<Value>> noneValues;
	 noneValues.push_back(anon);

	 vector<shared_ptr<Predicate>> nonePreds;
	 nonePreds.push_back(make_shared<Predicate>(NONE,noneValues));
	 nonePreds.push_back(conditionPredicate);

	 emitClause(nonePreds);

	 returnValue(anon);
 }
 
 void LogicProcessor::visitIfElseStatement(IfElseStatement *p){
	 // p->exp_ => p->statementblock_ v p->elseblock_
	 auto conditionPredicate = visitForPredicate(p);
	 context.push_back(conditionPredicate);

	 auto child = scope()->children.find(p)->second;
	 scopeStack.push(child);

	 auto expPred = visit(p->statementblock_);

	 // makeChildScope(p)
 }
 
 void LogicProcessor::visitElseIfBlock(ElseIfBlock *p){
	 // p ^ p->exp_ => p->statementblock_ 
	 // makeChildScope(p)
 }
 
 void LogicProcessor::visitElseIf2Block(ElseIf2Block *p){
	 // p ^ p->exp_ => p->statementblock_1 v p->elseblock_
	 // makeChildScope(p)
 }
 
 void LogicProcessor::visitElseBlockStat(ElseBlockStat *p){
	 // p => p->statementblock_
	 // makeChildScope(p)
 }
 
 void LogicProcessor::visitElseFailStat(ElseFailStat *p){
	 // p => F
 }
 
 void LogicProcessor::visitSomeStatement(SomeStatement *p){
	 // unique(x \in p->exp_)
	 // x \in p->exp_ => p->statementblock_
	 // makeChildScope(p)
 }
 
 void LogicProcessor::visitSomeElseStatement(SomeElseStatement *p){
	 // unique(x \in p->exp_) v p->elseblock_
	 // x \in p->exp_ => p->statementblock_
	 // makeChildScope(p)
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
	 argumentNames.push_back(p->ident_);
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

