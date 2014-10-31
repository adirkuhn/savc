#-------------------------------------------------
#
# Project created by QtCreator 2014-06-16T16:34:04
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SAVC
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    GUI/SAVCWidget.cpp \
    SAVC.cpp \
    Multicast/Receiver.cpp \
    Multicast/Sender.cpp \
    CPAR.cpp \
    CILO.cpp \
    PIU/BreakerIED.cpp \
    PIU/busied.cpp \
    PIU/switchied.cpp \
    PIU/TrafoIED.cpp \
    CPAR.cpp

HEADERS  += mainwindow.h \
    GUI/SAVCWidget.h \
    SAVC.h \
    Multicast/Receiver.h \
    Multicast/Sender.h \
    CPAR.h \
    CILO.h \
    PIU/BreakerIED.h \
    PIU/busied.h \
    PIU/switchied.h \
    PIU/TrafoIED.h \
    PIU/BreakerStatus.h \
    PIU/switchstatus.h \
    CPAR.h


FORMS    += mainwindow.ui


LIBS += -L/usr/lib/IEC61850/ -lIEC61850 \
        -L/usr/lib/libasn1 -lLIBASN1 \
        -L/usr/lib/IEC61970/ -lIEC61970 \


INCLUDEPATH += /usr/include/IEC61850/ /usr/include/libasn1 /usr/include/IEC61970
DEPENDPATH += /usr/include/IEC61850/ /usr/include/libasn1 /usr/include/IEC61970

