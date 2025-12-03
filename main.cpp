#include "Jeu.h"
#include <string>

int main() {
    std::string chemin = "C:\\Users\\ASUS\\CLionProjects\\projet-POO\\jeu_cellule_1.txt";

    // Mode console
    Jeu jeuConsole(chemin, false);
    jeuConsole.lancer();

    // Mode graphique
    // Jeu jeuGraphique(chemin, true);
    // jeuGraphique.lancer();

    return 0;
}
