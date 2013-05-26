//
// This file is part of the LifeTime project
//
// This program is free software licensed under the GNU LGPL. You can
// find a copy of this license in LICENSE in the top directory of
// the source code.
//
// Copyright 2013      Igor Zimaev       <i.zimaev@timeacademy.ru>
// Copyright 2013      Illya Kovalevskyy <illya.kovalevskyy@gmail.com>
//

//  LifeView - view of world

#ifndef LIFEVIEW_H
#define LIFEVIEW_H

#include <QGLWidget>
#include "world.h"
#include "readings.h"

class QMouseEvent;
class QPaintEvent;


class LifeView : public QGLWidget
{
    Q_OBJECT
public:
    explicit LifeView(QWidget* parent);

    // Freeze object choose
    void fixObject(bool fix);
    void renderWorld(const World& world, const World::TCells& object, Readings::eStates state);

signals:
    void cellActivated(int col, int row);

protected:
    void paintEvent(QPaintEvent *event);
    void doPaint(QPainter& painter);
    void mousePressEvent(QMouseEvent* event);

private:
    const World          *m_world;
    const World::TCells  *m_object;
    bool                  m_fixObject;
    Readings::eStates     m_state;

    QBrush  m_backBrush;
    QBrush  m_cellsBrush;
    QBrush  m_objectBrush[Readings::statesCount];

};

#endif // LIFEVIEW_H
