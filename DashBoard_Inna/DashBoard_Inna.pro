#-------------------------------------------------
#
# Project created by QtCreator 2019-11-25T11:41:24
#
#-------------------------------------------------

QT       += core gui network

QT += testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


TARGET = DashBoard_Inna
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    libCPP/speedometerinna.cpp \
    libCPP/tachometerinna.cpp \
    libCPP/oilgaugeinna.cpp \
    libCPP/infowindowinna.cpp \
    libCPP/fuelengine.cpp \
    libCPP/iconinna.cpp \
    libCPP/arrowspeedometerinna.cpp \
    libCPP/arrowtachometerinna.cpp \
    libCPP/arrowoilt.cpp \ 
    libCPP/arrowoill.cpp \
    libCPP/enginetinna.cpp \
    libCPP/fuellevelinna.cpp \
    prnd.cpp \
    objet_virtuel.cpp \
    libH/speedinna.cpp \
    icononoff.cpp \
    iconheadlight.cpp \
    clignotant.cpp \
    inna_scene.cpp \
    scene_globale.cpp \
    fondinna.cpp

HEADERS += \
        mainwindow.h \
    libH/speedometerinna.h \
    libH/tachometerinna.h \
    libH/oilgaugeinna.h \
    libH/infowindowinna.h \
    libH/fuelengine.h \
    libH/iconinna.h \
    libH/arrowspeedometerinna.h \
    libH/arrowtachometerinna.h \
    libH/arrowoilt.h \     
    libH/arrowoill.h \
    libH/enginetinna.h \
    libH/fuellevelinna.h \
    prnd.h \
    objet_virtuel.h \
    libH/speedinna.h \
    icononoff.h \
    iconheadlight.h \
    clignotant.h \
    inna_scene.h \
    scene_globale.h \
    fondinna.h
FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc
