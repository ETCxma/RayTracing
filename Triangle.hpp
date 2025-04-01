#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Objet.hpp" 
#include "Point.hpp"
#include "Vecteur.hpp"
#include "RaytracingPhongInfo.hpp"

class Triangle: public Objet{

    private:
        Point points[3];

    public:
        // Constructeur
        Triangle(); 
        Triangle(Point* points, Materiau mat);        // On lui donne une référence vers un tableau de Points
        Triangle(Triangle& t); 

        // Surcharges des méthodes virtuelles de Objet
        RaytracingSimpleInfo intersection(Rayon rayon, Coordonnee centre_camera) override; 
        RaytracingPhongInfo intersectionPhong(Rayon rayon, Coordonnee centre_camera, Coordonnee position_lumiere) override; 

};



#endif