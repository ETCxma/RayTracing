#ifndef OBJET_H
#define OBJET_H

#include <vector>
#include "Coordonnee.hpp"
#include "Materiau.hpp"
#include "Rayon.hpp"
#include "raytracingPhongInfo.hpp"

// TODO : figure out
// For example can be multiple rays that spawn from initial ray with different intensity values
typedef int raytracingSimpleInfo;

class Objet{

    public:
        // Objet();

        virtual raytracingSimpleInfo intersection(Rayon rayon, Coordonnee centre_camera) = 0;
        virtual raytracingPhongInfo intersectionPhong(Rayon rayon, Coordonnee centre_camera) = 0;

        double getIndiceSpectular();
        double getIndiceDiffuse();
        double getIndiceAmbient();

    protected:
        Materiau materiau;
        std::vector<Objet> objets;
};

#endif
