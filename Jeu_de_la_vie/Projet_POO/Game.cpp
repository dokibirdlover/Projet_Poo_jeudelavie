#include "Game.h"
#include "GameFile.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Game::Game(const Grid& grid, int iterations) : grid(grid), iterations(iterations) {}


Game::Game(const std::string& filename, int iterations)
    : iterations(iterations) {
    auto initialState = GameFile::readInitialState(filename);
    grid = Grid(initialState.size(), initialState[0].size(), initialState);
}

void Game::runConsole() {
    std::string filename;

    std::ofstream saveFile("output_console.txt");
    for (int i = 0; i < iterations; ++i) {
        grid.display();
        grid.update();
        std::cout << "~~~~~~~~~~~~~~~~~~\n";

        // Sauvegarde de l'état actuel de la grille dans le fichier
        if (saveFile.is_open()) {
            saveFile << "Iteration " << i + 1 << ":\n";
            const auto& currentGrid = grid.getGrid();
            for (const auto& row : currentGrid) {
                for (const auto& cell : row) {
                    saveFile << (cell.getState() ? '#' : '.') << ' ';
                }
                saveFile << '\n';
            }
            saveFile << "~~~~~~~~~~~~~~~~~~\n";
        }
    }
    saveFile.close();
}

     // Mettre à jour la fenêtre
        window.display();
        grid.update(); 
        sf::sleep(sf::milliseconds(delay));
        currentIteration++;

        // Sauvegarde de l'état dans le fichier
        if (saveFile.is_open()) {
            saveFile << "Iteration " << currentIteration << ":\n";
            const auto& currentGrid = grid.getGrid();
            for (const auto& row : currentGrid) {
                for (const auto& cell : row) {
                    saveFile << (cell.getState() ? '#' : '.') << ' ';
                }
                saveFile << '\n';
            }
            saveFile << "~~~~~~~~~~~~~~~~~~\n";
        }
    }
    saveFile.close();
}