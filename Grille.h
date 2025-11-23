#ifndef PROJET_POO_GRILLE_H
#define PROJET_POO_GRILLE_H

#include "EtatCellule.h"
#include "Cellule.h"

#include <vector>
/*
class Grille {
    private:
    int largeur;
    int hauteur;
    std::vector<std::vector<Cellule>> cellules;

    public:
    Grille(int largeur, int hauteur);

    int getLargeur();
    int getLongueur();

    Cellule& getCellule(int x, int y); // adresse vrmt necessaire ?
    Cellule& getCelluleMutable(int x, int y); // adresse vrmt necessaire ? / changer le nom aussi

    void initCellule(int x, int y, EtatCellule * etat);
    int compterVoisinsVivants(int x, int y);
    void actualiserToutesCellules();
};
*/

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
