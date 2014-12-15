#-------------------------------------------------
#
# Project created by QtCreator 2014-11-17T13:35:49
#
#-------------------------------------------------

QT       += core gui
QT       += xml

CONFIG += release

TARGET = madjan-test
TEMPLATE = app

# Copy plugin folder in build directory
#QMAKE_POST_LINK = $${QMAKE_COPY_DIR} \"$$PWD/../plugins\" \"$${OUT_PWD}/\"

SOURCES += test.cpp\
    pawn.cpp \
    TestPawn.cpp \
    rule.cpp \
    TestRule.cpp \
	abstractoperator.cpp \
    greateroperator.cpp \
    loweroperator.cpp \
    equaloperator.cpp \
    TestOperator.cpp \
	cell.cpp \
	TestCell.cpp \
	grid.cpp \
	TestGrid.cpp \
	plugin.cpp \
	TestPlugin.cpp \
	pluginmanager.cpp \
	TestPluginManager.cpp
	
# gui.cpp \
# controler.cpp \
# guicell.cpp \
# guibutton.cpp \
# guiimagemanager.cpp

HEADERS  += pawn.h \
    TestPawn.h \
    rule.h \
    TestRule.h \
	abstractoperator.h \
    greateroperator.h \
    loweroperator.h \
    equaloperator.h \
    TestOperator.h \
    cell.h \
    TestCell.h \
    grid.h \
    TestGrid.h \
	plugin.h \
	TestPlugin.h \
	pluginmanager.h \
	TestPluginManager.h

# gui.h \
# controler.h \
# guicell.h \
# guibutton.h \
# guiimagemanager.h
    
LIBS+=-lcppunit -ldl
