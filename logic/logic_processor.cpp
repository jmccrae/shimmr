#include "logic_processor.h"

#include <sstream>

using namespace std;

// TODO: Scoping

namespace shimmr {
	namespace logic {

		ProcessorResult::ProcessorResult(const std::vector<std::shared_ptr<Statement> >& s, std::shared_ptr<Value> v) 
			: stat(s),value(v) {

		}

		LogicProcessor::LogicProcessor(std::shared_ptr<shimmr::type::TypeSystem> s, std::shared_ptr<shimmr::Scope> t, std::map<Visitable*, std::shared_ptr<shimmr::type::Type >> &et) :
			sys(s), topScope(t), expressionTypes(et) {
				unit = make_shared<LiteralValue>(s, make_shared<shimmr::type::UnitTypeValue>());
				anonCounter = 1;
				ValueList empty;
				ERROR = make_shared<Predicate>("@error", empty);
				scopeStack.push(t);
		}

		LogicProcessor::~LogicProcessor() {
		}

		StatementList LogicProcessor::statements() {
			return stack.top()->stat;
		}

		string LogicProcessor::IN("@in");
		string LogicProcessor::IDX("@idx");
		string LogicProcessor::SOME("@some");
		string LogicProcessor::NONE("@none");
		string LogicProcessor::EQ("@eq");
		string LogicProcessor::TRUE("@true");
		string LogicProcessor::FALSE("@false");
		string LogicProcessor::OR("@or");
		string LogicProcessor::AND("@and");
		string LogicProcessor::NOT("@not");
		string LogicProcessor::PLUS("@plus");
		string LogicProcessor::MINUS("@minus");
		string LogicProcessor::TIMES("@times");
		string LogicProcessor::DIVIDE("@divide");
		string LogicProcessor::NEQ("@neq");
		string LogicProcessor::LT("@lt");
		string LogicProcessor::GT("@gt");
		string LogicProcessor::LEQ("@leq");
		string LogicProcessor::GEQ("@geq");
		string LogicProcessor::RANGE("@range");

		shared_ptr<ProcessorResult> LogicProcessor::visit(Visitable *p) {
			p->accept(this);
			auto r = stack.top();
			stack.pop();
			return r;
		}

		void LogicProcessor::emit(StatementList &s, shared_ptr<Value> v) {
			stack.push(make_shared<ProcessorResult>(s, v));
		}

		void LogicProcessor::emit(shared_ptr<ProcessorResult> r) {
			stack.push(r);
		}

		StatementList LogicProcessor::singlePredicate(shared_ptr<Statement> p) {
			StatementList v;
			v.push_back(p);
			return v;
		}

		shared_ptr<Value> LogicProcessor::anonVariable(shared_ptr<shimmr::type::Type> t) {
			stringstream ss;
			ss << "?" << anonCounter++;
			set<string> specifiers(scope()->functionArgs());
			specifiers.insert(scope()->iteratorArgs().begin(), scope()->iteratorArgs().end());
			return make_shared<VariableValue>(sys, t, ss.str(), specifiers);
		}

		shared_ptr<Value> LogicProcessor::anonVariable(const string& name, shared_ptr<shimmr::type::Type> t) {
			set<string> specifiers(scope()->functionArgs());
			specifiers.insert(scope()->iteratorArgs().begin(), scope()->iteratorArgs().end());
			return make_shared<VariableValue>(sys, t, name, specifiers);
		}

		shared_ptr<Value> LogicProcessor::variable(const string& id) {
			string resolvedName = scope()->resolveName(id);
			auto scopeElem = scope()->resolve(id);
			auto t = scopeElem->type();
			return make_shared<VariableValue>(sys, t, resolvedName, scopeElem->functionArgs());
		}

		void LogicProcessor::visitStatements(Statements *p) {
			auto r = visit(p->liststatement_);
			emit(r);
		}

		void LogicProcessor::visitStatementBlockStat(StatementBlockStat *p) {
			shared_ptr<shimmr::Scope> child = scope()->children.find(p)->second;
			scopeStack.push(child);
			auto r = visit(p->liststatement_);
			scopeStack.pop();
			emit(r);
		}

