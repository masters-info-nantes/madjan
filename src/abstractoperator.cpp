#include "abstractoperator.h"

AbstractOperator::AbstractOperator(int fixedValue, QString pawnId)
{
    this->fixedValue = fixedValue;
    this->pawnId = pawnId;
}

bool AbstractOperator::execute(QVector<Pawn*>* around)
{
    int nb = 0;
    for(int i = 0;i < around->size(); i++) {
        if(around->at(i)->getId() == pawnId) // count all pawn with id : pawnId
            nb++;
    }
    return this->execute(nb); // execute operateur between fixedValue and nb
}
