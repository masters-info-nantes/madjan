/**
 * @file Grid.h
 * @brief Grid class header
 * @author adrien, jeremy
 * @version 0.1
 */

#ifndef GRID_H
#define GRID_H

#include <QVector>
#include <QMap>
#include "cell.h"

/**
 * @class Grid
 * @brief Manage pawns locations
 *
 * Manage pawns location in the world where they will
 * evolve with under automata control
 *
 */
class Grid
{
    private:
        /*!< Grid internal representation, contains pawns */
        QVector<QVector<Cell*>*>* content;

        /*!< Grid height */
        int height;

        /*!< Grid width */
        int width;

    public:
        /**
         * @brief Create a new Grid with specified size
         *
         * @param width new width of grid
         * @param height new height of grid
         *
         * @return Created new grid
         */
        Grid(int, int);
        
        ~Grid();

        /**
         * @brief Returns cell at the given position in the grid.
         *
         * @param column grid column
         * @param width grid line
         *
         * @return Cell if it exists, NULL otherwise
         */
        Cell* getCell(int, int);

        /**
         * @brief Returns the 8 neighbors pawn of specified cell in the grid.
         * @warning Grid is considered as a tore.
         *
         * @param column grid column
         * @param width grid line
         *
         * @return List of given cell neighbors' pawn
         */
        QVector<Pawn*>* getCellNeighbors(int, int);

        /**
         * @brief Returns deep clone of this grid
         * @return Created clone
         */
        Grid* clone();

        /**
         * @brief Display grid in text mode in debug console
         */
        void debugDisplay();

        /**
         * @brief Returns grid height
         * @return grid height
         */
        int getHeight();

        /**
         * @brief Returns grid width
         * @return grid width
         */
        int getWidth();

    private:
        /**
         * @brief Check if a cell exists at the given position
         *
         * @param column grid column
         * @param width grid line
         *
         * @return true if cell exists, false otherwise
         */
        bool cellExists(int, int);

        /**
         * @brief Returns cell at the given position in the grid.
         * @warning Grid is considered as a tore.
         *
         * @param column grid column
         * @param width grid line
         *
         * @return Cell at the given position
         */
        Cell* getCellInTore(int, int);
};

#endif // GRID_H
