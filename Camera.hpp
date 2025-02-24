#ifndef CAMERA_H
#define CAMERA_H

#include <string>

#include "Ecran.hpp"
#include "Coordonnee.hpp"
#include "Vecteur.hpp"
#include "Rayon.hpp"
#include "Resolution.hpp"


class Camera{

    public:
        Camera();
        Camera(Camera &camera);
        Camera(Coordonnee position, double distance_ecran, double theta, double phi, Resolution resolution);

    private:
        void calculateScreenCoords(); // Called by constructor

        Ecran ecran;
        Coordonnee position;
        double distance_ecran;
        double theta, phi; // gives Vecteur rotation_espace;
        Rayon **rayons; // good ?


};

#endif

