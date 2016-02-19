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
           test.cpp \
             windows\mainwindow.cpp \
             windows\tagdatamainwindow.cpp \
                windows\mifare1k\datamifware1kwidget.cpp \
             tags\mifare1k.cpp

HEADERS  += data\keysarray.h \
            data\dataarray.h \
                data\mifare1k\keysarraymifare1k.h \
                data\mifare1k\dataarraymifare1k.h \
            windows\mainwindow.h \
            windows\tagdatamainwindow.h \
                windows\mifare1k\datamifware1kwidget.h \
            tags\mifare1k.h

FORMS    += windows\mainwindow.ui \
            windows\tagdatamainwindow.ui\
                windows\mifare1k\datamifware1kwidget.ui

