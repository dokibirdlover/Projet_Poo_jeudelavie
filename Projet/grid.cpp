#include <iostream> 
#include <vector>
#include <cell.H>

class Grid {
private : 
    int rows ;                              //Nbrs lignes
    int cols ;                              //Nbrs colones
    bool hasNeighbors ;                     //Grille torique bool
    std::vector<std::vector<int>> cells;    // matrice qui représente les cellules

public :
    //constructeur
    Grid (int rows, int cols, bool hasNeighbors = false) 
    : rows(rows), cols(cols), hasNeighbors(hasNeighbors),cells(rows, std::vector<int>(cols, 0)) {}



    //Méthode pour initialiser les dimension de la grile
    void initGrid(const std::vector<std::vector<int>>& initialState) {
        if (initialState.size() == rows && initialState[0].size() == cols) {
            cells = initialState;
        } else {
            std::cerr << "Erreur : Dimensions de l'état initial incorrectes.\n";
        }
    }



    //Mise a jour de la grille initiale en fonction du jeu 
    void updateGrid(){
        std::vector<std::vector<int>> nextState = cells; 

          for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                int aliveNeighbors = countAliveNeighbors(row, col);

                // Application des règles du jeu
                if (cells[row][col] == 1) { // Cellule vivante
                    nextState[row][col] = (aliveNeighbors == 2 || aliveNeighbors == 3) ? 1 : 0;
                } else { // Cellule morte
                    nextState[row][col] = (aliveNeighbors == 3) ? 1 : 0;
                }
            }
        }

        cells = nextState; // Mise à jour de l'état de la grille
    }



    // Compte le nombre de voisins vivants pour une cellule
    int countAliveNeighbors(int row, int col) {
        int count = 0;

        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                if (i == 0 && j == 0) continue; // Ignore la cellule elle-même

                int neighborRow = row + i;
                int neighborCol = col + j;

                // Gestion de la grille torique
                if (hasNeighbors) {
                    neighborRow = (neighborRow + rows) % rows;
                    neighborCol = (neighborCol + cols) % cols;
                }

                // Vérification des limites pour les grilles non toriques
                if (neighborRow >= 0 && neighborRow < rows && neighborCol >= 0 && neighborCol < cols) {
                    count += cells[neighborRow][neighborCol];
                }
            }
        }

        return count;
    }

};