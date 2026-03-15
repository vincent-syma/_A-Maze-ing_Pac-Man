#pragma once
#include <cstdint>

enum Direction : std::uint8_t
{
    NORTH = 1,
    EAST  = 2,
    SOUTH = 4,
    WEST  = 8
};
