TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    sockettransfer.cpp \
    socketconnector.cpp

HEADERS += \
    sockettransfer.h \
    socketconnector.h
