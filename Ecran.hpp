#ifndef ECRAN_H
#define ECRAN_H

#include "Coordonnee.hpp"
#include "Resolution.hpp"
#include "Pixel.hpp"
#include "Rayon.hpp"

class Ecran{

    public:
        Ecran();
        Ecran(Resolution resolution);
        
        ~Ecran();

        Pixel getPixel(int x, int y);
        // Coordonnee getCentrePixel(int x, int y);
        Rayon getRayon(int x, int y);
        Resolution getResolution();

        void setResolution(int x, int y);

        void SetPixel(int x, int y, Pixel &pixel);
        // void SetCentrePixel(int x, int y, Coordonnee &coordonnee);
        void SetRayon(int x, int y, Rayon &rayon);

    private:

        Pixel *pixels; // good storage method ?
        Rayon *rayons; // good ?
        // Coordonnee *centre_pixels; // good storage method ? Filled how ?
        Resolution resolution;

};

#endif