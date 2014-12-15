/**
 * @file guiimagemanager.h
 * @brief GuiImageManager class header
 * @author nicolas
 * @version 0.1
 */

#ifndef GUIIMAGEMANAGER_H
#define GUIIMAGEMANAGER_H

#include <QMap>
#include <QPixmap>
#include <QString>
#include <pawn.h>
#include <QVector>

/**
 * @class GuiImageManager
 * @brief Store pawn images
 *
 * Used as a singleton, to store every pawn images only once.
 *
 */
class GuiImageManager
{
    QMap<QString,QPixmap*>* images;

public:

    /**
     * @brief Constructor
     * @param pawns: list of the pawns to get their images
     */
    GuiImageManager(QVector<Pawn*>* pawns);

    /**
     * @brief getImageAt Return an image of a pawn
     * @param id: Identifier of the pawn
     * @return A QPixmap containing the image of the pawn
     */
    QPixmap* getImageAt(QString id);
};

#endif // GUIIMAGEMANAGER_H
