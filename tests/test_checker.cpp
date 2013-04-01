#include <UnitTest++.h>
#include "../parser/type.h"
#include "../parser/Parser.H"
#include "../parser/scope_inferrer.h"
#include <exception>
#include <iostream>
#include "tests.h"
#include "../parser/type_checker.h"

using namespace std;
using namespace shimmr;

Program *getAST_Program(const char *data) {
	FILE *stream = tmpfile();
	fwrite(data,1,strlen(data),stream);
	rewind(stream);
	auto p = pProgram(stream);
	fclose(stream);
	return p;
}

StatementBlock *getAST_StatementBlock(const char *data) {
	FILE *stream = tmpfile();
	fwrite(data,1,strlen(data),stream);
	rewind(stream);
	auto p = pStatementBlock(stream);
	fclose(stream);
	return p;
}

ListStatement* getAST_ListStatement(const char *data) {
	FILE *stream = tmpfile();
	fwrite(data,1,strlen(data),stream);
	rewind(stream);
	auto p = pListStatement(stream);
	fclose(stream);
	return p;
}

Statement* getAST_Statement(const char * data) {
	FILE *stream = tmpfile();
	fwrite(data,1,strlen(data),stream);
	rewind(stream);
	auto p = pStatement(stream);
	fclose(stream);
	return p;
}

Decl *getAST_Decl(const char *data) {
	FILE *stream = tmpfile();
	fwrite(data,1,strlen(data),stream);
	rewind(stream);
	auto p = pDecl(stream);
	fclose(stream);
	return p;
}

ElseBlock *getAST_ElseBlock(const char *data) {
	FILE *stream = tmpfile();
	fwrite(data,1,strlen(data),stream);
	rewind(stream);
	auto p = pElseBlock(stream);
	fclose(stream);
	return p;
}

Exp *getAST_Exp(const char *data) {
	FILE *stream = tmpfile();
	fwrite(data,1,strlen(data),stream);
	rewind(stream);
	auto p = pExp(stream);
	fclose(stream);
	return p;
}

Argument *getAST_Argument(const char *data) {
	FILE *stream = tmpfile();
	fwrite(data,1,strlen(data),stream);
	rewind(stream);
	auto p = pArgument(stream);
	fclose(stream);
	return p;
}

ListArgument *getAST_ListArgument(const char *data) {
	FILE *stream = tmpfile();
	fwrite(data,1,strlen(data),stream);
	rewind(stream);
	auto p = pListArgument(stream);
	fclose(stream);
	return p;
}

ListExp *getAST_ListExp(const char *data) {
	FILE *stream = tmpfile();
	fwrite(data,1,strlen(data),stream);
	rewind(stream);
	auto p = pListExp(stream);
	fclose(stream);
	return p;
}

Type *getAST_Type(const char *data) {
	FILE *stream = tmpfile();
	fwrite(data,1,strlen(data),stream);
	rewind(stream);
	auto p = pType(stream);
	fclose(stream);
	return p;
}

SetTypeElem *getAST_SetTypeElem(const char *data) {
	FILE *stream = tmpfile();
	fwrite(data,1,strlen(data),stream);
	rewind(stream);
	auto p = pSetTypeElem(stream);
	fclose(stream);
	return p;
}

ListSetTypeElem *getAST_ListSetTypeElem(const char *data) {
	FILE *stream = tmpfile();
	fwrite(data,1,strlen(data),stream);
	rewind(stream);
	auto p = pListSetTypeElem(stream);
	fclose(stream);
	return p;
}

TEST(TCStatement) {
	auto stats = getAST_Program("3");
	auto checker = new TypeChecker(ScopeInferrer::infer(stats));
	stats->accept(checker);
	CHECK_EQUAL(1,checker->typeStackSize());
	CHECK_EQUAL(0,checker->typeValueStackSize());
	CHECK_EQUAL("3:3",checker->topType()->symbol());
	delete stats;
	delete checker;

	stats = getAST_Program("3;\"x\"");
	checker = new TypeChecker(ScopeInferrer::infer(stats));
	stats->accept(checker);
	CHECK_EQUAL(1,checker->typeStackSize());
	CHECK_EQUAL(0,checker->typeValueStackSize());
	CHECK_EQUAL("{\"x\"}",checker->topType()->symbol());
	delete stats;
	delete checker;

	stats = getAST_Program("x;3");
	checker = new TypeChecker(ScopeInferrer::infer(stats));
	stats->accept(checker);
	CHECK_EQUAL(1,checker->typeStackSize());
	CHECK_EQUAL(0,checker->typeValueStackSize());
	CHECK(checker->topType()->isError());
	delete stats;
	delete checker;
}

