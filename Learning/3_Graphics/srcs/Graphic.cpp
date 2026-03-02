#include <SDL3/SDL.h>
#include <iostream>
#include "Map.hpp"

// const int TILE_SIZE = 32;
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

void    graphics_map(std::vector<Map>& map_history) {
    (void)map_history; // to avoid unused parameter warning for now
    if (SDL_Init(SDL_INIT_VIDEO) == 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return ;
    }

    // Create window (no SDL_WINDOW_SHOWN needed in SDL3)
    SDL_Window* window = SDL_CreateWindow(
        "Maze Map Window",
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        0 // no flags needed for basic window
    );

    if (!window) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return ;
    }

    // Create renderer (simpler flags in SDL3)
    SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);
    if (!renderer) {
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return ;
    }

    bool running = true;
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                running = false;
            }
            if (event.type == SDL_EVENT_KEY_DOWN) {
                if (event.key.key == SDLK_ESCAPE) { // SDL3 uses keycode
                    running = false;
                }
            }
        }

        // Clear screen to black
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Present the frame
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}