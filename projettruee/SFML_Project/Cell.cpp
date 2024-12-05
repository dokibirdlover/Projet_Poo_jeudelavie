#include "Cell.h"

Cell::Cell(bool state) : isAlive(state) {}

bool Cell::getState() const {
    return isAlive;
}

void Cell::setState(bool state) {
    isAlive = state;
}

void Cell::updateState(int aliveNeighbors) {
    if (isAlive) {
        isAlive = (aliveNeighbors == 2 || aliveNeighbors == 3);
    } else {
        isAlive = (aliveNeighbors == 3);
    }
}
