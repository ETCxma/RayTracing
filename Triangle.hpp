#ifndef TRIANGLE_H
#define TRIANGLE_H
/*
	va pu servir, l'implémentation sert à r...
*/

#include "Coordonnee.hpp"
#include "Couleur.hpp"

class Triangle{

    public:
        Triangle();
        Triangle(Coordonnee c1, Coordonnee c2, Coordonnee c3);

    private:
        Coordonnee c[3];
};



#endif