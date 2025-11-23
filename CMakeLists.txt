cmake_minimum_required(VERSION 4.0)
project(projet_POO)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(projet_POO
        Cellule.cpp
        main.cpp
        EtatMort.cpp
        EtatVivant.cpp
        Grille.cpp
        EtatCellule.cpp
        Cellule.h)
