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
        Vecteur(Coordonnee x1, Coordonnee x2);
        Vecteur(double dx, double dy, double dz);
        Vecteur(Vecteur &v);

        /**
         * Entrée: un vecteur et un string
         * Sortie: rien, affiche les composantes du vecteur
         * 
         * nb: je voulais qu'on ait le nom de l'instance donc j'ai fait comme ça
         */
        void afficheVecteur(std::string nom); 

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
         * Entrée: un double 
         * Sortie: faire tourner le vecteur suivant phi (dz)
         */
        void rotationPhi(double angle); 

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
        // friend Vecteur operator+(Vecteur &v, Vecteur &v2);  
        friend Vecteur operator+(Vecteur v, Vecteur v2);  

        // Surcharge de l'opérateur "-" pour les vecteurs en coordonnées cartésiennes (x, y, z)
        // friend Vecteur operator-(Vecteur &v, Vecteur &v2);  
        friend Vecteur operator-(Vecteur v, Vecteur v2);  

        // Surcharge de l'opérateur "*" pour un vecteur en coordonnées cartésiennes
        friend Vecteur operator*(Vecteur v, double scalaire); 
        friend Vecteur operator*(Vecteur v, int scalaire); 

        // Surcharge de l'opérateur "-" pour les vecteurs en coordonnées cartésiennes (x, y, z)
        friend Vecteur operator-(Vecteur &v);  

        // Surcharge de l'opérateur "*" entre deux vecteurs (on multiplie composante par composante)
        friend Vecteur operator*(Vecteur v1, Vecteur v2);
        friend Vecteur operator*(Vecteur &v1, Vecteur &v2);

        // Surcharge de l'opérateur "*" entre une coordonnée et un vecteur 
        friend Vecteur operator*(Vecteur v, Coordonnee c); 
        friend Vecteur operator*(Vecteur &v, Coordonnee &c);  

        // Surcharge de l'opérateur "+" entre un vecteur et une coordonnée
        friend Vecteur operator+(Vecteur v, Coordonnee c);
        friend Vecteur operator+(Vecteur &v, Coordonnee &c);

        // Surcharge de l'opérateur "-" entre un vecteur et une coordonnée
        friend Vecteur operator-(Vecteur v, Coordonnee c);
        friend Vecteur operator-(Vecteur &v, Coordonnee &c); 
        

    protected:
        double dx, dy, dz; 


};


#endif