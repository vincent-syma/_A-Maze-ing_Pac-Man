#include "map/BoolOverlay.hpp"

BoolOverlay::BoolOverlay(int w, int h)
{
    m_width = w;
    m_height = h;

    data.resize(w * h, false);
}

bool BoolOverlay::get(int x, int y) const
{
    return data[index(x, y)];
}

void BoolOverlay::set(int x, int y, bool value)
{
    data[index(x, y)] = value;
}

void BoolOverlay::clear()
{
    std::fill(data.begin(), data.end(), false);
}
