#pragma once

class EtatCellule {
public:
    virtual ~EtatCellule() = default;

    virtual bool estVivante() const = 0;
    virtual char getSymbole() const = 0;
    
    // Crée une copie dynamique de l'état courant
    virtual EtatCellule* clone() const = 0;
};
