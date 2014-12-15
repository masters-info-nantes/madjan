/**
 * @file Pawn.cpp
 * @brief Pawn class definition
 * @author adrien, jeremy
 * @version 0.1
 */

#include "pawn.h"


Pawn::Pawn(QString id, QString name, QString icon)
    : name(name), icon(icon), id(id)
{
    this->rules = new QVector<Rule*>();
}

Pawn::~Pawn()
{
	if(this->rules == NULL)
		return;
	QVector<Rule*>::iterator it;
    for(it=this->rules->begin();it!=this->rules->end();it++)
    {
		if((*it) != NULL)
		{
			delete *it;
		}
	}
	delete this->rules;
}

QString Pawn::getName(){
    return this->name;
}

QString Pawn::getIcon(){
    return this->icon;
}

QString Pawn::getId(){
    return this->id;
}

void Pawn::addRule(Rule* rule) {
	if(rule != NULL)
		this->rules->push_back(rule);
}

QVector<Rule*>* Pawn::getRules() {
    return this->rules;
}

