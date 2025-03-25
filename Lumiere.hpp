#ifndef LUMIERE_H
#define LUMIERE_H


#include "Coordonnee.hpp"
#include "Couleur.hpp"

class Lumiere: public Coordonnee{

    public:
        Lumiere();
        Lumiere(Couleur intensite, Coordonnee soure, float i_s, float i_d, float i_a); 
        Lumiere(Lumiere &l);

        // Getters
        Couleur getIntensite();
        Coordonnee getPosition(); 
		float getIS();
		float getID();
		float getIA();

        void afficheLumiere(); // À IMPLÉMENTER (???)

		// Setteurs.
		void setIntensite(Couleur intensite);
		void setPosition(Coordonnee source);
		void setIS(float i_s);
		void setID(float i_d);
		void setIA(float i_a);

    private:
        Couleur intensite;
		float i_s, i_d, i_a; // Intensité lumineuse (speculaire, diffuse, ambiante)
        // Coordonnee source; 

};


#endif