#ifndef CELLULE_H
#define CELLULE_H

class Cellule {
public:
    Cellule() : vivante(false) {}
    bool estVivante() const { return vivante; }
    void setVivante(bool etat) { vivante = etat; }

private:
    bool vivante;
};

#endif // CELLULE_H
