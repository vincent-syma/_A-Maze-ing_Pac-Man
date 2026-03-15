#pragma once

#include <stack>
#include <cstdint>
#include "map/Map.hpp"
#include "map/BoolOverlay.hpp"
#include "maze/Maze.hpp"

class MazeGenerator
{
public:
    MazeGenerator(Maze& maze);

    void reset();

    bool step();

    bool finished() const;

    std::uint32_t stepCount() const;

    const BoolOverlay& visited() const;
    const BoolOverlay& frontier() const;

    Position current() const;

private:
    Maze& m_maze;

    BoolOverlay m_visited;
    BoolOverlay m_frontier;

    std::stack<Position> m_stack;

    Position m_current;

    std::uint32_t m_step = 0U;
    bool m_finished = false;
};
