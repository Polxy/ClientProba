#-------------------------------------------------
#
# Project created by QtCreator 2016-04-25T15:28:41
#
#-------------------------------------------------

QT       += core gui network


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Clientradi
TEMPLATE = app


SOURCES += main.cpp \
    udpclient.cpp

HEADERS  += \
    udpclient.h

FORMS    += mainwindow.ui
