#ifndef LUMIERE_H
#define LUMIERE_H


#include "Coordonnee.hpp"
#include "Couleur.hpp"

class Lumiere: public Coordonnee{

    public:
        Lumiere();
        Lumiere(Couleur intensite, Coordonnee soure, float intensite_specular, float intensite_diffuse, float intensite_ambient); 
        Lumiere(Lumiere &l);

        // Getters
        Couleur getIntensite();
        Coordonnee getPosition(); 
		float getIntensiteSpecular();
		float getIntensiteDiffuse();
		float getIntensiteAmbient();

        void afficheLumiere(); // À IMPLÉMENTER (???)

		// Setteurs.
		void setIntensite(Couleur intensite);
		void setPosition(Coordonnee source);
		void setIntensiteSpecular(float intensite_specular);
		void setIntensiteDiffuse(float intensite_diffuse);
		void setIntensiteAmbient(float intensite_ambient);

    private:
        Couleur intensite;
		float intensite_specular, intensite_diffuse, intensite_ambient; // Intensité lumineuse (speculaire, diffuse, ambiante)
        // Coordonnee source; 

};


#endif