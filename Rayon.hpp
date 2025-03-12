#ifndef RAYON_H
#define RAYON_H


#include "Coordonnee.hpp"
#include "Couleur.hpp"
#include "Vecteur.hpp"


class Rayon: public Vecteur{

    public:
        Rayon();
        Rayon(Coordonnee x1, Coordonnee x2, Couleur couleur=Couleur());
        Rayon(Vecteur &vecteur, Couleur couleur=Couleur());

    private:
        Couleur couleur;


};


#endif