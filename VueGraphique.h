#pragma once
#include "IVue.h"
#include <SFML/Graphics.hpp>

class VueGraphique : public IVue {
private:
    sf::RenderWindow window;
    float tailleCellule;
    bool enPause;
    int delaiMs = 750;

public:
    VueGraphique(int largeurGrille, int hauteurGrille);
    
    void afficher(const Grille& grille, int iteration) override;
    bool gererEntree() override;
};
