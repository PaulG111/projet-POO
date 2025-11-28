#include <memory>
#include <utility> 

class EtatCellule;

class Cellule {
private:
    int x;
    int y;

    std::unique_ptr<EtatCellule> etatActuel;
    std::unique_ptr<EtatCellule> etatSuivant;

public:

    Cellule(int x, int y, EtatCellule* etatInitial);

    // Interdire la copie (unique_ptr non copiable)
    Cellule(const Cellule&) = delete;
    Cellule& operator=(const Cellule&) = delete;

    // Autoriser le mouvement pour permettre le stockage dans std::vector
    Cellule(Cellule&&) noexcept = default;
    Cellule& operator=(Cellule&&) noexcept = default;
    
    ~Cellule();

    void preparerProchainEtat(EtatCellule* nouvelEtat);

    void validerEtat();

    bool estVivante() const;

    char getSymbole() const;

    std::pair<int, int> getCoordonnees() const; //pourquoi rajouter ça ?
    
    const EtatCellule* getEtatActuel() const;
};