		void LogicProcessor::visitListStatement(ListStatement *p) {
			StatementList stats;
			shared_ptr<Value> v;
			for (auto stat : *p) {
				auto r = visit(stat);
				stats.insert(stats.end(), r->stat.begin(), r->stat.end());
				v = r->value;
			}
			emit(stats, v);
		}

		void LogicProcessor::visitDeclStat(DeclStat *p) {
			emit(visit(p->decl_));
		}

		void LogicProcessor::visitSimpleDecl(SimpleDecl *p) {
			auto r = visit(p->exp_);
			auto stats = statementBuilder(make_shared<Predicate>(EQ,variable(p->ident_),r->value));
			emit(stats->statements(), unit);
		}

		void LogicProcessor::visitTypedDecl(TypedDecl *p) {
			auto r = visit(p->exp_);
			StatementList stats(r->stat);
			ValueList vals;
			vals.push_back(variable(p->ident_));
			vals.push_back(r->value);
			stats.push_back(make_shared<Predicate>(EQ, vals));
			emit(stats, unit);
		}

		void LogicProcessor::visitSimpleDeclWith(SimpleDeclWith *p) {
			auto r1 = visit(p->exp_1);
			StatementList stats(r1->stat);
			ValueList vals;
			vals.push_back(variable(p->ident_));
			vals.push_back(r1->value);
			stats.push_back(make_shared<Predicate>(EQ, vals));
			auto r2 = visit(p->exp_2);
			StatementList stats2(r2->stat);
			stats2.push_back(make_shared<Weight>(stats, r2->value));
			emit(stats2, unit);
		}

		void LogicProcessor::visitTypedDeclWith(TypedDeclWith *p) {
			auto r1 = visit(p->exp_1);
			StatementList stats(r1->stat);
			ValueList vals;
			vals.push_back(variable(p->ident_));
			vals.push_back(r1->value);
			stats.push_back(make_shared<Predicate>(EQ, vals));
			auto r2 = visit(p->exp_2);
			StatementList stats2(r2->stat);
			stats2.push_back(make_shared<Weight>(stats, r2->value));
			emit(stats2, unit);
		}

		void LogicProcessor::visitBareDecl(BareDecl *p) {
			static StatementList empty;
			emit(empty, unit);
		}

		void LogicProcessor::visitEFuncDecl(EFuncDecl *p) {
			// Firstly create the predicate corresponding to calling this element
			auto name = scope()->resolveName(p->ident_);
			ValueList argValues;
			for (auto argument : *p->listargument_) {
				argument->accept(this);
				auto value = argumentNames[0];
				argValues.push_back(make_shared<VariableValue>(sys, scope()->resolve(value)->type(), value));
				argumentNames.clear();
			}
			auto predicate = make_shared<Predicate>(name, argValues);

			// Enter child scope and visit statement block
			auto child = scope()->children.find(p)->second;
			scopeStack.push(child);
			auto r = visit(p->statementblock_);
			scopeStack.pop();
			// Create return value predicate
			string returnName("!" + name);
			auto fType = (shimmr::type::FunctionType*)scope()->resolve(p->ident_)->type().get();
			auto var = anonVariable(returnName, fType->returnType());
			StatementList stats(r->stat);
			ValueList eqVals;
			eqVals.push_back(var);
			eqVals.push_back(r->value);
			stats.push_back(make_shared<Predicate>(EQ, eqVals));
			auto predStat = singlePredicate(predicate);
			auto impl = make_shared<Implication>(predStat, stats);
			auto implPred = singlePredicate(impl);
			emit(implPred, unit);
		}

