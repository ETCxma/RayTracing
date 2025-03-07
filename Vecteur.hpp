#ifndef VECTEUR_H
#define VECTEUR_H

#include "Coordonnee.hpp"
// #include "Objet.hpp"
// #include "Triangle.hpp"
#include <cmath>

class Vecteur{

    public:
        // Constructeurs 
        Vecteur();      
        Vecteur(double dx=0.0, double dy=0.0, double dz=0.0);
        Vecteur(Vecteur &v);

        /**
         * Entrée: rien
         * Sortie: renvoie la norme du vecteur
         */
        double norme();

        /**
         * Entrée: rien
         * Sortie: renvoie le vecteur unitaire du vecteur
         */
        Vecteur unitaire();

        /**
         * Entrée: une instance de vecteur
         * Sortie: renvoie la mesure d'angle entre les deux vecteurs
         */
        double angle(Vecteur &v);

        /**
         * Entrée: une instance de vecteur
         * Sortie: renvoie le résultat du produit scalaire des deux vecteurs
         */
        double produitScalaire(Vecteur &v);

        /**
         * Entrée: une instance de vecteur
         * Sortie: renvoie le résultat du produit vectoriel des deux vecteurs
         */
        Vecteur produitVectoriel(Vecteur &v);

        /**
         * Entrée: rien
         * Sortie: convertit le vecteur des coordonnées cartésiennes à sphériques
         * dx <=> r
         * dy <=> theta
         * dz <=> phi
         */
        Vecteur cartesienToSpherique(); 
        /**
         * Entrée: rien
         * Sortie: convertit le vecteur des coordonnées sphériques à cartésiennes
         */
        Vecteur spheriqueToCartesien(); 

        /**
         * Entrée: un double 
         * Sortie: Faire tourner le vecteur suivant theta (dy)
         */
        void rotationTheta(double angle); 

        /**
         * Entrée: rien
         * Sortie: convertit le vecteur des coordonnées cartésiennes à cylindriques
         */
        
        // NEED MORE FOR RAY TRACING
        // Coordonnee &Intersection(Objet &o); // Pass vecteur to o.intersection() and get usefulData for ray calc
        // Coordonnee &Intersection(Triangle &t); Not used because calculation will be done through the object
        
        // WIP
        // Vecteur &Reflechi(Triangle &t);

        // Getter
        double getDX(); 
        double getDY();
        double getDZ();  

        // Setter
        void setDX(double x);
        void setDY(double y);
        void setDZ(double z); 

        // Surcharge de l'opérateur "+" pour les vecteurs en coordonnées cartésiennes (x, y, z)
        Vecteur operator+(Vecteur &v);  

        // Surcharge de l'opérateur "*" pour un vecteur en coordonnées cartésiennes
        Vecteur operator*(double scalaire); 

        

    protected:
        double dx, dy, dz; 


};


#endif