#include "Game.h"
#include <iostream>

int main() {
    std::string filename;
    int iterations, choice;

    std::cout << "Entrez le chemin du fichier d'état initial : ";
    std::cin >> filename;
    std::cout << "Nombre d'itérations (mode console) : ";
    std::cin >> iterations;
    std::cout << "Mode de fonctionnement (1: Console, 2: Graphique) : ";
    std::cin >> choice;

    Game game(filename, iterations);
    if (choice == 1) {
        game.runConsole();
    } else if (choice == 2) {
        game.runGraphical();
    } else {
        std::cout << "Choix invalide.\n";
    }

    return 0;
}
