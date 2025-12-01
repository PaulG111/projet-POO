#pragma once
#include "IRegleJeu.h"

class Cellule;
class EtatCellule;

class RegleConway : public IRegleJeu {
public:
    RegleConway() = default;
    ~RegleConway() override = default;

    EtatCellule* calculerProchainEtat(const EtatCellule& etatActuel, int nbVoisins) const override;
};
