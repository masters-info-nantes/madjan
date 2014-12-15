#ifndef __TEST_CELL__
#define __TEST_CELL__

#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>

#include "cell.h"

class TestCell : public CppUnit::TestFixture {
	CPPUNIT_TEST_SUITE(TestCell);
		CPPUNIT_TEST(containsPawn);
		CPPUNIT_TEST(getPawn);
		CPPUNIT_TEST(setPawnOk);
		CPPUNIT_TEST(setPawnNull);
	CPPUNIT_TEST_SUITE_END();

public:
    virtual void setUp();
    virtual void tearDown();
    void containsPawn();
    void getPawn();
    void setPawnOk();
    void setPawnNull();

private:
    Cell *testCellNull;
    Pawn *testPawn;
    Cell *testCellOk;
};

#endif