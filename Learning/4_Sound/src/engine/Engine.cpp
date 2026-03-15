#include "Engine.hpp"

void Engine::setGame(std::unique_ptr<Game> game)
{
    currentGame = std::move(game);
}

void Engine::run()
{
    currentGame->init();

    while (true)
    {
        currentGame->update();
        currentGame->render();
    }
}
