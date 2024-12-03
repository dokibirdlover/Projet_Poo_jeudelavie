#ifndef CELL_H
#define CELL_H

class Cell {
private:
    bool isAlive;
    bool isObstacle;

public:
    Cell();
    
    void setState(bool state);
    void setObstacle(bool obstacle);

    bool getObstacle() const;
    bool getState() const;
};

#endif
