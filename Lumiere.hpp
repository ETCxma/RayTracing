#ifndef LUMIERE_H
#define LUMIERE_H


#include "Coordonnee.hpp"
#include "Couleur.hpp"

class Lumiere{

    public:
        Lumiere();
        Lumiere(Couleur intensite, Coordonnee soure); 
        Lumiere(Lumiere &l);

        // Getters
        Couleur getIntensite();
        Coordonnee getSource(); 

        void afficheLumiere(); 

    private:
        Couleur intensite;
        Coordonnee source; 

};


#endif