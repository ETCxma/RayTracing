#ifndef VECTEUR_H
#define VECTEUR_H

#include "Coordonnee.hpp"


class Vecteur{

    public:
        Vecteur();
        Vecteur(Coordonnee x1, Coordonnee x2);
        Vecteur(Vecteur &v);

        Coordonnee vecteur();
        double norme();
        Vecteur unitaire();

        double angle(Vecteur &v);
        double produitScalaire(Vecteur &v);
        Vecteur produitVectoriel(Vecteur &v);
        
        // NEED MORE FOR RAY TRACING
        // Coordonnee Intersection(Triangle &t);
        // Coordonnee Intersection(Objet &o);

        // WIP
        // Vecteur Reflechi(Triangle &t);


    protected:
        Coordonnee x1,x2; 

};


#endif