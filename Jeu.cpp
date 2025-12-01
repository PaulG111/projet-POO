#include "Jeu.h"
#include "LecteurFichier.h"
#include "RegleConway.h"
#include "VueConsole.h"
#include "VueGraphique.h"
#include "EtatVivante.h"
#include "EtatMort.h"

Jeu::Jeu(std::string fichierConfig, bool modeGraphique): iterationActuelle(0), maxIterations(100)
{
    int largeur, longueur;
    std::vector<std::vector<bool>> etats = LecteurFichier::lire(fichierConfig, largeur, longueur);
    grille = std::unique_ptr<Grille>(new Grille(largeur, longueur));
    for (int y = 0; y < longueur; y++) {
        for (int x = 0; x < largeur; x++) {
            if (etats[y][x])
                grille->initCellule(x, y, new EtatVivante());
            else
                grille->initCellule(x, y, new EtatMort());
        }
    }

    // la règle
    regle = std::unique_ptr<IRegleJeu>(new RegleConway());

    // la vue
    if (!modeGraphique)
        vue = std::unique_ptr<IVue>(new VueConsole());
    else
        vue = std::unique_ptr<IVue>(new VueGraphique());
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
