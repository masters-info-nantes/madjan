/**
 * @file guiimagemanager.cpp
 * @brief GuiImageManager class definition
 * @author nicolas
 * @version 0.1
 */

#include "guiimagemanager.h"

GuiImageManager::GuiImageManager(QVector<Pawn*>* pawns)
{
    qDebug("Loading pawn images");
    this->images = new QMap<QString,QPixmap*>;
    for(int i=0;i<pawns->size();i++)
    {
		qDebug("Image URL");
		qDebug(pawns->at(i)->getIcon().toUtf8());
        this->images->insert(pawns->at(i)->getId(),new QPixmap(pawns->at(i)->getIcon()));
    }
}

QPixmap* GuiImageManager::getImageAt(QString id)
{
    qDebug("Trying to access to img of:");
    qDebug(id.toUtf8());
    QMap<QString,QPixmap*>::iterator it;
    for(it=this->images->begin();it!=this->images->end();it++)
    {
        if(it.key()==id)
        {
            qDebug("image found in map");
            return it.value();
        }
    }
    return new QPixmap();
}
