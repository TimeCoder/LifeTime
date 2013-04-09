///////////////////////////////////////////////////////////////////////////////
//  LifeModel - world's life calculation, implementation of Conway algorythm
//
//  Project: "LifeTime"  (life.timeacademy.ru)
//  Autor: Zimaev Igor (i.zimaev@timeacademy.ru)
///////////////////////////////////////////////////////////////////////////////
#ifndef LIFEMODEL_H
#define LIFEMODEL_H
#include <QObject>
#include "world.h"

class LifeModel: public QObject
{
    Q_OBJECT
public:
    LifeModel();
    ~LifeModel();

    // 1st way of life start: random
    void  start(int rows, int cols, int count);
    // 2nd way of life start: exist world
    void setWorld(const World& world);

    // Next life frame
    const World& next();

    // world filling coef.
    float filling() const;

    // world and object intercross coef.
    float crossObject(const World::TCells&) const;

private:
    World* m_worldCur;
    World* m_worldPrev;
    float  m_filling;
};

#endif // LIFEMODEL_H
