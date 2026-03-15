#pragma once

#include <stack>
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

    int stepCount() const;

    const BoolOverlay& visited() const;
    const BoolOverlay& frontier() const;

    Position current() const;

private:
    Maze& m_maze;

    BoolOverlay m_visited;
    BoolOverlay m_frontier;

    std::stack<Position> m_stack;

    Position m_current;

    int m_step = 0;
    bool m_finished = false;
};
