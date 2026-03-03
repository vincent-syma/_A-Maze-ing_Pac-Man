#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <iostream>
#include <vector>
#include "Map.hpp"

const int TILE_SIZE = 32;
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 800;

// =========================
// Draw map with colored rectangles
// =========================
void draw_map1(SDL_Renderer* renderer, const Map& map)
{
    for (int y = 0; y < map.get_height(); ++y)
    {
        for (int x = 0; x < map.get_width(); ++x)
        {
            SDL_FRect rect;
            rect.x = x * TILE_SIZE;
            rect.y = y * TILE_SIZE;
            rect.w = TILE_SIZE;
            rect.h = TILE_SIZE;

            if (map.get_cell(x, y).status == CellType::WALL)
            {
                SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
                SDL_RenderFillRect(renderer, &rect);
            }
            else if (map.get_cell(x, y).status == CellType::PATH)
            {
                SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
                SDL_RenderFillRect(renderer, &rect);
            }
        }
    }
}

// =========================
// Load texture helper
// =========================
SDL_Texture* load_texture(SDL_Renderer* renderer, const char* path)
{
    SDL_Texture* texture = IMG_LoadTexture(renderer, path);
    if (!texture)
        std::cerr << "Failed to load texture '" << path << "': " << SDL_GetError() << "\n";
    return texture;
}

// =========================
// Split tilesheet into individual tile textures
// =========================
std::vector<SDL_Texture*> split_tiles(SDL_Renderer* renderer, SDL_Texture* tilesheet, int tile_count)
{
    std::vector<SDL_Texture*> tiles;
    SDL_Texture* tile_texture;
    SDL_FRect srcRect = {0, 0, TILE_SIZE, TILE_SIZE};

    for (int i = 0; i < tile_count; ++i)
    {
        tile_texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888,
                                         SDL_TEXTUREACCESS_TARGET, TILE_SIZE, TILE_SIZE);
        if (!tile_texture)
        {
            std::cerr << "SDL_CreateTexture Error: " << SDL_GetError() << "\n";
            continue;
        }

        SDL_SetRenderTarget(renderer, tile_texture);
        srcRect.x = i * TILE_SIZE;
        SDL_RenderTexture(renderer, tilesheet, &srcRect, nullptr);
        tiles.push_back(tile_texture);
    }

    SDL_SetRenderTarget(renderer, nullptr);
    return tiles;
}

// =========================
// Draw map with tilesheet
// =========================
void draw_map2(SDL_Renderer* renderer, const Map& map)
{
    static std::vector<SDL_Texture*> tiles;
    static bool initialized = false;

    if (!initialized)
    {
        SDL_Texture* tilesheet = load_texture(renderer, "assets/simple.png");
        if (!tilesheet) return;

        tiles = split_tiles(renderer, tilesheet, 2); // 0=WALL, 1=PATH
        SDL_DestroyTexture(tilesheet);
        initialized = true;
    }

    SDL_FRect dstRect = {0, 0, TILE_SIZE, TILE_SIZE};

    for (int y = 0; y < map.get_height(); ++y)
    {
        for (int x = 0; x < map.get_width(); ++x)
        {
            dstRect.x = x * TILE_SIZE;
            dstRect.y = y * TILE_SIZE;

            SDL_Texture* tex = (map.get_cell(x, y).status == CellType::WALL) ? tiles[0] : tiles[1];
            SDL_RenderTexture(renderer, tex, nullptr, &dstRect);
        }
    }
}

// =========================
// Main graphics function
// =========================
void graphics_map(Map& map)
{
    if (SDL_Init(SDL_INIT_VIDEO) == 0)
    {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << "\n";
        return;
    }

    SDL_Window* window = SDL_CreateWindow(
        "Maze Map Window",
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        0
    );

    if (!window)
    {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << "\n";
        SDL_Quit();
        return;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, nullptr);
    if (!renderer)
    {
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << "\n";
        SDL_DestroyWindow(window);
        SDL_Quit();
        return;
    }

    bool running = true;
    while (running)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_EVENT_QUIT ||
                (event.type == SDL_EVENT_KEY_DOWN && event.key.key == SDLK_ESCAPE))
            {
                running = false;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        draw_map1(renderer, map);
        draw_map2(renderer, map);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}