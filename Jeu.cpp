#include "Jeu.h"
#include "LecteurFichier.h"
#include "RegleConway.h"
#include "VueConsole.h"
#include "VueGraphique.h"
#include "EtatVivante.h"
#include "EtatMort.h"

using namespace std;

Jeu::Jeu(string fichierConfig, bool modeGraphique): iterationActuelle(0), maxIterations(100)
{
    int largeur, longueur;
    vector<vector<bool>> etats = LecteurFichier::lire(fichierConfig, largeur, longueur);
    grille = unique_ptr<Grille>(new Grille(largeur, longueur));
    for (int y = 0; y < longueur; y++) {
        for (int x = 0; x < largeur; x++) {
            if (etats[y][x])
                grille->initCellule(x, y, new EtatVivante());
            else
                grille->initCellule(x, y, new EtatMort());
        }
    }
    regle = unique_ptr<IRegleJeu>(new RegleConway());
    if (!modeGraphique)
        vue = unique_ptr<IVue>(new VueConsole());
    else
        vue = unique_ptr<IVue>(new VueGraphique());
}
void Jeu::lancer() {
    for (iterationActuelle = 0; iterationActuelle < maxIterations; ++iterationActuelle) {
        vue->afficher(*grille, iterationActuelle);
        traiterLogique();
    }
}
void Jeu::traiterLogique() {
    int h = grille->getLongueur();
    int l = grille->getLargeur();

    // 1) préparer les nouveaux états
    for (int y = 0; y < h; ++y) {
        for (int x = 0; x < l; ++x) {
            Cellule& c = grille->getCelluleMutable(x, y);

            int voisins = grille->compterVoisinsVivants(x, y);
            EtatCellule* nouvelEtat = regle->calculerProchainEtat(*c.getEtatActuel(), voisins);
            c.preparerProchainEtat(nouvelEtat);
        }
    }
    grille->actualiserToutesCellules();
}
bool Jeu::testUnitaire(const Grille& grilleAttendue, int nbIterations) {
    for (int i = 0; i < nbIterations; ++i) {
        traiterLogique();
    }

    if (grille->getLargeur() != grilleAttendue.getLargeur() ||
        grille->getLongueur() != grilleAttendue.getLongueur()) {
        return false;
    }


    for (int y = 0; y < grille->getLongueur(); ++y) {
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
