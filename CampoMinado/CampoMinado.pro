TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        libCampoMinado.cpp \
        main.cpp

HEADERS += \
    Field.h \
    Game.h \
    Position.h \
    Tile.h \
    libCampoMinado.h
