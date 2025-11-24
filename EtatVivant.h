#pragma once

class EtatVivant : public EtatCellule {
public :
  etatVivant() = default;
  bool estVivant() const override {return true}
  char getSymbole() const override {return "1"}
  EtatCellule* clone() const override { return new EtatVivant(*this); }
};
