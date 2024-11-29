#include "JeuDeLaVie/JeuDeLaVie.h"

int main() {
    JeuDeLaVie jeu(100, 100); // Exemple de grille 80x80
    jeu.initialiserGrille();
    jeu.executer();
    return 0;
}