		void LogicProcessor::visitEFuncDeclWithType(EFuncDeclWithType *p) {
			// Firstly create the predicate corresponding to calling this elemetn
			auto name = scope()->resolveName(p->ident_);
			ValueList argValues;
			for (auto argument : *p->listargument_) {
				argument->accept(this);
				auto value = argumentNames[0];
				argValues.push_back(make_shared<VariableValue>(sys, scope()->resolve(value)->type(), value));
				argumentNames.clear();
			}
			auto predicate = make_shared<Predicate>(name, argValues);

			// Enter child scope and visit statement block
			auto child = scope()->children.find(p)->second;
			scopeStack.push(child);
			auto r = visit(p->statementblock_);
			scopeStack.pop();
			// Create return value predicate
			string returnName("!" + name);
			auto fType = (shimmr::type::FunctionType*)scope()->resolve(p->ident_)->type().get();
			auto var = anonVariable(returnName, fType->returnType());
			StatementList stats(r->stat);
			ValueList eqValues;
			eqValues.push_back(var);
			eqValues.push_back(r->value);
			stats.push_back(make_shared<Predicate>(EQ, eqValues));
			auto predStat = singlePredicate(predicate);
			auto impl = make_shared<Implication>(predStat, stats);
			auto implPred = singlePredicate(impl);
			emit(implPred, unit);
		}

		void LogicProcessor::visitForStatement(ForStatement *p) {
			// x \in p->exp_ => p->statementblock_
			auto setValue = visit(p->exp_);
			ValueList setValues;

			auto child = scope()->children.find(p)->second;
			scopeStack.push(child);

			auto counterValue = make_shared<VariableValue>(sys, scope()->resolve(p->ident_)->type(), scope()->resolveName(p->ident_));
			setValues.push_back(counterValue);
			setValues.push_back(setValue->value);
			auto setPredicate = make_shared<Predicate>(IN, setValues);

			auto statValue = visit(p->statementblock_);

			scopeStack.pop();

			auto anonValue = anonVariable(expressionTypes.find(p)->second);

			StatementList stats(setValue->stat);
			auto setStat = singlePredicate(setPredicate);
			stats.push_back(make_shared<Implication>(setStat, statValue->stat));
			ValueList inValues;
			inValues.push_back(anonValue);
			inValues.push_back(counterValue);
			inValues.push_back(statValue->value);
			auto inStat = singlePredicate(make_shared<Predicate>(IN, inValues));
			stats.push_back(make_shared<Implication>(setStat, inStat));

			emit(stats, anonValue);
		}

		void LogicProcessor::visitIfStatement(IfStatement *p) {
			auto conditionPredicate = visit(p);
			ValueList cpValues;
			cpValues.push_back(conditionPredicate->value);
			auto conditionPred = make_shared<Predicate>(TRUE, cpValues);

			auto child = scope()->children.find(p)->second;
			scopeStack.push(child);

			auto expPred = visit(p->statementblock_);

			scopeStack.pop();

			auto anon = anonVariable(expressionTypes.find(p)->second);

			// cond -> @some(anon,exp)
			ValueList someValues;
			someValues.push_back(anon);
			someValues.push_back(expPred->value);

			// @none(anon) v cond
			ValueList noneValues;
			noneValues.push_back(anon);

			StatementList nonePreds;
			nonePreds.push_back(make_shared<Predicate>(NONE, noneValues));
			nonePreds.push_back(conditionPred);

			StatementList stats(conditionPredicate->stat);
			auto condStat = singlePredicate(conditionPred);
			auto someStat = singlePredicate(make_shared<Predicate>(SOME, someValues));
			stats.push_back(make_shared<Implication>(condStat, expPred->stat));
			stats.push_back(make_shared<Implication>(condStat, someStat));
			stats.push_back(make_shared<Disjunction>(condStat, nonePreds));

			emit(stats, anon);
		}

