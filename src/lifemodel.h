///////////////////////////////////////////////////////////////////////////////
//  LifeModel - расчет жизни мира по классическому алгоритму Конвея
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

    // 1-й способ запуска жизни: с нуля
    void  start(int rows, int cols, int count);
    // 2-й способ запуска жизни: мир дан
    void setWorld(const World& world);

    // Расчет следующего "кадра" жизни
    const World& next();

    // Коэффициент заполненности мира
    float filling() const;

    // Коэффициент пересечения объекта с миром
    float crossObject(const World::TCells&) const;

private:
    World* m_worldCur;
    World* m_worldPrev;
    float  m_filling;
};

#endif // LIFEMODEL_H
