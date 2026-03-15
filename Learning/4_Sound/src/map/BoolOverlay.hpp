#pragma once

#include <vector>
#include <cstdint>
#include "core/Grid.hpp"

class BoolOverlay : public Grid
{
public:
    BoolOverlay(std::uint32_t w, std::uint32_t h);

    bool get(std::uint32_t x, std::uint32_t y) const;
    void set(std::uint32_t x, std::uint32_t y, bool value);

    void clear();

private:
    std::vector<bool> data;
};
