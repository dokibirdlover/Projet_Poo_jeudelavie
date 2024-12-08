#ifndef GAME_H
#define GAME_H

#include "Grid.h"
#include <string>
#include <SFML/Graphics.hpp>

class Game {
private:
    Grid grid;
    int iterations;

public:
    Game(const Grid& grid, int iterations);
    Game(const std::string& filename, int iterations);
    void runConsole();
    void runGraphical();
};

#endif // GAME_H
