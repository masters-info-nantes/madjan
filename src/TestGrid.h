#ifndef __TEST_GRID__
#define __TEST_GRID__

#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>

#define private public
#include "grid.h"
#undef private

class TestGrid : public CppUnit::TestFixture {
	CPPUNIT_TEST_SUITE(TestGrid);
		CPPUNIT_TEST(clone);
		
		CPPUNIT_TEST(cellExistsOkOk);
		CPPUNIT_TEST(cellExistsSupOk);
		CPPUNIT_TEST(cellExistsOkSup);
		CPPUNIT_TEST(cellExistsSupSup);
		CPPUNIT_TEST(cellExistsNegOk);
		CPPUNIT_TEST(cellExistsOkNeg);
		CPPUNIT_TEST(cellExistsNegNeg);
		CPPUNIT_TEST(cellExistsNegSup);
		CPPUNIT_TEST(cellExistsSupNeg);
		
		CPPUNIT_TEST(getCellOkOk);
		CPPUNIT_TEST(getCellSupOk);
		CPPUNIT_TEST(getCellOkSup);
		CPPUNIT_TEST(getCellSupSup);
		CPPUNIT_TEST(getCellNegOk);
		CPPUNIT_TEST(getCellOkNeg);
		CPPUNIT_TEST(getCellNegNeg);
		CPPUNIT_TEST(getCellNegSup);
		CPPUNIT_TEST(getCellSupNeg);
		
		CPPUNIT_TEST(getCellInToreOkOk);
		CPPUNIT_TEST(getCellInToreSupOk);
		CPPUNIT_TEST(getCellInToreOkSup);
		CPPUNIT_TEST(getCellInToreSupSup);
		CPPUNIT_TEST(getCellInToreNegOk);
		CPPUNIT_TEST(getCellInToreOkNeg);
		CPPUNIT_TEST(getCellInToreNegNeg);
		CPPUNIT_TEST(getCellInToreNegSup);
		CPPUNIT_TEST(getCellInToreSupNeg);
	CPPUNIT_TEST_SUITE_END();

public:
    virtual void setUp();
    virtual void tearDown();
    void clone();
    void cellExistsOkOk();
	void cellExistsSupOk();
	void cellExistsOkSup();
	void cellExistsSupSup();
	void cellExistsNegOk();
	void cellExistsOkNeg();
	void cellExistsNegNeg();
	void cellExistsNegSup();
	void cellExistsSupNeg();
	
    void getCellOkOk();
	void getCellSupOk();
	void getCellOkSup();
	void getCellSupSup();
	void getCellNegOk();
	void getCellOkNeg();
	void getCellNegNeg();
	void getCellNegSup();
	void getCellSupNeg();
	
    void getCellInToreOkOk();
	void getCellInToreSupOk();
	void getCellInToreOkSup();
	void getCellInToreSupSup();
	void getCellInToreNegOk();
	void getCellInToreOkNeg();
	void getCellInToreNegNeg();
	void getCellInToreNegSup();
	void getCellInToreSupNeg();
	

private:
    Grid *testGrid;
};

#endif