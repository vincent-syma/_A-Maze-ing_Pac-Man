#include "map/BoolOverlay.hpp"
#include <cstdint>

BoolOverlay::BoolOverlay(std::uint32_t w, std::uint32_t h)
{
    m_width = w;
    m_height = h;

    data.resize(w * h, false);
}

bool BoolOverlay::get(std::uint32_t x, std::uint32_t y) const
{
    return data[index(x, y)];
}

void BoolOverlay::set(std::uint32_t x, std::uint32_t y, bool value)
{
    data[index(x, y)] = value;
}

void BoolOverlay::clear()
{
    std::fill(data.begin(), data.end(), false);
}
