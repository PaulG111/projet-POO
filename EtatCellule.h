#pragma once

class EtatCellule {
public:
    virtual ~EtatCellule() = default;

    virtual bool estVivante() const = 0;
    virtual char getSymbole() const = 0;
    
    virtual EtatCellule* cloner() const = 0;
};
