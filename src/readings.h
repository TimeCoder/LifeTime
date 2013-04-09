///////////////////////////////////////////////////////////////////////////////
//  Readings - data of time machine
//
//  Project: "LifeTime"  (life.timeacademy.ru)
//  Autor: Zimaev Igor (i.zimaev@timeacademy.ru)
///////////////////////////////////////////////////////////////////////////////
#ifndef READINGS_H
#define READINGS_H

struct Readings
{
    int worldWidth;
    int worldHeight;
    float worldFill;

    int objectSizeAbs;
    float objectSizeRel;

    // TM state
    enum eStates
    {
        showPast,
        inLoop,
        afterLoop
    };

    eStates state;

    int leapFrom;
    int leapTo;
    int leapDistance;

    // Reality max dif
    float leapDifMax;
    // Reality dif at loop end
    float leapDifRoot;
    // Fade of reality dif (0 - total fade)
    float leapDifFade;
    // Invar of object after leap
    float leapRootInvar;
    // Degree of history change
    int   leapType;

    Readings();
    void clear();
};

#endif // READINGS_H
