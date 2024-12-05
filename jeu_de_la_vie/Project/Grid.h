#ifndef GRID_H
#define GRID_H

#include <vector>
#include <iostream>

class Grid {
private:
    int rows;
    int cols;
    std::vector<std::vector<int>> grid;

public:
    Grid(); // Constructeur par défaut
    Grid(int rows, int cols, const std::vector<std::vector<int>>& initialGrid);

    void display() const; // Affiche la grille
    void update();        // Met à jour la grille selon les règles de Conway
    const std::vector<std::vector<int>>& getGrid() const; // Récupère la grille
};

#endif // GRID_H
