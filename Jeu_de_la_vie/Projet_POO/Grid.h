#ifndef GRID_H
#define GRID_H

#include "Cell.h"
#include <vector>
#include <iostream>
#include <cstdlib>

using namespace std;

class Grid {
protected:
    int rows;
    int cols;
    std::vector<std::vector<Cell>> grid;

public:
    Grid(); // Constructeur par défaut
    Grid(int rows, int cols, const std::vector<std::vector<int>>& initialGrid);

    void display() const; // Affiche la grille
    void update();        // Met à jour la grille selon les règles de Conway
    const std::vector<std::vector<Cell>>& getGrid() const; // Récupère la grille
    void saveGrid(const string& nomFichier);

    // Pour sauvegarde dans le ficheir créer
    int getHeight() const { return rows; }
    int getWidth() const { return cols; }
    const std::vector<std::vector<Cell>>& getCells() const { return grid; }

    // Initialisation de cellules aléatoires
    void RandomCell();
};

#endif // GRID_H
