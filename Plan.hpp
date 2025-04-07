#ifndef PLAN_H
#define PLAN_H

#include <array> 
#include "Coordonnee.hpp"
#include "Vecteur.hpp"
#include "Rayon.hpp" 

/**
 * L'idée derrière cette classe est d'implémenter le calcul d'intersection entre un triangle et un rayon.
 * 
 * Équation d'un plan: Nx*x0 + Ny*y0 + Nz*z0 + d = 0, où:
 *      - (Nx, Ny, Nz): composante du vecteur normal du plan 
 *      - d représente la distance du centre du plan à l'origine de l'espace 
 * 
 * Tout ces paramètres peuvent récupérés de la façon suivante:
 *      - (Nx, Ny, Nz): attributs de la classe Plan
 *      - d: on calcule la distance euclidienne entre l'origine notre plan et l'origine du repère 
 */
class Plan{

    private:
        Vecteur normal;            // Vecteur normal au plan
        Coordonnee origin;         // Origine du vecteur normal

    public: 
        // Constructeur
        // Plan();
        Plan(Vecteur n=Vecteur(1,1,1), Coordonnee origin=Coordonnee(0,0,0)); 
        Plan(Plan& p); 

        // GETTER
        Coordonnee getOrigin(); 
        Vecteur getNormal(); 

        // SETTER
        void setOrigin(Coordonnee origin); 
        void setNormal(Vecteur normal);  


        /**
         * Entrée: rien
         * Sortie: 
         * - renvoie le paramètre D, représentant la "distance" du plan à l'origine de l'espace (0,0,0). 
         * - Pour cela, on passe par l'équation Nx*x0 + Ny*y0 + Nz*z0 + D = 0, où:
         * - (Nx, Ny, Nz): composante du vecteur normal au plan (obtenu grâce à vecteurNormal()); 
         * - (x0, y0 z0): coordonnées d'un point quelconque du plan (ici on prendra le point origin). 
         */
        double distance(); 
  

        /**
         * Entrée: rien
         * Sortie: rien, affiche les informations du plan
         */
        void afficher(); 

        // /**
        //  * Entrée: un rayon 
        //  * Sortie: renvoie les coordonnées d'intersection du rayon et du plan si intersection il y a 
        //  */
        // Coordonnee intersectionPlan(Rayon r); 

};




#endif 