#include "GameFile.h"
#include <fstream>
#include <sstream>
#include <stdexcept>

std::vector<std::vector<int>> GameFile::readInitialState(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Impossible d'ouvrir le fichier : " + filename);
    }

    std::vector<std::vector<int>> grid;
    std::string line;
    while (std::getline(file, line)) {
        std::vector<int> row;
        std::istringstream stream(line);
        int value;
        while (stream >> value) {
            row.push_back(value);
        }
        grid.push_back(row);
    }

    return grid;
}
