#pragma once

#include <vector>
#include "debug/MazeSnapshot.hpp"

class MazeHistory
{
public:
    void add(const MazeSnapshot& snapshot);

    const MazeSnapshot& get(size_t step) const;

    size_t size() const;

private:
    std::vector<MazeSnapshot> snapshots;
};