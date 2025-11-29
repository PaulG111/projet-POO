#pragma once
#include "IRegleJeu.h"

class Cellule;
class EtatCellule;

class RegleConway{
public :
    RegleConway() = default;
    ~RegleConway() = default;

    EtatCellule* calculerProchainEtat(const Cellule& cellule, int nbVoisinsVivants) const override ;
};
