#ifndef __TEST_RULE__
#define __TEST_RULE__

#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>

#include "rule.h"

class TestRule : public CppUnit::TestFixture {
	CPPUNIT_TEST_SUITE(TestRule);
		CPPUNIT_TEST(addOperatorOk);
		CPPUNIT_TEST(addOperatorNull);
	CPPUNIT_TEST_SUITE_END();

public:
    virtual void setUp();
    virtual void tearDown();
    void addOperatorOk();
    void addOperatorNull();
private:
    Rule *testRule;
};

#endif