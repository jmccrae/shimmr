// tests.cpp : All tests for Shimmr
//
#include <stdio.h>
#include <memory>
#include <cstring>
#include "../parser/Absyn.H"
#include "../parser/Parser.H"
#include "../parser/type.h"
#include "tests.h"

CPPUNIT_TEST_SUITE_REGISTRATION(ParserTests);

Program *getAST(const char *data) {
	FILE *stream = tmpfile();
	fwrite(data,1,strlen(data),stream);
	rewind(stream);
	auto p = pProgram(stream);
	fclose(stream);
	return p;
}

void ParserTests::TestFirst() {
	auto result = getAST("def foo(Int x, Int y) { x + y }");
	CPPUNIT_ASSERT(result);
}

void ParserTests::TestAssignment() {
	auto result = getAST("val x = 3");
	CPPUNIT_ASSERT(result);
}

void ParserTests::TestIntArithExpression() {
	auto result1 = getAST("val x2 = 2 * 3;");
	CPPUNIT_ASSERT(result1);
	auto result2 = getAST("val aVariable = 2 / 3;");
	CPPUNIT_ASSERT(result2);
	auto result3 = getAST("val a323dadb = 2 + 3;");
	CPPUNIT_ASSERT(result3);
	auto result4 = getAST("val adfdfd = (2 - 3) * 6 + 2/ 7+3;");
	CPPUNIT_ASSERT(result4);
}

//void ParserTests::SimpleFailures) {
//	auto result = getAST("val 2x = 2 * 3;");
//	CPPUNIT_ASSERT(!result);
//}

void ParserTests::SimpleFloatExpr() {
	auto result1 = getAST("val x = 2.0 * 3.0");
	CPPUNIT_ASSERT(result1);
	auto result2 = getAST("val x = 2 + 3.0;");
	CPPUNIT_ASSERT(result2);
	auto result3 = getAST("val x = 2.0 * 3;");
	CPPUNIT_ASSERT(result3);
	auto result4 = getAST("val x = 2 * 3;");
	CPPUNIT_ASSERT(result4);
}

void ParserTests::SimpleBoolExpr() {
	auto result1 = getAST("val x = true");
	CPPUNIT_ASSERT(result1);
	auto result2 = getAST("val x = !true;");
	CPPUNIT_ASSERT(result2);
	auto result3 = getAST("val x = true && false;");
	CPPUNIT_ASSERT(result3);
	auto result4 = getAST("val x = true || false;");
	CPPUNIT_ASSERT(result4);
}

void ParserTests::TypedExpressions() {
	auto result = getAST("val Int x = 3;");
	CPPUNIT_ASSERT(result);
	result = getAST("val Float x = 3.0;");
	CPPUNIT_ASSERT(result);
}

void ParserTests::MultipleLines() {
	auto result = getAST("val Int x = 3; val y = 6.0;");
	CPPUNIT_ASSERT(result);
	//CPPUNIT_ASSERT_EQUAL(2,result->statements->size());
	
}

void ParserTests::IfStatement() {
	auto result = getAST("if(condition) { val x = 3; }");
	CPPUNIT_ASSERT(result);
}


void ParserTests::IfElseStatement() {
	auto result = getAST("if(x = 3) { val x = 3; } else if(x = 4) { val y = 3; } else { val z = 5; }");
	CPPUNIT_ASSERT(result);
}

void ParserTests::ComparisonStatement() {
	auto result = getAST("val x = 2 > 3;");
	CPPUNIT_ASSERT(result);
	result = getAST("val x = 2.0 < 3;");
	CPPUNIT_ASSERT(result);
	result = getAST("val x = 2 <= 3.0;");
	CPPUNIT_ASSERT(result);
	result = getAST("val x = 2.0 >= 3.0;");
	CPPUNIT_ASSERT(result);
	result = getAST("val x = (true = false);");
	CPPUNIT_ASSERT(result);
	result = getAST("val x = true != false;");
	CPPUNIT_ASSERT(result);
}

void ParserTests::VectorType() {
	auto result = getAST("val Int[1:3] x = 3;");
	CPPUNIT_ASSERT(result);
}

void ParserTests::ForLoop() {
	auto result = getAST("for(x in xs) { val y = x + 3 }");
	CPPUNIT_ASSERT(result);
}

void ParserTests::SomeLoop() {
	auto result = getAST("some(x in xs) { val y = x + 3 } else fail");
	CPPUNIT_ASSERT(result);
}

void ParserTests::FunctionDecl() {
	auto result = getAST("def Int foo(Int x) { val x = 3 }");
	CPPUNIT_ASSERT(result);
	result = getAST("def foo(Int x) { val x = 3 }");
	CPPUNIT_ASSERT(result);
}

void ParserTests::FunctionCall() {
	auto result = getAST("def foo(Int x, Int y) { x + y } ; val x = foo(3+4,2*5)");
	CPPUNIT_ASSERT(result);
}

void ParserTests::WeightedStatements() {
	auto result = getAST("val y = 3 ; y = 3 with 10");
	CPPUNIT_ASSERT(result);
	result = getAST("def foo(Int x, Int y) { x + y } ; val x = foo(3+4,2*5) with 5;");
	CPPUNIT_ASSERT(result);
}
