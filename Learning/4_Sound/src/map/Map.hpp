#pragma once
#include <vector>
#include "TileType.hpp"

class Map
{
public:
    Map(int w, int h);

    TileType get(int x, int y) const;

    int width() const;
    int height() const;

private:
    int m_width;
    int m_height;
    std::vector<TileType> tiles;

    friend class MapEditor;
};
