#ifndef VECTEUR_H
#define VECTEUR_H

#include "Coordonnee.hpp"
#include "Objet.hpp"
#include "Triangle.hpp"
#include <cmath>

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
        Coordonnee &Intersection(Objet &o); // Pass vecteur to o.intersection() and get usefulData for ray calc
        // Coordonnee &Intersection(Triangle &t); Not used because calculation will be done through the object
        
        // WIP
        // Vecteur &Reflechi(Triangle &t);
        
        
    protected:
        Coordonnee x1,x2; 

};


#endif