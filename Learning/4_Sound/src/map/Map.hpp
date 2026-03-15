#pragma once

#include <vector>
#include <cstdint>
#include "TileType.hpp"
#include "Position.hpp"



class Map
{
public:
    Map(std::uint32_t w, std::uint32_t h);

    TileType get(std::uint32_t x, std::uint32_t y) const;
    TileType& at(std::uint32_t x, std::uint32_t y);

    TileType get(Position p) const;
    TileType& at(Position p);

    bool inBounds(std::uint32_t x, std::uint32_t y) const;

    std::uint32_t width() const;
    std::uint32_t height() const;

private:
    std::uint32_t m_width;
    std::uint32_t m_height;

    std::vector<TileType> tiles;

    std::uint32_t index(std::uint32_t x, std::uint32_t y) const;

friend class MapEditor;
};
