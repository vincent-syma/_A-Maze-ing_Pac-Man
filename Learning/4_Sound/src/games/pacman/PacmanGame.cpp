#include "PacmanGame.hpp"
#include "map/MapEditor.hpp"
#include <iostream>

void PacmanGame::init() {
    std::cout << "initializing" << std::endl;
    MapEditor editor(map);
    editor.buildFromPath("assets/maps/map.txt");
    //debug print the map
    for (std::uint32_t y = 0U; y < map.height(); y++)
    {
        for (std::uint32_t x = 0U; x < map.width(); x++)
        {
            switch (map.get(x, y))
            {
                case TileType::Empty:
                    std::cout << ' ';
                    break;
                case TileType::Wall:
                    std::cout << '#';
                    break;
                case TileType::Pellet:
                    std::cout << '.';
                    break;
                case TileType::PowerPellet:
                    std::cout << 'o';
                    break;
                default:
                    std::cout << '?';
                    break;
            }
        }
        std::cout << std::endl;
    }
}

void PacmanGame::update() {
    std::cout << "updating" << std::endl;
}

void PacmanGame::render() {
    std::cout << "rendering" << std::endl;
}
