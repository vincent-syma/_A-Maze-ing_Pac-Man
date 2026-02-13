#ifndef MAZE_HPP
#define MAZE_HPP

#include <cstdint>
#include <vector>
#include "Cell.hpp"

class Maze {
public:
    Maze() = delete;
    Maze(const Maze&) = default;
    Maze& operator=(const Maze&) = delete;
    Maze(Maze&&) = default;
    Maze& operator=(Maze&&) = delete;
    Maze(uint16_t width, uint16_t height);
    ~Maze() = default;

    uint16_t get_width() const;
    uint16_t get_height() const;
    std::vector<Cell> get_cells() const;
    bool connectEast(uint16_t x, uint16_t y);
    bool connectWest(uint16_t x, uint16_t y);
    bool connectNorth(uint16_t x, uint16_t y);
    bool connectSouth(uint16_t x, uint16_t y);
    bool visit_cell(uint16_t x, uint16_t y);
    Cell& get_cell(uint16_t x, uint16_t y);
    const Cell& get_cell(uint16_t x, uint16_t y) const ;

    void flip_vertically();

    void flip_horizontally();

private:
    uint16_t m_width;
    uint16_t m_height;
    std::vector<Cell> m_cells;
};

#endif // MAZE_HPP