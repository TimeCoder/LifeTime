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
    void renderNewFlow(const TimeModel::TimeFlows& flows, const TimeModel::Bounds& bounds);

protected:
    void initializeGL();
    void resizeGL(int nWidth, int nHeight);
    void paintGL();

private:
    const TimeModel::TimeFlows* m_flows;
    const TimeModel::Bounds*    m_bounds;
};

#endif // TIMEVIEW_H
