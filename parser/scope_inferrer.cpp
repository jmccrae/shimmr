#include "scope_inferrer.h"

#include <algorithm>
#include <sstream>

using namespace std;

namespace shimmr {

    ScopeInferrer::ScopeInferrer(void) : root(Scope::root()) {
        current = root.get();
    }

    ScopeInferrer::~ScopeInferrer(void) {
    }

    shared_ptr<Scope> ScopeInferrer::infer(Visitable *p) {
        ScopeInferrer *inferrer = new ScopeInferrer();
        p->accept(inferrer);
        auto rv = inferrer->root;
        delete inferrer;
        return rv;
    }

    void ScopeInferrer::visitStatements(Statements *p) {
        p->liststatement_->accept(this);
    }

    void ScopeInferrer::visitStatementBlockStat(StatementBlockStat *p) {
        auto childScope = current->makeChildScope(p);
        current = childScope.get();
        p->liststatement_->accept(this);
        current = childScope->parent;
    }

    void ScopeInferrer::visitListStatement(ListStatement *p) {
        for (auto it = p->begin(); it != p->end(); ++it) {
            (*it)->accept(this);
        }
    }

    void ScopeInferrer::visitDeclStat(DeclStat *p) {
        p->decl_->accept(this);
    }

    void ScopeInferrer::visitSimpleDecl(SimpleDecl *p) {
        string varName(p->ident_);
        auto elem = make_shared<ScopeElement>(current, nullptr, p);
        current->assign(elem, varName);
        p->exp_->accept(this);
    }

    void ScopeInferrer::visitTypedDecl(TypedDecl *p) {
        string varName(p->ident_);
        p->type_->accept(this);
        auto type = typeStack.top();
        typeStack.pop();
        auto elem = make_shared<ScopeElement>(current, type, p);
        current->assign(elem, varName);
        p->exp_->accept(this);
    }

    void ScopeInferrer::visitSimpleDeclWith(SimpleDeclWith *p) {
        string varName(p->ident_);
        auto elem = make_shared<ScopeElement>(current, nullptr, p);
        current->assign(elem, varName);
        p->exp_1->accept(this);
        p->exp_2->accept(this);
    }

    void ScopeInferrer::visitTypedDeclWith(TypedDeclWith *p) {
        string varName(p->ident_);
        p->type_->accept(this);
        auto type = typeStack.top();
        typeStack.pop();
        auto elem = make_shared<ScopeElement>(current, type, p);
        current->assign(elem, varName);
        p->exp_1->accept(this);
        p->exp_2->accept(this);
    }

    void ScopeInferrer::visitBareDecl(BareDecl *p) {
        string varName(p->ident_);
        p->type_->accept(this);
        auto type = typeStack.top();
        typeStack.pop();
        auto elem = make_shared<ScopeElement>(current, type, p);
        current->assign(elem, varName);
    }

    void ScopeInferrer::visitEFuncDecl(EFuncDecl *p) {
        string varName(p->ident_);
        auto elem = make_shared<ScopeElement>(current, nullptr, p);
        current->assign(elem, varName);

        auto s = current->makeChildScope(p);
        current = s.get();

        p->listargument_->accept(this);
        p->statementblock_->accept(this);

        current = current->parent;
    }

    void ScopeInferrer::visitEFuncDeclWithType(EFuncDeclWithType *p) {
        string varName(p->ident_);
        p->type_->accept(this);
        auto retType = typeStack.top();
        typeStack.pop();

        auto s = current->makeChildScope(p);
        current = s.get();

        int i = typeStack.size();
        p->listargument_->accept(this);
        vector < shared_ptr < shimmr::type::Type >> argList;
        int end = typeStack.size();
        for (; i < end; i++) {
            argList.push_back(typeStack.top());
            typeStack.pop();
        }
        reverse(argList.begin(), argList.end());
        auto type = current->typeSystem->makeFunction(retType, argList);
        auto elem = make_shared<ScopeElement>(current, type, p);
        p->statementblock_->accept(this);
        current = current->parent;

        current->assign(elem, varName);
    }

    void ScopeInferrer::visitForStatement(ForStatement *p) {
        p->exp_->accept(this);
        auto s = current->makeChildScope(p);
        current = s.get();

        auto elem = make_shared<ScopeElement>(current, nullptr, p);
        string varName(p->ident_);
        current->assign(elem, varName);
        auto fullName = current->resolveName(varName);
        current->addIteratorArg(fullName);
        p->statementblock_->accept(this);

        current = current->parent;
    }

