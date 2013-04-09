///////////////////////////////////////////////////////////////////////////////
//  TimeFlow - ����� �������, ���������� ������� ���� � ������ ����������
//
//  Project: "LifeTime"  (life.timeacademy.ru)
//  Autor: Zimaev Igor (i.zimaev@gmail.com)
///////////////////////////////////////////////////////////////////////////////
#ifndef FLOW_H
#define FLOW_H
#include <QVector>
#include "world.h"

class LifeModel;


class TimeFlow
{
public:

    // ����� � �������������, t - ��� �������, b - ��� �������������� �����
    struct Point5D
    {
        enum  Kind { track, normal, leapIn, leapOut };

        int  t;
        int  b;
        Kind k;
        Point5D(){}
        Point5D(int time, int branch, Kind kind = normal)
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

    // ��� ����������
    void next();

    // �������� ������� � �������
    void addLeap(int from, int to);

    const TBranch& branch() const;
    const World& world(int time) const;
    const LifeModel* life() const;

    int tMax() const;
    int bMax() const;

    int b(int t) const;

private:
    // ������������ ����� �������
    const TimeFlow* m_parent;
    int m_birthday;

    // ����� �������
    QVector<World*> m_past;
    //
    LifeModel*      m_life;

    //
    TBranch         m_branch;
    int             m_bMax;

    // �������������� �������� �����
    static float worldDif(const World& world1, const World& world2);
};

#endif // FLOW_H
