#pragma once


#include <cppunit/extensions/HelperMacros.h>

class TypeTests : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(TypeTests);

	CPPUNIT_TEST(TestAnything);
	CPPUNIT_TEST(TestPrimitive);
	CPPUNIT_TEST(TestUnion);
	CPPUNIT_TEST(TestError);
	CPPUNIT_TEST(TestSet);
	CPPUNIT_TEST(TestRange);
	CPPUNIT_TEST(TestVector);

    CPPUNIT_TEST_SUITE_END();
    
	void TestAnything();
	void TestPrimitive();
	void TestUnion();
	void TestError();
	void TestSet();
	void TestRange();
	void TestVector();
};
