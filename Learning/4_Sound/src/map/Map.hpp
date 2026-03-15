#pragma once

#include <vector>

enum class TileType
{
    Empty,
    Wall,
    Pellet,
    PowerPellet
};

struct Position
{
    int x;
    int y;
};

class Map
{
public:
    Map(int w, int h);

    TileType get(int x, int y) const;
    TileType& at(int x, int y);

    TileType get(Position p) const;
    TileType& at(Position p);

    bool inBounds(int x, int y) const;

    int width() const;
    int height() const;

private:
    int m_width;
    int m_height;

    std::vector<TileType> tiles;

    int index(int x, int y) const;

friend class MapEditor;
};
