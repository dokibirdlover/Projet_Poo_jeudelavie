#ifndef CELL_H
#define CELL_H

class Cell {
private:
    bool isAlive;
public:
    Cell(bool state = false);
    bool getState() const;
    void setState(bool state);
    void updateState(int aliveNeighbors);
};

#endif
