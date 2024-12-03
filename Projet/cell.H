#ifndef CELL_H
#define CELL_H

class Cell {
private:
    bool isAlive;     
    bool isObstacle;  

public:
    //constructeur
    Cell(bool alive = false, bool obstacle = false)
        : isAlive(alive), isObstacle(obstacle) {}

    // Getters
    bool getState() const { return isAlive; }
    bool getObstacle() const { return isObstacle; }

    // Setters
    void setState(bool state) { isAlive = state; }
    void setObstacle(bool obstacle) { isObstacle = obstacle; }

    // Méthode pour actualiser l'état d'une cellule
    void updateState(bool newState) { isAlive = newState; }
};

#endif
