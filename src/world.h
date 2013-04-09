///////////////////////////////////////////////////////////////////////////////
//  World - клеточный 2-D мир
//
//  Project: "LifeTime"  (life.timeacademy.ru)
//  Autor: Zimaev Igor (i.zimaev@gmail.com)
///////////////////////////////////////////////////////////////////////////////
#ifndef WORLD_H
#define WORLD_H
#include <QPair>
#include <QSet>

class World
{
public:
    World();
    World(const World& obj);
    ~World();

    typedef QPair<int,int>  TCell;
    typedef QSet<TCell>     TCells;

    const World& operator = (const World& rhs);

    void init(int rows, int cols);
    void clear();
    void destroy();

    int rows() const;
    int cols() const;

    bool& cell(int row, int col) ;
    bool  cell(int row, int col) const;

    // ѕолучить список из 8 соседей
    TCells nearest(int row, int col) const;

    void selectObject(int row, int col, TCells& object, bool begin=true) const;

private:
    bool** m_cells;
    int    m_rows;
    int    m_cols;
};

#endif // WORLD_H
