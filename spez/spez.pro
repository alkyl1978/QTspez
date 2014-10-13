#-------------------------------------------------
#
# Project created by QtCreator 2014-10-11T11:52:52
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = spez
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    settingsmodbusrtu.cpp \
    modbuscommsettings.cpp \
    modbusadapter.cpp

HEADERS  += mainwindow.h \
    settingsmodbusrtu.h \
    modbuscommsettings.h \
    modbusadapter.h

FORMS    += mainwindow.ui \
    settingsmodbusrtu.ui

RESOURCES +=
