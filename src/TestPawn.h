#ifndef __TEST_PAWN__
#define __TEST_PAWN__

#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>

#include "pawn.h"

class TestPawn : public CppUnit::TestFixture {
	CPPUNIT_TEST_SUITE(TestPawn);
		CPPUNIT_TEST(addRuleOk);
		CPPUNIT_TEST(addRuleNull);
	CPPUNIT_TEST_SUITE_END();

public:
    virtual void setUp();
    virtual void tearDown();
    void addRuleOk();
    void addRuleNull();

private:
    Pawn *testPawn;
};

#endif