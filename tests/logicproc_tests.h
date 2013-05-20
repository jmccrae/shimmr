#pragma once

#include <cppunit/extensions/HelperMacros.h>
#include <string>

class LogicprocTests : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(LogicprocTests);

    CPPUNIT_TEST(testEq);
    
    CPPUNIT_TEST_SUITE_END();
public:
	LogicprocTests(void);
	~LogicprocTests(void);

	const std::string evaluate(const std::string& exp);

	void testEq();
};

