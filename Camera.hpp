#ifndef CAMERA_H
#define CAMERA_H

#include <string>

#include "Ecran.hpp"
#include "Coordonnee.hpp"
#include "Vecteur.hpp"
#include "Resolution.hpp"


class Camera{

    public:
        // Constructors
        Camera();
        Camera(Camera const &camera);
        Camera(Resolution resolution);
        Camera(Coordonnee position, double distance_ecran, double theta, double phi, Resolution resolution);

        // Setters
        void setPosition(Coordonnee position);
        void setDistanceEcran(double distance_ecran);
        void setTheta(double theta);
        void setPhi(double phi);
        void setResolution(int x, int y);

        // Getters
        Coordonnee getPosition();
        double getDistanceEcran();
        double getTheta();
        double getPhi();
        Resolution getResolution();
        Rayon getRayon(int x, int y);
        Pixel getPixel(int x, int y);
        int getPixelIntensite(int x, int y);

        // Others
        void addPixelIntensite(int x, int y, int intensite);
        void addRayonIntensite(int x, int y, double intensite);
        void updatePixels();

    private:
        void calculRayonsCoord(); // Called by constructor

        Ecran ecran;
        Coordonnee position;
        double distance_ecran;
        double theta, phi; // gives Vecteur rotation_espace;


};

#endif

