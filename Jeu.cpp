#include "Jeu.h"
#include "Fichier.h"
#include "RegleConway.h"
#include "VueConsole.h"
#include "VueGraphique.h"
#include "EtatVivant.h"
#include "EtatMort.h"

using namespace std;

Jeu::Jeu(string fichierConfig, bool modeGraphique): iterationActuelle(0), maxIterations(20) {
    int largeur, hauteur;
    Fichier fichier;
    vector<vector<bool>> etats = fichier.lire(fichierConfig, largeur, hauteur);
    grille = unique_ptr<Grille>(new Grille(largeur, hauteur));
    for (int y = 0; y < hauteur; y++) {
        for (int x = 0; x < largeur; x++) {
            if (etats[y][x])
                grille->initCellule(x, y, new EtatVivant());
            else
                grille->initCellule(x, y, new EtatMort());
        }
    }
    regle = unique_ptr<IRegleJeu>(new RegleConway());
    if (!modeGraphique)
        vue = unique_ptr<IVue>(new VueConsole());
    else
        vue = unique_ptr<IVue>(new VueGraphique(largeur, hauteur));
}

void Jeu::lancer() {
    for (iterationActuelle = 0; iterationActuelle < maxIterations; ++iterationActuelle) {
        vue->afficher(*grille, iterationActuelle);
        traiterLogique();
    }
}

void Jeu::traiterLogique() {
    grille->actualiserToutesCellules(*regle);
}

bool Jeu::testUnitaire(const Grille& grilleAttendue, int nbIterations) {
    for (int i = 0; i < nbIterations; ++i) {
        traiterLogique();
    }

    if (grille->getLargeur() != grilleAttendue.getLargeur() ||
        grille->getHauteur() != grilleAttendue.getHauteur()) {
        return false;
        }


    for (int y = 0; y < grille->getHauteur(); ++y) {
        for (int x = 0; x < grille->getLargeur(); ++x) {
            bool etatActuel  = grille->getCellule(x, y).estVivante();
            bool etatAttendu = grilleAttendue.getCellule(x, y).estVivante();

            if (etatActuel != etatAttendu) {
                return false;
            }
        }
    }

    return true;
}