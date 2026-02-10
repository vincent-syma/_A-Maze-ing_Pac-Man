#include <vector>
#include <array>
#include <cstddef>
#include <cstdint>
#include <random>
#include <iostream>
#include "MazeGenerator.hpp" 

MazeGenerator::MazeGenerator(uint8_t width, uint8_t height, uint32_t seed) : m_width(width), m_height(height), m_seed(seed), m_maze(width, height) {
}

uint8_t MazeGenerator::width()  const { return m_width; }
uint8_t MazeGenerator::height() const { return m_height; }
uint32_t MazeGenerator::seed() const { return m_seed; }

bool MazeGenerator::in_bounds(uint8_t x, uint8_t y) const {
    return x < m_width && y < m_height;
}

std::vector<Maze> MazeGenerator::share_maze_history() const {
    return m_maze_history;
}

// hunt kill algorithm
void MazeGenerator::generate_maze() {
    m_maze_history.push_back(m_maze);
    int todo = m_height * m_width;
    int y = m_seed % m_height;
    int x = m_seed % m_width;
    std::mt19937 rng(m_seed);
    std::uniform_int_distribution<uint32_t> dist(0, 3);
    while (todo) {
        int walking = 1;
        //walk
        if (DEBUG) {
            std::cout << "Walking from (" << x << ", " << y << ") todos: " << todo << "\n";
        }
        while (walking) {
            if (DEBUG) {
                std::cout << "At (" << x << ", " << y << ")\n";
            }
            m_maze.get_cell(x, y).visited = true;
            Directions r = static_cast<Directions>(dist(rng));
            if (DEBUG) {
                std::cout << "Trying direction " << (int)r << "\n";
            }
            // OPTIMISATION1: ABSTRACT JOINING NEIGHBOURS TO A FUNCTION - done
            // OPTIMISATION2: CHECK NUMBER OF NEIGHBOURS AND RANDOMLY JOIN ONE OF THEM
            if (r == Directions::NORTH) { // North
                if (y > 0 && !m_maze.get_cell(x, y - 1).visited) { // 
                    if (DEBUG) {
                        std::cout << "Moving North\n";
                    }
                    m_maze.connectNorth(x, y);
                    y--;
                    m_maze_history.push_back(m_maze);
                }
            }
            else if (r == Directions::EAST ) { // East
                if (x < m_width - 1 && !m_maze.get_cell(x + 1, y).visited) {
                    if (DEBUG) {
                        std::cout << "Moving East\n";
                    }   
                    m_maze.connectEast(x, y);
                    x++;
                    m_maze_history.push_back(m_maze);
                }
            }
            else if (r == Directions::SOUTH) { // South
                if (y < m_height - 1 && !m_maze.get_cell(x, y + 1).visited) {
                    if (DEBUG) {
                        std::cout << "Moving South\n";
                    }
                    m_maze.connectSouth(x, y);
                    y++;
                    m_maze_history.push_back(m_maze);
                }
            }
            else if (r == Directions::WEST) { // West
                if (x > 0 && !m_maze.get_cell(x - 1, y).visited) {
                    if (DEBUG) {
                        std::cout << "Moving West\n";
                    }
                    m_maze.connectWest(x, y);
                    x--;
                    m_maze_history.push_back(m_maze );
                }
            }
            if (// no unvisited neighbors
                (y == 0 || m_maze.get_cell(x, y - 1).visited) &&
                (x == m_width - 1 || m_maze.get_cell(x + 1, y).visited) &&
                (y == m_height - 1 || m_maze.get_cell(x, y + 1).visited) &&
                (x == 0 || m_maze.get_cell(x - 1, y).visited)
            )
            {
                m_maze.get_cell(x, y).visited = true;
                walking = 0;
                if (DEBUG) {
                    std::cout << "No unvisited neighbors, stopping walk.\n";
                }
            }
        }
        int hunting = 1;
        //hunt
        while (hunting) {
            if (DEBUG) {
                std::cout << "Hunting...\n";
            }
            bool found = false;
            // could use just one loop since maze is stored linearly
            for (uint8_t yy = 0U; !found && yy < m_height; ++yy) {
                for (uint8_t xx = 0U; !found && xx < m_width; ++xx) {
                    if (!m_maze.get_cell(xx, yy).visited) { // unvisited cell found
                        // check for visited neighbors
                        // SHOULD JOIN RANDOMLY ANY NEIGHBOUR THAT IS VISITED
                        if (yy > 0 && m_maze.get_cell(xx, yy - 1).visited) { // North
                            m_maze.connectNorth(xx, yy);
                            found = true;  
                        }
                        else if (xx < m_width - 1 && m_maze.get_cell(xx + 1, yy).visited) { // East
                            m_maze.connectEast(xx, yy);
                            found = true;
                        }
                        else if (yy < m_height - 1 && m_maze.get_cell(xx, yy + 1).visited) { // South
                            m_maze.connectSouth(xx, yy);
                            found = true;
                        }
                        else if (xx > 0 && m_maze.get_cell(xx - 1, yy).visited) { // West
                            m_maze.connectWest(xx, yy);
                            found = true;
                        }
                        if (found) {
                            if (DEBUG) {
                                std::cout << "Found new starting point at (" << (int)xx << ", " << (int)yy << ")\n";
                            }
                            // move to that cell
                            y = yy;
                            x = xx;
                        }
                    }
                }
            }
            hunting = 0;
            if (!found) {
               todo = 0; // no unvisited cells found, maze generation complete
            }
        }
        m_maze_history.push_back(m_maze);
    }
    // Final state
    m_maze_history.push_back(m_maze);
}
