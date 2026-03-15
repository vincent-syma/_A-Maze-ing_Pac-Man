#include "map/Map.hpp"

Map::Map(int w, int h)
    : m_width(w), m_height(h), tiles(w * h, TileType::Empty)
{
}

int Map::index(int x, int y) const
{
    return y * m_width + x;
}

TileType Map::get(int x, int y) const
{
    return tiles[index(x, y)];
}

TileType& Map::at(int x, int y)
{
    return tiles[index(x, y)];
}

TileType Map::get(Position p) const
{
    return get(p.x, p.y);
}

TileType& Map::at(Position p)
{
    return at(p.x, p.y);
}

bool Map::inBounds(int x, int y) const
{
    return x >= 0 && y >= 0 &&
           x < m_width && y < m_height;
}

int Map::width() const
{
    return m_width;
}

int Map::height() const
{
    return m_height;
}
