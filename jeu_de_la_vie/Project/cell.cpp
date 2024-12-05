#include "cell.h"

Cell::Cell() : isAlive(false), isObstacle(false) {}

void Cell::setState(bool state) { isAlive = state; }
bool Cell::getState() const { return isAlive; }

void Cell::setObstacle(bool obstacle) { isObstacle = obstacle; }
bool Cell::getObstacle() const { return isObstacle; }