#include "MazeGenerator.hpp"

MazeGenerator::MazeGenerator(Maze& maze)
    : m_maze(maze),
      m_visited(maze.width(), maze.height()),
      m_frontier(maze.width(), maze.height())
{
}

void MazeGenerator::reset()
{
    m_visited.clear();
    m_frontier.clear();

    while (!m_stack.empty())
        m_stack.pop();

    m_current = {0,0};
    m_step = 0;
    m_finished = false;
}

bool MazeGenerator::step()
{
    if (m_finished)
        return false;

    // Example placeholder logic

    m_visited.set(m_current.x, m_current.y, true);

    m_step++;

    // TODO: actual algorithm
    //placeholder
    m_maze.get(m_current.x, m_current.y).connections = 0b1111; // All walls open

    if (m_step > 100)
        m_finished = true;

    return !m_finished;
}

bool MazeGenerator::finished() const
{
    return m_finished;
}

int MazeGenerator::stepCount() const
{
    return m_step;
}

const BoolOverlay& MazeGenerator::visited() const
{
    return m_visited;
}

const BoolOverlay& MazeGenerator::frontier() const
{
    return m_frontier;
}

Position MazeGenerator::current() const
{
    return m_current;
}
