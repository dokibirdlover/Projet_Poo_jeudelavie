#include "grid.cpp"
#include "GameFile.cpp"*
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;


class Game {
private:
    Grid grid;
    int maxIteration;
    int currentIteration;

public:
    Game (Grid grid, int maxIteration) : grid(grid), maxIteration(maxIteration), currentIteration(0) {}; 

    void runConsoleMode() {
        while (currentIteration < maxIteration){
            grid.updateGrid();
            string outputPath = "output_" + to_string(currentIteration) + ".txt";
            GameFile::writeFile(grid, outputPath);
            currentIteration++;
        }
    }

    void runGraphicsMode() {
        sf::RenderWindow window(sf::VideoMode(gridWidth * cellSize, gridHeight * cellSize), "Le Jeu de la Vie");
        initializeGrid();

        while (render.getWindow().isOpen()) {
            sf::Event event;
            while (render.getWindow().pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    render.getWindow().close();
                }
            }

            grid.updateGrid();
            render.renderGrid();
            sf::sleep(sf::milliseconds(500));
        }
    }

    bool isStable() {
        return false;
    }
};





int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <input_file>" << endl;
        return 1;
    }

    try {
        Grid grid = GameFile::readFile(argv[1]);
        Game game(grid, 100);

        cout << "Choisissez le mode de jeu : \n1 - Mode Console, 2 - Mode Graphique.\n" << endl;
        int choice;
        cin >> choice;

        if (choice == 1) {
            game.runConsoleMode();
        } else if (choice == 2) {
            game.runGraphicsMode();
        } else {
            cerr << "Erreur! Mauvaise entrer!" << endl;
        }
    } catch (const exception& e) {
        cerr << e.what() << endl;
        return 1;
    }

    return 0;
}
