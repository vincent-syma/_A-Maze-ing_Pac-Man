#ifndef CELL_HPP
#define CELL_HPP

#include <cstdint>
#include "shared.hpp"

struct Cell {
    bool visited = false;
    CellType status = CellType::EMPTY;
    uint8_t connectionNumber = 0;
    uint8_t connections = 0;  // bitmask for connections: 1 = North, 2 = East, 4 = South, 8 = West
};

#endif //CELL_HPP