#ifndef JEUEDELAVIE_H
#define JEUEDELAVIE_H

#include "Grille.h"
#include <SFML/Graphics.hpp>
#include <string>

class JeuDeLaVie {
public:
    JeuDeLaVie(const std::string& filePath, int maxIterations);
    void executerModeConsole();
    void executerModeGraphique();

private:
    Grille grille;
    sf::RenderWindow fenetre;
    int maxIterations;

    void afficherGrille();
    void sauvegarderEtat(int iteration);
};

#endif // JEUEDELAVIE_H
