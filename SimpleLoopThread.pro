TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -std=c++0x -pthread 
LIBS += -pthread

SOURCES += \
        System1.cpp \
        System2.cpp \
        buf.cpp \
        main.cpp \
        pipeline.cpp \
        simpleloopthread.cpp \
        stringbuf.cpp \
        systeminterface.cpp

HEADERS += \
    System1.h \
    System2.h \
    buf.h \
    pipeline.h \
    simpleloopthread.h \
    stringbuf.h \
    systeminterface.h
