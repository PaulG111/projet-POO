#include "Cellule.h"
#include "EtatCellule.h"

#include <iostream>

// Constructeur
// On utilise std::move ou l'initialisation directe pour prendre la main sur le pointeur brut
Cellule::Cellule(int x, int y, EtatCellule* etatInitial)
    : x(x), y(y), etatActuel(etatInitial), etatSuivant(nullptr) 
{
    if (!etatActuel) {
        // Sécurité : on ne veut pas de cellule sans état
        std::cerr << "Erreur : Tentative de créer une cellule avec un état nul." << std::endl;
        // Ici on pourrait throw une exception ou initialiser un état par défaut
    }
}

// Destructeur
// Nécessaire ici car la classe EtatCellule est pleinement définie à cet endroit,
// ce qui permet à unique_ptr d'appeler correctement le destructeur de l'état.
Cellule::~Cellule() = default;

void Cellule::preparerProchainEtat(EtatCellule* nouvelEtat) {
    // On reset le unique_ptr, ce qui supprime l'ancien etatSuivant s'il existait
    // et on prend la propriété du nouveau pointeur.
    etatSuivant.reset(nouvelEtat);
}

void Cellule::validerEtat() {
    if (etatSuivant) {
        // On transfère la propriété de etatSuivant vers etatActuel
        // L'ancien etatActuel est automatiquement détruit par unique_ptr
        etatActuel = std::move(etatSuivant);
        
        // etatSuivant est maintenant nullptr (grâce au move)
    }
}

bool Cellule::estVivante() const {
    if (etatActuel) {
        return etatActuel->estVivante();
    }
    return false; // Sécurité
}

char Cellule::getSymbole() const {
    if (etatActuel) {
        return etatActuel->getSymbole();
    }
    return '?'; // Symbole d'erreur
}

std::pair<int, int> Cellule::getCoordonnees() const {
    return {x, y};
}

const EtatCellule* Cellule::getEtatActuel() const {
    // .get() retourne le pointeur brut géré par le unique_ptr
    return etatActuel.get();
}
