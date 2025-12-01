#ifndef PROJET_POO_VUECONSOLE_H
#define PROJET_POO_VUECONSOLE_H

#include <string>
#include "IVue.h"

class Grille;

class VueConsole : public IVue {
    std::string dossierSortie;

public:
    explicit VueConsole(std::string dossierSortie = "sorties");

    void afficher(const Grille& grille, int iteration) override;
    bool gererEntree() override; // retourne false pour quitter, true pour continuer
};

#endif //PROJET_POO_VUECONSOLE_H