#pragma once
class EtatCellule;

class IRegleJeu {
public:

virtual ~IRegleJeu() = default;

virtual EtatCellule* calculerProchainEtat(const EtatCellule& etatActuel, int nbVoisins) const = 0;
};