    void ScopeInferrer::visitIfStatement(IfStatement *p) {
        p->exp_->accept(this);
        auto s = current->makeChildScope(p);
        current = s.get();
        p->statementblock_->accept(this);
        current = current->parent;
    }

    void ScopeInferrer::visitIfElseStatement(IfElseStatement *p) {
        p->exp_->accept(this);
        auto s = current->makeChildScope(p);
        current = s.get();
        p->statementblock_->accept(this);
        current = current->parent;
        p->elseblock_->accept(this);
    }

    void ScopeInferrer::visitElseIfBlock(ElseIfBlock *p) {
        p->exp_->accept(this);
        auto s = current->makeChildScope(p);
        current = s.get();
        p->statementblock_->accept(this);
        current = current->parent;
    }

    void ScopeInferrer::visitElseIf2Block(ElseIf2Block *p) {
        p->exp_->accept(this);
        auto s = current->makeChildScope(p);
        current = s.get();
        p->statementblock_->accept(this);
        current = current->parent;
        p->elseblock_->accept(this);

    }

    void ScopeInferrer::visitElseBlockStat(ElseBlockStat *p) {
        auto s = current->makeChildScope(p);
        current = s.get();
        p->statementblock_->accept(this);
        current = current->parent;
    }

    void ScopeInferrer::visitElseFailStat(ElseFailStat *p) {

    }

    void ScopeInferrer::visitSomeStatement(SomeStatement *p) {
        p->exp_->accept(this);
        auto s = current->makeChildScope(p);
        current = s.get();

        auto elem = make_shared<ScopeElement>(current, nullptr, p);
        string varName(p->ident_);
        current->assign(elem, varName);

        p->statementblock_->accept(this);
        current = current->parent;
    }

    void ScopeInferrer::visitSomeElseStatement(SomeElseStatement *p) {
        p->exp_->accept(this);
        auto s = current->makeChildScope(p);
        current = s.get();

        auto elem = make_shared<ScopeElement>(current, nullptr, p);
        string varName(p->ident_);
        current->assign(elem, varName);

        p->statementblock_->accept(this);
        current = current->parent;
        p->elseblock_->accept(this);

    }

    void ScopeInferrer::visitConditionalStatement(ConditionalStatement *p) {
        p->exp_1->accept(this);
        p->exp_2->accept(this);
    }

    void ScopeInferrer::visitExpAsStatement(ExpAsStatement *p) {
        p->exp_->accept(this);

    }

    void ScopeInferrer::visitEOr(EOr *p) {
        p->exp_1->accept(this);
        p->exp_2->accept(this);

    }

    void ScopeInferrer::visitEAnd(EAnd *p) {

        p->exp_1->accept(this);
        p->exp_2->accept(this);
    }

    void ScopeInferrer::visitEEquals(EEquals *p) {

        p->exp_1->accept(this);
        p->exp_2->accept(this);
    }

    void ScopeInferrer::visitENEq(ENEq *p) {

        p->exp_1->accept(this);
        p->exp_2->accept(this);
    }

    void ScopeInferrer::visitELeq(ELeq *p) {

        p->exp_1->accept(this);
        p->exp_2->accept(this);
    }

    void ScopeInferrer::visitEGeq(EGeq *p) {

        p->exp_1->accept(this);
        p->exp_2->accept(this);
    }

    void ScopeInferrer::visitELessThan(ELessThan *p) {
        p->exp_1->accept(this);
        p->exp_2->accept(this);

    }

    void ScopeInferrer::visitEGreaterThan(EGreaterThan *p) {

        p->exp_1->accept(this);
        p->exp_2->accept(this);
    }

    void ScopeInferrer::visitEAdd(EAdd *p) {

        p->exp_1->accept(this);
        p->exp_2->accept(this);
    }

    void ScopeInferrer::visitESub(ESub *p) {

        p->exp_1->accept(this);
        p->exp_2->accept(this);
    }

    void ScopeInferrer::visitEMul(EMul *p) {

        p->exp_1->accept(this);
        p->exp_2->accept(this);
    }

    void ScopeInferrer::visitEDiv(EDiv *p) {

        p->exp_1->accept(this);
        p->exp_2->accept(this);
    }

    void ScopeInferrer::visitENot(ENot *p) {

        p->exp_->accept(this);
    }

    void ScopeInferrer::visitEIdent(EIdent *p) {

    }

    void ScopeInferrer::visitEFuncCall(EFuncCall *p) {
        p->listexp_->accept(this);
    }

    void ScopeInferrer::visitERange(ERange *p) {

    }

    void ScopeInferrer::visitESet(ESet *p) {

    }

