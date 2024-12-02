#include "Grid.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;



class Game : public Grid{
private:
    grid: Grid;
    int maxIteration;
    int currentIteration;

public:
    Game() : (){}
    Game (grid Grid, int maxIteration) : Grid(rows, cols) {}; 


    void runConsoleMode() {
        return 1;
    }

    void  runGraphiquesMode() {
        return 0;
    }

    bool isStable() {
        return 1;
    }
};





int main(){
    char current_parti_file;

    cout << "Bienvenu dans le Jeu de la Vie!";
    cout << "Entrez un chemin d'enregistrement pour votre partie!";
    cin >> current_parti_file;

    cout << "Parfait!\nMaintenant, entrez le nombre de colonne : \n";
    cin >> 

    int mode_choice;

    cout << "Pour le Mode Console tapez 1, pour le Mode Graphique tapez 2 :\n";
    cin >> mode_choice;

    if (mode_choice == 1){
        cout << "Mode Console\n";
        runConsoleMode();
    }
    if (mode_choice == 2){
        cout << "Mode Graphique\n"
        runGraphiquesMode();
    } else {
        cout << "Erreur";
        break;
    }
}

