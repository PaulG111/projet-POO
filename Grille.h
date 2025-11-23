#ifndef PROJET_POO_GRILLE_H
#define PROJET_POO_GRILLE_H

#include "Cellule.h"
#include <vector>


class Grille {
    private:
    int largeur;
    int hauteur;
    std::vector<std::vector<Cellule>> cellules;

    public:
};


#endif //PROJET_POO_GRILLE_H


#include "Cellule.h"
#include <vector>

class Grille {
private:
    int largeur;
    int longueur; 
    std::vector<std::vector<Cellule>> cellules;
public:
    Grille(int largeur, int longueur);
    int getLargeur();
    int getLongueur(); 
    Cellule& getCellule(int x, int y);
    int compterVoisinVivants(int x, int y);

};