TEST(TCStatementBlock) {
	auto stats = getAST_StatementBlock("def foo(Int x) { val y = 3 ; y }");
	auto checker = new TypeChecker(ScopeInferrer::infer(stats));
	stats->accept(checker);
	CHECK_EQUAL(1,checker->typeStackSize());
	CHECK_EQUAL(0,checker->typeValueStackSize());
	CHECK_EQUAL("3:3",checker->topType()->symbol());
	delete stats;
	delete checker;
}

TEST(TCSimpleDecl) {
	auto decl = getAST_Decl("val x = 3");
	auto checker = new TypeChecker(ScopeInferrer::infer(decl));
	decl->accept(checker);
	CHECK_EQUAL(1,checker->typeStackSize());
	CHECK_EQUAL(0,checker->typeValueStackSize());
	CHECK_EQUAL("Unit",checker->topType()->symbol());
	delete decl;
	delete checker;
}

TEST(TCTypedDecl) {
	auto decl = getAST_Decl("val Int x = 3");
	auto checker = new TypeChecker(ScopeInferrer::infer(decl));
	decl->accept(checker);
	CHECK_EQUAL(1,checker->typeStackSize());
	CHECK_EQUAL(0,checker->typeValueStackSize());
	CHECK_EQUAL("Unit",checker->topType()->symbol());
	delete decl;
	delete checker;

	decl = getAST_Decl("val String x = 3");
	checker = new TypeChecker(ScopeInferrer::infer(decl));
	decl->accept(checker);
	CHECK_EQUAL(1,checker->typeStackSize());
	CHECK_EQUAL(0,checker->typeValueStackSize());
	CHECK(checker->topType()->isError());
	delete decl;
	delete checker;
}

TEST(TCSimpleDeclWith) {
	auto decl = getAST_Decl("val x = 3 with 5.0");
	auto checker = new TypeChecker(ScopeInferrer::infer(decl));
	decl->accept(checker);
	CHECK_EQUAL(1,checker->typeStackSize());
	CHECK_EQUAL(0,checker->typeValueStackSize());
	CHECK_EQUAL("Unit",checker->topType()->symbol());
	delete decl;
	delete checker;
}

TEST(TCTypedDeclWith) {
	auto decl = getAST_Decl("val Int x = 3 with \"5.0\"");
	auto checker = new TypeChecker(ScopeInferrer::infer(decl));
	decl->accept(checker);
	CHECK_EQUAL(1,checker->typeStackSize());
	CHECK_EQUAL(0,checker->typeValueStackSize());
	CHECK(checker->topType()->isError());
	delete decl;
	delete checker;

	decl = getAST_Decl("val String x = 3 with 5.0");
	checker = new TypeChecker(ScopeInferrer::infer(decl));
	decl->accept(checker);
	CHECK_EQUAL(1,checker->typeStackSize());
	CHECK_EQUAL(0,checker->typeValueStackSize());
	CHECK(checker->topType()->isError());
	delete decl;
	delete checker;
}

TEST(TCBareDecl) {
	auto decl = getAST_Decl("val Int x");
	auto checker = new TypeChecker(ScopeInferrer::infer(decl));
	decl->accept(checker);
	CHECK_EQUAL(1,checker->typeStackSize());
	CHECK_EQUAL(0,checker->typeValueStackSize());
	CHECK_EQUAL("Unit",checker->topType()->symbol());
	delete decl;
	delete checker;
}

TEST(TCFuncDecl) {
	auto decl = getAST_Decl("def foo(Int x) { x + 3 }");
	auto checker = new TypeChecker(ScopeInferrer::infer(decl));
	decl->accept(checker);
	CHECK_EQUAL(1,checker->typeStackSize());
	CHECK_EQUAL(0,checker->typeValueStackSize());
	CHECK_EQUAL("Unit",checker->topType()->symbol());
	delete decl;
	delete checker;
}

