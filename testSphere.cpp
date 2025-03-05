#ifndef SPHERE_H
#define SPHERE_H

#include <iostream>
#include <vector>
#include <cmath>
#include "Sphere.hpp"
#include "Coordonnee.hpp"
#include "Triangle.hpp"


class Sphere: public Objet{

    public:
        // Créer une sphère à partir d'une autre sphère
        Sphere(Sphere &Sphere);
        // Crée une sphère à partir de son centre, de son rayon et du nombre de triangles souhaité
        Sphere(double rayon, Coordonnee centre, int nb_latitudes, int nb_longitudes);

    private:
        double rayon;
        Coordonnee centre;
        


        Sphere(double rayon, Coordonnee centre, int nb_latitudes, int nb_longitudes){
            // Liste des sommets et triangles de la sphère
            std::vector<Coordonnee> sommets;
            std::vector<Triangle> triangles;

            // On génère d'abord les points des triangles qui composeront la sphère (les sommets), on se place en convention rayon-longitude-colatitude
            for (int i = 0; i <= nb_latitudes; i++){
                // Colatitude, angle allant de Z à X (max Pi, min 0)
                double theta = M_PI * (i / (double)nb_latitudes);
                for (int j = 0; j < nb_longitudes; j++) {
                    // Longitude, angle allant de X à X suivant le plan (X,Y) (max 2*Pi, min 0)
                    double phi = 2 * M_PI * j / (double)nb_longitudes;
        
                    // Calcul des coordonnées sphériques dans nos conventions
                    double x = centre.x + rayon * (sin(phi) * cos(theta));
                    double y = centre.y + rayon * (sin(phi) * sin(theta));
                    double z = centre.z + rayon * cos(phi);
        
                    // On rajoute les coordonnées
                    // La liste des coordoonées contient donc logiquement en premier la coordonnée du bas de la sphère et en haut la coordonnée du haut de la sphère
                    sommets.push_back(Coordonnee(x, y, z));
                }
            }
        
            // On génère les triangles
            for (int i = 0; i < nb_latitudes; i++) {
                for (int j = 0; j < nb_longitudes; j++) {

                    int cur = i * nb_longitudes + j;
                    int next = (i + 1) * nb_longitudes + j;
        
                    // Triangle 1
                    int p1 = cur;
                    int p2 = next;
                    int p3 = (i + 1) * nb_longitudes + (j + 1) % nb_longitudes;
                    triangles.push_back(Triangle(p1, p2, p3));
        
                    // Triangle 2
                    p1 = cur;
                    p2 = (i + 1) * nb_longitudes + (j + 1) % nb_longitudes;
                    p3 = cur + (j + 1) % nb_longitudes;
                    triangles.push_back(Triangle(p1, p2, p3));
                }
            }
            return;
        }


};