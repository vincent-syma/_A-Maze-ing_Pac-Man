#pragma once
#include <cstdint>

#include "map/Map.hpp"
#include "maze/Maze.hpp"

class MapEditor
{
public:
    MapEditor(Map& map);

    void setTile(std::uint32_t x, std::uint32_t y, TileType type);

    void buildFromMaze(const Maze& maze);

    void buildFromPath(const std::string& path);

private:
    Map& map;
};