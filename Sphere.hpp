#ifndef SPHERE_H
#define SPHERE_H

#include "Coordonnee.hpp"
#include "Objet.hpp"
#include "Rayon.hpp"

class Sphere: public Objet{

    private:
        double rayon;
        Coordonnee centre;
        Materiau mat;

    public:
        // Crée une sphère à partir de son centre, de son rayon et de son matériau
        Sphere(Coordonnee centre, double rayon,const Materiau& mat);

        // Getters
        int getRayon();
        Coordonnee getCentre();

        // Setters
        void setRayon(double r);
        void setCentre(Coordonnee c);

        // Afficher les informations d'une sphère
        void affichInfos();

        RaytracingSimpleInfo intersection(Rayon rayon, Coordonnee centre_camera);
        RaytracingPhongInfo intersectionPhong(Rayon rayon, Coordonnee centre_camera, Coordonnee position_lumiere);

};

#endif
