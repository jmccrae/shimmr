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
            vector < shared_ptr < Value >> empty;
            ERROR = make_shared<Predicate>("@error", empty);
        }

        LogicProcessor::~LogicProcessor() {
        }


        string LogicProcessor::IN("@in");
        string LogicProcessor::IDX("@idx");
        string LogicProcessor::SOME("@some");
        string LogicProcessor::NONE("@none");
        string LogicProcessor::EQ("@eq");
        string LogicProcessor::TRUE("@true");

        shared_ptr<ProcessorResult> LogicProcessor::visit(Visitable *p) {
            p->accept(this);
            auto r = stack.top();
            stack.pop();
            return r;
        }

        void LogicProcessor::emit(vector<shared_ptr<Statement >> &s, shared_ptr<Value> v) {
            stack.push(make_shared<ProcessorResult>(s, v));
        }

        void LogicProcessor::emit(shared_ptr<ProcessorResult> r) {
            stack.push(r);
        }

        vector<shared_ptr<Statement >> LogicProcessor::singlePredicate(shared_ptr<Statement> p) {
            vector < shared_ptr < Statement >> v;
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
            vector < shared_ptr < Statement >> stats;
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
            vector < shared_ptr < Statement >> stats(r->stat);
            vector < shared_ptr < Value >> vals;
            vals.push_back(variable(p->ident_));
            vals.push_back(r->value);
            stats.push_back(make_shared<Predicate>(EQ, vals));
            emit(stats, unit);
        }

        void LogicProcessor::visitTypedDecl(TypedDecl *p) {
            auto r = visit(p->exp_);
            vector < shared_ptr < Statement >> stats(r->stat);
            vector < shared_ptr < Value >> vals;
            vals.push_back(variable(p->ident_));
            vals.push_back(r->value);
            stats.push_back(make_shared<Predicate>(EQ, vals));
            emit(stats, unit);
        }

        void LogicProcessor::visitSimpleDeclWith(SimpleDeclWith *p) {
            auto r1 = visit(p->exp_1);
            vector < shared_ptr < Statement >> stats(r1->stat);
            vector < shared_ptr < Value >> vals;
            vals.push_back(variable(p->ident_));
            vals.push_back(r1->value);
            stats.push_back(make_shared<Predicate>(EQ, vals));
            auto r2 = visit(p->exp_2);
            vector < shared_ptr < Statement >> stats2(r2->stat);
            stats2.push_back(make_shared<Weight>(stats, r2->value));
            emit(stats2, unit);
        }

        void LogicProcessor::visitTypedDeclWith(TypedDeclWith *p) {
            auto r1 = visit(p->exp_1);
            vector < shared_ptr < Statement >> stats(r1->stat);
            vector < shared_ptr < Value >> vals;
            vals.push_back(variable(p->ident_));
            vals.push_back(r1->value);
            stats.push_back(make_shared<Predicate>(EQ, vals));
            auto r2 = visit(p->exp_2);
            vector < shared_ptr < Statement >> stats2(r2->stat);
            stats2.push_back(make_shared<Weight>(stats, r2->value));
            emit(stats2, unit);
        }

        void LogicProcessor::visitBareDecl(BareDecl *p) {
            static vector < shared_ptr < Statement >> empty;
            emit(empty, unit);
        }

        void LogicProcessor::visitEFuncDecl(EFuncDecl *p) {
            // Firstly create the predicate corresponding to calling this elemetn
            auto name = scope()->resolveName(p->ident_);
            vector < shared_ptr < Value >> argValues;
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
            vector < shared_ptr < Statement >> stats(r->stat);
            vector < shared_ptr < Value >> eqVals;
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
            vector < shared_ptr < Value >> argValues;
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
            vector < shared_ptr < Statement >> stats(r->stat);
            vector < shared_ptr < Value >> eqValues;
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
            vector < shared_ptr < Value >> setValues;

            auto child = scope()->children.find(p)->second;
            scopeStack.push(child);

            auto counterValue = make_shared<VariableValue>(sys, scope()->resolve(p->ident_)->type(), scope()->resolveName(p->ident_));
            setValues.push_back(counterValue);
            setValues.push_back(setValue->value);
            auto setPredicate = make_shared<Predicate>(IN, setValues);

            auto statValue = visit(p->statementblock_);

            scopeStack.pop();

            auto anonValue = anonVariable(expressionTypes.find(p)->second);

            vector < shared_ptr < Statement >> stats(setValue->stat);
            auto setStat = singlePredicate(setPredicate);
            stats.push_back(make_shared<Implication>(setStat, statValue->stat));
            vector < shared_ptr < Value >> inValues;
            inValues.push_back(anonValue);
            inValues.push_back(counterValue);
            inValues.push_back(statValue->value);
            auto inStat = singlePredicate(make_shared<Predicate>(IN, inValues));
            stats.push_back(make_shared<Implication>(setStat, inStat));

            emit(stats, anonValue);
        }

        void LogicProcessor::visitIfStatement(IfStatement *p) {
            auto conditionPredicate = visit(p);
            vector < shared_ptr < Value >> cpValues;
            cpValues.push_back(conditionPredicate->value);
            auto conditionPred = make_shared<Predicate>(TRUE, cpValues);

            auto child = scope()->children.find(p)->second;
            scopeStack.push(child);

            auto expPred = visit(p->statementblock_);

            scopeStack.pop();

            auto anon = anonVariable(expressionTypes.find(p)->second);

            // cond -> @some(anon,exp)
            vector < shared_ptr < Value >> someValues;
            someValues.push_back(anon);
            someValues.push_back(expPred->value);

            // @none(anon) v cond
            vector < shared_ptr < Value >> noneValues;
            noneValues.push_back(anon);

            vector < shared_ptr < Statement >> nonePreds;
            nonePreds.push_back(make_shared<Predicate>(NONE, noneValues));
            nonePreds.push_back(conditionPred);

            vector < shared_ptr < Statement >> stats(conditionPredicate->stat);
            auto condStat = singlePredicate(conditionPred);
            auto someStat = singlePredicate(make_shared<Predicate>(SOME, someValues));
            stats.push_back(make_shared<Implication>(condStat, expPred->stat));
            stats.push_back(make_shared<Implication>(condStat, someStat));
            stats.push_back(make_shared<Disjunction>(nonePreds));

            emit(stats, anon);
        }

        void LogicProcessor::visitIfElseStatement(IfElseStatement *p) {
            auto conditionPredicate = visit(p);
            vector < shared_ptr < Value >> condVals;
            condVals.push_back(conditionPredicate->value);
            auto conditionPred = make_shared<Predicate>(TRUE, condVals);

            auto child = scope()->children.find(p)->second;
            scopeStack.push(child);

            auto expPred = visit(p->statementblock_);

            scopeStack.pop();

            auto elsePred = visit(p->elseblock_);

            auto anon = anonVariable(expressionTypes.find(p)->second);

            // cond -> @some(anon,exp)
            vector < shared_ptr < Value >> trueValues;
            trueValues.push_back(anon);
            trueValues.push_back(expPred->value);

            // @none(anon) v cond
            vector < shared_ptr < Value >> falseValues;
            falseValues.push_back(anon);
            falseValues.push_back(elsePred->value);

            vector < shared_ptr < Statement >> nonePreds(elsePred->stat);
            nonePreds.push_back(conditionPred);

            vector < shared_ptr < Statement >> stats(conditionPredicate->stat);
            auto condStat = singlePredicate(conditionPred);
            auto eqStat = singlePredicate(make_shared<Predicate>(EQ, trueValues));
            stats.push_back(make_shared<Implication>(condStat, expPred->stat));
            stats.push_back(make_shared<Implication>(condStat, eqStat));
            stats.push_back(make_shared<Disjunction>(nonePreds));

            emit(stats, anon);
        }

        void LogicProcessor::visitElseIfBlock(ElseIfBlock *p) {
            // p ^ p->exp_ => p->statementblock_ 
            // makeChildScope(p)
        }

        void LogicProcessor::visitElseIf2Block(ElseIf2Block *p) {
            // p ^ p->exp_ => p->statementblock_1 v p->elseblock_
            // makeChildScope(p)
        }

        void LogicProcessor::visitElseBlockStat(ElseBlockStat *p) {
            // p => p->statementblock_
            // makeChildScope(p)
        }

        void LogicProcessor::visitElseFailStat(ElseFailStat *p) {
            // p => F
        }

        void LogicProcessor::visitSomeStatement(SomeStatement *p) {
            // unique(x \in p->exp_)
            // x \in p->exp_ => p->statementblock_
            // makeChildScope(p)
        }

        void LogicProcessor::visitSomeElseStatement(SomeElseStatement *p) {
            // unique(x \in p->exp_) v p->elseblock_
            // x \in p->exp_ => p->statementblock_
            // makeChildScope(p)
        }

        void LogicProcessor::visitConditionalStatement(ConditionalStatement *p) {
            // p->exp_1 : p->exp_2
        }

        void LogicProcessor::visitExpAsStatement(ExpAsStatement *p) {
            // p->exp_
        }

        void LogicProcessor::visitEOr(EOr *p) {
            // p->exp_1 v p->exp_2
        }

        void LogicProcessor::visitEAnd(EAnd *p) {
            // p->exp_1
            // p->exp_2
        }

        void LogicProcessor::visitEEquals(EEquals *p) {
            // valueOf(p->exp_1) == valueOf(p->exp_2)
            // p->exp_1
            // p->exp_2
        }

        void LogicProcessor::visitENEq(ENEq *p) {
            // valueOf(p->exp_1) == valueOf(p->exp_2) => F
            // p->exp_1
            // p->exp_2
        }

        void LogicProcessor::visitELeq(ELeq *p) {
            // valueOf(p->exp_1) <= valueOf(p->exp_2)
            // p->exp_1
            // p->exp_2
        }

        void LogicProcessor::visitEGeq(EGeq *p) {
            // valueOf(p->exp_1) >= valueOf(p->exp_2)
            // p->exp_1
            // p->exp_2
        }

        void LogicProcessor::visitELessThan(ELessThan *p) {
            // valueOf(p->exp_1) < valueOf(p->exp_2)
            // p->exp_1
            // p->exp_2
        }

        void LogicProcessor::visitEGreaterThan(EGreaterThan *p) {
            // valueOf(p->exp_1) > valueOf(p->exp_2)
            // p->exp_1
            // p->exp_2
        }

        void LogicProcessor::visitEAdd(EAdd *p) {
            // valueOf(p) == valueOf(p->exp_1) + valueOf(p->exp_2)
            // p->exp_1
            // p->exp_2
        }

        void LogicProcessor::visitESub(ESub *p) {
            // valueOf(p) == valueOf(p->exp_1) - valueOf(p->exp_2)
            // p->exp_1
            // p->exp_2
        }

        void LogicProcessor::visitEMul(EMul *p) {
            // valueOf(p) == valueOf(p->exp_1) * valueOf(p->exp_2)
            // p->exp_1
            // p->exp_2
        }

        void LogicProcessor::visitEDiv(EDiv *p) {
            // valueOf(p) == valueOf(p->exp_1) / valueOf(p->exp_2)
            // p->exp_1
            // p->exp_2
        }

        void LogicProcessor::visitENot(ENot *p) {
            // p->exp_ => F
        }

        void LogicProcessor::visitEIdent(EIdent *p) {
            // p
        }

        void LogicProcessor::visitEFuncCall(EFuncCall *p) {
            // p(p->args_)
            // p->args_*
        }

        void LogicProcessor::visitArgumentDef(ArgumentDef *p) {
            argumentNames.push_back(p->ident_);
        }

        void LogicProcessor::visitERange(ERange *p) {
            // valueOf(p) == range(p->integer_1,p->integer_2)
        }

        void LogicProcessor::visitESet(ESet *p) {
            // valueOf(p) == set(p->listsettypeelem_)
        }

        void LogicProcessor::visitListArgument(ListArgument *p) {
            // EMPTY
        }

        void LogicProcessor::visitEInt(EInt *p) {
            // valueOf(p) == p->integer_
            auto value = make_shared<LiteralValue>(sys, make_shared<shimmr::type::IntTypeValue>(p->integer_));
            //			valueStack.push(value);
        }

        void LogicProcessor::visitEFloat(EFloat *p) {
            // valueOf(p) == p->double_
            auto value = make_shared<LiteralValue>(sys, make_shared<shimmr::type::FloatTypeValue>(p->double_));
            //		valueStack.push(value);
        }

        void LogicProcessor::visitEString(EString *p) {
            // valueOf(p) == p->string_
            auto value = make_shared<LiteralValue>(sys, make_shared<shimmr::type::StringTypeValue>(p->string_));
            //	valueStack.push(value); 
        }

        void LogicProcessor::visitListExp(ListExp *p) {
            // for(p2 in p) yield {
            //   valueOf(p2)
            // }
            // for(p2 in p) {
            //   p2
            // }
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
            // yield p->integer_
        }

        void LogicProcessor::visitEFloatSTE(EFloatSTE *p) {
            // yield p->double_
        }

        void LogicProcessor::visitEStringSTE(EStringSTE *p) {
            // yield p->string_
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

        void LogicProcessor::visitStatement(Statement *p) {
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

