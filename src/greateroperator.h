#ifndef GREATEROPERATOR_H
#define GREATEROPERATOR_H

#include"abstractoperator.h"
#include<QString>

class GreaterOperator : public AbstractOperator
{
public:
    /**
     * @brief Default constructor
     * @param number of pawns around for satisfy operator
     * @param pawn Id of pawns around for satisfy operator
     */
    GreaterOperator(int fixedValue, QString pawnId);

    /**
     * @brief execute
     * @param number of pawn around : int
     * @return true if value operator fixedValue
     */
    bool execute(int value);
};

#endif // GREATEROPERATOR_H
