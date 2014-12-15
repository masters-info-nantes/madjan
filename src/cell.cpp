/** 
 * @file Cell.cpp
 * @brief Cell class definition
 * @author adrien, jeremy
 * @version 0.1
 */

#include "cell.h"


Cell::Cell(Pawn* pawn)
    : pawn(pawn)
{}

bool Cell::containsPawn(){
    return this->pawn != NULL;
}

Pawn* Cell::setPawn(Pawn* pawn){
    Pawn* oldPawn = this->pawn;
    this->pawn = pawn;
    return oldPawn;
}

Pawn* Cell::getPawn(){
    return this->pawn;
}