TEST(TCFuncDeclWithType) {
	auto decl = getAST_Decl("def Int foo(Int x) { x + 3 }");
	auto checker = new TypeChecker(ScopeInferrer::infer(decl));
	decl->accept(checker);
	CHECK_EQUAL(1,checker->typeStackSize());
	CHECK_EQUAL(0,checker->typeValueStackSize());
	CHECK_EQUAL("Unit",checker->topType()->symbol());
	delete decl;
	delete checker;

	decl = getAST_Decl("def String foo(Int x) { x + 3 }");
	checker = new TypeChecker(ScopeInferrer::infer(decl));
	decl->accept(checker);
	CHECK_EQUAL(1,checker->typeStackSize());
	CHECK_EQUAL(0,checker->typeValueStackSize());
	CHECK(checker->topType()->isError());
	delete decl;
	delete checker;
}

TEST(TCForStatement) {
	auto stat = getAST_Program("val Int[1:3] x ; for(i in x) { \"test\" }");
	auto checker = new TypeChecker(ScopeInferrer::infer(stat));
	stat->accept(checker);
	CHECK_EQUAL(1,checker->typeStackSize());
	CHECK_EQUAL(0,checker->typeValueStackSize());
	CHECK_EQUAL("{\"test\"}[1:3]",checker->topType()->symbol());
	delete stat;
	delete checker;

	stat = getAST_Program("for(i in 1:3) { \"test\" }");
	checker = new TypeChecker(ScopeInferrer::infer(stat));
	stat->accept(checker);
	CHECK_EQUAL(1,checker->typeStackSize());
	CHECK_EQUAL(0,checker->typeValueStackSize());
	CHECK_EQUAL("{\"test\"}[1:3]",checker->topType()->symbol());
	delete stat;
	delete checker;

	stat = getAST_Program("for(i in {1,2,3}) { \"test\" }");
	checker = new TypeChecker(ScopeInferrer::infer(stat));
	stat->accept(checker);
	CHECK_EQUAL(1,checker->typeStackSize());
	CHECK_EQUAL(0,checker->typeValueStackSize());
	CHECK_EQUAL("{\"test\"}[{1,2,3}]",checker->topType()->symbol());
	delete stat;
	delete checker;
}

TEST(TCIfStatement) {
	auto stat = getAST_Program("if(true){ 3 }");
	auto checker = new TypeChecker(ScopeInferrer::infer(stat));
	stat->accept(checker);
	CHECK_EQUAL(1,checker->typeStackSize());
	CHECK_EQUAL(0,checker->typeValueStackSize());
	CHECK_EQUAL("3:3|Null",checker->topType()->symbol());
	delete stat;
	delete checker;

}

TEST(TCIfElseStatement) {
	auto stat = getAST_Program("if(true) { 3 } else { 5 }");
	auto checker = new TypeChecker(ScopeInferrer::infer(stat));
	stat->accept(checker);
	CHECK_EQUAL(1,checker->typeStackSize());
	CHECK_EQUAL(0,checker->typeValueStackSize());
	CHECK_EQUAL("3:3|5:5",checker->topType()->symbol());
	delete stat;
	delete checker;
}

TEST(TCElseIfBlock) {
	auto stat = getAST_Program("if(true) { 3 } else if(2 + 1 = 3) { 4 } else { 5 }");
	auto checker = new TypeChecker(ScopeInferrer::infer(stat));
	stat->accept(checker);
	CHECK_EQUAL(1,checker->typeStackSize());
	CHECK_EQUAL(0,checker->typeValueStackSize());
	CHECK_EQUAL("3:5",checker->topType()->symbol());
	delete stat;
	delete checker;
}

TEST(TCElseFailBlock) {
	auto stat = getAST_Program("if(true) { 3 } else fail");
	auto checker = new TypeChecker(ScopeInferrer::infer(stat));
	stat->accept(checker);
	CHECK_EQUAL(1,checker->typeStackSize());
	CHECK_EQUAL(0,checker->typeValueStackSize());
	CHECK_EQUAL("3:3",checker->topType()->symbol());
	delete stat;
	delete checker;
}

TEST(TCSomeBlock) {
	auto stat = getAST_Program("val Int[1:3] x; some(i in x) { i }");
	auto checker = new TypeChecker(ScopeInferrer::infer(stat));
	stat->accept(checker);
	CHECK_EQUAL(1,checker->typeStackSize());
	CHECK_EQUAL(0,checker->typeValueStackSize());
	CHECK_EQUAL("Int|Null",checker->topType()->symbol());
	delete stat;
	delete checker;
}

