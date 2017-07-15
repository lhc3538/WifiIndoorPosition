TEMPLATE = app
CONFIG += c++11
CONFIG -= app_bundle

TARGET = WifiLocator

LIBS += -lmysqlclient

SOURCES += main.cpp \
    ../Common/sockettransfer.cpp \
    socketconnector.cpp \
    wificell.cpp \
    stringutils.cpp \
    dbopter.cpp \
    wificellarray.cpp

HEADERS += \
    ../Common/sockettransfer.h \
    socketconnector.h \
    wificell.h \
    stringutils.h \
    dbopter.h \
    wificellarray.h
