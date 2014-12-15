#include "greateroperator.h"

GreaterOperator::GreaterOperator(int fixedValue, QString pawnId)
    : AbstractOperator(fixedValue, pawnId)
{
}

bool GreaterOperator::execute(int value)
{
    return value>fixedValue;
}
