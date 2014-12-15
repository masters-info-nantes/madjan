#include "rule.h"

Rule::Rule(Pawn* from, Pawn* to)
{
    this->from = from;
    this->to = to;
    this->operators = new QVector<AbstractOperator *>();
}

Rule::~Rule()
{
	if(this->operators == NULL)
		return;
	QVector<AbstractOperator*>::iterator it;
    for(it=this->operators->begin();it!=this->operators->end();it++)
    {
		if((*it) != NULL)
		{
			delete *it;
		}
	}
	delete this->operators;
}

Pawn* Rule::getFrom()
{
    return this->from;
}

Pawn* Rule::getTo()
{
    return this->to;
}

QVector<AbstractOperator*>* Rule::getOperators()
{
    return this->operators;
}

void Rule::addOperator(AbstractOperator* op)
{
	if(op != NULL)
		this->operators->push_back(op);
}