TEST(TCSomeElseBlock) {
	auto stat = getAST_Program("val Int[1:3] x; some(i in x) { i } else fail");
	auto checker = new TypeChecker(ScopeInferrer::infer(stat));
	stat->accept(checker);
	CHECK_EQUAL(1,checker->typeStackSize());
	CHECK_EQUAL(0,checker->typeValueStackSize());
	CHECK_EQUAL("Int",checker->topType()->symbol());
	delete stat;
	delete checker;
}

TEST(TCConditionalStatement) {
	auto stat = getAST_Program("3 = 3 with 5");
	auto checker = new TypeChecker(ScopeInferrer::infer(stat));
	stat->accept(checker);
	CHECK_EQUAL(1,checker->typeStackSize());
	CHECK_EQUAL(0,checker->typeValueStackSize());
	CHECK_EQUAL("Bool|Null",checker->topType()->symbol());
	delete stat;
	delete checker;

	stat = getAST_Program("3 = 3 with x");
	checker = new TypeChecker(ScopeInferrer::infer(stat));
	stat->accept(checker);
	CHECK_EQUAL(1,checker->typeStackSize());
	CHECK_EQUAL(0,checker->typeValueStackSize());
	CHECK(checker->topType()->isError());
	delete stat;
	delete checker;
}

TEST(TCEOr) {
	auto stat = getAST_Program("true || false");
	auto checker = new TypeChecker(ScopeInferrer::infer(stat));
	stat->accept(checker);
	CHECK_EQUAL(1,checker->typeStackSize());
	CHECK_EQUAL(0,checker->typeValueStackSize());
	CHECK_EQUAL("Bool",checker->topType()->symbol());
	delete stat;
	delete checker;

	stat = getAST_Program("\"true\" || \"false\"");
	checker = new TypeChecker(ScopeInferrer::infer(stat));
	stat->accept(checker);
	CHECK_EQUAL(1,checker->typeStackSize());
	CHECK_EQUAL(0,checker->typeValueStackSize());
	CHECK(checker->topType()->isError());
	delete stat;
	delete checker;
}

TEST(TCEAnd) {
	auto stat = getAST_Program("true && false");
	auto checker = new TypeChecker(ScopeInferrer::infer(stat));
	stat->accept(checker);
	CHECK_EQUAL(1,checker->typeStackSize());
	CHECK_EQUAL(0,checker->typeValueStackSize());
	CHECK_EQUAL("Bool",checker->topType()->symbol());
	delete stat;
	delete checker;
}

TEST(TCEEquals) {
	auto stat = getAST_Program("true = false");
	auto checker = new TypeChecker(ScopeInferrer::infer(stat));
	stat->accept(checker);
	CHECK_EQUAL(1,checker->typeStackSize());
	CHECK_EQUAL(0,checker->typeValueStackSize());
	CHECK_EQUAL("Bool",checker->topType()->symbol());
	delete stat;
	delete checker;
}

TEST(TCENeq) {
	auto stat = getAST_Program("true != false");
	auto checker = new TypeChecker(ScopeInferrer::infer(stat));
	stat->accept(checker);
	CHECK_EQUAL(1,checker->typeStackSize());
	CHECK_EQUAL(0,checker->typeValueStackSize());
	CHECK_EQUAL("Bool",checker->topType()->symbol());
	delete stat;
	delete checker;
}


TEST(TCELeq) {
	auto stat = getAST_Program("1 <= 3");
	auto checker = new TypeChecker(ScopeInferrer::infer(stat));
	stat->accept(checker);
	CHECK_EQUAL(1,checker->typeStackSize());
	CHECK_EQUAL(0,checker->typeValueStackSize());
	CHECK_EQUAL("Bool",checker->topType()->symbol());
	delete stat;
	delete checker;

	stat = getAST_Program("1 <= true");
	checker = new TypeChecker(ScopeInferrer::infer(stat));
	stat->accept(checker);
	CHECK_EQUAL(1,checker->typeStackSize());
	CHECK_EQUAL(0,checker->typeValueStackSize());
	CHECK(checker->topType()->isError());
	delete stat;
	delete checker;
}

TEST(TCEGeq) {
	auto stat = getAST_Program("1 >= 3");
	auto checker = new TypeChecker(ScopeInferrer::infer(stat));
	stat->accept(checker);
	CHECK_EQUAL(1,checker->typeStackSize());
	CHECK_EQUAL(0,checker->typeValueStackSize());
	CHECK_EQUAL("Bool",checker->topType()->symbol());
	delete stat;
	delete checker;
}

