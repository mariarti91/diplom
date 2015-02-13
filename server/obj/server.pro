#-------------------------------------------------
#
# Project created by QtCreator 2015-02-13T11:34:23
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = server.bin

DESTDIR = ../bin

TEMPLATE = app


SOURCES += ../src/main.cpp\
        ../src/mainwindow.cpp

HEADERS  += ../src/mainwindow.h

FORMS    += ../src/mainwindow.ui
