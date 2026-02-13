#ifndef CELL_HPP
#define CELL_HPP

#include <cstdint>

struct Cell {
    bool visited = false;
    uint8_t status = 0; // 0 = new, 1 = working, 2 = finished
    uint8_t connectionNumber = 0;
    uint8_t connections = 0;  // bitmask for connections: 1 = North, 2 = East, 4 = South, 8 = West
};

#endif //CELL_HPP