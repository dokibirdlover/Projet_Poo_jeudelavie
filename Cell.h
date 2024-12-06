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

    // Ajout de l'opérateur == pour comparer une cellule avec un entier (1 ou 0)
    bool operator==(int value) const;
};

#endif
