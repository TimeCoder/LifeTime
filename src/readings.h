///////////////////////////////////////////////////////////////////////////////
//  Readings - data of time machine
//
//  Project: "LifeTime"
//  Autor: Igor Zimaev  (i.zimaev@timeacademy.ru)
///////////////////////////////////////////////////////////////////////////////
#ifndef READINGS_H
#define READINGS_H

struct Readings
{
    int worldWidth;
    int worldHeight;
    double worldFill;

    int objectSizeAbs;
    double objectSizeRel;

    // TM state
    enum eStates
    {
        showPast,
        inLoop,
        afterLoop,
        statesCount
    };

    eStates state;

    int leapFrom;
    int leapTo;
    int leapDistance;

    // Reality max dif
    double leapDifMax;
    // Reality dif at loop end
    double leapDifRoot;
    // Coef. of dif stable in root of loop (0 - total fade)
    double leapDifK;
    // Invar of object after leap
    double leapRootInvar;
    // Degree of history change
    int   leapType;

    Readings();
    void clear();
};

#endif // READINGS_H
