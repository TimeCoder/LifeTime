#include "timeview.h"
#include "timemodel.h"
#include "timeflow.h"
#include "settings.h"


TimeView::TimeView(QWidget *parent) :
    QGLWidget(QGLFormat(QGL::SampleBuffers), parent),
    m_flows(NULL)
{
    m_backBrush         = QBrush(QColor(0, 0, 0));
    m_curvePens[trunk]  = QPen(Settings::instance().colorWorld, 1.5);
    m_curvePens[canal]  = QPen(Settings::instance().colorGate, 1.5);
    m_curvePens[branch] = QPen(Settings::instance().colorObjectChoose, 1.5);
}


void TimeView::renderFlows(const TimeModel::TimeFlows& flows, const TimeModel::Bounds& bounds)
{
    m_flows  = &flows;
    m_bounds = &bounds;
    repaint();
}


void TimeView::paintEvent(QPaintEvent*)
{
    QPainter painter;
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);
    doPaint(painter);
    painter.end();
}


void TimeView::doPaint(QPainter& painter)
{
    painter.fillRect(0, 0, width(), height(), m_backBrush);

    if (!m_flows || !m_bounds) return;

    double midY = height() * 0.2;
    double x_scale = width() / (m_bounds->tMax - m_bounds->tMin);
    double yRange = (m_bounds->bMax - m_bounds->bMin);
    double y_scale = 0.45 * height() / (yRange > 0 ? yRange : 1);

    int flowNum = 0;
    QVector<QPointF> curve;

    foreach (const TimeFlow* flow, (*m_flows))
    {
        double x, y;
        curve.clear();

        foreach (const TimeFlow::Point5D& point, flow->branch())
        {
            x = double(point.t - m_bounds->tMin) * x_scale;
            y = double(point.b * y_scale + midY);
            curve << QPointF(x, y);
        }

        painter.setPen(m_curvePens[flowNum == 0 ? trunk : branch]);
        painter.drawPolyline(curve);

        TimeFlow::LeapInfo leap = flow->leap();

        if (leap.was)
        {
            curve.clear();

            x = double(leap.from.t - m_bounds->tMin) * x_scale;
            y = double(leap.from.b * y_scale + midY);
            curve << QPointF(x, y);

            y = double((leap.from.b - yRange*0.3) * y_scale + midY);
            curve << QPointF(x, y);

            x = double(leap.to.t - m_bounds->tMin) * x_scale;
            y = double((leap.to.b - yRange*0.3) * y_scale + midY);
            curve << QPointF(x, y);

            y = double(leap.to.b * y_scale + midY);
            curve << QPointF(x, y);

            painter.setPen(m_curvePens[canal]);
            painter.drawPolyline(curve);
        }

        flowNum++;
    }
}

