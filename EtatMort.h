#pragma once

class EtatMort : EtatCellule {
public :
  etatmort() = default;
  bool estVivant() const {return false}
  char getSymbole() const {return "0"}
};
