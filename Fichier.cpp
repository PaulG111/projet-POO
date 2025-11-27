#include "Fichier.h"

#include <fstream>
#include <iostream>

Fichier::Fichier() {}

vector<vector<bool>> Fichier::lire(string chemin, int& largeur, int& hauteur) {
    ifstream fichier(chemin);

    if (!fichier) {
        cout << "Impossible de charger fichier : " + chemin << endl;
    }
    fichier >> largeur >> hauteur;

    vector<vector<bool>> matrice(largeur, vector<bool>(largeur, false));

    for (int y = 0; y < hauteur; y++) {
      for (int x=0; x<largeur; x++) {
          int val;
          fichier >> val;
          matrice[y][x]= (val==1);
      }
    }
    return matrice;
}