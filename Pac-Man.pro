#-------------------------------------------------
#
# Project created by QtCreator 2015-10-28T01:55:10
#
#-------------------------------------------------
CONFIG += c++11
QT       += core gui

QMAKE_MAC_SDK = macosx10.11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Pac-Man
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mainboard.cpp \
    pacman.cpp \
    mainboard2.cpp \
    mainboard3.cpp \
    instructions.cpp

HEADERS  += mainwindow.h \
    mainboard.h \
    pacman.h \
    bullet.h \
    enemy.h \
    mainboard2.h \
    mainboard3.h \
    instructions.h \
    documentation.h

FORMS    += mainwindow.ui \
    mainboard.ui \
    mainboard2.ui \
    mainboard3.ui \
    instructions.ui

RESOURCES += \
    images.qrc
