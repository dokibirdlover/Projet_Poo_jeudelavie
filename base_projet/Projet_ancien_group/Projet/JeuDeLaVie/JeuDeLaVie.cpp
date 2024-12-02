#include "JeuDeLaVie.h"
#include <thread> // Pour les pauses entre itérations

JeuDeLaVie::JeuDeLaVie(int largeur, int hauteur)
    : grille(largeur, hauteur), fenetre(sf::VideoMode(largeur * 10, hauteur * 10), "Jeu de la Vie") {}

void JeuDeLaVie::initialiserGrille() {
    grille.initialiser(); // Méthode de la classe Grille
}

void JeuDeLaVie::executer() {
    while (fenetre.isOpen()) {
        sf::Event event;
        while (fenetre.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                fenetre.close();
        }

        grille.mettreAJour(); // Met à jour l'état de la grille
        afficherGrille();
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Pause de 100ms
    }
}

void JeuDeLaVie::afficherGrille() {
    fenetre.clear();
    grille.afficher(fenetre); // La méthode `afficher` utilise SFML pour dessiner
    fenetre.display();
}
