#ifndef ECRAN_H
#define ECRAN_H

#include <vector>
#include "Coordonnee.hpp"
#include "Resolution.hpp"
#include "Pixel.hpp"
#include "Rayon.hpp"

class Ecran{

    public:
        Ecran();
        Ecran(Resolution resolution);
        // ~Ecran();
        

        Pixel getPixel(int x, int y);
        // Coordonnee getCentrePixel(int x, int y);
        Rayon getRayon(int x, int y);
        Resolution getResolution();

        int getPixelIntensite(int x, int y);
        double getRayonIntensite(int x, int y);

        void setResolution(int x, int y);

        // void SetPixel(int x, int y, Pixel &pixel);
        // void SetCentrePixel(int x, int y, Coordonnee &coordonnee);
        void SetRayon(int x, int y, Rayon &rayon);
        
        void setPixelIntensite(int x, int y, int intensite);
        void addPixelIntensite(int x, int y, int intensite);

        void addRayonIntensite(int x, int y, double intensite);
        
        void updatePixels();

    private:


        std::vector<Pixel> pixels; 
        std::vector<Rayon> rayons; 

        Resolution resolution;

};

#endif