#include "Jeu.h"

void Jeu::traiterLogique() {
    grille->actualiserToutesCellules(*regle);
    iterationActuelle++;
}