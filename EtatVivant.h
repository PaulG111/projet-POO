#pragma once

class EtatVivant : public EtatCellule {
public :
  etatVivant() = default;
  bool estVivant() const {return true}
  char getSymbole() const {return "1"}
};