TEST(TCELessThen) {
	auto stat = getAST_Program("1 > 3");
	auto checker = new TypeChecker(ScopeInferrer::infer(stat));
	stat->accept(checker);
	CHECK_EQUAL(1,checker->typeStackSize());
	CHECK_EQUAL(0,checker->typeValueStackSize());
	CHECK_EQUAL("Bool",checker->topType()->symbol());
	delete stat;
	delete checker;
}

TEST(TCEGreaterThen) {
	auto stat = getAST_Program("1 < 3");
	auto checker = new TypeChecker(ScopeInferrer::infer(stat));
	stat->accept(checker);
	CHECK_EQUAL(1,checker->typeStackSize());
	CHECK_EQUAL(0,checker->typeValueStackSize());
	CHECK_EQUAL("Bool",checker->topType()->symbol());
	delete stat;
	delete checker;
}

TEST(TCEAdd) {
	auto stat = getAST_Program("1 + 3");
	auto checker = new TypeChecker(ScopeInferrer::infer(stat));
	stat->accept(checker);
	CHECK_EQUAL(1,checker->typeStackSize());
	CHECK_EQUAL(0,checker->typeValueStackSize());
	CHECK_EQUAL("4:4",checker->topType()->symbol());
	delete stat;
	delete checker;

	stat = getAST_Program("val Int x ; x + 3");
	checker = new TypeChecker(ScopeInferrer::infer(stat));
	stat->accept(checker);
	CHECK_EQUAL(1,checker->typeStackSize());
	CHECK_EQUAL(0,checker->typeValueStackSize());
	CHECK_EQUAL("Int",checker->topType()->symbol());
	delete stat;
	delete checker;

	stat = getAST_Program("2.0 + 3");
	checker = new TypeChecker(ScopeInferrer::infer(stat));
	stat->accept(checker);
	CHECK_EQUAL(1,checker->typeStackSize());
	CHECK_EQUAL(0,checker->typeValueStackSize());
	CHECK_EQUAL("{5.000000}",checker->topType()->symbol());
	delete stat;
	delete checker;

	stat = getAST_Program("2 + 3.0");
	checker = new TypeChecker(ScopeInferrer::infer(stat));
	stat->accept(checker);
	CHECK_EQUAL(1,checker->typeStackSize());
	CHECK_EQUAL(0,checker->typeValueStackSize());
	CHECK_EQUAL("{5.000000}",checker->topType()->symbol());
	delete stat;
	delete checker;

	stat = getAST_Program("2.0 + 3.0");
	checker = new TypeChecker(ScopeInferrer::infer(stat));
	stat->accept(checker);
	CHECK_EQUAL(1,checker->typeStackSize());
	CHECK_EQUAL(0,checker->typeValueStackSize());
	CHECK_EQUAL("{5.000000}",checker->topType()->symbol());
	delete stat;
	delete checker;

	stat = getAST_Program("val 1:3 x ; val 2:5 y ; x + y");
	checker = new TypeChecker(ScopeInferrer::infer(stat));
	stat->accept(checker);
	CHECK_EQUAL(1,checker->typeStackSize());
	CHECK_EQUAL(0,checker->typeValueStackSize());
	CHECK_EQUAL("3:8",checker->topType()->symbol());
	delete stat;
	delete checker;
}

TEST(TCESub) {
	auto stat = getAST_Program("val 1:3 x ; val 2:5 y ; x - y");
	auto checker = new TypeChecker(ScopeInferrer::infer(stat));
	stat->accept(checker);
	CHECK_EQUAL(1,checker->typeStackSize());
	CHECK_EQUAL(0,checker->typeValueStackSize());
	CHECK_EQUAL("-4:1",checker->topType()->symbol());
	delete stat;
	delete checker;
}

TEST(TCEMul) {
	auto stat = getAST_Program("val 1:3 x ; val 2:5 y ; x * y");
	auto checker = new TypeChecker(ScopeInferrer::infer(stat));
	stat->accept(checker);
	CHECK_EQUAL(1,checker->typeStackSize());
	CHECK_EQUAL(0,checker->typeValueStackSize());
	CHECK_EQUAL("2:15",checker->topType()->symbol());
	delete stat;
	delete checker;
}

