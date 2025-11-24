#pragma once

class EtatMort : public EtatCellule {
public :
  etatmort() = default;
  bool estVivant() const override {return false}
  char getSymbole() const override {return "0"}
  EtatCellule* clone() const override { return new EtatMort(*this); }
};
