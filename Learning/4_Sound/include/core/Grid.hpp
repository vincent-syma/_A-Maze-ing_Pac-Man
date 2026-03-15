#pragma once

#include <cstdint>

class Grid
{
protected:
    std::uint32_t m_width;
    std::uint32_t m_height;

    std::uint32_t index(std::uint32_t x, std::uint32_t y) const
    {
        return y * m_width + x;
    }

public:
    std::uint32_t width() const { return m_width; }
    std::uint32_t height() const { return m_height; }
};
