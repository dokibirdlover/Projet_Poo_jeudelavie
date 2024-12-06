#ifndef GAMEFILE_H
#define GAMEFILE_H

#include "Grid.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class GameFile {
public:
    Grid grid;

    static vector<vector<int>> readInitialState(const string& filename);

    void writeFile(const std::string& Fichier) {
        std::ofstream fichier(Fichier);
        if (fichier.is_open()) {
            fichier << grid.getHeight() << " " << grid.getWidth() << std::endl;
            const auto& cells = grid.getGrid();
            for (const auto& row : cells) {
                for (const auto& cell : row) {
                    fichier << (cell.getState() ? 1 : 0) << " ";
                }
                fichier << std::endl;
            }
            fichier.close();
        } else {
            cerr << "Impossible d'ouvrir le fichier : " << Fichier << endl;
        }
    }
};

#endif // GAMEFILE_H
