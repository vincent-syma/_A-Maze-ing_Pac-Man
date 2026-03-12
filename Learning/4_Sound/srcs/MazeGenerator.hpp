#ifndef MAZEGENERATOR_HPP
#define MAZEGENERATOR_HPP

#include <vector>
#include <array>
#include <cstddef>
#include <cstdint>

#include "shared.hpp"

#include "Maze.hpp"

class MazeGenerator {
public:
    MazeGenerator() = delete;
    MazeGenerator(uint8_t width, uint8_t height, uint32_t seed);
    ~MazeGenerator() = default;

    uint8_t width()  const;
    uint8_t height() const;
    uint32_t seed() const;

    bool in_bounds(uint8_t x, uint8_t y) const;
    bool visit_cell(uint8_t x, uint8_t y);

    std::vector<Maze> share_maze_history() const;

    void generate_maze();

    void remove_deadends();

    void increase_connections();

    void flip_horizontally();

    void flip_vertically();

private:
    uint8_t m_width; // not needed
    uint8_t m_height; // not needed
    uint32_t m_seed;
    // std::vector<Cell>   m_maze;
    Maze                m_maze;
    // std::vector<std::vector<Cell>> m_maze_history;
    std::vector<Maze> m_maze_history;
};

#endif // MAZEGENERATOR_HPP