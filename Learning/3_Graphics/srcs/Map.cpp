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
                m_cells[map_y * m_width + map_x].wall = 13;
                m_cells[map_y * m_width + map_x].path = maze_cell.connections;
                // m_cells[map_y * m_width + map_x].connectionNumber = maze_cell.connectionNumber;
                // m_cells[map_y * m_width + map_x].visited = false;
                if (maze_cell.connections & 1) { // North
                    m_cells[(map_y - 1) * m_width + map_x].status = CellType::PATH;
                    m_cells[(map_y - 1) * m_width + map_x].path = 5;
                    m_cells[(map_y - 1) * m_width + map_x].wall = 13;
                }
                else {
                    m_cells[(map_y - 1) * m_width + map_x].status = CellType::WALL;
                    m_cells[(map_y - 1) * m_width + map_x].wall = 8;
                }
                if (maze_cell.connections & 2) { // East
                    m_cells[map_y * m_width + (map_x + 1)].status = CellType::PATH;
                    m_cells[map_y * m_width + (map_x + 1)].path = 10;
                    m_cells[map_y * m_width + (map_x + 1)].wall = 13;
                }
                else {
                    m_cells[map_y * m_width + (map_x + 1)].status = CellType::WALL;
                    m_cells[map_y * m_width + (map_x + 1)].wall = 5;
                }
                if (maze_cell.connections & 4) { // South
                    m_cells[(map_y + 1) * m_width + map_x].status = CellType::PATH;
                    m_cells[(map_y + 1) * m_width + map_x].path = 5;
                    m_cells[(map_y + 1) * m_width + map_x].wall = 13;
                }
                else {
                    m_cells[(map_y + 1) * m_width + map_x].status = CellType::WALL;
                    m_cells[(map_y + 1) * m_width + map_x].wall = 6;
                }
                if (maze_cell.connections & 8) { // West
                    m_cells[map_y * m_width + (map_x - 1)].status = CellType::PATH;
                    m_cells[map_y * m_width + (map_x - 1)].path = 10;
                    m_cells[map_y * m_width + (map_x - 1)].wall = 13;
                }
                else {
                    m_cells[map_y * m_width + (map_x - 1)].status = CellType::WALL;
                    m_cells[map_y * m_width + (map_x - 1)].wall = 7;
                }
                m_cells[(map_y - 1) * m_width + (map_x - 1)].status = CellType::WALL;
                if ((maze_cell.connections & 8) && (maze_cell.connections & 1)) { // west && north
                    m_cells[(map_y - 1) * m_width + (map_x - 1)].wall = 12; 
                }
                else if (maze_cell.connections & 8) { // west
                    m_cells[(map_y - 1) * m_width + (map_x - 1)].wall = 8; 
                }
                else if (maze_cell.connections & 1) { // north
                    m_cells[(map_y - 1) * m_width + (map_x - 1)].wall = 7; 
                }
                else {
                    m_cells[(map_y - 1) * m_width + (map_x - 1)].wall = 4;
                }
                m_cells[(map_y - 1) * m_width + (map_x + 1)].status = CellType::WALL;
                if ((maze_cell.connections & 2) && (maze_cell.connections & 1)) { // east && north
                    m_cells[(map_y - 1) * m_width + (map_x + 1)].wall = 11;
                }
                else if (maze_cell.connections & 2) { // east
                    m_cells[(map_y - 1) * m_width + (map_x + 1)].wall = 8;
                }
                else if (maze_cell.connections & 1) { // north
                    m_cells[(map_y - 1) * m_width + (map_x + 1)].wall = 5;
                }
                else {
                    m_cells[(map_y - 1) * m_width + (map_x + 1)].wall = 3;
                }
                m_cells[(map_y + 1) * m_width + (map_x - 1)].status = CellType::WALL;
                if ((maze_cell.connections & 8) && (maze_cell.connections & 4)) { // west && south
                    m_cells[(map_y + 1) * m_width + (map_x - 1)].wall = 10;
                }
                else if (maze_cell.connections & 8) { // west
                    m_cells[(map_y + 1) * m_width + (map_x - 1)].wall = 6;
                }
                else if (maze_cell.connections & 4) { // south
                    m_cells[(map_y + 1) * m_width + (map_x - 1)].wall = 7;
                }
                else {
                    m_cells[(map_y + 1) * m_width + (map_x - 1)].wall = 2;
                }
                m_cells[(map_y + 1) * m_width + (map_x + 1)].status = CellType::WALL;
                if ((maze_cell.connections & 2) && (maze_cell.connections & 4)) { // east && south
                    m_cells[(map_y + 1) * m_width + (map_x + 1)].wall = 9;
                }
                else if (maze_cell.connections & 2) { // east
                    m_cells[(map_y + 1) * m_width + (map_x + 1)].wall = 6;
                }
                else if (maze_cell.connections & 4) { // south
                    m_cells[(map_y + 1) * m_width + (map_x + 1)].wall = 5;
                }
                else {
                    m_cells[(map_y + 1) * m_width + (map_x + 1)].wall = 1;
                }
            }
            else {
                m_cells[(map_y - 1) * m_width + (map_x - 1)].status = CellType::WALL;
                m_cells[(map_y - 1) * m_width + map_x].status = CellType::WALL;
                m_cells[(map_y - 1) * m_width + (map_x + 1)].status = CellType::WALL;
                m_cells[map_y * m_width + (map_x - 1)].status = CellType::WALL;
                m_cells[map_y * m_width + map_x].status = CellType::WALL;
                m_cells[map_y * m_width + (map_x + 1)].status = CellType::WALL;
                m_cells[(map_y + 1) * m_width + (map_x - 1)].status = CellType::WALL;
                m_cells[(map_y + 1) * m_width + map_x].status = CellType::WALL;
                m_cells[(map_y + 1) * m_width + (map_x + 1)].status = CellType::WALL;
            }
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
            switch (new_cells[old_y * m_width + x].wall) {
                case 1:
                    new_cells[old_y * m_width + x].wall = 5;
                    break ;
                case 2:
                    new_cells[old_y * m_width + x].wall = 7;
                    break ;
                case 3:
                    new_cells[old_y * m_width + x].wall = 0;
                    break ;
                case 4:
                    new_cells[old_y * m_width + x].wall = 0;
                    break ;
                case 6:
                    new_cells[old_y * m_width + x].wall = 13;
                    break ;
                case 8:
                    new_cells[old_y * m_width + x].wall = 0;
                    break ;
                case 9:
                    new_cells[old_y * m_width + x].wall = 13;
                    break ;
                case 10:
                    new_cells[old_y * m_width + x].wall = 13;
                    break ;
                case 11:
                    new_cells[old_y * m_width + x].wall = 5;
                    break ;
                case 12:
                    new_cells[old_y * m_width + x].wall = 7;
                    break ;

                default:
                    break ;
            }
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
         m_cells[(y * 3) * m_width + x].wall = 12;
         m_cells[(y * 3 + 1) * m_width + x].wall = 13;
         m_cells[(y * 3 + 2) * m_width + x].wall = 10;
         x++;   
    }
    x = m_width - 1;
    while (m_cells[(y * 3 + 1) * m_width + x].status != CellType::PATH) {
         m_cells[(y * 3 + 1) * m_width + x].status = CellType::PATH;
         m_cells[(y * 3) * m_width + x].wall = 11;
         m_cells[(y * 3 + 1) * m_width + x].wall = 13;
         m_cells[(y * 3 + 2) * m_width + x].wall = 9;
         x--;   
    }
    m_map_history.push_back(*this);
}
