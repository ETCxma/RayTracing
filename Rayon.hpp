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
        Rayon(Coordonnee vecteur, Couleur couleur=Couleur());
        Rayon(Rayon &rayon);
        // Rayon(const Rayon&) = default;
        Rayon(Rayon &&rayon);

        Rayon operator=(Rayon rayon){
            return Rayon(rayon.getVecteur(), rayon.getCouleur());
        }

        void addIntensite(double intensite);
        double getIntensite();

        Couleur getCouleur();

    private:
        Couleur couleur;


};


#endif