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
        cserialport.cpp \
    settingsmodbusrtu.cpp \
    settingsmodbustcp.cpp \
    modbuscommsettings.cpp

HEADERS  += mainwindow.h \
            cserialport.h \
    settingsmodbusrtu.h \
    settingsmodbustcp.h \
    modbuscommsettings.h

FORMS    += mainwindow.ui \
    settingsmodbusrtu.ui \
    settingsmodbustcp.ui

RESOURCES += \
    data/qModMaster.qrc
