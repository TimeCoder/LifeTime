#include "world.h"

World::World() : m_cells(0), m_rows(0), m_cols(0)
{
}


World::World(const World& obj) : m_cells(0), m_rows(0), m_cols(0)
{
    (*this) = obj;
}


World::~World()
{
    destroy();
}


const World& World::operator = (const World& rhs)
{
    if (this == &rhs) return (*this);
    destroy();

    init(rhs.m_rows, rhs.m_cols);

    for (int i=0; i<m_rows; ++i)
    {
        for (int j=0; j<m_cols; ++j)
        {
            m_cells[i][j] = rhs.m_cells[i][j];
        }
    }
    return *this;
}


void World::init(int rows, int cols)
{
    destroy();

    m_rows  = rows;
    m_cols  = cols;
    m_cells = new bool*[m_rows];

    for (int i=0; i<m_rows; ++i)
    {
        m_cells[i] = new bool[m_cols];
        for (int j=0; j<m_cols; ++j)
        {
            m_cells[i][j] = false;
        }
    }
}


void World::clear()
{
    for (int i=0; i<m_rows; ++i)
    {
        for (int j=0; j<m_cols; ++j)
        {
            m_cells[i][j] = false;
        }
    }
}


void World::destroy()
{
    for (int i=0; i<m_rows; ++i)
    {
        delete[] m_cells[i];
    }

    if (m_cells) delete[] m_cells;

    m_cells = 0;
    m_rows  = 0;
    m_cols  = 0;
}


int World::rows() const
{
    return m_rows;
}


int World::cols() const
{
    return m_cols;
}


bool& World::cell(int row, int col)
{
    Q_ASSERT(row >= 0 && row < m_rows);
    Q_ASSERT(col >= 0 && col < m_cols);
    return m_cells[row][col];
}


bool World::cell(int row, int col) const
{
    Q_ASSERT(row >= 0 && row < m_rows);
    Q_ASSERT(col >= 0 && col < m_cols);
    return m_cells[row][col];
}


World::TCells World::nearest(int row, int col) const
{
    World::TCells cells;
    int prevRow = row - 1; if (prevRow < 0) prevRow += rows();
    int prevCol = col - 1; if (prevCol < 0) prevCol += cols();

    int nextRow = row + 1; if (nextRow >= rows()) nextRow -= rows();
    int nextCol = col + 1; if (nextCol >= cols()) nextCol -= cols();

    cells << qMakePair(prevRow, prevCol);
    cells << qMakePair(prevRow, col);
    cells << qMakePair(prevRow, nextCol);
    cells << qMakePair(row, prevCol);
    cells << qMakePair(row, nextCol);
    cells << qMakePair(nextRow, prevCol);
    cells << qMakePair(nextRow, col);
    cells << qMakePair(nextRow, nextCol);

    return cells;
}


void World::selectObject(int row, int col, TCells& object, bool begin) const
{
    if (begin) object.clear();

    if (object.contains(qMakePair(row, col))) return;

    if (cell(row, col))
    {
        object << qMakePair(row, col);
    }
    else
    {
        return;
    }

    foreach(const TCell& cell, nearest(row, col))
    {
        selectObject(cell.first, cell.second, object, false);
    }
}

