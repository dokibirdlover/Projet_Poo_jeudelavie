#ifndef GRILLE_H
#define GRILLE_H

#include "Cellule.h"
#include <vector>
#include <SFML/Graphics.hpp>

class Grille {
public:
    Grille(int largeur, int hauteur);
    void initialiser();
    void mettreAJour();
    void afficher(sf::RenderWindow &fenetre) const;

private:
    int largeur;
    int hauteur;
    std::vector<std::vector<Cellule>> cellules;
    int compterVoisinsVivants(int x, int y) const;
};

#endif // GRILLE_H
