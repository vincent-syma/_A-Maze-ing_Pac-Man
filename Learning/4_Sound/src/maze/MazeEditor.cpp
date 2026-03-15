
#include <cstdint>
#include "MazeEditor.hpp"

MazeEditor::MazeEditor(Maze& m)
    : maze(m)
{}

void MazeEditor::generate()
{
    for (std::uint32_t y = 0U; y < maze.height(); y++)
    {
        for (std::uint32_t x = 0U; x < maze.width(); x++)
        {
            maze.get(x,y).connections = 0U;
        }
    }
}
