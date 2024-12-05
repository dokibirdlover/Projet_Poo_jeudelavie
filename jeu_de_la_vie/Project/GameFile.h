#ifndef GAMEFILE_H
#define GAMEFILE_H

#include <vector>
#include <string>

class GameFile {
public:
    static std::vector<std::vector<int>> readInitialState(const std::string& filename);
};

#endif // GAMEFILE_H
