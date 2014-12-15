/**
 * @file Cell.h
 * @brief Cell class header
 * @author adrien, jeremy
 * @version 0.1
 */

#ifndef CELL_H
#define CELL_H

#include "pawn.h"

/**
 * @class Cell
 * @brief Represents a cell in the grid and contains one pawn
 *
 * Manage cell style and control pawn
 *
 */
class Cell
{
    private:
        /*!< Pawn which evolve during simulation */
        Pawn* pawn;

    public:
        /**
         * @brief Create a new Cell for grid
         *
         * @param pawn Hosted pawn, can be NULL
         *
         * @return Created cell
         */
        Cell(Pawn*);

        /**
         * @brief Test if cell contains a pawn
         *
         * @return true if cell contains a pawn, false otherwise
         */
        bool containsPawn();

        /**
         * @brief Replace pawn in cell
         * @warning If cell contains pawn, it will be replaced by new one even if passed pawn is NULL
         *
         * @param pawn Pawn to be placed in cell
         *
         * @return Old pawn in cell if exists, NULL otherwise
         */
        Pawn* setPawn(Pawn*);

        /**
         * @brief Return pawn hosted by cell
         * @return pawn in cell if exists, NULL otherwise
         */
        Pawn* getPawn();
};

#endif // CELL_H
