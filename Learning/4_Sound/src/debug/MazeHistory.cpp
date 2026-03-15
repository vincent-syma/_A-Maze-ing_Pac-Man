#include "debug/MazeHistory.hpp"

void MazeHistory::add(const MazeSnapshot& snapshot)
{
    snapshots.push_back(snapshot);
}

const MazeSnapshot& MazeHistory::get(size_t step) const
{
    return snapshots.at(step);
}

size_t MazeHistory::size() const
{
    return snapshots.size();
}
