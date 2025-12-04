#ifndef PROJET_POO_IVUE_H
#define PROJET_POO_IVUE_H

class Grille;

class IVue {
public:
    virtual ~IVue() = default;

    virtual void afficher(const Grille& grille, int iteration) = 0;
    virtual bool gererEntree() = 0;
    virtual bool estEnPause() const =0;
    virtual bool attendreToucheEntree() = 0;
    virtual bool estOuverte() const = 0; 
    
};

#endif //PROJET_POO_IVUE_H
