/**
 * @file guicell.cpp
 * @brief GuiCell class definition
 * @author nicolas
 * @version 0.1
 */

#include "guicell.h"

GuiCell::GuiCell(int anX, int anY, GuiImageManager* im) :
    QWidget(),x(anX),y(anY),imageManager(im)
{
    this->pawnImage = 0;
    this->imageContainer = new QLabel(this);
    this->setStyleSheet("border:1px dotted grey;margin:0;");
    this->imageContainer->hasScaledContents();
}

GuiCell::~GuiCell()
{
	if(this->imageContainer != NULL)
		delete this->imageContainer;
}

void GuiCell::resizeEvent(QResizeEvent *)
{
    this->imageContainer->setFixedSize(this->size());
    if(this->pawnImage!=0 && !this->pawnImage->isNull())
    {
        this->imageContainer->setPixmap(this->pawnImage->scaled(this->width(),this->height()));
    }
}

void GuiCell::setPawnImage(QString index)
{
    this->pawnImage = this->imageManager->getImageAt(index);
    if(!this->pawnImage->isNull())
    {
        this->imageContainer->setPixmap(this->pawnImage->scaled(this->width(),this->height()));
    }
    else
    {
        this->imageContainer->setPixmap(*(this->pawnImage));
    }
}

void GuiCell::mousePressEvent(QMouseEvent*)
{
    emit(this->clicked());
}

int GuiCell::getX()
{
    return this->x;
}

int GuiCell::getY()
{
    return this->y;
}