TEST(TCEDiv) {
	auto stat = getAST_Program("val 1:3 x ; val 2:5 y ; x / y");
	auto checker = new TypeChecker(ScopeInferrer::infer(stat));
	stat->accept(checker);
	CHECK_EQUAL(1,checker->typeStackSize());
	CHECK_EQUAL(0,checker->typeValueStackSize());
	CHECK_EQUAL("0:1",checker->topType()->symbol());
	delete stat;
	delete checker;
}

TEST(TCENot) {
	auto stat = getAST_Program("!true");
	auto checker = new TypeChecker(ScopeInferrer::infer(stat));
	stat->accept(checker);
	CHECK_EQUAL(1,checker->typeStackSize());
	CHECK_EQUAL(0,checker->typeValueStackSize());
	CHECK_EQUAL("Bool",checker->topType()->symbol());
	delete stat;
	delete checker;

	stat = getAST_Program("!\"true\"");
	checker = new TypeChecker(ScopeInferrer::infer(stat));
	stat->accept(checker);
	CHECK_EQUAL(1,checker->typeStackSize());
	CHECK_EQUAL(0,checker->typeValueStackSize());
	CHECK(checker->topType()->isError());
	delete stat;
	delete checker;
}

TEST(TCEIdent) {
	auto stat = getAST_Program("val Int x ; x");
	auto checker = new TypeChecker(ScopeInferrer::infer(stat));
	stat->accept(checker);
	CHECK_EQUAL(1,checker->typeStackSize());
	CHECK_EQUAL(0,checker->typeValueStackSize());
	CHECK_EQUAL("Int",checker->topType()->symbol());
	delete stat;
	delete checker;
}

TEST(TCEFuncCall) {
	auto stat = getAST_Program("def foo() { 3 } ; foo()");
	auto checker = new TypeChecker(ScopeInferrer::infer(stat));
	stat->accept(checker);
	CHECK_EQUAL(1,checker->typeStackSize());
	CHECK_EQUAL(0,checker->typeValueStackSize());
	CHECK_EQUAL("3:3",checker->topType()->symbol());
	delete stat;
	delete checker;

	stat = getAST_Program("def Int foo() { 3 } ; foo()");
	checker = new TypeChecker(ScopeInferrer::infer(stat));
	stat->accept(checker);
	CHECK_EQUAL(1,checker->typeStackSize());
	CHECK_EQUAL(0,checker->typeValueStackSize());
	CHECK_EQUAL("Int",checker->topType()->symbol());
	delete stat;
	delete checker;

	stat = getAST_Program("def Int foo(Int x) { 3 } ; foo(3)");
	checker = new TypeChecker(ScopeInferrer::infer(stat));
	stat->accept(checker);
	CHECK_EQUAL(1,checker->typeStackSize());
	CHECK_EQUAL(0,checker->typeValueStackSize());
	CHECK_EQUAL("Int",checker->topType()->symbol());
	delete stat;
	delete checker;

	stat = getAST_Program("def Int foo(Int x) { 3 } ; foo(\"3\")");
	checker = new TypeChecker(ScopeInferrer::infer(stat));
	stat->accept(checker);
	CHECK_EQUAL(1,checker->typeStackSize());
	CHECK_EQUAL(0,checker->typeValueStackSize());
	CHECK(checker->topType()->isError());
	delete stat;
	delete checker;
}

TEST(TCEVector) {
	auto stat = getAST_Program("val Int[1:3] x ; x[2]");
	auto checker = new TypeChecker(ScopeInferrer::infer(stat));
	stat->accept(checker);
	CHECK_EQUAL(1,checker->typeStackSize());
	CHECK_EQUAL(0,checker->typeValueStackSize());
	CHECK_EQUAL("Int",checker->topType()->symbol());
	delete stat;
	delete checker;

	stat = getAST_Program("val Int[1:3][5:6] x ; x[2,5]");
	checker = new TypeChecker(ScopeInferrer::infer(stat));
	stat->accept(checker);
	CHECK_EQUAL(1,checker->typeStackSize());
	CHECK_EQUAL(0,checker->typeValueStackSize());
	CHECK_EQUAL("Int",checker->topType()->symbol());
	delete stat;
	delete checker;

	stat = getAST_Program("val Int[1:3][5:6] x ; x[5,2]");
	checker = new TypeChecker(ScopeInferrer::infer(stat));
	stat->accept(checker);
	CHECK_EQUAL(1,checker->typeStackSize());
	CHECK_EQUAL(0,checker->typeValueStackSize());
	CHECK(checker->topType()->isError());
	delete stat;
	delete checker;
}