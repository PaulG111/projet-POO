#pragma once

#include <memory> 
#include <utility> 

class EtatCellule;

class Cellule {
private:
    int x;
    int y;

    std::unique_ptr<EtatCellule> etatActuel;

    std::unique_ptr<EtatCellule> etatSuivant;

public:

    Cellule(int x, int y, EtatCellule* etatInitial);
    
    ~Cellule();

    void preparerProchainEtat(EtatCellule* nouvelEtat);

    void validerEtat();

    bool estVivante() const;

    char getSymbole() const;

    std::pair<int, int> getCoordonnees() const;
    
    const EtatCellule* getEtatActuel() const;
};