		void LogicProcessor::visitIfElseStatement(IfElseStatement *p) {
			auto conditionPredicate = visit(p);
			ValueList condVals;
			condVals.push_back(conditionPredicate->value);
			auto conditionPred = make_shared<Predicate>(TRUE, condVals);

			auto child = scope()->children.find(p)->second;
			scopeStack.push(child);

			auto expPred = visit(p->statementblock_);

			scopeStack.pop();

			auto elsePred = visit(p->elseblock_);

			auto anon = anonVariable(expressionTypes.find(p)->second);

			ValueList trueValues;
			trueValues.push_back(anon);
			trueValues.push_back(expPred->value);

			ValueList falseValues;
			falseValues.push_back(anon);
			falseValues.push_back(elsePred->value);

			StatementList nonePreds(elsePred->stat);
			nonePreds.push_back(conditionPred);

			StatementList stats(conditionPredicate->stat);
			auto condStat = singlePredicate(conditionPred);
			auto eqStat = singlePredicate(make_shared<Predicate>(EQ, trueValues));
			stats.push_back(make_shared<Implication>(condStat, expPred->stat));
			stats.push_back(make_shared<Implication>(condStat, eqStat));
			stats.push_back(make_shared<Disjunction>(condStat, nonePreds));

			emit(stats, anon);
		}

		void LogicProcessor::visitElseIfBlock(ElseIfBlock *p) {
			auto conditionPredicate = visit(p);
			ValueList cpValues;
			cpValues.push_back(conditionPredicate->value);
			auto conditionPred = make_shared<Predicate>(TRUE, cpValues);

			auto child = scope()->children.find(p)->second;
			scopeStack.push(child);

			auto expPred = visit(p->statementblock_);

			scopeStack.pop();

			auto anon = anonVariable(expressionTypes.find(p)->second);

			// cond -> @some(anon,exp)
			ValueList someValues;
			someValues.push_back(anon);
			someValues.push_back(expPred->value);

			// @none(anon) v cond
			ValueList noneValues;
			noneValues.push_back(anon);

			StatementList nonePreds;
			nonePreds.push_back(make_shared<Predicate>(NONE, noneValues));
			nonePreds.push_back(conditionPred);

			StatementList stats(conditionPredicate->stat);
			auto condStat = singlePredicate(conditionPred);
			auto someStat = singlePredicate(make_shared<Predicate>(SOME, someValues));
			stats.push_back(make_shared<Implication>(condStat, expPred->stat));
			stats.push_back(make_shared<Implication>(condStat, someStat));
			stats.push_back(make_shared<Disjunction>(condStat, nonePreds));

			emit(stats, anon);
		}

		void LogicProcessor::visitElseIf2Block(ElseIf2Block *p) {
			auto conditionPredicate = visit(p);
			ValueList condVals;
			condVals.push_back(conditionPredicate->value);
			auto conditionPred = make_shared<Predicate>(TRUE, condVals);

			auto child = scope()->children.find(p)->second;
			scopeStack.push(child);

			auto expPred = visit(p->statementblock_);

			scopeStack.pop();

			auto elsePred = visit(p->elseblock_);

			auto anon = anonVariable(expressionTypes.find(p)->second);

			ValueList trueValues;
			trueValues.push_back(anon);
			trueValues.push_back(expPred->value);

			ValueList falseValues;
			falseValues.push_back(anon);
			falseValues.push_back(elsePred->value);

			StatementList nonePreds(elsePred->stat);
			nonePreds.push_back(conditionPred);

			StatementList stats(conditionPredicate->stat);
			auto condStat = singlePredicate(conditionPred);
			auto eqStat = singlePredicate(make_shared<Predicate>(EQ, trueValues));
			stats.push_back(make_shared<Implication>(condStat, expPred->stat));
			stats.push_back(make_shared<Implication>(condStat, eqStat));
			stats.push_back(make_shared<Disjunction>(condStat, nonePreds));

			emit(stats, anon);
		}

		void LogicProcessor::visitElseBlockStat(ElseBlockStat *p) {
			auto child = scope()->children.find(p)->second;
			scopeStack.push(child);

			auto expPred = visit(p->statementblock_);

			scopeStack.pop();

			emit(expPred);
		}

		void LogicProcessor::visitElseFailStat(ElseFailStat *p) {
			ValueList empty;
			auto fail = make_shared<Predicate>(FALSE,empty);
			auto failStats = singlePredicate(fail);

			emit(failStats,unit);
		}

