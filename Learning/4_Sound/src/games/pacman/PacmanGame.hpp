#pragma once

#include "engine/Game.hpp"
#include "map/Map.hpp"
#include "maze/Maze.hpp"

class PacmanGame : public Game
{
public:
    void init() override;
    void update() override;
    void render() override;

private:
    Maze maze{21,21};
    Map map{43,43};
};
