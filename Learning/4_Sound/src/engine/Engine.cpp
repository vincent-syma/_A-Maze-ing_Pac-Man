#include "Engine.hpp"
#include "utils/getTime.hpp"
#include <thread>
#include <chrono>

const std::uint64_t FPS = 1;
const std::uint64_t FRAME_DURATION = 1000 / FPS;

void Engine::setGame(std::unique_ptr<Game> game)
{
    currentGame = std::move(game);
}

void Engine::run()
{
    currentGame->init();

    while (true) {
        std::uint64_t currentTime = getTimeInMilliseconds();
        currentGame->update();
        currentGame->render();

        std::uint64_t elapsedTime = getTimeInMilliseconds() - currentTime;
        if (elapsedTime >= FRAME_DURATION) {
            continue;
        }
        std::uint64_t timeToSleep = FRAME_DURATION - elapsedTime;
        std::this_thread::sleep_for(std::chrono::milliseconds(timeToSleep));
    }
}
