#include "equaloperator.h"

EqualOperator::EqualOperator(int fixedValue, QString pawnId)
    : AbstractOperator(fixedValue, pawnId)
{
}

bool EqualOperator::execute(int value)
{
    return value==fixedValue;
}
