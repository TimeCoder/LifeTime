#include <QVector>
#include <QTime>
#include "lifemodel.h"
#include "world.h"

LifeModel::LifeModel() :
	m_worldCur(new World()),
	m_worldPrev(new World()),
	m_filling(0.f)
{
}


LifeModel::~LifeModel()
{
    delete m_worldPrev;
    delete m_worldCur;
}


void LifeModel::start(int rows, int cols, int count)
{
    m_worldPrev->init(rows, cols);
    m_worldCur->init(rows, cols);

    qsrand(QTime::currentTime().msec());

    for (int n=0; n<count; ++n)
    {
        m_worldPrev->cell(qrand()%rows, qrand()%cols) = true;
    }
}

void LifeModel::setWorld(const World& world)
{
    *m_worldPrev = world;
    m_worldCur->init(world.rows(), world.cols());
}


const World& LifeModel::next()
{
    int lifeCount = 0;

    for (int row=0; row<m_worldPrev->rows(); ++row)
    {
        for (int col=0; col<m_worldPrev->cols(); ++col)
        {
            int lifeAround = 0;
            World::TCells cells = m_worldPrev->nearest(row, col);
            foreach(const World::TCell& c,  cells)
            {
                if (m_worldPrev->cell(c.first, c.second)) lifeAround++;
            }

            // empty cell, near 3 life - born life
            if (!m_worldPrev->cell(row, col) && lifeAround == 3)
                 m_worldCur->cell(row, col) = true;
            else
            // dead of cell, if near less 2 or over 3 life
            if (m_worldPrev->cell(row, col) && (lifeAround < 2 || lifeAround > 3))
                m_worldCur->cell(row, col) = false;
            else
                m_worldCur->cell(row, col) = m_worldPrev->cell(row, col);
            //
            if (m_worldCur->cell(row, col)) lifeCount++;
        }
    }

    //
    World* tmp = m_worldPrev;
    m_worldPrev = m_worldCur;
    m_worldCur  = tmp;

    m_filling = double(lifeCount) / (m_worldCur->rows() * m_worldCur->cols());

    return (*m_worldPrev);
}


double LifeModel::filling() const
{
    return m_filling;
}


double LifeModel::crossObject(const World::TCells& object) const
{
    int countMatch = 0;
    foreach(const World::TCell& c, object)
    {
        if (m_worldPrev->cell(c.first, c.second)) countMatch++;
    }

    return double(countMatch) / object.size();
}
