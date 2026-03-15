#include "MazeEditor.hpp"

MazeEditor::MazeEditor(Maze& m)
    : maze(m)
{}

void MazeEditor::generate()
{
    for (int y = 0; y < maze.height(); y++)
    {
        for (int x = 0; x < maze.width(); x++)
        {
            maze.get(x,y).connections = 0;
        }
    }
}
