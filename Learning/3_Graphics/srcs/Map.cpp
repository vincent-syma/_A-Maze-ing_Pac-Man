//converts Maze to map


// double a line

// double a column


// add ghost area (Maybe add to maze generation step?)
// add portals

#include "shared.hpp"
#include "Cell.hpp"
#include "Maze.hpp"
#include "Map.hpp"

Map::Map(Maze maze)
{
	m_width = maze.get_width() * 3;
    m_height = maze.get_height() * 3;
    m_cells.resize(m_width * m_height);
    uint16_t maze_width = maze.get_width();
    uint16_t maze_height = maze.get_height();
    for (uint16_t y = 0; y < maze_height; ++y) {
        for (uint16_t x = 0; x < maze_width; ++x) {
            const Cell& maze_cell = maze.get_cell(x, y);
            uint16_t map_x = x * 3 + 1;
            uint16_t map_y = y * 3 + 1;
            if (maze_cell.connectionNumber) {
                m_cells[map_y * m_width + map_x].status = CellType::PATH;
            } else {
                m_cells[map_y * m_width + map_x].status = CellType::WALL;
            }
            // m_cells[map_y * m_width + map_x].connections = maze_cell.connections;
            // m_cells[map_y * m_width + map_x].connectionNumber = maze_cell.connectionNumber;
            // m_cells[map_y * m_width + map_x].visited = false;
            if (maze_cell.connections & 1) { // North
                m_cells[(map_y - 1) * m_width + map_x].status = CellType::PATH;
            }
            else {
                m_cells[(map_y - 1) * m_width + map_x].status = CellType::WALL;
            }
            if (maze_cell.connections & 2) { // East
                m_cells[map_y * m_width + (map_x + 1)].status = CellType::PATH;
            }
            else {
                m_cells[map_y * m_width + (map_x + 1)].status = CellType::WALL;
            }
            if (maze_cell.connections & 4) { // South
                m_cells[(map_y + 1) * m_width + map_x].status = CellType::PATH;
            }
            else {
                m_cells[(map_y + 1) * m_width + map_x].status = CellType::WALL;
            }
            if (maze_cell.connections & 8) { // West
                m_cells[map_y * m_width + (map_x - 1)].status = CellType::PATH;
            }
            else {
                m_cells[map_y * m_width + (map_x - 1)].status = CellType::WALL;
            }
            m_cells[(map_y - 1) * m_width + (map_x - 1)].status = CellType::WALL;
            m_cells[(map_y - 1) * m_width + (map_x + 1)].status = CellType::WALL;
            m_cells[(map_y + 1) * m_width + (map_x - 1)].status = CellType::WALL;
            m_cells[(map_y + 1) * m_width + (map_x + 1)].status = CellType::WALL;

        }
    }
    m_map_history.push_back(*this);
}

uint16_t Map::get_width() const {
    return m_width;
}

uint16_t Map::get_height() const {
    return m_height;
}

const Cell& Map::get_cell(uint16_t x, uint16_t y) const {
    return m_cells[y * m_width + x];
}

std::vector<Map> Map::share_map_history() const {
    return m_map_history;
}

void Map::double_line(uint16_t y) {
    if (y >= m_height) {
        return;
    }
    std::vector<Cell> new_cells(m_width * (m_height + 1));
    for (uint16_t i = 0; i < m_width * (m_height + 1); ++i) {
        uint16_t x = i % m_width;
        uint16_t old_y = i / m_width;
        uint16_t new_y = old_y + (old_y >= y ? 1 : 0);
        if (old_y == y) {
            new_cells[old_y * m_width + x] = m_cells[i];
        }
        new_cells[new_y * m_width + x] = m_cells[i];
    }
    m_cells = std::move(new_cells);
    m_height += 1;
    m_map_history.push_back(*this);
}

void Map::add_portal_line(uint16_t y) {
    if (y > m_height / 3) {
        return;
    }
    uint16_t x = 0;
    while (m_cells[(y * 3 + 1) * m_width + x].status != CellType::PATH) {
         m_cells[(y * 3 + 1) * m_width + x].status = CellType::PATH;
         x++;   
    }
    x = m_width - 1;
    while (m_cells[(y * 3 + 1) * m_width + x].status != CellType::PATH) {
         m_cells[(y * 3 + 1) * m_width + x].status = CellType::PATH;
         x--;   
    }
    m_map_history.push_back(*this);
}
