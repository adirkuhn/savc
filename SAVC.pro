#-------------------------------------------------
#
# Project created by QtCreator 2014-06-16T16:34:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SAVC
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    GUI/SAVCWidget.cpp \
    SAVC.cpp

HEADERS  += mainwindow.h \
    GUI/SAVCWidget.h \
    SAVC.h

FORMS    += mainwindow.ui


LIBS += -L/usr/lib/IEC61850/ -lIEC61850


INCLUDEPATH += /usr/include/IEC61850/
DEPENDPATH += /usr/include/IEC61850/