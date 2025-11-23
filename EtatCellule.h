#pragma once

// Interface abstraite (State Pattern)
class EtatCellule {
public:
    virtual ~EtatCellule() = default;

    // Méthodes virtuelles pures
    virtual bool estVivante() const = 0;
    virtual char getSymbole() const = 0;
    
    // Pattern Prototype : permet de dupliquer l'état sans connaitre son type concret
    virtual EtatCellule* cloner() const = 0;
};
