#include "map/MapEditor.hpp"

MapEditor::MapEditor(Map& m)
    : map(m)
{}

void MapEditor::setTile(int x, int y, TileType type)
{
    map.tiles[y * map.m_width + x] = type;
}

void MapEditor::buildFromMaze(const Maze& maze)
{
    for (int y = 0; y < map.m_height; y++)
    {
        for (int x = 0; x < map.m_width; x++)
        {
            setTile(x, y, TileType::Wall);
        }
    }

    for (int y = 0; y < maze.height(); y++)
    {
        for (int x = 0; x < maze.width(); x++)
        {
            int mx = x * 2 + 1;
            int my = y * 2 + 1;

            setTile(mx, my, TileType::Pellet);
        }
    }
}