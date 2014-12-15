#include "TestGrid.h"

void TestGrid::setUp() {
	testGrid = new Grid(5,5);
}

void TestGrid::tearDown() {
	delete testGrid;
	testGrid = NULL;
}

void TestGrid::clone() {
	Grid *gridClone = testGrid->clone();
	CPPUNIT_ASSERT_EQUAL(testGrid->getHeight(),gridClone->getHeight());
	CPPUNIT_ASSERT_EQUAL(testGrid->getWidth(),gridClone->getWidth());
	for(int i=0;i<gridClone->getWidth();i++) {
		for(int j=0;j<gridClone->getHeight();j++) {
			CPPUNIT_ASSERT(testGrid->getCell(i,j) != gridClone->getCell(i,j));
			CPPUNIT_ASSERT_EQUAL(testGrid->getCell(i,j)->getPawn(),gridClone->getCell(i,j)->getPawn());
		}
	}
}

/* cellExists */

void TestGrid::cellExistsOkOk() {
	CPPUNIT_ASSERT(testGrid->cellExists(4,4));
}

void TestGrid::cellExistsSupOk() {
	CPPUNIT_ASSERT(!testGrid->cellExists(5,4));
}

void TestGrid::cellExistsOkSup() {
	CPPUNIT_ASSERT(!testGrid->cellExists(4,5));
}

void TestGrid::cellExistsSupSup() {
	CPPUNIT_ASSERT(!testGrid->cellExists(5,5));
}

void TestGrid::cellExistsNegOk() {
	CPPUNIT_ASSERT(!testGrid->cellExists(-1,3));
}

void TestGrid::cellExistsOkNeg() {
	CPPUNIT_ASSERT(!testGrid->cellExists(3,-1));
}

void TestGrid::cellExistsNegNeg() {
	CPPUNIT_ASSERT(!testGrid->cellExists(-1,-1));
}

void TestGrid::cellExistsNegSup() {
	CPPUNIT_ASSERT(!testGrid->cellExists(-1,5));
}

void TestGrid::cellExistsSupNeg() {
	CPPUNIT_ASSERT(!testGrid->cellExists(5,-1));
}

/* getCell */

void TestGrid::getCellOkOk() {
	CPPUNIT_ASSERT(testGrid->getCell(4,4) != NULL);
}

void TestGrid::getCellSupOk() {
	CPPUNIT_ASSERT(testGrid->getCell(5,4) == NULL);
}

void TestGrid::getCellOkSup() {
	CPPUNIT_ASSERT(testGrid->getCell(4,5) == NULL);
}

void TestGrid::getCellSupSup() {
	CPPUNIT_ASSERT(testGrid->getCell(5,5) == NULL);
}

void TestGrid::getCellNegOk() {
	CPPUNIT_ASSERT(testGrid->getCell(-1,3) == NULL);
}

void TestGrid::getCellOkNeg() {
	CPPUNIT_ASSERT(testGrid->getCell(3,-1) == NULL);
}

void TestGrid::getCellNegNeg() {
	CPPUNIT_ASSERT(testGrid->getCell(-1,-1) == NULL);
}

void TestGrid::getCellNegSup() {
	CPPUNIT_ASSERT(testGrid->getCell(-1,5) == NULL);
}

void TestGrid::getCellSupNeg() {
	CPPUNIT_ASSERT(testGrid->getCell(5,-1) == NULL);
}

/* getCellInTore */

void TestGrid::getCellInToreOkOk() {
	CPPUNIT_ASSERT(testGrid->getCellInTore(4,4) == testGrid->getCell(4,4));
}

void TestGrid::getCellInToreSupOk() {
	CPPUNIT_ASSERT(testGrid->getCellInTore(5,4) == testGrid->getCell(0,4));
}

void TestGrid::getCellInToreOkSup() {
	CPPUNIT_ASSERT(testGrid->getCellInTore(4,5) == testGrid->getCell(4,0));
}

void TestGrid::getCellInToreSupSup() {
	CPPUNIT_ASSERT(testGrid->getCellInTore(5,5) == testGrid->getCell(0,0));
}

void TestGrid::getCellInToreNegOk() {
	CPPUNIT_ASSERT(testGrid->getCellInTore(-1,3) == testGrid->getCell(4,3));
}

void TestGrid::getCellInToreOkNeg() {
	CPPUNIT_ASSERT(testGrid->getCellInTore(3,-1) == testGrid->getCell(3,4));
}

void TestGrid::getCellInToreNegNeg() {
	CPPUNIT_ASSERT(testGrid->getCellInTore(-1,-1) == testGrid->getCell(4,4));
}

void TestGrid::getCellInToreNegSup() {
	CPPUNIT_ASSERT(testGrid->getCellInTore(-1,5) == testGrid->getCell(4,0));
}

void TestGrid::getCellInToreSupNeg() {
	CPPUNIT_ASSERT(testGrid->getCellInTore(5,-1) == testGrid->getCell(0,4));
}

