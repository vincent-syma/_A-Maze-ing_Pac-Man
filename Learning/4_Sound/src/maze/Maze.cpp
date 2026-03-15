#include <cstdint>

#include "Maze.hpp"

Maze::Maze(std::uint32_t w, std::uint32_t h)
    : m_width(w), m_height(h), cells(w*h)
{}

Cell& Maze::get(std::uint32_t x, std::uint32_t y)
{
    return cells[y*m_width + x];
}

const Cell& Maze::get(std::uint32_t x, std::uint32_t y) const
{
    return cells[y*m_width + x];
}

std::uint32_t Maze::width() const { return m_width; }
std::uint32_t Maze::height() const { return m_height; }