		void LogicProcessor::visitSomeStatement(SomeStatement *p) {
			auto setValue = visit(p->exp_);
			ValueList setValues;

			auto child = scope()->children.find(p)->second;
			scopeStack.push(child);

			auto counterValue = make_shared<VariableValue>(sys, scope()->resolve(p->ident_)->type(), scope()->resolveName(p->ident_));
			setValues.push_back(counterValue);
			setValues.push_back(setValue->value);
			auto setPredicate = make_shared<Predicate>(IN, setValues);

			auto statValue = visit(p->statementblock_);

			scopeStack.pop();

			auto anonValue = anonVariable(expressionTypes.find(p)->second);

			StatementList stats(setValue->stat);
			StatementList oneofStats(statValue->stat);
			oneofStats.push_back(setPredicate);
			ValueList someValues;
			someValues.push_back(anonValue);
			someValues.push_back(statValue->value);

			auto somePred = make_shared<Predicate>(SOME,someValues);
			oneofStats.push_back(somePred);

			StatementList elseStats;
			ValueList elseValues;
			elseStats.push_back(make_shared<Predicate>(FALSE,elseValues));

			auto oneof = make_shared<OneOf>(oneofStats,elseStats,counterValue);
			stats.push_back(oneof);

			emit(stats, anonValue);
		}

		void LogicProcessor::visitSomeElseStatement(SomeElseStatement *p) {
			auto setValue = visit(p->exp_);
			ValueList setValues;

			auto child = scope()->children.find(p)->second;
			scopeStack.push(child);

			auto counterValue = make_shared<VariableValue>(sys, scope()->resolve(p->ident_)->type(), scope()->resolveName(p->ident_));
			setValues.push_back(counterValue);
			setValues.push_back(setValue->value);
			auto setPredicate = make_shared<Predicate>(IN, setValues);

			auto statValue = visit(p->statementblock_);

			scopeStack.pop();

			auto anonValue = anonVariable(expressionTypes.find(p)->second);

			StatementList stats(setValue->stat);
			StatementList oneofStats(statValue->stat);
			oneofStats.push_back(setPredicate);
			ValueList someValues;
			someValues.push_back(anonValue);
			someValues.push_back(statValue->value);

			auto somePred = make_shared<Predicate>(EQ,someValues);
			oneofStats.push_back(somePred);


			auto elseValues = visit(p->elseblock_);
			StatementList elseStats(elseValues->stat);
			ValueList elseVals;
			elseVals.push_back(anonValue);
			elseVals.push_back(elseValues->value);
			elseStats.push_back(make_shared<Predicate>(EQ,elseVals));
			
			auto oneof = make_shared<OneOf>(oneofStats,elseStats,counterValue);
			stats.push_back(oneof);

			emit(stats, anonValue);
		}

		void LogicProcessor::visitConditionalStatement(ConditionalStatement *p) {
			auto wtResult = visit(p->exp_2);
			auto expResult = visit(p->exp_1);
			StatementList stats(wtResult->stat);
			stats.push_back(make_shared<Weight>(expResult->stat,wtResult->value));

			auto anonValue = anonVariable(expressionTypes.find(p)->second);
			ValueList someValues;
			someValues.push_back(anonValue);
			someValues.push_back(expResult->value);
			stats.push_back(make_shared<Predicate>(SOME,someValues));

			emit(stats,anonValue);
		}

		void LogicProcessor::visitExpAsStatement(ExpAsStatement *p) {
			emit(visit(p->exp_));
		}

		void LogicProcessor::visitEOr(EOr *p) {
			auto result1 = visit(p->exp_1);
			auto result2 = visit(p->exp_2);
			
			auto anon = anonVariable(sys->Bool);
			ValueList orValues;
			orValues.push_back(result1->value);
			orValues.push_back(result2->value);
			orValues.push_back(anon);

			StatementList stats;
			stats.push_back(make_shared<Disjunction>(result1->stat,result2->stat));
			stats.push_back(make_shared<Predicate>(OR,orValues));

			emit(stats,anon);
		}

