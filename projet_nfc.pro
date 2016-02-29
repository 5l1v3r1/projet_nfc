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
           data\save_and_load.cpp \
           windows\mainwindow.cpp \
           windows\tagdatamainwindow.cpp \
                windows\mifare1k\datamifware1kwidget.cpp \
           tags\mifare1k.cpp \
           readerAlgorithms\detect_library.cpp \
                readerAlgorithms\mifare1k\mifare1k_read_write.cpp \
           data/convertion.cpp


HEADERS  += data\keysarray.h \
            data\dataarray.h \
            data\save_and_load.h \
                data\mifare1k\keysarraymifare1k.h \
                data\mifare1k\dataarraymifare1k.h \
            windows\mainwindow.h \
            windows\tagdatamainwindow.h \
                windows\mifare1k\datamifware1kwidget.h \
            tags\mifare1k.h \
            readerAlgorithms\detect_library.h \
            readerAlgorithms\library_include.h \
                readerAlgorithms\mifare1k\mifare1k_read_write.h \
    data/convertion.h \
    other.h

FORMS    += windows\mainwindow.ui \
            windows\tagdatamainwindow.ui\
                windows\mifare1k\datamifware1kwidget.ui

LIBS=-ldl
LIBS=-lnfc
