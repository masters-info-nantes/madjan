#ifndef __TEST_OPERATOR__
#define __TEST_OPERATOR__

#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>

#include "abstractoperator.h"
#include "equaloperator.h"
#include "greateroperator.h"
#include "loweroperator.h"

class TestOperator : public CppUnit::TestFixture {
	CPPUNIT_TEST_SUITE(TestOperator);
		CPPUNIT_TEST(executeQVectorEmptyOk);
		CPPUNIT_TEST(executeQVectorEmptyKo);
		CPPUNIT_TEST(executeQVectorFullOk);
		CPPUNIT_TEST(executeQVectorFullKo);
		CPPUNIT_TEST(executeQVectorMixedOk);
		CPPUNIT_TEST(executeQVectorMixedKo);
		CPPUNIT_TEST(equalExecuteIntOk);
		CPPUNIT_TEST(greaterExecuteIntOk);
		CPPUNIT_TEST(lowerExecuteIntOk);
	CPPUNIT_TEST_SUITE_END();

public:
    void executeQVectorEmptyOk();
    void executeQVectorEmptyKo();
    void executeQVectorFullOk();
    void executeQVectorFullKo();
    void executeQVectorMixedOk();
    void executeQVectorMixedKo();
    void equalExecuteIntOk();
    void greaterExecuteIntOk();
    void lowerExecuteIntOk();
};

#endif