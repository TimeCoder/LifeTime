///////////////////////////////////////////////////////////////////////////////
//  TimeModel - multiversum, contains all time flows (time tree)
//
//  Project: "LifeTime"
//  Autor: Igor Zimaev  (i.zimaev@timeacademy.ru)
///////////////////////////////////////////////////////////////////////////////
#ifndef TIMEMODEL_H
#define TIMEMODEL_H
#include <QObject>
#include <QVector>
#include "timeflow.h"
#include "world.h"
#include "readings.h"

class TimeModel : public QObject
{
    Q_OBJECT
public:
    typedef QVector<TimeFlow*> TimeFlows;  //TODO: smart_ptr

    struct Bounds
    {
        double tMin;
        double tMax;
        double bMin;
        double bMax;
    };

    TimeModel();

    // Begin of space and time
    void bigBan(int rows, int cols, int count);
    // Next step of evolution
    void next();

    void showPast(int destTime);
    void gotoPast(int destTime);

    int curTime() const;
    int maxTime() const;

    double objectSize() const;

signals:
    void worldChanged(const World& world, const World::TCells& object, Readings::eStates);
    void timeChanged(const TimeModel::TimeFlows& flows, const TimeModel::Bounds& bounds);
    void loopFinished();
    void readingsUpdated(const Readings& readings);

public slots:
    void chooseObject(int col, int row);
    void switchFlow(int flow);

private:
    TimeFlows     m_flows;
    Bounds        m_bounds;
    int           m_curFlow;
    int           m_curTime;
    World::TCells m_object;
    Readings      m_readings;

private:
    void calcReadings();
};
#endif // TIMEMODEL_H
