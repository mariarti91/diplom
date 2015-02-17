QT += core network

QT -= gui

TEMPLATE = app

TARGET = clients.bin

DESTDIR = ../bin

SOURCES = ../src/main.cpp \
          ../src/clientsock.cpp \
    ../src/testserv.cpp

HEADERS = ../src/clientsock.h \
          ../src/globaldefines.h \
    ../src/testserv.h
