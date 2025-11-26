#pragma once
#include "EtatCellule.h"

class EtatVivant : public EtatCellule {

public :

  etatvivant() = default;
  bool estVivante() const override;
  char getSymbole() const override;
  EtatCellule* clone() const override;

};
