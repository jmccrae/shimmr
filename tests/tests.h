#pragma once

#include "../parser/Absyn.H"

Program *getAST(const char *data);


#include <cppunit/extensions/HelperMacros.h>

class ParserTests : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(ParserTests);

    CPPUNIT_TEST(TestFirst);
	CPPUNIT_TEST(TestAssignment);
	CPPUNIT_TEST(TestIntArithExpression);
	CPPUNIT_TEST(SimpleFloatExpr);
	CPPUNIT_TEST(SimpleBoolExpr);
	CPPUNIT_TEST(TypedExpressions);
	CPPUNIT_TEST(MultipleLines);
	CPPUNIT_TEST(IfStatement);
	CPPUNIT_TEST(IfElseStatement);
	CPPUNIT_TEST(ComparisonStatement);
	CPPUNIT_TEST(VectorType);
	CPPUNIT_TEST(ForLoop);
	CPPUNIT_TEST(SomeLoop);
	CPPUNIT_TEST(FunctionDecl);
	CPPUNIT_TEST(FunctionCall);
	CPPUNIT_TEST(WeightedStatements);

    CPPUNIT_TEST_SUITE_END();
    
	void TestFirst();
	void TestAssignment();
	void TestIntArithExpression();
	void SimpleFloatExpr();
	void SimpleBoolExpr();
	void TypedExpressions();
	void MultipleLines();
	void IfStatement();
	void IfElseStatement();
	void ComparisonStatement();
	void VectorType();
	void ForLoop();
	void SomeLoop();
	void FunctionDecl();
	void FunctionCall();
	void WeightedStatements();
};
