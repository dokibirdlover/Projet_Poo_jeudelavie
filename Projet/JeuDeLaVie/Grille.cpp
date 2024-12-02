#include "Grille.h"
#include <cstdlib>

Grille::Grille(int largeur, int hauteur) : largeur(largeur), hauteur(hauteur), cellules(largeur, std::vector<Cellule>(hauteur)) {}

void Grille::initialiser() {
    for (int x = 0; x < largeur; ++x) {
        for (int y = 0; y < hauteur; ++y) {
            cellules[x][y].setVivante(rand() % 2); // Initialisation aléatoire
        }
    }
}

void Grille::mettreAJour() {
    std::vector<std::vector<Cellule>> nouvelleGrille = cellules;

    for (int x = 0; x < largeur; ++x) {
        for (int y = 0; y < hauteur; ++y) {
            int voisinsVivants = compterVoisinsVivants(x, y);
            if (cellules[x][y].estVivante()) {
                nouvelleGrille[x][y].setVivante(voisinsVivants == 2 || voisinsVivants == 3);
            } else {
                nouvelleGrille[x][y].setVivante(voisinsVivants == 3);
            }
        }
    }
    cellules = nouvelleGrille;
}

void Grille::afficher(sf::RenderWindow &fenetre) const {
    sf::RectangleShape cellule(sf::Vector2f(9.0f, 9.0f)); // Taille des cellules
    cellule.setFillColor(sf::Color::White);

    for (int x = 0; x < largeur; ++x) {
        for (int y = 0; y < hauteur; ++y) {
            if (cellules[x][y].estVivante()) {
                cellule.setPosition(x * 10, y * 10);
                fenetre.draw(cellule);
            }
        }
    }
}

int Grille::compterVoisinsVivants(int x, int y) const {
    int compte = 0;
    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            if (dx == 0 && dy == 0) continue;
            int nx = (x + dx + largeur) % largeur;
            int ny = (y + dy + hauteur) % hauteur;
            if (cellules[nx][ny].estVivante())
                ++compte;
        }
    }
    return compte;
}
