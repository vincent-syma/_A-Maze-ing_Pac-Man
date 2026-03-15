#pragma once

#include <cstdint>
#include <vector>
#include "Cell.hpp"

class Maze
{
public:
    Maze(std::uint32_t w, std::uint32_t h);

    Cell& get(std::uint32_t x, std::uint32_t y);
    const Cell& get(std::uint32_t x, std::uint32_t y) const;

    std::uint32_t width() const;
    std::uint32_t height() const;

private:
    std::uint32_t m_width;
    std::uint32_t m_height;
    std::vector<Cell> cells;

    friend class MazeEditor;
};
