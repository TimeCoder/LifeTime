#-------------------------------------------------
#
# Project created by QtCreator 2013-01-08T00:14:36
#
#-------------------------------------------------

QT       += core gui opengl

TARGET = LifeTime
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    lifeview.cpp \
    timeview.cpp \
    timemodel.cpp \
    world.cpp \
    lifemodel.cpp \
    timeflow.cpp \
    settings.cpp \
    readings.cpp \
    readingsui.cpp \
    settingsui.cpp \
    infoui.cpp

HEADERS  += mainwindow.h \
    lifeview.h \
    timeview.h \
    timemodel.h \
    world.h \
    lifemodel.h \
    timeflow.h \
    settings.h \
    readings.h \
    readingsui.h \
    settingsui.h \
    infoui.h

FORMS    += mainwindow.ui \
    settingsui.ui \
    infoui.ui

OTHER_FILES +=

RESOURCES += \
    ui.qrc

unix:LIBS += -lGLU
