#include "TestPlugin.h"
#include "pawn.h"
#include "rule.h"
#include "equaloperator.h"
#include "greateroperator.h"
#include "loweroperator.h"

void TestPlugin::setUp() {
	testPlugin = new Plugin("plugin","plugin desc","1.0");
}

void TestPlugin::tearDown() {
	delete testPlugin;
	testPlugin = NULL;
}

void TestPlugin::addPawnOk() {
	int sizeBefore = testPlugin->getPawns()->size();
	Pawn *p = new Pawn("test","test",NULL);
	testPlugin->addPawn(p);
	int sizeAfter = testPlugin->getPawns()->size();
	CPPUNIT_ASSERT_EQUAL(sizeBefore+1,sizeAfter);
	CPPUNIT_ASSERT_EQUAL(p,testPlugin->getPawns()->last());
}

void TestPlugin::addPawnNull() {
	int sizeBefore = testPlugin->getPawns()->size();
	Pawn *p = NULL;
	testPlugin->addPawn(p);
	int sizeAfter = testPlugin->getPawns()->size();
	CPPUNIT_ASSERT_EQUAL(sizeBefore,sizeAfter);
}

void TestPlugin::existPawnEmptyOk() {
	CPPUNIT_ASSERT(testPlugin->existPawn("empty"));
}

void TestPlugin::existPawnEmptyKo() {
	CPPUNIT_ASSERT(!testPlugin->existPawn("test"));
}

void TestPlugin::existPawnFillOk() {
	testPlugin->addPawn(new Pawn("test","test",NULL));
	CPPUNIT_ASSERT(testPlugin->existPawn("test"));
}

void TestPlugin::existPawnFillKo() {
	testPlugin->addPawn(new Pawn("test","test",NULL));
	CPPUNIT_ASSERT(!testPlugin->existPawn("test2"));
}

void TestPlugin::getNewPawnOk() {
	Pawn *arbre = new Pawn("arbre","arbre",NULL);
	Pawn *feu = new Pawn("feu","feu",NULL);
	testPlugin->addPawn(arbre);
	testPlugin->addPawn(feu);
	
	Rule *r = new Rule(arbre,feu);
	r->addOperator(new GreaterOperator(1,"feu"));
	
	arbre->addRule(r);
	
	QVector<Pawn*> *around = new QVector<Pawn*>();
	around->push_back(new Pawn("empty","empty",NULL));
	around->push_back(new Pawn("empty","empty",NULL));
	around->push_back(new Pawn("feu","feu",NULL));
	around->push_back(new Pawn("empty","empty",NULL));
	
	around->push_back(new Pawn("feu","feu",NULL));
	around->push_back(new Pawn("empty","empty",NULL));
	around->push_back(new Pawn("empty","empty",NULL));
	around->push_back(new Pawn("empty","empty",NULL));
	
	CPPUNIT_ASSERT_EQUAL(feu,testPlugin->getNewPawn(arbre,around));
}

void TestPlugin::getNewPawnKo() {
	Pawn *arbre = new Pawn("arbre","arbre",NULL);
	Pawn *feu = new Pawn("feu","feu",NULL);
	testPlugin->addPawn(arbre);
	testPlugin->addPawn(feu);
	
	Rule *r = new Rule(arbre,feu);
	r->addOperator(new GreaterOperator(3,"feu"));
	
	arbre->addRule(r);
	
	QVector<Pawn*> *around = new QVector<Pawn*>();
	around->push_back(new Pawn("empty","empty",NULL));
	around->push_back(new Pawn("empty","empty",NULL));
	around->push_back(new Pawn("feu","feu",NULL));
	around->push_back(new Pawn("empty","empty",NULL));
	
	around->push_back(new Pawn("feu","feu",NULL));
	around->push_back(new Pawn("empty","empty",NULL));
	around->push_back(new Pawn("empty","empty",NULL));
	around->push_back(new Pawn("empty","empty",NULL));
	
	CPPUNIT_ASSERT_EQUAL(arbre,testPlugin->getNewPawn(arbre,around));
}

void TestPlugin::getNewPawnOkAroundLess8() {
	Pawn *arbre = new Pawn("arbre","arbre",NULL);
	Pawn *feu = new Pawn("feu","feu",NULL);
	testPlugin->addPawn(arbre);
	testPlugin->addPawn(feu);
	
	Rule *r = new Rule(arbre,feu);
	r->addOperator(new GreaterOperator(1,"feu"));
	
	arbre->addRule(r);
	
	QVector<Pawn*> *around = new QVector<Pawn*>();
	around->push_back(new Pawn("empty","empty",NULL));
	around->push_back(new Pawn("empty","empty",NULL));
	around->push_back(new Pawn("feu","feu",NULL));
	around->push_back(new Pawn("empty","empty",NULL));
	
	around->push_back(new Pawn("feu","feu",NULL));
	
	CPPUNIT_ASSERT_EQUAL(feu,testPlugin->getNewPawn(arbre,around));
}

