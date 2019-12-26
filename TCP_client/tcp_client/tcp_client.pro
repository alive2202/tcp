#-------------------------------------------------
#
# Project created by QtCreator 2019-12-26T18:35:13
#
#-------------------------------------------------

QT       += core gui network
CONFIG += C++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tcp_client
TEMPLATE = app


SOURCES += main.cpp\
        tcp_client.cpp

HEADERS  += tcp_client.h

FORMS    += tcp_client.ui
