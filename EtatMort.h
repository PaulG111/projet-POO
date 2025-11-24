#pragma once

class EtatMort : public EtatCellule {

public :

  etatmort() = default;
  bool estVivante() const override;
  char getSymbole() const override;
  EtatCellule* clone() const override;

};
