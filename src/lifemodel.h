//
// This file is part of the LifeTime project
//
// This program is free software licensed under the GNU LGPL. You can
// find a copy of this license in LICENSE in the top directory of
// the source code.
//
// Copyright 2013      Igor Zimaev       <i.zimaev@timeacademy.ru>
// Copyright 2013      Illya Kovalevskyy <illya.kovalevskyy@gmail.com>
//

//  LifeModel - world's life calculation, implementation of Conway algorythm

#ifndef LIFEMODEL_H
#define LIFEMODEL_H

#include "world.h"

class LifeModel
{
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
    double filling() const;

    // world and object intercross coef.
    double crossObject(const World::TCells&) const;

private:
    World*  m_worldCur;
    World*  m_worldPrev;
    double  m_filling;
};

#endif // LIFEMODEL_H
