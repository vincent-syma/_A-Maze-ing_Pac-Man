#pragma once

#include "map/Map.hpp"
#include "map/BoolOverlay.hpp"

struct MazeSnapshot
{
    int step;

    Map map;

    BoolOverlay visited;
    BoolOverlay frontier;

    Position current;

    MazeSnapshot(
        int step_,
        const Map& map_,
        const BoolOverlay& visited_,
        const BoolOverlay& frontier_,
        Position current_
    )
        : step(step_),
          map(map_),
          visited(visited_),
          frontier(frontier_),
          current(current_)
    {
    }
};