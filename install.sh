#!/bin/bash

OS="`uname`"

BASEDIR="`dirname $0`"

mkdir -p "$BASEDIR/build" && cd $_

if [ $OS = "Linux" ] ; then
    qmake-qt4 ../src/madjan.pro && make && cp madjan ../Madjan
elif [ $OS = "Darwin" ] ; then
    qmake-4.8 -spec macx-g++ ../src/madjan.pro && make && cp madjan.app ../Madjan.app
fi

