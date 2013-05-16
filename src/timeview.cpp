#include "timeview.h"
#include "timemodel.h"
#include "timeflow.h"
#include "settings.h"

#ifdef Q_OS_LINUX
#include <GL/glu.h>
#include <GL/glut.h>
#endif

#ifdef Q_OS_MAC
#include <OpenGL/glu.h>
#endif

TimeView::TimeView(QWidget *parent) :
    QGLWidget(QGLFormat(QGL::SampleBuffers), parent),
    m_flows(NULL)
{
}


void TimeView::renderNewFlow(const TimeModel::TimeFlows& flows, const TimeModel::Bounds& bounds)
{
    m_flows  = &flows;
    m_bounds = &bounds;
    updateGL();
}


void TimeView::initializeGL()
{
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_COLOR_MATERIAL);
    glEnable(GL_BLEND);
    glEnable(GL_POLYGON_SMOOTH);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glClearColor(0, 0, 0, 0);
}


void TimeView::resizeGL(int nWidth, int nHeight)
{
    glViewport(0, 0, nWidth, nHeight);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, nWidth, 0, nHeight);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


void TimeView::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);

    if (!m_flows || !m_bounds) return;

    double midY = height() * 0.8;
    double x_scale = width() / (m_bounds->tMax - m_bounds->tMin);
    double yRange = (m_bounds->bMax - m_bounds->bMin);
    double y_scale = 0.45 * height() / (yRange > 0 ? yRange : 1);

    int flowNum = 0;
    bool inGate = false;

    foreach (const TimeFlow* flow, (*m_flows))
    {
        double x, y;
        glBegin(GL_LINE_STRIP);
        foreach (const TimeFlow::Point5D& point, flow->branch())
        {
            if (point.k == TimeFlow::Point5D::leapIn)
            {
                inGate = true;
                x = double(point.t - m_bounds->tMin) * x_scale;
                y = double((point.b - yRange*0.3) * -y_scale + midY);
            }
            else
            if (point.k == TimeFlow::Point5D::leapOut)
            {
                x = double(point.t - m_bounds->tMin) * x_scale;
                y = double((point.b - yRange*0.3) * -y_scale + midY);
                glVertex2f(x, y);
                y = double((point.b - yRange*0.0) * -y_scale + midY);
            }
            else
            {
                inGate = false;
                x = double(point.t - m_bounds->tMin) * x_scale;
                y = double(point.b * -y_scale + midY);
            }

            const QColor& color = inGate ? Settings::instance().colorGate :
              (flowNum == 0 ? Settings::instance().colorWorld : Settings::instance().colorObjectChoose);

            glColor4f(color.redF(), color.greenF(), color.blueF(), color.alphaF());
            glVertex2f(x, y);
        }
        glEnd();

        flowNum++;
    }

}

