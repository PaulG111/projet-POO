#pragma once
#include "EtatCellule.h"

class EtatVivant : public EtatCellule {
public:
    EtatVivant() = default;

    bool estVivante() const override;
    char getSymbole() const override;
    EtatCellule* clone() const override;
};
