#ifndef ABSTRACTOPERATOR_H
#define ABSTRACTOPERATOR_H

#include <QString>
#include <QVector>
#include "pawn.h"


/**
 * @class AbstractOperator
 * @brief abstract operator for define rules
 */
class AbstractOperator
{
protected:
    /**
     * @brief fixed value (in xml definition)
     */
    int fixedValue;
    /**
     * @brief pawnId (in xml definition)
     */
    QString pawnId;
public:
    /**
     * @brief Default constructor
     * @param number of pawns around for satisfy operator
     * @param pawn Id of pawns around for satisfy operator
     */
    AbstractOperator(int fixedValue, QString pawnId);
    /**
     * @brief execute
     * @param pawns list
     * @return true if number of pawn (with this id) operator fixedValue
     */
    bool execute(QVector<Pawn*>*);
    /**
     * @brief execute
     * @param number of pawn around : int
     * @return true if value operator fixedValue
     */
    virtual bool execute(int value) = 0;
};

#endif // OPERATOR_H
