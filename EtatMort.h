#pragma once
#include "EtatCellule.h"

class EtatMort : public EtatCellule {
public:
    EtatMort() = default;

    bool estVivante() const override;
    char getSymbole() const override;
    EtatCellule* clone() const override;
};
