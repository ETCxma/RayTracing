#ifndef LUMIERE_H
#define LUMIERE_H


#include "Coordonnee.hpp"

class Lumiere{

    public:
        Lumiere();
        Lumiere(int intensite, Coordonnee soure); 
        Lumiere(Lumiere &l);

        // Getters
        int getIntensite();
        Coordonnee getSource(); 

    private:
        int intensite;
        Coordonnee source; 

};


#endif