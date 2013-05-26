#include <QPainter>
#include <QPaintEvent>
#include <QMouseEvent>
#include "lifeview.h"
#include "world.h"
#include "settings.h"


LifeView::LifeView(QWidget *parent) :
    QGLWidget(QGLFormat(QGL::SampleBuffers), parent),
    m_world(NULL),
    m_object(NULL),
    m_fixObject(false),
    m_state(Readings::showPast)
{

    m_backBrush  = QBrush(QColor(0, 0, 0));
    m_cellsBrush = QBrush(Settings::instance().colorWorld);
    m_objectBrush[Readings::showPast]  = QBrush(Settings::instance().colorObjectChoose);
    m_objectBrush[Readings::inLoop]    = QBrush(Settings::instance().colorObjectGhost);
    m_objectBrush[Readings::afterLoop] = QBrush(Settings::instance().colorObjectFinal);
}


void LifeView::renderWorld(const World& world, const World::TCells& object, Readings::eStates state)
{
    m_world  = &world;
    m_object = &object;
    m_state  = state;
    repaint();
}


void LifeView::paintEvent(QPaintEvent*)
{
    QPainter painter;
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);
    doPaint(painter);
    painter.end();
}


void LifeView::doPaint(QPainter& painter)
{
    painter.fillRect(0, 0, width(), height(), m_backBrush);

    if (!m_world) return;

    double cellW = double(width())  / m_world->cols();
    double cellH = double(height()) / m_world->rows();

    //
    QVector<QRectF> cellsRects;

    double y;
    double x;
    for (int row=0; row < m_world->rows(); ++row)
    {
        for (int col=0; col < m_world->cols(); ++col)
        {
            if (m_world->cell(row, col))
            {
                y = cellH*((double)row);
                x = cellW*((double)(col));

                cellsRects << QRectF(x, y, cellW, cellH);
            }
        }
    }

    //
    QVector<QRectF> objRects;

    if (m_object)
    {
        foreach(const World::TCell& cell, (*m_object))
        {
            y = cellH*((double)cell.first);
            x = cellW*((double)(cell.second));

            objRects << QRectF(x, y, cellW, cellH);
        }
    }

    painter.setBrush(m_cellsBrush);
    painter.drawRects(cellsRects);

    painter.setBrush(m_objectBrush[m_state]);
    painter.drawRects(objRects);
}



void LifeView::mousePressEvent(QMouseEvent* event)
{
    if (m_fixObject) return;

    int row = int( (double)event->pos().y() / height() * m_world->rows() );
    int col = int( (double)event->pos().x() / width()  * m_world->cols() );

    emit cellActivated(row, col);
}



void LifeView::fixObject(bool fix)
{
    m_fixObject = fix;
}
