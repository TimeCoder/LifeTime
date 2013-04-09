///////////////////////////////////////////////////////////////////////////////
//  TimeModel - мультиверсум, содержащий все потоки времени
//
//  Project: "LifeTime"  (life.timeacademy.ru)
//  Autor: Zimaev Igor (i.zimaev@gmail.com)
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
        float tMin;
        float tMax;
        float bMin;
        float bMax;
    };

    TimeModel();

    // Рождение мира
    void bigBan(int rows, int cols, int count);
    // Следующий шаг мира
    void next();

    // Просмотр прошлого
    void showPast(int destTime);
    // Перемещение в прошлое
    void gotoPast(int destTime);

    int curTime() const;
    int maxTime() const;

    float objectSize() const;

signals:
    void worldChangeEvent(const World& world, const World::TCells& object, Readings::eStates);
    void timeChangeEvent(const TimeModel::TimeFlows& flows, const TimeModel::Bounds& bounds);
    void loopEndEvent();
    void updateReadingsEvent(const Readings& readings);

public slots:
    void on_chooseObject(int col, int row);

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
