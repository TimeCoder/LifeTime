#include <QMouseEvent>
#include "lifeview.h"
#include "world.h"
#include "settings.h"

#ifdef Q_OS_LINUX
#include <GL/glu.h>
#include <GL/glut.h>
#endif

#ifdef Q_OS_MAC
#include <OpenGL/glu.h>
#endif

LifeView::LifeView(QWidget *parent) :
    QGLWidget(QGLFormat(QGL::SampleBuffers), parent),
    m_world(NULL),
    m_object(NULL),
    m_fixObject(false),
    m_state(Readings::showPast)
{

}


void LifeView::initializeGL()
{
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_COLOR_MATERIAL);
    glEnable(GL_BLEND);
    glEnable(GL_POLYGON_SMOOTH);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glClearColor(0, 0, 0, 0);
}


void LifeView::resizeGL(int nWidth, int nHeight)
{
    glViewport(0, 0, nWidth, nHeight);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, nWidth, 0, nHeight); // set origin to bottom left corner
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


void LifeView::renderNewWorld(const World& world, const World::TCells& object, Readings::eStates state)
{
    m_world  = &world;
    m_object = &object;
    m_state  = state;
    updateGL();
}


void LifeView::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);

    if (!m_world) return;

    double cellW = (double)width()  / m_world->cols();
    double cellH = (double)height() / m_world->rows();

    //
    const QColor& color = Settings::instance().colorWorld;
    glColor4f(color.redF(), color.greenF(), color.blueF(), color.alphaF());

    double y;
    double x;
    for (int row=0; row < m_world->rows(); ++row)
    {
        for (int col=0; col < m_world->cols(); ++col)
        {
            if (m_world->cell(row, col))
            {
                glBegin(GL_POLYGON);

                y = cellH*((double)(m_world->rows()-row));
                x = cellW*((double)(col+1));

                glVertex2f(x, y);
                glVertex2f(x, y-cellH);
                glVertex2f(x-cellW, y-cellH);
                glVertex2f(x-cellW, y);

                glEnd();
            }
        }
    }

    //
    if (m_object)
    {
        const QColor& color = (m_state == Readings::showPast ? Settings::instance().colorObjectChoose :
          (m_state == Readings::inLoop ? Settings::instance().colorObjectGhost : Settings::instance().colorObjectFinal));

        glColor4f(color.redF(), color.greenF(), color.blueF(), color.alphaF());

        foreach(const World::TCell& cell, (*m_object))
        {
            glBegin(GL_POLYGON);

            y = cellH*((double)(m_world->rows()-cell.first));
            x = cellW*((double)(cell.second+1));

            glVertex2f(x, y);
            glVertex2f(x, y-cellH);
            glVertex2f(x-cellW, y-cellH);
            glVertex2f(x-cellW, y);

            glEnd();
        }
    }
}


void LifeView::mousePressEvent(QMouseEvent* event)
{
    if (m_fixObject) return;

    int row = int( event->pos().y() / height() * m_world->rows() );
    int col = int( event->pos().x() / width()  * m_world->cols() );

    emit objectChosen(row, col);
}


void LifeView::fixObject(bool fix)
{
    m_fixObject = fix;
}
