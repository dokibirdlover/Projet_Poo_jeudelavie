#ifndef GRILLE_H
#define GRILLE_H

#include "Cellule.h"
#include <vector>
#include <fstream>
#include <SFML/Graphics.hpp>

class Grille {
public:
    Grille(int largeur, int hauteur);
    void chargerDepuisFichier(const std::string& filePath);
    void sauvegarderDansFichier(std::ostream& out) const;
    void initialiser();
    bool mettreAJour();
    void afficher(sf::RenderWindow &fenetre) const;
    void afficherConsole() const;

private:
    int largeur;
    int hauteur;
    std::vector<std::vector<Cellule>> cellules;
    int compterVoisinsVivants(int x, int y) const;
};

#endif // GRILLE_H
