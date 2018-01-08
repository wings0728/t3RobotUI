#-------------------------------------------------
#
# Project created by QtCreator 2017-12-24T11:41:42
#
#-------------------------------------------------

QT       += core gui sql serialport network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = T3_AF
TEMPLATE = app


SOURCES += main.cpp\
        t3_af_welcome.cpp \
    t3_af_login.cpp \
    t3_af_userdatabase.cpp \
    t3_af_mainwindow.cpp \
    t3_af_confirmexit.cpp \
    t3_af_face.cpp \
    t3_af_getweather.cpp \
    t3_af_weatherforecast.cpp \
    t3_af_map.cpp \
    t3_af_robotinfo.cpp

HEADERS  += t3_af_welcome.h \
    t3_af_config.h \
    t3_af_login.h \
    t3_af_userdatabase.h \
    t3_af_mainwindow.h \
    t3_af_confirmexit.h \
    t3_af_face.h \
    t3_af_getweather.h \
    t3_af_weatherforecast.h \
    t3_af_map.h \
    t3_af_robotinfo.h

FORMS    += t3_af_welcome.ui \
    t3_af_login.ui \
    t3_af_mainwindow.ui \
    t3_af_confirmexit.ui \
    t3_af_face.ui \
    t3_af_getweather.ui \
    t3_af_weatherforecast.ui \
    t3_af_map.ui \
    t3_af_robotinfo.ui

RESOURCES += \
    t3_af.qrc
