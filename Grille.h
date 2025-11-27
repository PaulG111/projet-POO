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
    Grille(int largeur, int hauteur);

    int getLargeur();
    int getHauteur();

    Cellule& getCellule(int x, int y);
    Cellule& getCelluleMutable(int x, int y); // changer le nom aussi

    void initCellule(int x, int y, EtatCellule * etat);
    int compterVoisinsVivants(int x, int y);
    void actualiserToutesCellules(); //attends les regles du jeu
};

#endif //PROJET_POO_GRILLE_H

