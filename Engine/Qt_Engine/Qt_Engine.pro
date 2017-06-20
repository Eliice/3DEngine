#-------------------------------------------------
#
# Project created by QtCreator 2017-03-29T12:49:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += gui

TARGET = Qt_Engine
TARGET += QtSDL

TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    exitdialog.cpp \
    transform.cpp \
    position.cpp \
    addcomponentfont.cpp \
    capsulecollider.cpp \
    spherecollider.cpp \
    cubecollider.cpp \
    savewindow.cpp \
    collider.cpp

HEADERS  += mainwindow.h \
    exitdialog.h \
    transform.h \
    position.h \
    addcomponentfont.h \
    capsulecollider.h \
    spherecollider.h \
    cubecollider.h \
    savewindow.h \
    collider.h

FORMS    += mainwindow.ui \
    exitdialog.ui \
    transform.ui \
    position.ui \
    addcomponentfont.ui \
    capsulecollider.ui \
    spherecollider.ui \
    cubecollider.ui \
    savewindow.ui \
    collider.ui
