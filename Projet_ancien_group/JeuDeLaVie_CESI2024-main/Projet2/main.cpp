#include "JeuDeLaVie/JeuDeLaVie.h"
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <file_path> <mode (console/graphique)> [iterations]" << std::endl;
        return 1;
    }

    std::string filePath = argv[1];
    std::string mode = argv[2];
    int maxIterations = (argc == 4) ? std::stoi(argv[3]) : 100;

    try {
        JeuDeLaVie jeu(filePath, maxIterations);

        if (mode == "console") {
            jeu.executerModeConsole();
        } else if (mode == "graphique") {
            jeu.executerModeGraphique();
        } else {
            std::cerr << "Mode inconnu. Utilisez 'console' ou 'graphique'." << std::endl;
            return 1;
        }
    } catch (const std::exception& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
