#ifndef SPHERE_H
#define SPHERE_H

#include "Objet.hpp"

class Sphere: public Objet{

    public:
        Sphere();
        Sphere(Sphere &Sphere);
        Sphere(double rayon, Coordonnee centre, int nb_triangles); // This automatically construct every triangle of the sphere 

    private:
        double rayon;
        Coordonnee centre;




};

#endif
