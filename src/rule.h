class Rule;
#ifndef RULE_H
#define RULE_H

#include "pawn.h"
#include "abstractoperator.h"
#include <QVector>

class AbstractOperator;
/**
 * @class Rule
 * @brief rule for pawn
 */
class Rule
{
    /**
     * @brief From pawn
     */
    Pawn* from;
    /**
     * @brief To pawn
     */
    Pawn* to;
    /**
     * @brief List of operators
     */
    QVector<AbstractOperator*>* operators;
public:
    /**
     * @brief Default constructor
     */
    Rule(Pawn*,Pawn*);
    
    ~Rule();
    
    /**
     * @brief getFrom
     * @return from pawn
     */
    Pawn* getFrom();
    /**
     * @brief getTo
     * @return to pawn
     */
    Pawn* getTo();
    /**
     * @brief getOperators
     * @return operator list
     */
    QVector<AbstractOperator*>* getOperators();
    /**
     * @brief addOperator
     * @param operator
     */
    void addOperator(AbstractOperator*);
};

#endif // RULE_H
