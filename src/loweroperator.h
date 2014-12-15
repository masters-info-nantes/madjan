#ifndef LOWEROPERATOR_H
#define LOWEROPERATOR_H

#include"abstractoperator.h"
#include<QString>

class LowerOperator : public AbstractOperator
{
public:
    /**
     * @brief Default constructor
     * @param number of pawns around for satisfy operator
     * @param pawn Id of pawns around for satisfy operator
     */
    LowerOperator(int fixedValue, QString pawnId);

    /**
     * @brief execute
     * @param number of pawn around : int
     * @return true if value operator fixedValue
     */
    bool execute(int value);
};

#endif // LOWEROPERATOR_H
