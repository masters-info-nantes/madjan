#ifndef CONTROLER_H
#define CONTROLER_H

#include "pluginmanager.h"

#include <grid.h>
#include <pawn.h>
#include <QMap>

class Controler : public QObject
{
    Q_OBJECT

    PluginManager* pluginManager;
    Pawn* currentPawn;
    Grid* currentGrid;
    int frame;
    int maxGenerations;
    QMap<Pawn*, QString>* pawnStop;

public:
    /**
     * @brief default constructor
     * @return Controler
     */
    Controler();

    /**
     * @brief get Plugin Manager;
     * @return PluginManager
     */
    PluginManager* getPluginManager();

    /**
     * @brief get Current Pawn
     * @return Pawn
     */
    Pawn* getCurrentPawn();

    /**
     * @brief get Current Grid
     * @return Grid
     */
    Grid* getCurrentGrid();

    /**
     * @brief change current plugin
     * @param plugin name
     */
    void changeCurrentPlugin(QString);
public slots:

    /**
     * @brief set current pown
     * @param pawn id
     */
    void setCurrentPawn(int);

    /**
     * @brief set current plugin
     * @param plugin id
     */
    void setCurrentPlugin(int);

    /**
     * @brief Iterate one turn in grid
     */
    bool nextFrame();

    /**
     * @brief change Grid Size
     * @param width
     * @param height
     */
    void changeGridSize(int,int);

    /**
     * @brief get Frame
     * @return curent frame
     */
    int getFrame();

    /**
     * @brief Returns grid distribution;
     * @return grid width
     */
    QMap<Pawn*, double>* getDistribution();

    /**
     * @brief respect stop rules
     * @return true if can go to next step
     */
    bool checkStepDistribution();

    /**
     * @brief generateGrid Générate a new Grid in currentGrid and respect the pawn partition in pawnPartition
     *
     * @param pawnPartition Map with Pawn and percent of presence of this pawn
     * @param pawnStop Map with Pawn and percent of presence and operator for stop next step
     * @param width of Grid
     * @param height of Grid
     * @return True if generate
     *         False if somme of Pawn percent greater than 100
     */
    bool generateGrid(QMap<Pawn*, unsigned int>* pawnPartition, QMap<Pawn*, QString>* pawnStop, int generations, int width, int height);
};

#endif // CONTROLER_H
