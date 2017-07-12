TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

target.path = /root/lhc
INSTALLS += target

SOURCES += main.cpp \
    socketlistener.cpp \
    sockettransfer.cpp

HEADERS += \
    socketlistener.h \
    sockettransfer.h
