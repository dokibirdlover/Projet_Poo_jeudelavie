#ifndef GAME_H
#define GAME_H

#include "Grid.h"
#include "GameFile.h"
#include <string>

class Game {
private:
    Grid grid;
    int iterations;

public:
    Game(const std::string& filename, int iterations);
    void runConsole();
    void runGraphical();
};

#endif // GAME_H
