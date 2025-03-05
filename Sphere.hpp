#ifndef SPHERE_H
#define SPHERE_H

#include "Objet.hpp"

class Sphere: public Objet{

    public:
        // Créer une sphère à partir d'une autre sphère
        Sphere(Sphere &Sphere);
        // Crée une sphère à partir de son centre, de son rayon et du nombre de triangles souhaité
        Sphere(double rayon, Coordonnee centre, int nb_latitudes, int nb_longitudes);

    private:
        double rayon;
        Coordonnee centre;




};

#endif
