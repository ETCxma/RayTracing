#ifndef OBJET_H
#define OBJET_H

#include <vector>
#include "Materiau.hpp"
#include "Rayon.hpp"

// TODO : figure out
// For example can be multiple rays that spawn from initial ray with different intensity values
typedef int raytracingUsefulInfo;

class Objet{

    public:
        Objet();

        virtual raytracingUsefulInfo intersection(Rayon rayon) = 0;

    protected:
        Materiau materiau;
        std::vector<Objet> objets;
};

#endif
