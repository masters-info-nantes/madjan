#ifndef EQUALOPERATOR_H
#define EQUALOPERATOR_H

#include<QString>
#include<abstractoperator.h>

class EqualOperator : public AbstractOperator
{
public:
    /**
     * @brief Default constructor
     * @param number of pawns around for satisfy operator
     * @param pawn Id of pawns around for satisfy operator
     */
    EqualOperator(int fixedValue, QString pawnId);

    /**
     * @brief execute
     * @param number of pawn around : int
     * @return true if value operator fixedValue
     */
    bool execute(int value);
};

#endif // EQUALOPERATOR_H
