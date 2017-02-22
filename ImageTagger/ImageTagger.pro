#-------------------------------------------------
#
# Project created by QtCreator 2014-10-22T18:00:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ImageTagger
TEMPLATE = app
QMAKE_MAC_SDK = macosx10.12

SOURCES += main.cpp\
        imagetagger.cpp \
    imagedisplay.cpp \

HEADERS  += imagetagger.h \
    imagedisplay.h \
    structs.h

FORMS    += imagetagger.ui
