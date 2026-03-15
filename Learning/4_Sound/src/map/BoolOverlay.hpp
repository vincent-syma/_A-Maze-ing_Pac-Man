#pragma once

#include <vector>
#include "core/Grid.hpp"

class BoolOverlay : public Grid
{
public:
    BoolOverlay(int w, int h);

    bool get(int x, int y) const;
    void set(int x, int y, bool value);

    void clear();

private:
    std::vector<bool> data;
};
