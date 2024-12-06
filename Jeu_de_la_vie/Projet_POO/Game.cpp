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

void Game::runGraphical() {
    int cellSize = 10; // Défini avant son utilisation
    int rows = grid.getGrid().size(); // Nombre de lignes de la grille
    int cols = rows > 0 ? grid.getGrid()[0].size() : 0; // Nombre de colonnes, si la grille n'est pas vide
    
    std::ofstream saveFile("output_graphical.txt");

    // Créer la fenêtre SFML avec les dimensions adaptées
    sf::RenderWindow window(sf::VideoMode(cols * cellSize, rows * cellSize), "Jeu de la Vie");

    int currentIteration = 0;
    int delay = 100;

    while (window.isOpen() && currentIteration < iterations) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Gestion des entrées clavier pour ajuster la vitesse
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Up) {
                    delay = std::max(10, delay - 10); // Augmente la vitesse (diminue le délai)
                } else if (event.key.code == sf::Keyboard::Down) {
                    delay += 10; // Diminue la vitesse (augmente le délai)
                }
            }
        }
window.clear(sf::Color::White);

        // Dessiner les cellules
        const auto& currentGrid = grid.getGrid();
        for (size_t i = 0; i < currentGrid.size(); ++i) {
            for (size_t j = 0; j < currentGrid[i].size(); ++j) {
                if (currentGrid[i][j] == 1) {
                    sf::RectangleShape cell(sf::Vector2f(cellSize, cellSize));
                    cell.setPosition(j * cellSize, i * cellSize);
                    cell.setFillColor(sf::Color::Magenta);
                    window.draw(cell);
                }
            }
        }

        // Dessiner les lignes de la grille
        sf::VertexArray lines(sf::Lines);
        for (int i = 0; i <= rows; ++i) {
            // Ligne horizontale
            lines.append(sf::Vertex(sf::Vector2f(0, i * cellSize), sf::Color::Black));
            lines.append(sf::Vertex(sf::Vector2f(cols * cellSize, i * cellSize), sf::Color::Black));
        }
        for (int j = 0; j <= cols; ++j) {
            // Ligne verticale
            lines.append(sf::Vertex(sf::Vector2f(j * cellSize, 0), sf::Color::Black));
            lines.append(sf::Vertex(sf::Vector2f(j * cellSize, rows * cellSize), sf::Color::Black));
        }
        window.draw(lines);

        // Mettre à jour la fenêtre
        window.display();
        grid.update();
        sf::sleep(sf::milliseconds(delay));
        currentIteration++;

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