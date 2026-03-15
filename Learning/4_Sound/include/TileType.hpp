#pragma once

#include <cstdint>

enum class TileType : std::uint8_t
{
    Empty = 0,
    Wall,

    Pellet,
    PowerPellet,

    PlayerSpawn,
    GhostSpawn,

    Tunnel
};
