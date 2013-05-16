///////////////////////////////////////////////////////////////////////////////
//  TimeFlow - flow of time, contains world's history and branch curve
//
//  Project: "LifeTime"
//  Autor: Igor Zimaev  (i.zimaev@timeacademy.ru)
///////////////////////////////////////////////////////////////////////////////
#ifndef FLOW_H
#define FLOW_H

#include <QVector>
#include "world.h"

class LifeModel;

class TimeFlow
{
public:
    // Point of multiversum, t - time axis, b - axis of alternate realities
    struct Point5D
    {
        enum  Kind { track, normal, leapIn, leapOut };

        int    t;
        double  b;
        Kind k;
        Point5D(){}
        Point5D(int time, double branch, Kind kind = normal)
            : t(time), b(branch), k(kind)
        {
        }
    };
    typedef QVector<Point5D>  TBranch;

    TimeFlow();
    TimeFlow(int rows, int cols, int count);
    TimeFlow(const TimeFlow* parent, World::TCells* object, int birthday);
    TimeFlow(const TimeFlow&);
    ~TimeFlow();

    TimeFlow& operator =(const TimeFlow&);

    // Calcs step
    void next();

    // Add tonnel in past
    void addLeap(int from, int to);

    const TBranch& branch() const;
    const World& world(int time) const;
    const LifeModel* life() const;

    int tMax() const;
    double bMax() const;

    double b(int t) const;
    double filling(int t) const;

private:
    // Parent flow
    const TimeFlow* m_parent;
    int m_birthday;

    // Copy of history
    QVector<World*> m_past;

    // FIXME: parallel arrays is bad
    QVector<double>  m_fillings;

    //
    LifeModel*      m_life;

    //
    TBranch         m_branch;
    double           m_bMax;

private:
    // The quantitative difference between the worlds
    static double worldDif(const World& world1, const World& world2);
};

#endif // FLOW_H
