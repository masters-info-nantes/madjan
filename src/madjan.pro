#-------------------------------------------------
#
# Project created by QtCreator 2014-11-17T13:35:49
#
#-------------------------------------------------

QT       += core gui
QT       += xml

CONFIG += release

#DEFINES += QT_NO_DEBUG_OUTPUT

TARGET = madjan
TEMPLATE = app

# Copy plugin folder in build directory
copy.commands = $${QMAKE_COPY_DIR} \"$$PWD/../plugins\" \"$${OUT_PWD}/\"
copy.target = all
QMAKE_EXTRA_TARGETS += copy

SOURCES += main.cpp\
        gui.cpp \
    pluginmanager.cpp \
    plugin.cpp \
    controler.cpp \
    cell.cpp \
    grid.cpp \
    pawn.cpp \
    rule.cpp \
    greateroperator.cpp \
    loweroperator.cpp \
    equaloperator.cpp \
    abstractoperator.cpp \
    guicell.cpp \
    guibutton.cpp \
    guiimagemanager.cpp

HEADERS  += gui.h \
    pluginmanager.h \
    plugin.h \
    controler.h \
    cell.h \
    grid.h \
    pawn.h \
    rule.h \
    greateroperator.h \
    loweroperator.h \
    equaloperator.h \
    abstractoperator.h \
    guicell.h \
    guibutton.h \
    guiimagemanager.h
