/**
 * @file guibutton.cpp
 * @brief GuiButton class definition
 * @author nicolas
 * @version 0.1
 */

#include "guibutton.h"

GuiButton::GuiButton(QString text,int value) :
    QPushButton(text),index(value)
{
    QObject::connect(this,SIGNAL(clicked()),this,SLOT(recieveClick()));
}

void GuiButton::recieveClick()
{
    emit(this->click(this->index));
}
