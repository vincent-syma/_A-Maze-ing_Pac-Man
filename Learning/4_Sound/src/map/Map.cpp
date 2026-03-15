#include <cstdint>
#include "map/Map.hpp"

Map::Map(std::uint32_t w, std::uint32_t h)
    : m_width(w), m_height(h), tiles(w * h, TileType::Empty)
{
}

std::uint32_t Map::index(std::uint32_t x, std::uint32_t y) const
{
    return y * m_width + x;
}

TileType Map::get(std::uint32_t x, std::uint32_t y) const
{
    return tiles[index(x, y)];
}

TileType& Map::at(std::uint32_t x, std::uint32_t y)
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

bool Map::inBounds(std::uint32_t x, std::uint32_t y) const
{
    return x >= 0 && y >= 0 &&
           x < m_width && y < m_height;
}

std::uint32_t Map::width() const
{
    return m_width;
}

std::uint32_t Map::height() const
{
    return m_height;
}
