#ifndef SPHERE_H
#define SPHERE_H

#include "Coordonnee.hpp"

class Sphere{

    private:
        double rayon;
        Coordonnee centre;

    public:
        // Crée une sphère à partir de son centre et de son rayon
        Sphere(Coordonnee centre, double rayon);

        // Getters
        int get_rayon();
        Coordonnee get_centre();

        // Setters
        void set_rayon(double r);
        void set_centre(Coordonnee c);

        // Afficher les informations d'une sphère
        void Affich_Infos();

};

#endif