		void LogicProcessor::visitEAnd(EAnd *p) {
			auto result1 = visit(p->exp_1);
			auto result2 = visit(p->exp_2);
			
			auto anon = anonVariable(sys->Bool);
			ValueList andValues;
			andValues.push_back(result1->value);
			andValues.push_back(result2->value);
			andValues.push_back(anon);

			StatementList stats(result1->stat);
			stats.insert(stats.end(),result2->stat.begin(),result2->stat.end());
			stats.push_back(make_shared<Predicate>(AND,andValues));

			emit(stats,anon);
		}

		void LogicProcessor::visitEEquals(EEquals *p) {
			auto result1 = visit(p->exp_1);
			auto result2 = visit(p->exp_2);
			
			auto anon = anonVariable(sys->Bool);
			ValueList eqValues;
			eqValues.push_back(result1->value);
			eqValues.push_back(result2->value);
			eqValues.push_back(anon);


			StatementList stats(result1->stat);
			stats.insert(stats.end(),result2->stat.begin(),result2->stat.end());
			stats.push_back(make_shared<Predicate>(EQ,eqValues));

			emit(stats,anon);
		}

		void LogicProcessor::visitENEq(ENEq *p) {
			auto result1 = visit(p->exp_1);
			auto result2 = visit(p->exp_2);
			
			auto anon = anonVariable(sys->Bool);
			ValueList eqValues;
			eqValues.push_back(result1->value);
			eqValues.push_back(result2->value);
			eqValues.push_back(anon);

			StatementList stats(result1->stat);
			stats.insert(stats.end(),result2->stat.begin(),result2->stat.end());
			stats.push_back(make_shared<Predicate>(NEQ,eqValues));

			emit(stats,anon);
		}

		void LogicProcessor::visitELeq(ELeq *p) {
			auto result1 = visit(p->exp_1);
			auto result2 = visit(p->exp_2);
			
			auto anon = anonVariable(sys->Bool);
			ValueList eqValues;
			eqValues.push_back(result1->value);
			eqValues.push_back(result2->value);
			eqValues.push_back(anon);

			StatementList stats(result1->stat);
			stats.insert(stats.end(),result2->stat.begin(),result2->stat.end());
			stats.push_back(make_shared<Predicate>(LEQ,eqValues));

			emit(stats,anon);
		}

		void LogicProcessor::visitEGeq(EGeq *p) {
			
			auto result1 = visit(p->exp_1);
			auto result2 = visit(p->exp_2);
			
			auto anon = anonVariable(sys->Bool);
			ValueList eqValues;
			eqValues.push_back(result1->value);
			eqValues.push_back(result2->value);
			eqValues.push_back(anon);

			StatementList stats(result1->stat);
			stats.insert(stats.end(),result2->stat.begin(),result2->stat.end());
			stats.push_back(make_shared<Predicate>(GEQ,eqValues));

			emit(stats,anon);
		}

		void LogicProcessor::visitELessThan(ELessThan *p) {
			
			auto result1 = visit(p->exp_1);
			auto result2 = visit(p->exp_2);
			
			auto anon = anonVariable(sys->Bool);
			ValueList eqValues;
			eqValues.push_back(result1->value);
			eqValues.push_back(result2->value);
			eqValues.push_back(anon);

			StatementList stats(result1->stat);
			stats.insert(stats.end(),result2->stat.begin(),result2->stat.end());
			stats.push_back(make_shared<Predicate>(LT,eqValues));

			emit(stats,anon);
		}

		void LogicProcessor::visitEGreaterThan(EGreaterThan *p) {
			
			auto result1 = visit(p->exp_1);
			auto result2 = visit(p->exp_2);
			
			auto anon = anonVariable(sys->Bool);
			ValueList eqValues;
			eqValues.push_back(result1->value);
			eqValues.push_back(result2->value);
			eqValues.push_back(anon);

			StatementList stats(result1->stat);
			stats.insert(stats.end(),result2->stat.begin(),result2->stat.end());
			stats.push_back(make_shared<Predicate>(GT,eqValues));

			emit(stats,anon);
		}

