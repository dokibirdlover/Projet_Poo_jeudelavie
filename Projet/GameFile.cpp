#ifndef GAMEFILE_H
#define GAMEFILE_H
#include "grid.cpp"
#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>

using namespace std;


class GameFile {
public:
    static Grid readFile (const string& filePath){};
    static void writeFile (const Grid& grid, const string& outputPath){};
};

#endif



Grid GameFile::readFile(const string& filePath){
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

void GameFile::writeFile(const Grid& grid, const string& outputPath) {
    std::ofstream file(outputPath);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file: " + outputPath);
    }
    
    const auto& cells = grid.getCell();
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