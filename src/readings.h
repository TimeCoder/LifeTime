///////////////////////////////////////////////////////////////////////////////
//  Readings - ������� ������, ���������� ������� �������
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

    // ��������� ��
    enum eStates
    {
        showPast, // ����� �������
        inLoop,   // � ����� �������
        afterLoop // ����� ��������
    };

    eStates state;

    int leapFrom;
    int leapTo;
    int leapDistance;

    // ������������ ���������� ����������
    float leapDifMax;
    // ���������� ���������� � ����� �����
    float leapDifRoot;
    // ����������� ��������� ���������� (0 - ������ ���������)
    float leapDifFade;
    // ����������� ������������ ������� ����� �����������
    float leapRootInvar;
    // ������� ������� �� �������
    int   leapType;

    Readings();
    void clear();
};

#endif // READINGS_H
