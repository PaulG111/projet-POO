#include "Grille.h"
#include "EtatCellule.h"
#include "EtatMort.h"

#include <memory>
#include <vector>
#include <string>

using namespace std;


Grille::Grille(int largeur, int hauteur):
largeur(largeur), hauteur(hauteur)
{
    cellules.resize(hauteur);
    for (int y = 0; y < hauteur; y++) {
        // Éviter la nécessité d'un constructeur par défaut de Cellule
        cellules[y].reserve(largeur);
        for (int x = 0; x < largeur; x++) {
            // Initialiser chaque cellule avec un état valide (morte par défaut)
            cellules[y].emplace_back(x, y, new EtatMort());
        }
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

Cellule& Grille::getCelluleMutable(int x, int y) {
    return cellules[y][x];
}

void Grille::initCellule(int x, int y, EtatCellule * etat) {
    // Éviter la copie/assignation de Cellule (non copiable à cause de unique_ptr)
    cellules[y][x].preparerProchainEtat(etat);
    cellules[y][x].validerEtat();
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

void Grille::actualiserToutesCellules() {

}