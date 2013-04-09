///////////////////////////////////////////////////////////////////////////////
//  Readings - рабочие данные, выдываемые машиной времени
//
//  Project: "LifeTime"  (life.timeacademy.ru)
//  Autor: Zimaev Igor (i.zimaev@gmail.com)
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

    // Состояние МВ
    enum eStates
    {
        showPast, // выбор момента
        inLoop,   // в петле времени
        afterLoop // петля пройдена
    };

    eStates state;

    int leapFrom;
    int leapTo;
    int leapDistance;

    // Максимальное отклонение реальности
    float leapDifMax;
    // Отклонение реальности в корне петли
    float leapDifRoot;
    // Коэффициент затухания отклонения (0 - полное затухание)
    float leapDifFade;
    // Коэффициент стабильности объекта после перемещения
    float leapRootInvar;
    // Степень влияния на историю
    int   leapType;

    Readings();
    void clear();
};

#endif // READINGS_H
