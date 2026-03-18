#include "PacmanGame.hpp"
#include "map/MapEditor.hpp"
#include <iostream>

void PacmanGame::init() {
    std::cout << "initializing" << std::endl;
    MapEditor editor(map);
    editor.buildFromPath("assets/maps/map.txt");
    //debug print the map
    
}

void PacmanGame::update() {
    std::cout << "updating" << std::endl;
}

void PacmanGame::render() {
    std::cout << "rendering" << std::endl;
}
