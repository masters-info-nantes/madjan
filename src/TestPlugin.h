#ifndef __TEST_PLUGIN__
#define __TEST_PLUGIN__

#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>

#include "plugin.h"

class TestPlugin : public CppUnit::TestFixture {
	CPPUNIT_TEST_SUITE(TestPlugin);
		CPPUNIT_TEST(addPawnOk);
		CPPUNIT_TEST(addPawnNull);
		CPPUNIT_TEST(existPawnEmptyOk);
		CPPUNIT_TEST(existPawnEmptyKo);
		CPPUNIT_TEST(existPawnFillOk);
		CPPUNIT_TEST(existPawnFillKo);
		CPPUNIT_TEST(getNewPawnOk);
		CPPUNIT_TEST(getNewPawnKo);
		CPPUNIT_TEST(getNewPawnOkAroundLess8);
		CPPUNIT_TEST(getNewPawnKoAroundLess8);
		CPPUNIT_TEST(getNewPawnEmptyAround);
		CPPUNIT_TEST(getNewPawnFromPawnNotInPlugin);
		CPPUNIT_TEST(getNewPawnTargetPawnNotInPlugin);
		CPPUNIT_TEST(getNewPawnPawnNull);
		CPPUNIT_TEST(getNewPawnAroundNull);
	CPPUNIT_TEST_SUITE_END();

public:
    virtual void setUp();
    virtual void tearDown();
    void addPawnOk();
    void addPawnNull();
    void existPawnEmptyOk();
    void existPawnEmptyKo();
    void existPawnFillOk();
    void existPawnFillKo();
	void getNewPawnOk();
	void getNewPawnKo();
	void getNewPawnOkAroundLess8();
	void getNewPawnKoAroundLess8();
	void getNewPawnEmptyAround();
	void getNewPawnFromPawnNotInPlugin();
	void getNewPawnTargetPawnNotInPlugin();
	void getNewPawnPawnNull();
	void getNewPawnAroundNull();
	
private:
    Plugin *testPlugin;
};

#endif