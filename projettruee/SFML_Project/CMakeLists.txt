cmake_minimum_required(VERSION 3.10)

# Nom du projet
project(SFML_Project)

# Activer C++17
set(CMAKE_CXX_STANDARD 17)

# Ajouter l'exécutable avec tous les fichiers sources nécessaires
add_executable(main
    main.cpp
    GameFile.cpp
    Game.cpp
    Cell.cpp
    Grid.cpp
    Renderer.cpp
)

# Trouver SFML
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# Lier SFML
target_link_libraries(main sfml-graphics sfml-window sfml-system)
