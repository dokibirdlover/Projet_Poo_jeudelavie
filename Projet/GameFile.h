#ifndef GAMEFILE_H
#define GAMEFILE_H
#include "Grid.h"
#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>

using namespace std;

class GameFile {
public:
    static Grid readFile (const string& filePath){};
    static void writeFile (const Grid& grid, const string& outputPath){};
    
}
#endif // GAMEFILE_H