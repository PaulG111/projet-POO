#include "Grille.h"
#include "EtatCellule.h"
#include "EtatMort.h"

#include <memory>
#include <vector>
#include <string>

using namespace std;


Grille::Grille(int largeur, int hauteur): largeur(largeur), hauteur(hauteur) {
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

int Grille::getLargeur() const {
    return largeur;
}

int Grille::getHauteur() const {
    return hauteur;
}

Cellule& Grille::getCellule(int x, int y) {
    return cellules[y][x];
}

const Cellule& Grille::getCellule(int x, int y) const {
    return cellules[y][x];
}

Cellule& Grille::getCelluleMutable(int x, int y) {
    return cellules[y][x];
}
bool Grille::estVide() {
    for (int y=0 ; y<hauteur ; y++) {
        for ( int x=0 ; x<largeur ; x++) {
            if (cellules [y][x].estVivante())
                return false;
        }
    }
    return true;
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

void Grille::actualiserToutesCellules(const IRegleJeu& regle) {
    // On parcourt toute la grille pour déterminer le futur état de chaque cellule
    // sans encore modifier l'état actuel.
    for (int y = 0; y < hauteur; ++y) {
        for (int x = 0; x < largeur; ++x) {
            // 1. Récupérer la cellule et son état actuel
            Cellule& celluleCourante = cellules[y][x];

            const EtatCellule& etatActuel = *celluleCourante.getEtatActuel();
            int nbVoisins = compterVoisinsVivants(x, y);

            EtatCellule* nouvelEtat = regle.calculerProchainEtat(etatActuel, nbVoisins);

            celluleCourante.preparerProchainEtat(nouvelEtat);
        }
    }

    // Maintenant que tout le monde a calculé son futur, on applique les changements.
    for (int y = 0; y < hauteur; ++y) {
        for (int x = 0; x < largeur; ++x) {
            cellules[y][x].validerEtat();
        }
    }
}
bool Grille::operator==(const Grille& autre) {
    if (largeur != autre.largeur ||  hauteur != autre.hauteur)
        return false;
    for (int y=0; y<hauteur ; y++)
        for (int x =0; x<largeur; x++)
            if (cellule(x,y).estVivante() != autre.cellule(x,y).estVivante())
                return false;
    return true;
}
