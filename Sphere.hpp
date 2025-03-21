#ifndef SPHERE_H
#define SPHERE_H

#include "Coordonnee.hpp"
#include "Objet.hpp"
#include "Rayon.hpp"

class Sphere: public Objet{

    private:
        double rayon;
        Coordonnee centre;

    public:
        // Crée une sphère à partir de son centre et de son rayon
        Sphere(Coordonnee centre, double rayon);

        // Getters
        int getRayon();
        Coordonnee getCentre();

        // Setters
        void setRayon(double r);
        void setCentre(Coordonnee c);

        // Afficher les informations d'une sphère
        void affichInfos();

        raytracingUsefulInfo intersection(Rayon rayon, Coordonnee centre_camera);

};

#endif
