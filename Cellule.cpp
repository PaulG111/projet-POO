#include "Cellule.hpp"
#include "EtatCellule.hpp"
#include <iostream>

Cellule::Cellule(int x, int y, EtatCellule* etatInitial)
    : x(x), y(y), etatActuel(etatInitial), etatSuivant(nullptr) {
    if (!etatActuel) {
        std::cerr << "Erreur : Tentative de créer une cellule avec un état nul." << std::endl;
    }
}

Cellule::~Cellule() = default;

void Cellule::preparerProchainEtat(EtatCellule* nouvelEtat) {
    etatSuivant.reset(nouvelEtat);
}

void Cellule::validerEtat() {
    if (etatSuivant) {

        etatActuel = std::move(etatSuivant);
    }
}

bool Cellule::estVivante() const {
    if (etatActuel) {
        return etatActuel->estVivante();
    }
    return false;
}

char Cellule::getSymbole() const {
    if (etatActuel) {
        return etatActuel->getSymbole();
    }
    return '?'; 
}

std::pair<int, int> Cellule::getCoordonnees() const {
    return {x, y};
}

const EtatCellule* Cellule::getEtatActuel() const {
    return etatActuel.get();
}
