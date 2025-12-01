#ifndef PROJET_POO_JEU_H
#define PROJET_POO_JEU_H


#include <memory>

#include "Grille.h"
#include "IVue.h"
using namespace std;

class Jeu {
    int iterationActuelle;
    int maxIterations;
    unique_ptr<Grille> grille;
    unique_ptr<IRegleJeu> regle;
    unique_ptr<IVue> vue;

public :
    Jeu(string fichierConfig, bool modeGraphique);
    void lancer();
    void traiterLogique();
    void testUnitaire(Grille attendu, int iter);
};


#endif //PROJET_POO_JEU_H