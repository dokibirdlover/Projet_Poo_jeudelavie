#include "Game.h"
#include <iostream>

int main() {
    std::string filename;
    int iterations, alea, choice;

    Grid grid;

    std::cout << "Entrez le chemin d'un pattern ou continuer en mode aléatoire (1: Patern, 2: Aléatoire) : ";
    std::cin >> alea;

    if (alea == 1) {
        std::cout << "Entrez le chemin du fichier d'état initial : ";
        std::cin >> filename;
    } else if (alea == 2) {
        int rows, cols;
        std::cout << "Entrez le nombre de lignes : ";
        std::cin >> rows;
        std::cout << "Entrez le nombre de colonnes : ";
        std::cin >> cols;
        grid = Grid(rows, cols, std::vector<std::vector<int>>(rows, std::vector<int>(cols, 0)));
        grid.RandomCell();
    } else {
        std::cout << "Choix invalide.\n";
        return 1;
    }

    std::cout << "Nombre d'itérations : ";
    std::cin >> iterations;

    std::cout << "Mode de fonctionnement (1: Console, 2: Graphique) : ";
    std::cin >> choice;

    Game game = (alea == 1) ? Game(filename, iterations) : Game(grid, iterations); // Utilisation du bon constructeur

    if (choice == 1) {
        game.runConsole();
    } else if (choice == 2) {
        game.runGraphical();
    } else {
        std::cout << "Choix invalide.\n";
    }

    return 0;
}
