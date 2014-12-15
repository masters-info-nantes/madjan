#include <QtGui/QApplication>
#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestResult.h>
#include <cppunit/ui/text/TestRunner.h>

#include "TestPawn.h"
#include "TestOperator.h"
#include "TestRule.h"
#include "TestCell.h"
#include "TestGrid.h"
#include "TestPlugin.h"
#include "TestPluginManager.h"

CPPUNIT_TEST_SUITE_REGISTRATION(TestPawn);
CPPUNIT_TEST_SUITE_REGISTRATION(TestOperator);
CPPUNIT_TEST_SUITE_REGISTRATION(TestRule);
CPPUNIT_TEST_SUITE_REGISTRATION(TestCell);
CPPUNIT_TEST_SUITE_REGISTRATION(TestGrid);
CPPUNIT_TEST_SUITE_REGISTRATION(TestPlugin);
CPPUNIT_TEST_SUITE_REGISTRATION(TestPluginManager);

int main(int argc, char *argv[]) {
	QApplication a(argc, argv);
	CppUnit::TextUi::TestRunner runner;
	CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
	runner.addTest(registry.makeTest());
	runner.run();
	return 0;
}