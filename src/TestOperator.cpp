#include <QVector>
#include "TestOperator.h"
#include "pawn.h"

void TestOperator::executeQVectorEmptyOk() {
	AbstractOperator *op = new EqualOperator(0,"test");
	
	QVector<Pawn*> *v = new QVector<Pawn*>();
	v->push_back(new Pawn("empty","empty",NULL));
	v->push_back(new Pawn("empty","empty",NULL));
	v->push_back(new Pawn("empty","empty",NULL));
	v->push_back(new Pawn("empty","empty",NULL));
	v->push_back(new Pawn("empty","empty",NULL));
	v->push_back(new Pawn("empty","empty",NULL));
	v->push_back(new Pawn("empty","empty",NULL));
	v->push_back(new Pawn("empty","empty",NULL));
	
	CPPUNIT_ASSERT(op->execute(v));
}

void TestOperator::executeQVectorEmptyKo() {
	AbstractOperator *op = new EqualOperator(1,"test");
	
	QVector<Pawn*> *v = new QVector<Pawn*>();
	v->push_back(new Pawn("empty","empty",NULL));
	v->push_back(new Pawn("empty","empty",NULL));
	v->push_back(new Pawn("empty","empty",NULL));
	v->push_back(new Pawn("empty","empty",NULL));
	v->push_back(new Pawn("empty","empty",NULL));
	v->push_back(new Pawn("empty","empty",NULL));
	v->push_back(new Pawn("empty","empty",NULL));
	v->push_back(new Pawn("empty","empty",NULL));
	
	CPPUNIT_ASSERT(!op->execute(v));
}

void TestOperator::executeQVectorFullOk() {
	AbstractOperator *op = new EqualOperator(8,"empty");
	
	QVector<Pawn*> *v = new QVector<Pawn*>();
	v->push_back(new Pawn("empty","empty",NULL));
	v->push_back(new Pawn("empty","empty",NULL));
	v->push_back(new Pawn("empty","empty",NULL));
	v->push_back(new Pawn("empty","empty",NULL));
	v->push_back(new Pawn("empty","empty",NULL));
	v->push_back(new Pawn("empty","empty",NULL));
	v->push_back(new Pawn("empty","empty",NULL));
	v->push_back(new Pawn("empty","empty",NULL));
	
	CPPUNIT_ASSERT(op->execute(v));
}

void TestOperator::executeQVectorFullKo() {
	AbstractOperator *op = new EqualOperator(7,"empty");
	
	QVector<Pawn*> *v = new QVector<Pawn*>();
	v->push_back(new Pawn("empty","empty",NULL));
	v->push_back(new Pawn("empty","empty",NULL));
	v->push_back(new Pawn("empty","empty",NULL));
	v->push_back(new Pawn("empty","empty",NULL));
	v->push_back(new Pawn("empty","empty",NULL));
	v->push_back(new Pawn("empty","empty",NULL));
	v->push_back(new Pawn("empty","empty",NULL));
	v->push_back(new Pawn("empty","empty",NULL));
	
	CPPUNIT_ASSERT(!op->execute(v));
}

void TestOperator::executeQVectorMixedOk() {
	AbstractOperator *op = new EqualOperator(3,"feu");
	
	QVector<Pawn*> *v = new QVector<Pawn*>();
	v->push_back(new Pawn("feu","feu",NULL));
	v->push_back(new Pawn("empty","empty",NULL));
	v->push_back(new Pawn("empty","empty",NULL));
	v->push_back(new Pawn("feu","feu",NULL));
	v->push_back(new Pawn("empty","empty",NULL));
	v->push_back(new Pawn("feu","feu",NULL));
	v->push_back(new Pawn("empty","empty",NULL));
	v->push_back(new Pawn("empty","empty",NULL));
	
	CPPUNIT_ASSERT(op->execute(v));
}

void TestOperator::executeQVectorMixedKo() {
	AbstractOperator *op = new EqualOperator(4,"feu");
	
	QVector<Pawn*> *v = new QVector<Pawn*>();
	v->push_back(new Pawn("feu","feu",NULL));
	v->push_back(new Pawn("empty","empty",NULL));
	v->push_back(new Pawn("empty","empty",NULL));
	v->push_back(new Pawn("feu","feu",NULL));
	v->push_back(new Pawn("empty","empty",NULL));
	v->push_back(new Pawn("feu","feu",NULL));
	v->push_back(new Pawn("empty","empty",NULL));
	v->push_back(new Pawn("empty","empty",NULL));
	
	CPPUNIT_ASSERT(!op->execute(v));
}

void TestOperator::equalExecuteIntOk() {
	EqualOperator op(1,"");
	CPPUNIT_ASSERT(op.execute(1));
	CPPUNIT_ASSERT(!op.execute(2));
	CPPUNIT_ASSERT(!op.execute(-1));
}


void TestOperator::greaterExecuteIntOk() {
	GreaterOperator op(1,"");
	CPPUNIT_ASSERT(!op.execute(1));
	CPPUNIT_ASSERT(op.execute(2));
	CPPUNIT_ASSERT(!op.execute(-1));
}


void TestOperator::lowerExecuteIntOk() {
	LowerOperator op(1,"");
	CPPUNIT_ASSERT(!op.execute(1));
	CPPUNIT_ASSERT(!op.execute(2));
	CPPUNIT_ASSERT(op.execute(-1));
}