		void LogicProcessor::visitEAdd(EAdd *p) {
			auto result1 = visit(p->exp_1);
			auto result2 = visit(p->exp_2);
			
			auto anon = anonVariable(expressionTypes.find(p)->second);
			ValueList eqValues;
			eqValues.push_back(result1->value);
			eqValues.push_back(result2->value);
			eqValues.push_back(anon);

			StatementList stats(result1->stat);
			stats.insert(stats.end(),result2->stat.begin(),result2->stat.end());
			stats.push_back(make_shared<Predicate>(PLUS,eqValues));

			emit(stats,anon);
		}

		void LogicProcessor::visitESub(ESub *p) {
			auto result1 = visit(p->exp_1);
			auto result2 = visit(p->exp_2);
			
			auto anon = anonVariable(expressionTypes.find(p)->second);
			ValueList eqValues;
			eqValues.push_back(result1->value);
			eqValues.push_back(result2->value);
			eqValues.push_back(anon);

			StatementList stats(result1->stat);
			stats.insert(stats.end(),result2->stat.begin(),result2->stat.end());
			stats.push_back(make_shared<Predicate>(MINUS,eqValues));

			emit(stats,anon);
		}

		void LogicProcessor::visitEMul(EMul *p) {
			auto result1 = visit(p->exp_1);
			auto result2 = visit(p->exp_2);
			
			auto anon = anonVariable(expressionTypes.find(p)->second);
			ValueList eqValues;
			eqValues.push_back(result1->value);
			eqValues.push_back(result2->value);
			eqValues.push_back(anon);

			StatementList stats(result1->stat);
			stats.insert(stats.end(),result2->stat.begin(),result2->stat.end());
			stats.push_back(make_shared<Predicate>(TIMES,eqValues));

			emit(stats,anon);
		}

		void LogicProcessor::visitEDiv(EDiv *p) {
			auto result1 = visit(p->exp_1);
			auto result2 = visit(p->exp_2);
			
			auto anon = anonVariable(expressionTypes.find(p)->second);
			ValueList eqValues;
			eqValues.push_back(result1->value);
			eqValues.push_back(result2->value);
			eqValues.push_back(anon);

			StatementList stats(result1->stat);
			stats.insert(stats.end(),result2->stat.begin(),result2->stat.end());
			stats.push_back(make_shared<Predicate>(DIVIDE,eqValues));

			emit(stats,anon);
		}

		void LogicProcessor::visitENot(ENot *p) {
			auto result = visit(p->exp_);
			
			auto anon = anonVariable(expressionTypes.find(p)->second);
			ValueList eqValues;
			eqValues.push_back(result->value);
			eqValues.push_back(anon);

			StatementList stats(result->stat);
			stats.push_back(make_shared<Predicate>(NOT,eqValues));

			emit(stats,anon);
		}

		void LogicProcessor::visitEIdent(EIdent *p) {
			StatementList empty;
			auto scopeElem = scope()->resolve(p->ident_);
			auto fullName = scope()->resolveName(p->ident_);
			auto var = make_shared<VariableValue>(sys, scopeElem->type(), fullName, scopeElem->functionArgs());
			emit(empty,var);
		}

		void LogicProcessor::visitEFuncCall(EFuncCall *p) {
			StatementList stats;
			auto fname = scope()->resolveName(p->ident_);
			ValueList argList;
			for(auto arg : *(p->listexp_)) {
				auto result = visit(arg);
				stats.insert(stats.end(),result->stat.begin(),result->stat.end());
				argList.push_back(result->value);
			}
			auto callPred = make_shared<Predicate>(fname,argList);
			stats.push_back(callPred);

			string returnName("!" + fname);
			auto fType = (shimmr::type::FunctionType*)scope()->resolve(p->ident_)->type().get();
			auto var = anonVariable(returnName, fType->returnType());

			emit(stats,var);
		}

		void LogicProcessor::visitArgumentDef(ArgumentDef *p) {
			argumentNames.push_back(p->ident_);
		}

