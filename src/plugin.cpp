#include "plugin.h"

Plugin::Plugin(QString aName, QString aDescription, QString aVersion)
{
    this->name = aName;
    this->description = aDescription;
    this->version = aVersion;
    this->pawns = new QVector<Pawn*>();
    this->addPawn(new Pawn("empty", "Empty", NULL));
}

QString Plugin::getName()
{
    return this->name;
}

QString Plugin::getDescription()
{
    return this->description;
}

QString Plugin::getVersion()
{
    return this->version;
}

QVector<Pawn*>* Plugin::getPawns()
{
    return this->pawns;
}

bool Plugin::existPawn(QString pawnId)
{
    bool exist = false;
    for(int i = 0;i < pawns->size(); i++) {
        if(pawns->at(i)->getId() == pawnId)
        {
            exist = true;
            break;
        }
    }
    return exist;
}

void Plugin::addPawn(Pawn* pawn)
{
    if(pawn != NULL)
        this->pawns->push_back(pawn);
}

Pawn* Plugin::getPawn(QString pawnId)
{
    for(int i = 0;i < pawns->size(); i++) {
        if(pawns->at(i)->getId() == pawnId)
        {
            return pawns->at(i);
        }
    }
    return NULL;
}

void Plugin::setCellBackground(QString background)
{
    this->cellBackground = background;
}

Pawn* Plugin::getNewPawn(Pawn* from, QVector<Pawn*>* around)
{
	if(from == NULL)
		return NULL;
    Pawn* to = from;
    for(int i = 0;i < from->getRules()->size(); i++) {
        bool isValid = true;
        Rule* r = from->getRules()->at(i);
        for(int j = 0;j < r->getOperators()->size(); j++) {
            if(!r->getOperators()->at(j)->execute(around))
                isValid = false;
        }
        if (isValid)
            to = r->getTo();
    }
    return to;
}
