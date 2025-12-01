#include "RegleConway.hpp"
#include "EtatVivant.hpp"
#include "EtatMort.hpp"

EtatCellule* RegleConway::calculerProchainEtat(const EtatCellule& etatActuel, int nbVoisins) const {
    bool estVivante = etatActuel.estVivante();

    if (estVivante) {
        if (nbVoisins == 2 || nbVoisins == 3) {
            return new EtatVivant();
        } else {
            return new EtatMort();
        }
    } else {
        if (nbVoisins == 3) {
            return new EtatVivant();
        } else {
            return new EtatMort();
        }
    }
}
