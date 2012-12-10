#-------------------------------------------------
#
# Project created by QtCreator 2012-01-03T10:18:00
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = BowlingKata
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp

unix:!symbian: LIBS += -L$$PWD/../gtest-1.6.0/ -lgtest

INCLUDEPATH += $$PWD/../gtest-1.6.0/include
DEPENDPATH += $$PWD/../gtest-1.6.0/include

unix:!symbian: PRE_TARGETDEPS += $$PWD/../gtest-1.6.0/libgtest.a
