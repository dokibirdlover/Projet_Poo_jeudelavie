# Projet_Poo_jeudelavie
## Présentation
Le jeu de la vie désigne un automate cellulaire proposé par le mathématicien John Conway. Il décrit l’évolution d’une population de cellules sur un intervalle de temps discret. Les cellules, placées dans une grille rectangulaire bidimensionnelle, sont caractérisées par deux états : elles sont soit vivantes, soit mortes.

## Instructions pour le démarrage
Pour le bon fonctionnement du projet, il vous faut installer au préalable SFML (https://www.sfml-dev.org/index-fr.php).  
Installez l'extension sur votre PC, puis effectuez ces manipulations dans VS Code :

1. Ouvrez le fichier `c_cpp_properties.json` dans VS Code,
2. Ajoutez une virgule après "${workspaceFolder}/**" puis entrez, entre guillemets, le chemin vers votre dossier SFML,
3. Ouvrez un terminal WSL,
4. Entrez la commande `sudo apt update`,
5. Ensuite, installez SFML avec la commande suivante `sudo apt-get install libsfml-dev`,
6. Installez CMake avec la commande `sudo apt install cmake`,
7. Vérifiez que CMake est bien installé `cmake --version`,
8. Entrez la commande `make` dans le même terminal pour compiler,
9. Si aucune erreur n'apparaît, vous devriez pouvoir entrer `./main` pour lancer le programme.
