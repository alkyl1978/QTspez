#-------------------------------------------------
#
# Project created by QtCreator 2014-10-11T11:52:52
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = spez
TEMPLATE = app

#LIBS += -lmodbus

SOURCES += main.cpp\
	mainwindow.cpp \
    modbusadapter.cpp
	setingmodbus.cpp

HEADERS  += mainwindow.h \
	    modbusadapter.h \
	    setingmodbus.h

FORMS    += mainwindow.ui

RESOURCES +=
