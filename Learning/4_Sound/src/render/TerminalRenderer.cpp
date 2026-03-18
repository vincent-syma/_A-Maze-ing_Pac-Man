#include <stdint.h>
#include <iostream>
#include "TerminalRenderer.hpp"
#include "map/Map.hpp"

void TerminalRenderer::clear(){}
void TerminalRenderer::present(){}

void TerminalRenderer::drawMap(const Map& map) {
    for (std::uint32_t y = 0U; y < map.height(); y++)
    {
        for (std::uint32_t x = 0U; x < map.width(); x++)
        {
            switch (map.get(x, y))
            {
                case TileType::Empty:
                    std::cout << "  ";
                    break;
                case TileType::BonusSpawn:
                    std::cout << "B ";
                    break;
                case TileType::ReadySpawn:
                    std::cout << "R ";
                    break;
                case TileType::PlayerSpawn:
                    std::cout << "S ";
                    break;
                case TileType::GhostSpawn:
                    std::cout << "G ";
                    break;
                case TileType::Wall:
                    std::cout << "##";
                    break;
                case TileType::Wall2:
                    std::cout << "**";
                    break;
                case TileType::Door_EastWest:
                    std::cout << "--";
                    break;
                case TileType::Pellet:
                    std::cout << ". ";
                    break;
                case TileType::PowerPellet:
                    std::cout << "o ";
                    break;
                default:
                    std::cout << "? ";
                    break;
            }
        }
        std::cout << std::endl;
    }
}
