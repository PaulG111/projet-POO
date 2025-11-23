#pragma once

#include <memory> // Pour std::unique_ptr
#include <utility> // Pour std::pair

// Déclaration anticipée (évite d'inclure tout le fichier header ici)
class EtatCellule;

class Cellule {
private:
    int x;
    int y;

    // Pointeur intelligent vers l'état actuel (State Pattern)
    // unique_ptr gère la suppression de la mémoire automatiquement
    std::unique_ptr<EtatCellule> etatActuel;

    // Tampon pour stocker le futur état calculé par la règle
    std::unique_ptr<EtatCellule> etatSuivant;

public:
    /**
     * Constructeur
     * @param x Coordonnée X
     * @param y Coordonnée Y
     * @param etatInitial Pointeur vers l'état de départ (La cellule prend la propriété de ce pointeur)
     */
    Cellule(int x, int y, EtatCellule* etatInitial);

    // Destructeur (nécessaire à cause du forward declaration avec unique_ptr)
    ~Cellule();

    /**
     * Stocke le futur état dans la variable tampon sans modifier l'état actuel.
     * @param nouvelEtat Pointeur brut (la méthode va le transformer en unique_ptr)
     */
    void preparerProchainEtat(EtatCellule* nouvelEtat);

    /**
     * Applique la transition : etatSuivant devient etatActuel.
     * Appelé une fois que toutes les cellules ont calculé leur futur.
     */
    void validerEtat();

    // Délègue la question à l'état actuel (Polymorphisme)
    bool estVivante() const;

    // Délègue l'affichage à l'état actuel
    char getSymbole() const;

    // Accesseur pour les coordonnées (utile pour l'affichage ou le debug)
    std::pair<int, int> getCoordonnees() const;
    
    // Accesseur lecture seule vers l'état (utile pour les règles)
    const EtatCellule* getEtatActuel() const;
};

