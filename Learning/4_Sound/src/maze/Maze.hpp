#pragma once

#include <vector>
#include "Cell.hpp"

class Maze
{
public:
    Maze(int w, int h);

    Cell& get(int x, int y);
    const Cell& get(int x, int y) const;

    int width() const;
    int height() const;

private:
    int m_width;
    int m_height;
    std::vector<Cell> cells;

    friend class MazeEditor;
};
