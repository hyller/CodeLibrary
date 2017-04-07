#-------------------------------------------------
#
# Project created by QtCreator 2013-09-30T12:57:00
#
#-------------------------------------------------

QT       += core gui serialport network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = zboss_sniffer
TEMPLATE = app


SOURCES += main.cpp\
        snifferwindow.cpp \
    snifferserialdevice.cpp \
    pcaplogger.cpp \
    snifferlogger.cpp

HEADERS  += snifferwindow.h \
    snifferserialdevice.h \
    pcaplogger.h \
    snifferlogger.h \
    devicefield.h

FORMS    += snifferwindow.ui

RESOURCES += \
    icons/icons.qrc

RC_ICONS = zigbee.ico

VERSION = 3.0.0.1