void TestPlugin::getNewPawnKoAroundLess8() {
	Pawn *arbre = new Pawn("arbre","arbre",NULL);
	Pawn *feu = new Pawn("feu","feu",NULL);
	testPlugin->addPawn(arbre);
	testPlugin->addPawn(feu);
	
	Rule *r = new Rule(arbre,feu);
	r->addOperator(new GreaterOperator(3,"feu"));
	
	arbre->addRule(r);
	
	QVector<Pawn*> *around = new QVector<Pawn*>();
	around->push_back(new Pawn("empty","empty",NULL));
	around->push_back(new Pawn("empty","empty",NULL));
	around->push_back(new Pawn("feu","feu",NULL));
	around->push_back(new Pawn("empty","empty",NULL));
	
	around->push_back(new Pawn("feu","feu",NULL));
	
	CPPUNIT_ASSERT_EQUAL(arbre,testPlugin->getNewPawn(arbre,around));
}

void TestPlugin::getNewPawnEmptyAround() {
	Pawn *arbre = new Pawn("arbre","arbre",NULL);
	Pawn *feu = new Pawn("feu","feu",NULL);
	testPlugin->addPawn(arbre);
	testPlugin->addPawn(feu);
	
	Rule *r = new Rule(arbre,feu);
	r->addOperator(new GreaterOperator(1,"feu"));
	
	arbre->addRule(r);
	
	QVector<Pawn*> *around = new QVector<Pawn*>();
	
	CPPUNIT_ASSERT_EQUAL(arbre,testPlugin->getNewPawn(arbre,around));
}


void TestPlugin::getNewPawnFromPawnNotInPlugin() {
	Pawn *arbre = new Pawn("arbre","arbre",NULL);
	Pawn *feu = new Pawn("feu","feu",NULL);
	testPlugin->addPawn(feu);
	
	Rule *r = new Rule(arbre,feu);
	r->addOperator(new GreaterOperator(1,"feu"));
	
	arbre->addRule(r);
	
	QVector<Pawn*> *around = new QVector<Pawn*>();
	around->push_back(new Pawn("empty","empty",NULL));
	around->push_back(new Pawn("empty","empty",NULL));
	around->push_back(new Pawn("feu","feu",NULL));
	around->push_back(new Pawn("empty","empty",NULL));
	
	around->push_back(new Pawn("feu","feu",NULL));
	around->push_back(new Pawn("empty","empty",NULL));
	around->push_back(new Pawn("empty","empty",NULL));
	around->push_back(new Pawn("empty","empty",NULL));
	
	CPPUNIT_ASSERT_EQUAL(feu,testPlugin->getNewPawn(arbre,around));
}

void TestPlugin::getNewPawnTargetPawnNotInPlugin() {
	Pawn *arbre = new Pawn("arbre","arbre",NULL);
	Pawn *feu = new Pawn("feu","feu",NULL);
	testPlugin->addPawn(arbre);
	
	Rule *r = new Rule(arbre,feu);
	r->addOperator(new GreaterOperator(1,"feu"));
	
	arbre->addRule(r);
	
	QVector<Pawn*> *around = new QVector<Pawn*>();
	around->push_back(new Pawn("empty","empty",NULL));
	around->push_back(new Pawn("empty","empty",NULL));
	around->push_back(new Pawn("feu","feu",NULL));
	around->push_back(new Pawn("empty","empty",NULL));
	
	around->push_back(new Pawn("feu","feu",NULL));
	around->push_back(new Pawn("empty","empty",NULL));
	around->push_back(new Pawn("empty","empty",NULL));
	around->push_back(new Pawn("empty","empty",NULL));
	
	CPPUNIT_ASSERT_EQUAL(feu,testPlugin->getNewPawn(arbre,around));
}

void TestPlugin::getNewPawnPawnNull() {
	CPPUNIT_ASSERT(testPlugin->getNewPawn(NULL,new QVector<Pawn*>()) == NULL);
}

void TestPlugin::getNewPawnAroundNull() {
	Pawn *arbre = new Pawn("arbre","arbre",NULL);
	CPPUNIT_ASSERT_EQUAL(arbre,testPlugin->getNewPawn(arbre,NULL));
}