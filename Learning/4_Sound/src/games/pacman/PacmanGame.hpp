#pragma once

#include "games/Game.hpp"
#include "map/Map.hpp"
#include "maze/Maze.hpp"

class PacmanGame : public Game
{
public:
    void init() override;
    void update() override;
    void render() override;

private:
    Map map{0U, 0U};
};
