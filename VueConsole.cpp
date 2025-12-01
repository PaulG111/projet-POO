#include "VueConsole.h"
#include "Grille.h"

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

VueConsole::VueConsole(std::string dossierSortie)
    : dossierSortie(std::move(dossierSortie)) {
    try {
        if (!std::filesystem::exists(this->dossierSortie)) {
            std::filesystem::create_directories(this->dossierSortie);
        }
    } catch (const std::exception& e) {
        std::cerr << "Erreur lors de la création du dossier de sortie: " << e.what() << std::endl;
    }
}

void VueConsole::afficher(const Grille& grille, int iteration) {
    std::cout << "----- Iteration " << iteration << " -----" << std::endl;

    for (int y = 0; y < grille.getHauteur(); ++y) {
        for (int x = 0; x < grille.getLargeur(); ++x) {
            char symbole = grille.getCellule(x, y).getSymbole();
            std::cout << symbole << ' ';
        }
        std::cout << std::endl;
    }

    std::filesystem::path nomFichier = std::filesystem::path(dossierSortie) / ("iteration_" + std::to_string(iteration) + ".txt");
    std::ofstream fichier(nomFichier);

    if (fichier.is_open()) {
        fichier << grille.getHauteur() << ' ' << grille.getLargeur() << '\n';

        for (int y = 0; y < grille.getHauteur(); ++y) {
            for (int x = 0; x < grille.getLargeur(); ++x) {
                bool vivante = grille.getCellule(x, y).estVivante();
                fichier << (vivante ? '1' : '0') << ' ';
            }
            fichier << '\n';
        }
        fichier.close();
    } else {
        std::cerr << "Erreur : Impossible d'écrire le fichier " << nomFichier << std::endl;
    }
}

bool VueConsole::gererEntree() {
    std::cout << "Appuyez sur Entrée pour continuer, tapez q puis Entrée pour quitter: ";
    std::string ligne;
    std::getline(std::cin, ligne);
    if (!std::cin) {
        return false; // EOF ou erreur -> on arrête
    }
    return !(ligne == "q" || ligne == "Q");
}