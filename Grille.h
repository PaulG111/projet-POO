#ifndef PROJET_POO_GRILLE_H
#define PROJET_POO_GRILLE_H


#include "IRegleJeu.h"
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
    Cellule& getCelluleMutable(int x, int y);

    void initCellule(int x, int y, EtatCellule * etat);
    int compterVoisinsVivants(int x, int y);
    void actualiserToutesCellules(const IRegleJeu& regle); // applique la règle du jeu fournie sur toute la grille
};

#endif //PROJET_POO_GRILLE_H

