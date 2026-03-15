#pragma once

#include "Maze.hpp"

class MazeEditor
{
public:
    MazeEditor(Maze& maze);

    void generate();

private:
    Maze& maze;
};
