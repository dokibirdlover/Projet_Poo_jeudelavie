#ifndef JEUEDELAVIE_H
#define JEUEDELAVIE_H

#include "Grille.h"
#include <SFML/Graphics.hpp>

class JeuDeLaVie {
public:
    JeuDeLaVie(int largeur, int hauteur);
    void initialiserGrille();
    void executer();

private:
    Grille grille;
    sf::RenderWindow fenetre;
    void afficherGrille();
};

#endif // JEUEDELAVIE_H
