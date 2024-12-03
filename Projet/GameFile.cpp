#include "GameFile.h"
#include <fstream>
#include <stdexcept>


Grid Game::readFile(const string& filePath){
    ifstream file (filePath);
    if (!file.is_open()){
        throw runtime_error("Impossible d'ouvrir le fichier\n");
    }

    int rows, cols;
    file >> rows >> cols;

    vector<vector<int>> initState(rows, vector<int>(cols));
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            file >> initState[i][j];
        }
    }

    Grid grid(rows, cols);
    grid.initGrid(initState);

    return grid;
}

void Game::writeFile(const Grid& grid, const std::string& outputPath) {
    std::ofstream file(outputPath);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file: " + outputPath);
    }
    
    const auto& cells = grid.getCells();
    int rows = cells.size();
    int cols = cells[0].size();

    file << rows << " " << cols << "\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            file << (cells[i][j].getObstacle() ? -1 : cells[i][j].getState()) << " ";
        }
        file << "\n";
    }
}