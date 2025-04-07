#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Objet.hpp" 
#include "Materiau.hpp"
#include "Point.hpp"
#include "Vecteur.hpp"
#include "RaytracingPhongInfo.hpp"
#include "Plan.hpp"
#include <array>

class Triangle: public Objet{

    private:
        std::array<Point, 3> points; // Tableau de 3 points
		Plan plan; //sd
		Materiau materiau;

    public:
        // Constructeur
        Triangle();
        Triangle(Point* points);
        Triangle(Point* points, Materiau mat);        // On lui donne une référence vers un tableau de Points
		Triangle(Point A, Point B, Point C);
		Triangle(Point A, Point B, Point C, Materiau mat);
        Triangle(Triangle& t); 

        // Surcharges des méthodes virtuelles de Objet
        RaytracingSimpleInfo intersection(Rayon rayon, Coordonnee centre_camera) override; 
        RaytracingPhongInfo intersectionPhong(Rayon rayon, Coordonnee centre_camera, Coordonnee position_lumiere) override; 

		// Méthodes
		// Retourne un plan à partir des points
		Plan getPlan(); // avec ça on peut avoir aussi la normale
						// On peut aussi avoir le point d'intersection avec ce plan

		Point getPoint(int n); // Retourne le tableau de points
		
		double Aire(); 	// Retourne S_triangle ; 
						//Utiliser getPlan pour avoir la normale!!

		bool intersection(Rayon rayon); // def les 3 vect;
										// calc normales sous-triangles; 
										// calc aires sous-trinalges;
										// alpha, beta, gamma;
										// Condition;
										// retour.

};



#endif