#ifndef MAZE_HPP
#define MAZE_HPP

#include <vector>
#include <array>
#include <cstddef>
#include <cstdint>

#include "shared.hpp"

class MazeGenerator {
public:
    MazeGenerator() = delete;
    MazeGenerator(uint8_t width, uint8_t height, uint32_t seed);
    ~MazeGenerator() = default;

    uint8_t width()  const;
    uint8_t height() const;
    uint32_t seed() const;

    // Cell& get_cell(uint8_t x, uint8_t y);

    // const Cell& get_cell(uint8_t x, uint8_t y) const;

    bool in_bounds(uint8_t x, uint8_t y) const;
    // std::vector<Cell> get_maze() const;
    // std::vector<std::vector<Cell>> share_history() const;
    std::vector<Maze> share_maze_history() const;

    void generate_maze();

private:
    uint8_t m_width;
    uint8_t m_height;
    uint32_t m_seed;
    // std::vector<Cell>   m_maze;
    Maze                m_maze;
    // std::vector<std::vector<Cell>> m_maze_history;
    std::vector<Maze> m_maze_history;
};

#endif // MAZE_HPP