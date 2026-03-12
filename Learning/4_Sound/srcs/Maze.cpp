#include <cstdint>
#include <vector>
#include "Cell.hpp"
#include "Maze.hpp"

// maze struct
// maybe should be class?

Maze::Maze(uint16_t width, uint16_t height) : m_width(width),
                                              m_height(height),
                                              m_cells(width * height) {};


uint16_t Maze::get_width() const {
    return m_width; }

uint16_t Maze::get_height() const {
    return m_height; }

std::vector<Cell> Maze::get_cells() const {
    return m_cells; }

bool Maze::connectEast(uint16_t x, uint16_t y) {
    if (x < m_width - 1) {
        if (m_cells[y * m_width + x].connections & 2) {
            return false; // Already connected East
        }
        m_cells[y * m_width + x].connections |= 2;     // Connect East
        m_cells[y * m_width + x].connectionNumber += 1;
        m_cells[y * m_width + (x + 1)].connections |= 8; // Connect West
        m_cells[y * m_width + (x + 1)].connectionNumber += 1;
        return true;
    }
    return false;
}

bool Maze::connectWest(uint16_t x, uint16_t y) {
    if (x > 0) {
        if (m_cells[y * m_width + x].connections & 8) {
            return false; // Already connected West
        }
        m_cells[y * m_width + x].connections |= 8;     // Connect West
        m_cells[y * m_width + x].connectionNumber += 1;
        m_cells[y * m_width + (x - 1)].connections |= 2; // Connect East
        m_cells[y * m_width + (x - 1)].connectionNumber += 1;
        return true;
    }
    return false;
}

bool Maze::connectNorth(uint16_t x, uint16_t y) {
    if (y > 0) {
        if (m_cells[y * m_width + x].connections & 1) {
            return false; // Already connected North
        }
        m_cells[y * m_width + x].connections |= 1;     // Connect North
        m_cells[y * m_width + x].connectionNumber += 1;
        m_cells[(y - 1) * m_width + x].connections |= 4; // Connect South
        m_cells[(y - 1) * m_width + x].connectionNumber +=  1;
        return true;
    }
    return false;
}

bool Maze::connectSouth(uint16_t x, uint16_t y) {
    if (y < m_height - 1) {
        if (m_cells[y * m_width + x].connections & 4) {
            return false; // Already connected South
        }
        m_cells[y * m_width + x].connections |= 4;     // Connect South
        m_cells[y * m_width + x].connectionNumber += 1;
        m_cells[(y + 1) * m_width + x].connections |= 1; // Connect North
        m_cells[(y + 1) * m_width + x].connectionNumber += 1;
        return true;
    }
    return false;
}

bool Maze::visit_cell(uint16_t x, uint16_t y) {
    if (x < m_width && y < m_height && m_cells[y * m_width + x].visited == false) {
        m_cells[y * m_width + x].visited = true;
        return true;
    }
    return false;
}
Cell& Maze::get_cell(uint16_t x, uint16_t y) {
    return m_cells[y * m_width + x]; }

const Cell& Maze::get_cell(uint16_t x, uint16_t y) const {
    return m_cells[y * m_width + x]; }

void Maze::flip_vertically() {
    uint16_t new_width = m_width * 2 - 1;
    uint16_t new_height = m_height;
    std::vector<Cell> new_cells(new_width * new_height);
    for (uint16_t y = 0; y < m_height; ++y) {
        for (uint16_t x = 0; x < m_width; ++x) {
            new_cells[y * new_width + x] = m_cells[y * m_width + x];
        }
        if (new_cells[y * new_width + m_width - 1].connections & 8) {
            new_cells[y * new_width + m_width - 1].connections |= 2; // add west connection if east connection was present
            new_cells[y * new_width + m_width - 1].connectionNumber += 1;
        }
        for (uint16_t x = new_width - 1; x >= m_width; --x) {
            new_cells[y * new_width + x] = m_cells[y * m_width + (m_width - 1 - (x - m_width + 1))];
            uint8_t connections = new_cells[y * new_width + x].connections;
            new_cells[y * new_width + x].connections &= 5; // keep north and south connections, remove east and west
            new_cells[y * new_width + x].connections |= (connections & 2) * 4; // add east connection if west connection was present
            new_cells[y * new_width + x].connections |= (connections & 8) / 4; // add west connection if east connection was present
        }
    }
    m_cells = std::move(new_cells);
    m_width = new_width;
    m_height = new_height;
};

void Maze::flip_horizontally() {
    uint16_t new_width = m_width;
    uint16_t new_height = m_height * 2 - 1;
    std::vector<Cell> new_cells(new_width * new_height);
    for (uint16_t y = 0; y < m_height; ++y) {
        for (uint16_t x = 0; x < m_width; ++x) {
            new_cells[y * new_width + x] = m_cells[y * m_width + x];
        }
    }
    for (uint16_t x = 0; x < m_width; ++x) {
        if (new_cells[(m_height - 1) * new_width + x].connections & 1) {
                new_cells[(m_height - 1) * new_width + x].connections |= 4; // add south connection if north connection was present
                new_cells[(m_height - 1) * new_width + x].connectionNumber += 1;
        }
    }
    for (uint16_t y = m_height; y < new_height; ++y) {
        for (uint16_t x = 0; x < m_width; ++x) {
            new_cells[y * new_width + x] = m_cells[(m_height - 1 - (y - m_height + 1)) * m_width + x];
            uint8_t connections = new_cells[y * new_width + x].connections;
            new_cells[y * new_width + x].connections &= 10; // keep east and west connections, remove north and south
            new_cells[y * new_width + x].connections |= (connections & 1) * 4; // add north connection if south connection was present
            new_cells[y * new_width + x].connections |= (connections & 4) / 4; // add south connection if north connection was present
        }
    }
    m_cells = std::move(new_cells);
    m_width = new_width;
    m_height = new_height;
};
