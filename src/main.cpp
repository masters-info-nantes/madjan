#include <iostream>
#include <QtGui/QApplication>
#include "gui.h"
#include "grid.h"
#include <QDebug>

int main(int argc, char *argv[])
{	
    QApplication a(argc, argv);
    Gui w;
    w.show();
    return a.exec();
}
