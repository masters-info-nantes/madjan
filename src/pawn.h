/**
 * @file Pawn.h
 * @brief Pawn class header
 * @author adrien, jeremy, maxime
 * @version 0.1
 */
class Pawn;
#ifndef PAWN_H
#define PAWN_H

#include <QString>
#include <QVector>
#include "rule.h"

/**
 * @class Pawn
 * @brief Represents an entity
 *
 * A pawn is an entity which can evolve in the world
 * controled by automata
 *
 */
class Pawn
{
    private:
        /*!< Unique identifier */
        QString id;

        /*!< Pawn name */
        QString name;

        /*!< Icon for graphic representation */
        QString icon;

        /*!< List of rules */
        QVector<Rule*>* rules;

    public:
        /**
         * @brief Create a new Pawn which is in a cell
         *
         * @param id pawn id
         * @param name pawn name
         * @param icon Icon for graphic representation
         *
         * @return Created pawn
         */
        Pawn(QString,QString,QString);
		
		~Pawn();
		
        /**
         * @brief Returns pawn name property
         * @return pawn name
         */
        QString getName();

        /**
         * @brief Returns pawn icon property
         * @return pawn icon
         */
        QString getIcon();
        /*!< Unique identifier */
        QString getId();
        /*!< List of rules */
        QVector<Rule*>* getRules();
        /*!< Add a rule */
        void addRule(Rule*);
};

#endif // PAWN_H
