#ifndef LUMIERE_H
#define LUMIERE_H


#include "Coordonnee.hpp"
#include "Couleur.hpp"

class Lumiere: public Coordonnee{

    public:
        Lumiere();
        Lumiere(Couleur intensite, Coordonnee soure, double intensite_specular, double intensite_diffuse, double intensite_ambient); 
        Lumiere(Lumiere &l);

        // Getters
        Couleur getIntensite();
        Coordonnee getPosition(); 
		double getIntensiteSpecular();
		double getIntensiteDiffuse();
		double getIntensiteAmbient();

        void afficheLumiere(); // À IMPLÉMENTER (???)

		// Setteurs.
		void setIntensite(Couleur intensite);
		void setPosition(Coordonnee source);
		void setIntensiteSpecular(double intensite_specular);
		void setIntensiteDiffuse(double intensite_diffuse);
		void setIntensiteAmbient(double intensite_ambient);

    private:
        Couleur intensite;
		double intensite_specular, intensite_diffuse, intensite_ambient; // Intensité lumineuse (speculaire, diffuse, ambiante)
        // Coordonnee source; 

};


#endif