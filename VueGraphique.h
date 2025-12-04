#include "IVue.h"
#include <SFML/Graphics.hpp>

class VueGraphique : public IVue {
private:
    sf::RenderWindow window;
    float tailleCellule;
    bool enPause;
    int delaiMs = 500;
    sf::Texture textureAide;
    sf::Sprite spriteAide;  
    bool imageChargee; 

public:
    VueGraphique(int largeurGrille, int hauteurGrille);
    
    void afficher(const Grille& grille, int iteration) override;
    bool gererEntree();
    bool estEnPause() const;
    bool attendreToucheEntree() override;
    bool estOuverte() const override;
};
