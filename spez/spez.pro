#-------------------------------------------------
#
# Project created by QtCreator 2014-10-11T11:52:52
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = spez
TEMPLATE = app

LIBS += -lmodbus

SOURCES += main.cpp\
	mainwindow.cpp \
	modbusadapter.cpp

HEADERS  += mainwindow.h \
	    modbusadapter.h

FORMS    += mainwindow.ui

RESOURCES +=

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/modbus/lib/ -llibmodbus
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/modbus/lib/ -llibmodbusd

INCLUDEPATH += $$PWD/modbus
DEPENDPATH += $$PWD/modbus
