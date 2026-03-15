#include "map/Map.hpp"

Map::Map(int w, int h)
    : m_width(w), m_height(h), tiles(w*h, TileType::Empty)
{}

TileType Map::get(int x, int y) const
{
    return tiles[y*m_width + x];
}

int Map::width() const
{
    return m_width;
}

int Map::height() const
{
    return m_height;
}