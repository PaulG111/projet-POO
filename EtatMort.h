#pragma once

class EtatMort : public EtatCellule {

public :

  etatmort() = default;
  bool estVivant() const override;
  char getSymbole() const override;
  EtatCellule* clone() const override;

};
