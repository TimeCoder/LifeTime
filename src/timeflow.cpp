#include "timeflow.h"
#include "lifemodel.h"

TimeFlow::TimeFlow()
{
    m_parent = NULL;
    m_birthday = 0;
    m_life = NULL;
    m_bMax = 0;
}


TimeFlow::TimeFlow(int rows, int cols, int count)
{
    // Start of root flow
    m_parent = NULL;
    m_birthday = 0;
    m_life = new LifeModel();
    m_life->start(rows, cols, count);
    m_bMax = 0;
}


TimeFlow::TimeFlow(const TimeFlow* parent, World::TCells* object, int birthday)
    : m_parent(parent), m_birthday(birthday)
{
    // Start of child flow

    m_life = new LifeModel();
    m_past = parent->m_past.mid(0, birthday);
    m_bMax = 0.f;

    World* w = m_past.last();
    foreach(const World::TCell& cell, (*object))
    {
        w->cell(cell.first, cell.second) = 1;
    }

    m_life->setWorld(*w);

    m_branch.push_back(Point5D(birthday, parent->m_branch[birthday].b));
}


TimeFlow::TimeFlow(const TimeFlow& rhs)
    : m_parent(rhs.m_parent),
      m_birthday(rhs.m_birthday),
      m_past(rhs.m_past),
      m_life(rhs.m_life),
      m_branch(rhs.m_branch),
      m_bMax(rhs.m_bMax)
{

}


TimeFlow::~TimeFlow()
{

}


TimeFlow& TimeFlow::operator =(const TimeFlow& rhs)
{
    m_parent = rhs.m_parent;
    m_birthday = rhs.m_birthday;
    m_past = rhs.m_past;
    m_life = rhs.m_life;
    m_branch = rhs.m_branch;
    m_bMax = rhs.m_bMax;

    return *this;
}


void TimeFlow::next()
{
    // First, calc next world "frame"
    m_past << new World(m_life->next());

    // Second, calc his 5D coords
    int t = m_past.size()-1;
    int b = m_parent ?
                (worldDif(world(t), m_parent->world(t))) : 0;

    // Dif between flow and its parent, and b-coord parent
    b += m_parent ? m_parent->b(t) : 0;

    if (m_bMax < b)
        m_bMax = b;

    m_branch.push_back(Point5D(t, b));
}


int TimeFlow::b(int t) const
{
    if (t > m_birthday) return m_branch[t - m_birthday].b;
    return m_parent->b(t);
}


const TimeFlow::TBranch& TimeFlow::branch() const
{
    return m_branch;
}


const World& TimeFlow::world(int time) const
{
    Q_ASSERT(time >=0 && time < m_past.size());
    return *m_past[time];
}


const LifeModel* TimeFlow::life() const
{
    return m_life;
}


int TimeFlow::tMax() const
{
    return m_past.size() - 1;
}


int TimeFlow::bMax() const
{
    return m_bMax;
}


void TimeFlow::addLeap(int from, int to)
{
    m_branch.push_back(Point5D(from, b(from), Point5D::leapIn));
    m_branch.push_back(Point5D(to,   b(to), Point5D::leapOut));
}


float TimeFlow::worldDif(const World& world1, const World& world2)
{
    //TODO: asserts on equal size
    int dif = 0;

    for (int row=0; row<world1.rows(); ++row)
    {
        for (int col=0; col<world1.cols(); ++col)
        {
            dif += abs(world1.cell(row, col) - world2.cell(row, col));
        }
    }

    return dif;
}
