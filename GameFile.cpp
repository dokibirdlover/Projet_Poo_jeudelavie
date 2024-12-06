#include "GameFile.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream>

std::vector<std::vector<int>> GameFile::readInitialState(const std::string& filename) {
    std::ifstream file(filename, std::ios::in | std::ios::ate);  // Ouverture en mode "fin de fichier"
    if (!file.is_open()) {
        throw std::runtime_error("Impossible d'ouvrir le fichier : " + filename);
    }

    // Lire tout le contenu du fichier d'un coup
    std::streampos size = file.tellg();
    file.seekg(0, std::ios::beg);

    std::string content(size, '\0');
    file.read(&content[0], size);
    file.close();

    // Transformation du contenu en une grille
    std::vector<std::vector<int>> grid;
    std::vector<int> row;

    for (char c : content) {
        if (c == '0' || c == '1') {
            row.push_back(c - '0');  // Conversion char -> int
        } else if (c == '\n' || c == '\r') {
            if (!row.empty()) {
                grid.push_back(row);
                row.clear();
            }
        } else if (!isspace(c)) {
            throw std::runtime_error("Caractère invalide trouvé dans le fichier : " + filename);
        }
    }

    // Ajouter la dernière ligne si elle n'a pas encore été ajoutée
    if (!row.empty()) {
        grid.push_back(row);
    }

    // Vérification des tailles de lignes
    size_t expectedSize = grid.empty() ? 0 : grid[0].size();
    for (const auto& r : grid) {
        if (r.size() != expectedSize) {
            throw std::runtime_error("Les lignes ont des tailles différentes dans le fichier : " + filename);
        }
    }

    return grid;
}
