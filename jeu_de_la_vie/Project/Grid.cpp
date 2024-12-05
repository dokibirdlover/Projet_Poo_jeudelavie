#include "Grid.h"

// Constructeur par défaut
Grid::Grid() : rows(0), cols(0), grid({}) {}

// Constructeur avec dimensions et grille initiale
Grid::Grid(int rows, int cols, const std::vector<std::vector<int>>& initialGrid)
    : rows(rows), cols(cols), grid(initialGrid) {}

// Affiche la grille dans la console
void Grid::display() const {
    for (const auto& row : grid) {
        for (const auto& cell : row) {
            std::cout << (cell ? '#' : '.') << ' '; // '#' pour vivant, '.' pour mort
        }
        std::cout << std::endl;
    }
}

// Met à jour la grille selon les règles de Conway
void Grid::update() {
    std::vector<std::vector<int>> newGrid = grid;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int liveNeighbors = 0;

            // Parcours des voisins
            for (int di = -1; di <= 1; ++di) {
                for (int dj = -1; dj <= 1; ++dj) {
                    if (di == 0 && dj == 0) continue; // Ignore la cellule actuelle
                    int ni = i + di, nj = j + dj;
                    if (ni >= 0 && ni < rows && nj >= 0 && nj < cols) {
                        liveNeighbors += grid[ni][nj];
                    }
                }
            }

            // Règles de Conway
            if (grid[i][j] == 1) {
                newGrid[i][j] = (liveNeighbors == 2 || liveNeighbors == 3) ? 1 : 0;
            } else {
                newGrid[i][j] = (liveNeighbors == 3) ? 1 : 0;
            }
        }
    }

    grid = newGrid;
}

// Récupère la grille actuelle
const std::vector<std::vector<int>>& Grid::getGrid() const {
    return grid;
}
