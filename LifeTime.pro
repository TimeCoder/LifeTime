#-------------------------------------------------
#
# Project created by QtCreator 2013-01-08T00:14:36
#
#-------------------------------------------------

QT       += core widgets opengl

TARGET = LifeTime
TEMPLATE = app
DESTDIR = bin

SOURCES += src/world.cpp \
    src/timeview.cpp \
    src/timemodel.cpp \
    src/timeflow.cpp \
    src/settingsui.cpp \
    src/settings.cpp \
    src/readingsui.cpp \
    src/readings.cpp \
    src/mainwindow.cpp \
    src/main.cpp \
    src/lifeview.cpp \
    src/lifemodel.cpp \
    src/infoui.cpp

HEADERS  += src/world.h \
    src/ui_settingswindow.h \
    src/timeview.h \
    src/timemodel.h \
    src/timeflow.h \
    src/settingsui.h \
    src/settings.h \
    src/readingsui.h \
    src/readings.h \
    src/mainwindow.h \
    src/lifeview.h \
    src/lifemodel.h \
    src/infoui.h

FORMS    += src/settingsui.ui \
    src/mainwindow.ui \
    src/infoui.ui

RESOURCES += shared/ui.qrc
