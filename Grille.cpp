#include "Grille.h"

#include <memory>
#include <vector>
#include <string>

#include "EtatCellule.h"

using namespace std;

Grille::Grille(int largeur, int hauteur):
largeur(largeur), hauteur(hauteur)
{
    cellules.resize(hauteur);
    for (int y = 0; y < hauteur; y++) {
        cellules[y].resize(largeur);
        for (int x = 0; x < largeur; x++) {
            cellules[y][x] = Cellule(x, y, false);
        };
    }
}

int Grille::getLargeur() {
    return largeur;
}

int Grille::getHauteur() {
    return hauteur;
}

Cellule& Grille::getCellule(int x, int y) {
    return cellules[y][x];
}

void Grille::initCellule(int x, int y, EtatCellule * etat) {
    Cellule c(x,y, etat);
    cellules [y][x] = c;
}

int Grille::compterVoisinsVivants(int x, int y) {
    int compteur = 0;
    for (int dy = -1; dy <= 1; dy++) {
        for (int dx = -1; dx <= 1; dx++) {
            if (dx == 0 && dy == 0){ //savoir si c'est sur la cellule elle meme
                continue;
            }
            int voisinX = x + dx;
            int voisinY = y + dy;
            if (voisinX < 0 || voisinX >= largeur){ //pour les cellules au extremite
                continue;
            }
            if (voisinY < 0 || voisinY >= hauteur){
                continue;
            }
            if (cellules[voisinY][voisinX].estVivante()) {
                compteur++;
            }
        }
    }
    return compteur;
}