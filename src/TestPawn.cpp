#include "TestPawn.h"

void TestPawn::setUp() {
	testPawn = new Pawn("empty","empty",NULL);
}

void TestPawn::tearDown() {
	delete testPawn;
	testPawn = NULL;
}

void TestPawn::addRuleOk() {
	int sizeBefore = testPawn->getRules()->size();
	Rule *r = new Rule(testPawn,testPawn);
	testPawn->addRule(r);
	int sizeAfter = testPawn->getRules()->size();
	CPPUNIT_ASSERT_EQUAL(sizeBefore+1,sizeAfter);
	CPPUNIT_ASSERT_EQUAL(r,testPawn->getRules()->last());
}

void TestPawn::addRuleNull() {
	int sizeBefore = testPawn->getRules()->size();
	Rule *r = NULL;
	testPawn->addRule(r);
	int sizeAfter = testPawn->getRules()->size();
	CPPUNIT_ASSERT_EQUAL(sizeBefore,sizeAfter);
}
