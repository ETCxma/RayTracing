#ifndef ECRAN_H
#define ECRAN_H

#include "Coordonnee.hpp"
#include "Resolution.hpp"
#include "Pixel.hpp"

class Ecran{

    public:
        Ecran();
        Ecran(Ecran &e);
        Ecran(Resolution r);

        void SetPixel(int x, int y, Pixel &pixel);
        void SetCentrePixel(int x, int y, Coordonnee &coordonnee);
        
        // Coordonnee centre(){}; How ?
        // double largeur(); How ?
        // double hauteur(); How ?
       

    private:


        Pixel **pixels; // good storage method ?
        Coordonnee **centre_pixels; // good storage method ? Filled how ?
        Resolution resolution;

};

#endif