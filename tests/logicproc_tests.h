#pragma once

#include <cppunit/extensions/HelperMacros.h>
#include <string>

class LogicprocTests : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(LogicprocTests);

    CPPUNIT_TEST(testEq);
	CPPUNIT_TEST(testSTE);
	CPPUNIT_TEST(testString);
	CPPUNIT_TEST(testInt);
	CPPUNIT_TEST(testFloat);
	CPPUNIT_TEST(testRange);
	CPPUNIT_TEST(testFuncCall);
	CPPUNIT_TEST(testIdent);
	CPPUNIT_TEST(testNot);
	CPPUNIT_TEST(testDiv);
	CPPUNIT_TEST(testMul);
	CPPUNIT_TEST(testSub);
	CPPUNIT_TEST(testAdd);
	CPPUNIT_TEST(testGT);
	CPPUNIT_TEST(testLT);
	CPPUNIT_TEST(testGEQ);
	CPPUNIT_TEST(testLEQ);
	CPPUNIT_TEST(testNEQ);
	CPPUNIT_TEST(testEQ);
	CPPUNIT_TEST(testAND);
	CPPUNIT_TEST(testOR);
	CPPUNIT_TEST(testConditional);
	CPPUNIT_TEST(testSomeElse);
    CPPUNIT_TEST(testSome);
	CPPUNIT_TEST(testElseFail);
	CPPUNIT_TEST(testIfElseIfElse);
	CPPUNIT_TEST(testIfElse);
	CPPUNIT_TEST(testIf);
	CPPUNIT_TEST(testFor);
	CPPUNIT_TEST(testFuncWithType);
	CPPUNIT_TEST(testFunc);
	CPPUNIT_TEST(testSimpleDecl);
	CPPUNIT_TEST(testTypedDecl);
	CPPUNIT_TEST(testSimpleDeclWith);
	CPPUNIT_TEST(testTypedDeclWith);
	CPPUNIT_TEST(testBareDecl);

    CPPUNIT_TEST_SUITE_END();
public:
	LogicprocTests(void);
	~LogicprocTests(void);

	const std::string evaluate(const std::string& exp);

	void testEq();
	void testSTE();
	void testString();
	void testFloat();
	void testInt();
	void testRange();
	void testFuncCall();
	void testIdent();
	void testNot();
	void testDiv();
	void testMul();
	void testSub();
	void testAdd();
	void testGT();
	void testLT();
	void testGEQ();
	void testLEQ();
	void testNEQ();
	void testEQ();
	void testAND();
	void testOR();
	void testConditional();
	void testSomeElse();
	void testSome();
	void testElseFail();
	void testIfElseIfElse();
	void testIfElse();
	void testIf();
	void testFor();
	void testFuncWithType();
	void testFunc();
	void testSimpleDecl();
	void testTypedDecl();
	void testSimpleDeclWith();
	void testTypedDeclWith();
	void testBareDecl();
};

