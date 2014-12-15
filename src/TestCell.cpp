#include "TestCell.h"

void TestCell::setUp() {
	testCellNull = new Cell(NULL);
	testPawn = new Pawn("empty","empty",NULL);
	testCellOk = new Cell(testPawn);
}

void TestCell::tearDown() {
	delete testCellNull;
	testCellNull = NULL;
	delete testPawn;
	testPawn = NULL;
	delete testCellOk;
	testCellOk = NULL;
}

void TestCell::containsPawn() {
	CPPUNIT_ASSERT(testCellOk->containsPawn());
	CPPUNIT_ASSERT(!testCellNull->containsPawn());
}

void TestCell::getPawn() {
	CPPUNIT_ASSERT(testCellOk->getPawn() == testPawn);
	CPPUNIT_ASSERT(testCellNull->getPawn() == NULL);
}

void TestCell::setPawnOk() {
	testCellOk->setPawn(testPawn);
	testCellOk->setPawn(new Pawn("empty","empty",NULL));
	testCellNull->setPawn(new Pawn("empty","empty",NULL));
	CPPUNIT_ASSERT(testCellOk->containsPawn());
	CPPUNIT_ASSERT(testCellOk->containsPawn());
	CPPUNIT_ASSERT(testCellNull->containsPawn());
}

void TestCell::setPawnNull() {
	testCellOk->setPawn(NULL);
	testCellNull->setPawn(NULL);
	CPPUNIT_ASSERT(!testCellOk->containsPawn());
	CPPUNIT_ASSERT(!testCellNull->containsPawn());
}