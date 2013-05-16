#
# This file is part of the Supernova IDE
#
# This program is free software licensed under the GNU LGPL. You can
# find a copy of this license in LICENSE in the top directory of
# the source code.
#
# Copyright 2013      Igor Zimaev   <i.zimaev@timeacademy.ru>
#

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
