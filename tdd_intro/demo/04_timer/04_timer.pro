include(../../gtest.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += thread

DEFINES += NOMINMAX

SOURCES += \
    test.cpp