		void LogicProcessor::visitERange(ERange *p) {
			StatementList stats;
			ValueList rangeValues;
			auto anon = anonVariable(expressionTypes.find(p)->second);
			rangeValues.push_back(anon);
			rangeValues.push_back(make_shared<LiteralValue>(sys,make_shared<shimmr::type::IntTypeValue>(p->integer_1)));			
			rangeValues.push_back(make_shared<LiteralValue>(sys,make_shared<shimmr::type::IntTypeValue>(p->integer_2)));
			stats.push_back(make_shared<Predicate>(RANGE,rangeValues));

			emit(stats,anon);
		}

		void LogicProcessor::visitESet(ESet *p) {
			StatementList stats;
			auto anon = anonVariable(expressionTypes.find(p)->second);
			for(auto elem : *(p->listsettypeelem_)) {
				ValueList inValues;
				inValues.push_back(anon);
				auto result = visit(elem);
				inValues.push_back(result->value);
				stats.push_back(make_shared<Predicate>(IN,inValues));
			}

			emit(stats,anon);
		}

		void LogicProcessor::visitListArgument(ListArgument *p) {
			// EMPTY
		}

		void LogicProcessor::visitEInt(EInt *p) {
			StatementList empty;
			auto value = make_shared<LiteralValue>(sys, make_shared<shimmr::type::IntTypeValue>(p->integer_));
			emit(empty,value);
		}

		void LogicProcessor::visitEFloat(EFloat *p) {
			StatementList empty;
			auto value = make_shared<LiteralValue>(sys, make_shared<shimmr::type::FloatTypeValue>(p->double_));
			emit(empty,value);
		}

		void LogicProcessor::visitEString(EString *p) {
			static StatementList empty;
			auto value = make_shared<LiteralValue>(sys, make_shared<shimmr::type::StringTypeValue>(p->string_));
			emit(empty,value);
		}

		void LogicProcessor::visitListExp(ListExp *p) {
		}

		void LogicProcessor::visitEType(EType *p) {
			// EMPTY
		}

		void LogicProcessor::visitVectorType(VectorType *p) {
			// EMPTY
		}

		void LogicProcessor::visitRangeType(RangeType *p) {
			// EMPTY
		}

		void LogicProcessor::visitSetType(SetType *p) {
			// EMPTY
		}

		void LogicProcessor::visitEIntSTE(EIntSTE *p) {
			static StatementList empty;
			emit(empty, make_shared<LiteralValue>(sys,make_shared<shimmr::type::IntTypeValue>(p->integer_)));
		}

		void LogicProcessor::visitEFloatSTE(EFloatSTE *p) {
			static StatementList empty;
			emit(empty, make_shared<LiteralValue>(sys,make_shared<shimmr::type::FloatTypeValue>(p->double_)));
		}

		void LogicProcessor::visitEStringSTE(EStringSTE *p) {
			static StatementList empty;
			emit(empty, make_shared<LiteralValue>(sys,make_shared<shimmr::type::StringTypeValue>(p->string_)));
		}

		void LogicProcessor::visitListSetTypeElem(ListSetTypeElem *p) {
			// yield p*
		}

		void LogicProcessor::visitProgram(Program *p) {
			// EMPTY
		}

		void LogicProcessor::visitStatementBlock(StatementBlock *p) {
			// EMPTY
		}

		void LogicProcessor::visitStatement(::Statement *p) {
			// EMPTY
		}

		void LogicProcessor::visitDecl(Decl *p) {

		}

		void LogicProcessor::visitElseBlock(ElseBlock *p) {

		}

		void LogicProcessor::visitExp(Exp *p) {

		}

		void LogicProcessor::visitArgument(Argument *p) {

		}

		void LogicProcessor::visitType(Type *p) {

		}

		void LogicProcessor::visitSetTypeElem(SetTypeElem *p) {

		}

		void LogicProcessor::visitIdent(Ident) {

		}

		void LogicProcessor::visitEVector(EVector *p) {

		}

		void LogicProcessor::visitInteger(Integer i) {

		}

		void LogicProcessor::visitDouble(Double d) {

		}

		void LogicProcessor::visitChar(Char c) {

		}

		void LogicProcessor::visitString(String s) {

		}


	}
}