    void ScopeInferrer::visitArgumentDef(ArgumentDef *p) {
        string varName(p->ident_);
        p->type_->accept(this);
        auto type = typeStack.top();
        auto elem = make_shared<ScopeElement>(current, type, p);
        current->assign(elem, varName);
        current->addFunctionArg(current->resolveName(p->ident_));
    }

    void ScopeInferrer::visitListArgument(ListArgument *p) {
        for (auto it = p->begin(); it != p->end(); ++it) {
            (*it)->accept(this);
        }
    }

    void ScopeInferrer::visitEInt(EInt *p) {

    }

    void ScopeInferrer::visitEFloat(EFloat *p) {

    }

    void ScopeInferrer::visitEString(EString *p) {

    }

    void ScopeInferrer::visitListExp(ListExp *p) {
        for (auto it = p->begin(); it != p->end(); ++it) {
            (*it)->accept(this);
        }
    }

    void ScopeInferrer::visitEType(EType *p) {
        auto type = current->typeSystem->get(p->ident_);
        if (type) {
            typeStack.push(type);
        } else {
            string errMsg("Undefined type: ");
            errMsg.append(p->ident_);
            typeStack.push(current->typeSystem->makeError(p->line_number, errMsg));
        }
    }

    void ScopeInferrer::visitVectorType(VectorType *p) {
        p->type_1->accept(this);
        auto cType = typeStack.top();
        typeStack.pop();
        if (!cType->isError()) {
            p->type_2->accept(this);
            auto iType = typeStack.top();
            typeStack.pop();
            if (!iType->isError()) {
                auto type = current->typeSystem->makeVector(cType, iType);
                typeStack.push(type);
            } else {
                typeStack.push(iType);
            }
        } else {
            typeStack.push(cType);
        }
    }

    void ScopeInferrer::visitRangeType(RangeType *p) {
        if (p->integer_1 <= p->integer_2) {
            auto type = current->typeSystem->makeRange(p->integer_1, p->integer_2);
            typeStack.push(type);
        } else {
            stringstream msg;
            msg << "Invalid range from " << p->integer_1
                    << " to " << p->integer_2;
            auto type = current->typeSystem->makeError(p->line_number, msg.str());
            typeStack.push(type);
        }
    }

    void ScopeInferrer::visitSetType(SetType *p) {
        int i = typeValueStack.size();
        p->listsettypeelem_->accept(this);
        int e = typeValueStack.size();
        std::set < std::shared_ptr<shimmr::type::TypeValue>, decltype(shimmr::type::compareTypeValue)*> values(shimmr::type::compareTypeValue);
        for (; i < e; i++) {
            values.insert(typeValueStack.top());
            typeValueStack.pop();
        }
        typeStack.push(current->typeSystem->makeSet(values));
    }

    void ScopeInferrer::visitEIntSTE(EIntSTE *p) {
        auto ste = make_shared<shimmr::type::IntTypeValue>(p->integer_);
        typeValueStack.push(ste);
    }

    void ScopeInferrer::visitEFloatSTE(EFloatSTE *p) {
        auto ste = make_shared<shimmr::type::FloatTypeValue>(p->double_);
        typeValueStack.push(ste);
    }

    void ScopeInferrer::visitEStringSTE(EStringSTE *p) {
        string val(p->string_);
        auto ste = make_shared<shimmr::type::StringTypeValue>(val);
        typeValueStack.push(ste);
    }

    void ScopeInferrer::visitListSetTypeElem(ListSetTypeElem *p) {
        for (auto it = p->begin(); it != p->end(); ++it) {
            (*it)->accept(this);
        }
    }

    void ScopeInferrer::visitIdent(Ident p) {

    }

    void ScopeInferrer::visitEVector(EVector *p) {

    }

    void ScopeInferrer::visitProgram(Program *p) {

    }

    void ScopeInferrer::visitStatementBlock(StatementBlock *p) {

    }

    void ScopeInferrer::visitStatement(Statement *p) {

    }

    void ScopeInferrer::visitDecl(Decl *p) {

    }

    void ScopeInferrer::visitElseBlock(ElseBlock *p) {

    }

    void ScopeInferrer::visitExp(Exp *p) {

    }

    void ScopeInferrer::visitArgument(Argument *p) {

    }

    void ScopeInferrer::visitType(Type *p) {

    }

    void ScopeInferrer::visitSetTypeElem(SetTypeElem *p) {

    }

    void ScopeInferrer::visitInteger(Integer i) {

    }

    void ScopeInferrer::visitDouble(Double d) {

    }

    void ScopeInferrer::visitChar(Char c) {

    }

    void ScopeInferrer::visitString(String s) {

    }
}