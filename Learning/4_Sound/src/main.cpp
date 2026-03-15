#include "engine/Engine.hpp"
#include "games/pacman/PacmanGame.hpp"
#include <memory>

int main()
{
    Engine engine;

    engine.setGame(std::make_unique<PacmanGame>());
    engine.run();
}
