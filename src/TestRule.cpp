#include "TestRule.h"
#include "abstractoperator.h"
#include "equaloperator.h"
#include "pawn.h"

void TestRule::setUp() {
	testRule = new Rule(new Pawn("empty","empty",NULL),new Pawn("empty","empty",NULL));
}

void TestRule::tearDown() {
	delete testRule->getFrom();
	delete testRule->getTo();
	delete testRule;
	testRule = NULL;
}

void TestRule::addOperatorOk() {
	int sizeBefore = testRule->getOperators()->size();
	AbstractOperator *op = new EqualOperator(1,"");
	testRule->addOperator(op);
	int sizeAfter = testRule->getOperators()->size();
	CPPUNIT_ASSERT_EQUAL(sizeBefore+1,sizeAfter);
	CPPUNIT_ASSERT_EQUAL(op,testRule->getOperators()->last());
}

void TestRule::addOperatorNull() {
	int sizeBefore = testRule->getOperators()->size();
	AbstractOperator *op = NULL;
	testRule->addOperator(op);
	int sizeAfter = testRule->getOperators()->size();
	CPPUNIT_ASSERT_EQUAL(sizeBefore,sizeAfter);
}
