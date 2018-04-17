#Workaround for Issue #60
CONFIG += git_build

load(qt_build_config)

MODULE_VERSION = 0.3.0

QT       += core gui xml
QTPLUGIN += gif

#CONFIG += static

RC_FILE = deltaproxmlgen.rc

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DeltaProXmlGen
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
        about.cpp \
    genxml.cpp

HEADERS  += mainwindow.h \
    about.h \w \
    genxml.h \
    metainfo.h
    mainwindow.h

FORMS    += mainwindow.ui \
    about.ui

RESOURCES += \
    graphics.qrc


