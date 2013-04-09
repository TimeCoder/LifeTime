///////////////////////////////////////////////////////////////////////////////
//  LifeView - визуальное отображение мира (используя OpenGL)
//
//  Project: "LifeTime"  (life.timeacademy.ru)
//  Autor: Zimaev Igor (i.zimaev@gmail.com)
///////////////////////////////////////////////////////////////////////////////

#ifndef LIFEVIEW_H
#define LIFEVIEW_H
#include <QGLWidget>
#include "world.h"
#include "readings.h"

class QMouseEvent;

class LifeView : public QGLWidget
{
    Q_OBJECT
public:
    explicit LifeView(QWidget* parent);

    // Заморозить выбор объекта
    void fixObject(bool fix);

public slots:
    void on_changeWorld(const World& world, const World::TCells& object, Readings::eStates state);

signals:
    void chooseObjectEvent(int col, int row);

private:
    void initializeGL();
    void resizeGL(int nWidth, int nHeight);
    void paintGL();
    void mousePressEvent(QMouseEvent* event);

    const World*          m_world;
    const World::TCells*  m_object;
    bool                  m_fixObject;
    Readings::eStates     m_state;
};

#endif // LIFEVIEW_H
