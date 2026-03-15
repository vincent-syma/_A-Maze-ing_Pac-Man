#pragma once

#include <memory>
#include "Game.hpp"

class Engine
{
public:
    void setGame(std::unique_ptr<Game> game);
    void run();

private:
    std::unique_ptr<Game> currentGame;
};
