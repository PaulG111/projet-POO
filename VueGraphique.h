#pragma once
#include "IVue.h"
#include <SFML/Graphics.hpp>

class VueGraphique : public IVue {
private:
    sf::RenderWindow window;
    float tailleCellule;
    bool enPause;
    int delaiMs= 1000;

public:
    VueGraphique(int largeurGrille, int hauteurGrille);
    
    void afficher(const Grille& grille, int iteration) override;
    void setVitesse(int ms);
    bool gererEntree() override;
};
