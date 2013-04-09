#include "timemodel.h"
#include "world.h"
#include "lifemodel.h"


TimeModel::TimeModel()
{
    m_bounds.tMin = 0;
    m_bounds.tMax = 0;
    m_bounds.bMin = 0;
    m_bounds.bMax = 0;

    m_curFlow  = -1;
    m_curTime  = -1;
}


int TimeModel::curTime() const
{
    return m_curTime;
}


int TimeModel::maxTime() const
{
    return m_bounds.tMax;
}


void TimeModel::bigBan(int rows, int cols, int count)
{
    m_readings.clear();
    m_object.clear();
    m_flows.clear();
    m_flows.push_back(new TimeFlow(rows, cols, count));
    m_curTime = -1;
    m_curFlow = 0;
    m_readings.worldWidth = rows;
    m_readings.worldHeight = cols;
}


void TimeModel::next()
{
    m_curTime++;

    int tMax = 0;
    int bSum = 0;

    // Просчет параллельных потоков (среди них - и основной)
    for (int i=0; i<m_flows.size(); i++)
    {
        TimeFlow* flow = m_flows[i];
        if (flow->tMax() <= m_curTime) flow->next();

        if (tMax < flow->tMax())
            tMax = flow->tMax();

        bSum += flow->bMax();
    }

    // Расчет диапазона древа
    m_bounds.tMax = tMax;
    m_bounds.bMax = bSum;

    //
    // Расчеты рабочих данных
    //
    m_readings.worldFill = m_flows[m_curFlow]->life()->filling();
    m_readings.leapDifMax = m_flows[m_curFlow]->bMax();

    // Достигли корня петли (отправной точки)
    if (m_curTime >= m_readings.leapFrom && m_readings.leapFrom != 0)
    {
        if (m_readings.state == Readings::inLoop)
        {
            m_readings.leapDifRoot   = m_flows[m_curFlow]->b(m_curTime);
            m_readings.leapDifFade   = m_readings.leapDifRoot / m_readings.leapDifMax;
            m_readings.leapRootInvar = m_flows[m_curFlow]->life()->crossObject(m_object);

            // TODO: вынести хардкод в настройки
            if (m_readings.leapRootInvar > 0.99)
                m_readings.leapType = 1;
            else
            if (m_readings.leapRootInvar > 0.50)
                m_readings.leapType = 2;
            else
                m_readings.leapType = 3;

            m_readings.state = Readings::afterLoop;

            emit loopEndEvent();
        }
    }

    emit worldChangeEvent(m_flows[m_curFlow]->world(m_curTime), m_object, m_readings.state);
    emit timeChangeEvent(m_flows, m_bounds);
    emit updateReadingsEvent(m_readings);
}


void TimeModel::on_chooseObject(int row, int col)
{
    m_flows[m_curFlow]->world(m_curTime).selectObject(row, col, m_object);

    m_readings.objectSizeAbs = m_object.size();
    m_readings.objectSizeRel = float(m_object.size()) / (m_readings.worldWidth * m_readings.worldHeight) * 100.f;

    emit updateReadingsEvent(m_readings);
    emit worldChangeEvent(m_flows[m_curFlow]->world(m_curTime), m_object, m_readings.state);
}


void TimeModel::showPast(int destTime)
{
    m_readings.state = Readings::showPast;
    emit worldChangeEvent(m_flows[m_curFlow]->world(destTime), m_object, m_readings.state);
}


void TimeModel::gotoPast(int destTime)
{
    m_readings.state = Readings::inLoop;
    m_readings.leapDifMax = 0;
    m_readings.leapDifRoot = 0;
    m_readings.leapFrom = m_curTime;
    m_readings.leapTo = destTime;
    m_readings.leapDistance = m_curTime - destTime;
    emit updateReadingsEvent(m_readings);

    m_flows[m_curFlow]->addLeap(m_curTime, destTime);
    m_flows.push_back(new TimeFlow(m_flows[m_curFlow], &m_object, destTime));
    m_curFlow++;
    m_curTime = destTime-1;
}


float TimeModel::objectSize() const
{
    const World& world = m_flows[m_curFlow]->world(m_curTime);
    return (float)m_object.size() / (world.rows() * world.cols());
}


