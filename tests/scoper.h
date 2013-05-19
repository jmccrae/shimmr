/* 
 * File:   scoper.h
 * Author: jmccrae
 *
 * Created on 19 May 2013, 17:24
 */

#ifndef SCOPER_H
#define	SCOPER_H

#include <cppunit/extensions/HelperMacros.h>

class ScoperTests : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(ScoperTests);

    CPPUNIT_TEST(testScope);
    CPPUNIT_TEST(testBadScope);

    CPPUNIT_TEST_SUITE_END();
    
    void testScope();
    void testBadScope();
};


#endif	/* SCOPER_H */

