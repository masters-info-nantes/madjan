#ifndef __TEST_PLUGINMANAGER__
#define __TEST_PLUGINMANAGER__

#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>

#include "pluginmanager.h"

class TestPluginManager : public CppUnit::TestFixture {
	CPPUNIT_TEST_SUITE(TestPluginManager);
		CPPUNIT_TEST(setCurrentPluginOk);
		CPPUNIT_TEST(setCurrentPluginSame);
		CPPUNIT_TEST(setCurrentPluginNeg);
		CPPUNIT_TEST(setCurrentPluginSup);
	CPPUNIT_TEST_SUITE_END();

public:
    virtual void setUp();
    virtual void tearDown();
    void constructor();
    void setCurrentPluginOk();
    void setCurrentPluginSame();
    void setCurrentPluginNeg();
    void setCurrentPluginSup();

private:
    PluginManager *testPluginManager;
};

#endif