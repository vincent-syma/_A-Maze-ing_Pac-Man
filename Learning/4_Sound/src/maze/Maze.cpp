#include "Maze.hpp"

Maze::Maze(int w, int h)
    : m_width(w), m_height(h), cells(w*h)
{}

Cell& Maze::get(int x, int y)
{
    return cells[y*m_width + x];
}

const Cell& Maze::get(int x, int y) const
{
    return cells[y*m_width + x];
}

int Maze::width() const { return m_width; }
int Maze::height() const { return m_height; }