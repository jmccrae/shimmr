// tests.cpp : All tests for Shimmr
//
#include <unittest++/UnitTest++.h>
#include "../parser/Absyn.H"
#include "../parser/Parser.H"
#include "../parser/type.h"

#include <stdio.h>
#include <memory>
#include <cstring>

Program *getAST(const char *data) {
	FILE *stream = tmpfile();
	fwrite(data,1,strlen(data),stream);
	rewind(stream);
	auto p = pProgram(stream);
	fclose(stream);
	return p;
}

TEST(TestFirst) {
	auto result = getAST("def foo(Int x, Int y) { x + y }");
	CHECK(result);
}

TEST(TestAssignment) {
	auto result = getAST("val x = 3");
	CHECK(result);
}

TEST(TestIntArithExpression) {
	auto result1 = getAST("val x2 = 2 * 3;");
	CHECK(result1);
	auto result2 = getAST("val aVariable = 2 / 3;");
	CHECK(result2);
	auto result3 = getAST("val a323dadb = 2 + 3;");
	CHECK(result3);
	auto result4 = getAST("val adfdfd = (2 - 3) * 6 + 2/ 7+3;");
	CHECK(result4);
}

//TEST(SimpleFailures) {
//	auto result = getAST("val 2x = 2 * 3;");
//	CHECK(!result);
//}

TEST(SimpleFloatExpr) {
	auto result1 = getAST("val x = 2.0 * 3.0");
	CHECK(result1);
	auto result2 = getAST("val x = 2 + 3.0;");
	CHECK(result2);
	auto result3 = getAST("val x = 2.0 * 3;");
	CHECK(result3);
	auto result4 = getAST("val x = 2 * 3;");
	CHECK(result4);
}

TEST(SimpleBoolExpr) {
	auto result1 = getAST("val x = true");
	CHECK(result1);
	auto result2 = getAST("val x = !true;");
	CHECK(result2);
	auto result3 = getAST("val x = true && false;");
	CHECK(result3);
	auto result4 = getAST("val x = true || false;");
	CHECK(result4);
}

TEST(TypedExpressions) {
	auto result = getAST("val Int x = 3;");
	CHECK(result);
	result = getAST("val Float x = 3.0;");
	CHECK(result);
}

TEST(MultipleLines) {
	auto result = getAST("val Int x = 3; val y = 6.0;");
	CHECK(result);
	//CHECK_EQUAL(2,result->statements->size());
	
}

TEST(IfStatement) {
	auto result = getAST("if(condition) { val x = 3; }");
	CHECK(result);
}


TEST(IfElseStatement) {
	auto result = getAST("if(x = 3) { val x = 3; } else if(x = 4) { val y = 3; } else { val z = 5; }");
	CHECK(result);
}

TEST(ComparisonStatement) {
	auto result = getAST("val x = 2 > 3;");
	CHECK(result);
	result = getAST("val x = 2.0 < 3;");
	CHECK(result);
	result = getAST("val x = 2 <= 3.0;");
	CHECK(result);
	result = getAST("val x = 2.0 >= 3.0;");
	CHECK(result);
	result = getAST("val x = (true = false);");
	CHECK(result);
	result = getAST("val x = true != false;");
	CHECK(result);
}

TEST(VectorType) {
	auto result = getAST("val Int[1:3] x = 3;");
	CHECK(result);
}

TEST(ForLoop) {
	auto result = getAST("for(x in xs) { val y = x + 3 }");
	CHECK(result);
}

TEST(SomeLoop) {
	auto result = getAST("some(x in xs) { val y = x + 3 } else fail");
	CHECK(result);
}

TEST(FunctionDecl) {
	auto result = getAST("def Int foo(Int x) { val x = 3 }");
	CHECK(result);
	result = getAST("def foo(Int x) { val x = 3 }");
	CHECK(result);
}

TEST(FunctionCall) {
	auto result = getAST("def foo(Int x, Int y) { x + y } ; val x = foo(3+4,2*5)");
	CHECK(result);
}

TEST(WeightedStatements) {
	auto result = getAST("val y = 3 ; y = 3 with 10");
	CHECK(result);
	result = getAST("def foo(Int x, Int y) { x + y } ; val x = foo(3+4,2*5) with 5;");
	CHECK(result);
}

// run all tests
int main(int argc, char **argv)
{
	auto rv = UnitTest::RunAllTests();
	//cout << "Press any key to exit...";
	//cin.get();
	return rv;
}

