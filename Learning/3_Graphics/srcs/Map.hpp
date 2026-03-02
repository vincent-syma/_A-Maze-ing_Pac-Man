#ifndef MAP_HPP
#define MAP_HPP

#include <cstdint>
#include <vector>
#include "Cell.hpp"
#include "Maze.hpp"

class Map {
public:
    Map() = delete;
    Map(const Map&) = default;
    Map& operator=(const Map&) = delete;
    Map(Map&&) = default;
    Map& operator=(Map&&) = delete;
    Map(Maze maze);
    ~Map() = default;

    uint16_t get_width() const;
    uint16_t get_height() const;

    // // maybe??
    // std::vector<Cell> get_cells() const;

    void double_line(uint16_t y);

    void add_portal_line(uint16_t y);

    const Cell& get_cell(uint16_t x, uint16_t y) const ;

    std::vector<Map> share_map_history() const;

private:
    uint16_t m_width;
    uint16_t m_height;
    std::vector<Cell> m_cells;
    std::vector<Map> m_map_history;
};

#endif // MAP_HPP

//converts Maze to map


// double a line

// double a column

// add portals
