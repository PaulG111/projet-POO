#pragma once

class EtatMort {
public :
  etatmort() = default;
  bool estVivant() const {return false}
  char getSymbole() const {return "0"}
};
