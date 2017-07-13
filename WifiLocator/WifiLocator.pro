TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    ../Common/sockettransfer.cpp \
    socketconnector.cpp \
    wificell.cpp

HEADERS += \
    ../Common/sockettransfer.h \
    socketconnector.h \
    wificell.h
