#pragma once
#include "IVue.h"
#include <SFML/Graphics.hpp>

class VueGraphique : public IVue {
private:
    sf::Font font;
    sf::Text texteMessage;
    sf::RenderWindow window;
    float tailleCellule;
    bool enPause;
    int delaiMs = 500;

public:
    VueGraphique(int largeurGrille, int hauteurGrille);
    
    void afficher(const Grille& grille, int iteration) override;
    bool gererEntree();
    bool estEnPause() const;
    void afficherMenu();
    void afficherFin();
    bool toucheEntree();
};
