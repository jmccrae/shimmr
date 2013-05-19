#pragma once

#include <cppunit/extensions/HelperMacros.h>

class CheckerTests : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(CheckerTests);

    CPPUNIT_TEST(TCStatement);
	CPPUNIT_TEST(TCStatement);
	CPPUNIT_TEST(TCStatementBlock);
	CPPUNIT_TEST(TCSimpleDecl);
	CPPUNIT_TEST(TCTypedDecl);
	CPPUNIT_TEST(TCSimpleDeclWith);
	CPPUNIT_TEST(TCTypedDeclWith);
	CPPUNIT_TEST(TCBareDecl);
	CPPUNIT_TEST(TCFuncDecl);
	CPPUNIT_TEST(TCFuncDeclWithType);
	CPPUNIT_TEST(TCForStatement);
	CPPUNIT_TEST(TCIfStatement);
	CPPUNIT_TEST(TCIfElseStatement);
	CPPUNIT_TEST(TCElseIfBlock);
	CPPUNIT_TEST(TCElseFailBlock);
	CPPUNIT_TEST(TCSomeBlock);
	CPPUNIT_TEST(TCSomeElseBlock);
	CPPUNIT_TEST(TCConditionalStatement);
	CPPUNIT_TEST(TCEOr);
	CPPUNIT_TEST(TCEAnd);
	CPPUNIT_TEST(TCEEquals);
	CPPUNIT_TEST(TCENeq);
	CPPUNIT_TEST(TCELeq);
	CPPUNIT_TEST(TCEGeq);
	CPPUNIT_TEST(TCELessThen);
	CPPUNIT_TEST(TCEGreaterThen);
	CPPUNIT_TEST(TCEAdd);
	CPPUNIT_TEST(TCESub);
	CPPUNIT_TEST(TCEMul);
	CPPUNIT_TEST(TCEDiv);
	CPPUNIT_TEST(TCENot);
	CPPUNIT_TEST(TCEIdent);
	CPPUNIT_TEST(TCEFuncCall);
	CPPUNIT_TEST(TCEVector);
    CPPUNIT_TEST_SUITE_END();
    
    void TCStatement();
	void TCStatementBlock();
	void TCSimpleDecl();
	void TCTypedDecl();
	void TCSimpleDeclWith();
	void TCTypedDeclWith();
	void TCBareDecl();
	void TCFuncDecl();
	void TCFuncDeclWithType();
	void TCForStatement();
	void TCIfStatement();
	void TCIfElseStatement();
	void TCElseIfBlock();
	void TCElseFailBlock();
	void TCSomeBlock();
	void TCSomeElseBlock();
	void TCConditionalStatement();
	void TCEOr();
	void TCEAnd();
	void TCEEquals();
	void TCENeq();
	void TCELeq();
	void TCEGeq();
	void TCELessThen();
	void TCEGreaterThen();
	void TCEAdd();
	void TCESub();
	void TCEMul();
	void TCEDiv();
	void TCENot();
	void TCEIdent();
	void TCEFuncCall();
	void TCEVector();
};