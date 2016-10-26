TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    node.cpp \
    vec.cpp \
    particle.cpp \
    randomnumbergenerator.cpp

HEADERS += \
    node.h \
    vec.h \
    particle.h \
    randomnumbergenerator.h
