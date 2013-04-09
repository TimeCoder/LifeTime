///////////////////////////////////////////////////////////////////////////////
//  TimeView - визуальное отображение древа ¬ремени (использу€ OpenGL)
//
//  Project: "LifeTime"  (life.timeacademy.ru)
//  Autor: Zimaev Igor (i.zimaev@gmail.com)
///////////////////////////////////////////////////////////////////////////////
#ifndef TIMEVIEW_H
#define TIMEVIEW_H
#include <QGLWidget>
#include "timemodel.h"

class TimeView : public QGLWidget
{
    Q_OBJECT
public:
    explicit TimeView(QWidget* parent);

public slots:
    void on_changeTime(const TimeModel::TimeFlows& flows, const TimeModel::Bounds& bounds);

private:
    void initializeGL();
    void resizeGL(int nWidth, int nHeight);
    void paintGL();

    const TimeModel::TimeFlows* m_flows;
    const TimeModel::Bounds*    m_bounds;
};

#endif // TIMEVIEW_H
