///////////////////////////////////////////////////////////////////////////////
//  LifeModel - ������ ����� ���� �� ������������� ��������� ������
//
//  Project: "LifeTime"  (life.timeacademy.ru)
//  Autor: Zimaev Igor (i.zimaev@gmail.com)
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

    // 1-� ������ ������� �����: � ����
    void  start(int rows, int cols, int count);
    // 2-� ������ ������� �����: ��� ���
    void setWorld(const World& world);

    // ������ ���������� "�����" �����
    const World& next();

    // ����������� ������������� ����
    float filling() const;

    // ����������� ����������� ������� � �����
    float crossObject(const World::TCells&) const;

private:
    World* m_worldCur;
    World* m_worldPrev;
    float  m_filling;
};

#endif // LIFEMODEL_H
