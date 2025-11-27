#include "EtatMort.h"

bool EtatMort::estVivante() const {
    return false;
}

char EtatMort::getSymbole() const {
    return '0';
}

EtatCellule* EtatMort::clone() const {
    return new EtatMort(*this);
}
