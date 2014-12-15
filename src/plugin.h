#ifndef PLUGIN_H
#define PLUGIN_H

#include <QString>
#include <QVector>
#include "pawn.h"

/**
 * @class Plugin
 * @brief manage pawns type and rules
 */
class Plugin
{
    /**
     * @brief Plugin name
     */
    QString name;
    /**
     * @brief Plugin description
     */
    QString description;
    /**
     * @brief Plugin version
     */
    QString version;
    /**
     * @brief Cell Background
     */
    QString cellBackground;
    /**
     * @brief List of Plugin pawns
     */
    QVector<Pawn*>* pawns;
public:
    /**
     * @brief Create a new plugin with a pawn list containing only an pawn name "empty"
     * @param aName plugin name
     * @param aDescription plugin description
     * @param aVersion plugin version
     */
    Plugin(QString aName, QString aDescription, QString aVersion);
    /**
     * @brief getName
     * @return plugin name
     */
    QString getName();
    /**
     * @brief getDescription
     * @return plugin description
     */
    QString getDescription();
    /**
     * @brief getVersion
     * @return plugin version
     */
    QString getVersion();
    /**
     * @brief getPawns
     * @return list of Plugin pawns
     */
    QVector<Pawn*>* getPawns();
    /**
     * @brief existPawn
     * @param pawn : id of pawn
     * @return true if exist
     */
    bool existPawn(QString);
    /**
     * @brief addPawn
     * @param pawn : pawn object
     */
    void addPawn(Pawn*);
    /**
     * @brief getPawn
     * @param pawn : id of pawn
     * @return the pawn object
     */
    Pawn* getPawn(QString pawn);
    /**
     * @brief setCellBackground
     * @param uri : set a cell background for all cell
     */
    void setCellBackground(QString uri);
    /**
     * @brief getNewPawn
     * @param pawn : a pawn contain in a cell
     * @param pawns : a list of pawns around the pawn
     * @return the new pawn
     */
    Pawn* getNewPawn(Pawn* pawn, QVector<Pawn*>* pawns);
};

#endif // PLUGIN_H
