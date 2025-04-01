#ifndef PLAN_H
#define PLAN_H

#include <array> 
#include "Coordonnee.hpp"
#include "Vecteur.hpp"
#include "Rayon.hpp" 

/**
 * L'idée derrière cette classe est d'implémenter le calcul d'intersection entre un triangle et un rayon.
 * 
 * Équation d'un plan: ax + by + cz + d = 0, où:
 *      - a, b et c sont les coordonnées du vecteur n, normal au plan (donnant au passage son orientation)
 *      - d représente la distance du centre du plan à l'origine du repère 
 * 
 * Tout ces paramètres peuvent récupérés de la façon suivante:
 *      - a, b, c: on détermine n grâce à la relation n = produitVectoriel(u, v) 
 *      - d: on calcule la distance euclidienne entre le centre de notre plan et l'origine du repère
 */
class Plan{

    private:
        Coordonnee origin;      // Point commun des deux vecteurs (point d'origine, à ne pas confondre avec l'origine du repère)
        Coordonnee c1;          // Point d'arrivé du premier vecteur du plan vectoriel
        Coordonnee c2;          // Point d'arrivé du deuxième vecteur du plan vectoriel
        Coordonnee centre;      // Permet d'accéder à d

    public: 
        // Constructeur
        Plan();
        // Par défaut, un plan est contenu dans l'axe z
        Plan(Coordonnee origin=Coordonnee(0,0,0), Coordonnee c1=Coordonnee(1,0,0), Coordonnee c2=Coordonnee(0,1,0), Coordonnee centre=Coordonnee(0,0,0)); 
        Plan(Plan& p); 

        // GETTER
        Coordonnee getOrigin(); 
        Coordonnee getC1(); 
        Coordonnee getC2(); 
        Coordonnee getCentre(); 

        // SETTER
        void setOrigin(Coordonnee origin); 
        void setC1(Coordonnee c);
        void setC2(Coordonnee c);
        void setCentre(Coordonnee centre); 

        /**
         * Entrée: rien
         * Sortie: 
         * - Renvoie le vecteur de ce plan (produit vectoriel des deux vecteurs définissant ce plan)
         * - Procéder de cette manière nous permet de récupérer les scalaires a, b et c 
         */
        Vecteur vecteurNormal(); 

        /**
         * Entrée: rien
         * Sortie: 
         * - renvoie la norme du vecteur ((0,0,0), centre)
         * - procéder de cette manière nous permet de récupérer d
         */
        double distance(); 

        /**
         * Entrée: rien
         * Sortie: renvoie un pointeur vers un tableau de vecteur contenant les deux vecteurs de plan
         */
        std::array<Vecteur, 2> vec();  

        /**
         * Entrée: rien
         * Sortie: rien, affiche les informations du plan
         */
        void afficher(); 

        /**
         * Entrée: un rayon 
         * Sortie: renvoie les coordonnées d'intersection du rayon et du plan si intersection il y a 
         */
        Coordonnee intersectionPlan(Rayon r); 

};




#endif 