#-------------------------------------------------
#
# Project created by QtCreator 2016-02-17T20:50:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = projet_nfc
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    datamifware1kwidget.cpp \
    tagdatamainwindow.cpp \
    test.cpp \
    mifare1k.cpp

HEADERS  += mainwindow.h \
    tagdatawindow.h \
    datamifware1kwidget.h \
    tagdatamainwindow.h \
    keysarray.h \
    keysarraymifare1k.h \
    dataarray.h \
    dataarraymifare1k.h \
    mifare1k.h

FORMS    += mainwindow.ui \
    datamifware1kwidget.ui \
    tagdatamainwindow.ui
