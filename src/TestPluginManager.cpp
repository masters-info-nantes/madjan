#include "TestPluginManager.h"

void TestPluginManager::setUp() {
	testPluginManager = new PluginManager();
}

void TestPluginManager::tearDown() {
	delete testPluginManager;
	testPluginManager = NULL;
}

void TestPluginManager::constructor() {
	CPPUNIT_ASSERT(testPluginManager->getCurrentPlugin() != NULL);
	CPPUNIT_ASSERT(testPluginManager->getPlugins() != NULL);
}

void TestPluginManager::setCurrentPluginOk() {
	Plugin *before = testPluginManager->getCurrentPlugin();
	//~ int size = testPluginManager->getPlugins()->size();
	testPluginManager->setCurrentPlugin(1);
	CPPUNIT_ASSERT(before != testPluginManager->getCurrentPlugin());
}

void TestPluginManager::setCurrentPluginSame() {
	Plugin *before = testPluginManager->getCurrentPlugin();
	int index = testPluginManager->getPlugins()->indexOf(before);
	testPluginManager->setCurrentPlugin(index);
	CPPUNIT_ASSERT_EQUAL(before,testPluginManager->getCurrentPlugin());
}

void TestPluginManager::setCurrentPluginNeg() {
	Plugin *before = testPluginManager->getCurrentPlugin();
	testPluginManager->setCurrentPlugin(-1);
	CPPUNIT_ASSERT_EQUAL(before,testPluginManager->getCurrentPlugin());
}

void TestPluginManager::setCurrentPluginSup() {
	Plugin *before = testPluginManager->getCurrentPlugin();
	int size = testPluginManager->getPlugins()->size();
	testPluginManager->setCurrentPlugin(size);
	CPPUNIT_ASSERT_EQUAL(before,testPluginManager->getCurrentPlugin());
}