#ifndef PROJET_POO_IVUE_H
#define PROJET_POO_IVUE_H


class IVue {
    virtual void init(int largeur, int hauteur); //dans VueGraphique, mais pas dans VueConsole ?!
    virtual void afficher(const Grille &, int iteration);
    virtual bool gererEntree();
    virtual ~IVue();
};


#endif //PROJET_POO_IVUE_H