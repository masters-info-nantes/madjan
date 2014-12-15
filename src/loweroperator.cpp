#include "loweroperator.h"

LowerOperator::LowerOperator(int fixedValue, QString pawnId)
    : AbstractOperator(fixedValue, pawnId)
{
}

bool LowerOperator::execute(int value)
{
    return value<fixedValue;
}
