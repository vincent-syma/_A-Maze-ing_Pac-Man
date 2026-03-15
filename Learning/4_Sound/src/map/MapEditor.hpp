#pragma once

#include "map/Map.hpp"
#include "maze/Maze.hpp"

class MapEditor
{
public:
    MapEditor(Map& map);

    void setTile(int x, int y, TileType type);

    void buildFromMaze(const Maze& maze);

private:
    Map& map;
};