///////////////////////////////////////////////////////////////////////////////
//  TimeView - view of time tree (use OpenGL)
//
//  Project: "LifeTime"
//  Autor: Igor Zimaev  (i.zimaev@timeacademy.ru)
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
    void renderFlows(const TimeModel::TimeFlows& flows, const TimeModel::Bounds& bounds);

protected:
    void paintEvent(QPaintEvent *event);
    void doPaint(QPainter& painter);

private:
    const TimeModel::TimeFlows* m_flows;
    const TimeModel::Bounds*    m_bounds;
    QBrush                      m_backBrush;

    enum { trunk, canal, branch, count };
    QPen m_curvePens[count];
};

#endif // TIMEVIEW_H
