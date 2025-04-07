#ifndef OBJET_H
#define OBJET_H

#include <vector>
#include "Coordonnee.hpp"
#include "Materiau.hpp"
#include "Rayon.hpp"
#include "RaytracingPhongInfo.hpp"

// TODO : figure out
// For example can be multiple rays that spawn from initial ray with different intensity values
typedef int RaytracingSimpleInfo;

class Objet{

    public:
        // Objet();

        virtual RaytracingSimpleInfo intersection(Rayon rayon, Coordonnee centre_camera) = 0;
        virtual RaytracingPhongInfo intersectionPhong(Rayon rayon, Coordonnee centre_camera, Coordonnee position_lumiere) = 0;

        double getIndiceSpecular();
        double getIndiceDiffuse();
        double getIndiceAmbient();
        double getAlpha();

        void setMateriau(const Materiau& mat);

    protected:
        Materiau materiau;
};

#endif
