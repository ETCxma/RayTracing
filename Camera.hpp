#ifndef CAMERA_H
#define CAMERA_H

#include <string>

#include "Ecran.hpp"
#include "Coordonnee.hpp"
#include "Vecteur.hpp"
#include "Resolution.hpp"


class Camera{

    public:
        Camera();
        Camera(Camera &camera);
        Camera(Resolution resolution);
        Camera(Coordonnee position, double distance_ecran, double theta, double phi, Resolution resolution);

        void setPosition(Coordonnee position);
        void setDistanceEcran(double distance_ecran);
        void setTheta(double theta);
        void setPhi(double phi);

        Coordonnee getPosition();
        double getDistanceEcran();
        double getTheta();
        double getPhi();
        Resolution getResolution();

    private:
        void calculateScreenCoords(); // Called by constructor

        Ecran ecran;
        Coordonnee position;
        double distance_ecran;
        double theta, phi; // gives Vecteur rotation_espace;


};

#endif

