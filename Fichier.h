#ifndef PROJET_POO_FICHIER_H
#define PROJET_POO_FICHIER_H


#include <string>
#include <vector>
using namespace std;

class Fichier {
    public:
    Fichier();

    vector<vector<bool>> lire(string, int&, int&);
};


#endif //PROJET_POO_FICHIER_H