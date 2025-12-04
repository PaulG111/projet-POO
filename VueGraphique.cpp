#include "VueGraphique.h"
#include "Grille.h"
#include <thread> 
#include <chrono>

VueGraphique::VueGraphique(int largeurGrille, int hauteurGrille) 
    : tailleCellule(30.0f), enPause(false)
{
    sf::VideoMode mode(largeurGrille * tailleCellule, hauteurGrille * tailleCellule);
    window.create(mode, "Jeu de la Vie - POO");
    window.setFramerateLimit(60);
}

void VueGraphique::afficher(const Grille& grille, int iteration) {
    window.clear(sf::Color::White); 

    sf::RectangleShape rect(sf::Vector2f(tailleCellule - 1.0f, tailleCellule - 1.0f));
    rect.setFillColor(sf::Color::Black); 

    for (int y = 0; y < grille.getHauteur(); ++y) {
        for (int x = 0; x < grille.getLargeur(); ++x) {
            if (grille.getCellule(x, y).estVivante()) {
                rect.setPosition(x * tailleCellule, y * tailleCellule);
                window.draw(rect);
            }
        }
    }
    
    window.display();
    
    std::this_thread::sleep_for(std::chrono::milliseconds(delaiMs));
}

bool VueGraphique::estEnPause() const {
    return enPause;
}

bool VueGraphique::gererEntree() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
            return false; 
        }
        if (event.type == sf::Event:: KeyPressed && event.key.code == sf::Keyboard::Space)
          enPause = !enPause;
    }
    
    return window.isOpen();
}
