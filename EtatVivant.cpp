#include "EtatVivant.h"

bool EtatVivant::estVivante() const {
    return true;
}

char EtatVivant::getSymbole() const {
    return '1';
}

EtatCellule* EtatVivant::clone() const {
    return new EtatVivant(*this);
}
