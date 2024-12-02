#include "Grille.h"
#include <iostream>
#include <cstdlib>
#include <sstream>

Grille::Grille(int largeur, int hauteur) : largeur(largeur), hauteur(hauteur), cellules(largeur, std::vector<Cellule>(hauteur)) {}

void Grille::chargerDepuisFichier(const std::string& filePath) {
    std::ifstream inFile(filePath);
    if (!inFile)
        throw std::runtime_error("Impossible de lire le fichier : " + filePath);

    inFile >> largeur >> hauteur;
    cellules = std::vector<std::vector<Cellule>>(largeur, std::vector<Cellule>(hauteur));

    for (int y = 0; y < hauteur; ++y) {
        for (int x = 0; x < largeur; ++x) {
            int etat;
            inFile >> etat;
            cellules[x][y].setVivante(etat == 1);
        }
    }
}

void Grille::sauvegarderDansFichier(std::ostream& out) const {
    out << largeur << " " << hauteur << "\n";
    for (int y = 0; y < hauteur; ++y) {
        for (int x = 0; x < largeur; ++x) {
            out << (cellules[x][y].estVivante() ? "1" : "0") << " ";
        }
        out << "\n";
    }
}

void Grille::afficherConsole() const {
    for (int y = 0; y < hauteur; ++y) {
        for (int x = 0; x < largeur; ++x) {
            std::cout << (cellules[x][y].estVivante() ? "1" : "0") << " ";
        }
        std::cout << "\n";
    }
}

bool Grille::mettreAJour() {
    std::vector<std::vector<Cellule>> nouvelleGrille = cellules;
    bool aChange = false;

    for (int x = 0; x < largeur; ++x) {
        for (int y = 0; y < hauteur; ++y) {
            int voisinsVivants = compterVoisinsVivants(x, y);
            bool etatActuel = cellules[x][y].estVivante();
            bool nouvelEtat = etatActuel;

            if (etatActuel) {
                nouvelEtat = (voisinsVivants == 2 || voisinsVivants == 3);
            } else {
                nouvelEtat = (voisinsVivants == 3);
            }

            nouvelleGrille[x][y].setVivante(nouvelEtat);

            // Vérifie si l'état de la cellule a changé
            if (etatActuel != nouvelEtat) {
                aChange = true;
            }
        }
    }

    cellules = nouvelleGrille;
    return aChange;
}

int Grille::compterVoisinsVivants(int x, int y) const {
    int compte = 0;
    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            if (dx == 0 && dy == 0) continue; // Ignore la cellule elle-même
            int nx = (x + dx + largeur) % largeur; // Gestion des bords (grille torique)
            int ny = (y + dy + hauteur) % hauteur;
            if (cellules[nx][ny].estVivante()) {
                ++compte;
            }
        }
    }
    return compte;
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
