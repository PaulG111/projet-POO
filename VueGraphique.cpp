#include <iostream>
#include "VueGraphique.h"
#include "Grille.h"
#include <thread> 
#include <chrono>

VueGraphique::VueGraphique(int largeurGrille, int hauteurGrille) 
    : tailleCellule(7.0f), enPause(false), imageChargee(false)
{
    int hauteurBandeau = 100;
    sf::VideoMode mode(largeurGrille * tailleCellule, (hauteurGrille * tailleCellule) + hauteurBandeau);
    window.create(mode, "Jeu de la Vie");
    window.setFramerateLimit(60);

    if (textureAide.loadFromFile("aide.png")) {
        imageChargee = true;
        spriteAide.setTexture(textureAide);
        float ratioX = (float)mode.width / textureAide.getSize().x;
        float ratioY = (float)hauteurBandeau / textureAide.getSize().y;
        spriteAide.setScale(ratioX, ratioY); 
        spriteAide.setPosition(0, hauteurGrille * tailleCellule);
    } else {
        // Si l'image n'est pas là, ce n'est pas grave, on continue sans.
        std::cerr << "Attention : aide.png introuvable." << std::endl;
    }
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
    
    if (imageChargee) {
        spriteAide.setColor(sf::Color(255, 255, 255, 200)); 
        window.draw(spriteAide);
    }
    if (enPause) {
        // On dessine deux barres verticales rouges (Symbole ||)
        sf::RectangleShape barre1(sf::Vector2f(20, 60));
        sf::RectangleShape barre2(sf::Vector2f(20, 60));
        
        barre1.setFillColor(sf::Color::Red);
        barre2.setFillColor(sf::Color::Red);
        
        // Position au centre de l'écran
        float cx = window.getSize().x / 2.0f;
        float cy = window.getSize().y / 2.0f;
        
        barre1.setPosition(cx - 30, cy - 30);
        barre2.setPosition(cx + 10, cy - 30);
        
        window.draw(barre1);
        window.draw(barre2);
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

bool VueGraphique::attendreToucheEntree() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
            return false;
        }
        
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
            return true; 
        }
    }
    return false; 
}

bool VueGraphique::estOuverte() const {
    return window.isOpen();
}

