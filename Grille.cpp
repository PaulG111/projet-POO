#include "Grille.h"

Grille::Grille(int largeur, int longueur):
largeur(largeur), longueur(longueur)
{
    cellules.resize(longueur);
    for (int y = 0; y < longueur; y++) {
        cellules[y].resize(largeur);
        for (int x = 0; x < largeur; x++) {
            cellules[y][x] = Cellule(x, y, false);
        };
    }
}

int Grille::getLargeur() {
    return largeur;
}

int Grille::getLongueur() {
    return longueur;
}

Cellule& Grille::getCellule(int x, int y) {
    return cellules[y][x];
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
            if (voisinY < 0 || voisinY >= longueur){
                continue;
            }
            if (cellules[voisinY][voisinX].estVivante()) {
                compteur++;
            }
        }
    }
    return compteur;
}