#ifndef RAYON_H
#define RAYON_H


#include "Coordonnee.hpp"
#include "Couleur.hpp"
#include "Vecteur.hpp"


class Rayon: public Vecteur{

    public:
        Rayon();
        Rayon(Coordonnee x1, Coordonnee x2, double intensite=0);
        Rayon(Vecteur &v, double intensite=0);
        Rayon(Rayon &r);

    private:
        Couleur Couleur;


};


#endif