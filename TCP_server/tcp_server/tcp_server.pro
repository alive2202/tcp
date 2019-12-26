#-------------------------------------------------
#
# Project created by QtCreator 2019-12-26T17:51:06
#
#-------------------------------------------------

QT       += core network

QT       -= gui

CONFIG += C++11


TARGET = tcp_server
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    tcp_server.cpp

HEADERS += \
    tcp_server.h
