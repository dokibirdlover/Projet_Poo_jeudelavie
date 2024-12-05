#include "Game.h"
#include "Grid.h"
#include "GameFile.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Game::Game(const std::string& filename, int iterations)
    : iterations(iterations) {
    auto initialState = GameFile::readInitialState(filename);
    grid = Grid(initialState.size(), initialState[0].size(), initialState);
}

void Game::runConsole() {
    for (int i = 0; i < iterations; ++i) {
        grid.display();
        grid.update();
        std::cout << "-----------------\n";
    }
}

void Game::runGraphical() {
    sf::RenderWindow window(sf::VideoMode(800, 800), "Game of Life");
    int cellSize = 20;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();
        const auto& currentGrid = grid.getGrid();

        for (size_t i = 0; i < currentGrid.size(); ++i) {
            for (size_t j = 0; j < currentGrid[i].size(); ++j) {
                if (currentGrid[i][j] == 1) {
                    sf::RectangleShape cell(sf::Vector2f(cellSize, cellSize));
                    cell.setPosition(j * cellSize, i * cellSize);
                    cell.setFillColor(sf::Color::Green);
                    window.draw(cell);
                }
            }
        }

        window.display();
        grid.update();
        sf::sleep(sf::milliseconds(100));
    }
}
