#include "JeuDeLaVie.h"
#include <iostream>
#include <fstream>
#include <filesystem>
#include <thread>

JeuDeLaVie::JeuDeLaVie(const std::string& filePath, int maxIterations)
    : grille(0, 0), fenetre(sf::VideoMode(800, 800), "Jeu de la Vie"), maxIterations(maxIterations) {
    grille.chargerDepuisFichier(filePath);
}

void JeuDeLaVie::sauvegarderEtat(int iteration) {
    std::string folderName = "output";
    std::filesystem::create_directory(folderName);

    std::ofstream outFile(folderName + "/iteration_" + std::to_string(iteration) + ".txt");
    grille.sauvegarderDansFichier(outFile);
}

void JeuDeLaVie::executerModeConsole() {
    for (int iteration = 0; iteration < maxIterations; ++iteration) {
        std::cout << "Itération " << iteration << ":" << std::endl;
        grille.afficherConsole();

        sauvegarderEtat(iteration);

        if (!grille.mettreAJour()) {
            std::cout << "Aucune évolution. Fin de la simulation." << std::endl;
            break;
        }
    }
}

void JeuDeLaVie::executerModeGraphique() {
    while (fenetre.isOpen()) {
        sf::Event event;
        while (fenetre.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                fenetre.close();
        }

        grille.mettreAJour();
        afficherGrille();
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Pause entre itérations
    }
}

void JeuDeLaVie::afficherGrille() {
    fenetre.clear();
    grille.afficher(fenetre);
    fenetre.display();
}
