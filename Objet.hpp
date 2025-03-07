#ifndef OBJET_H
#define OBJET_H

#include <vector>
#include "Triangle.hpp"
#include "Materiau.hpp"
#include "Vecteur.hpp"

typedef int raytracingUsefulInfo;

class Objet{

    public:
        Objet();
        Objet(Objet &objet);
        Objet(std::vector<Triangle> elements);
        Objet(Materiau materiau);
        Objet(std::vector<Triangle> elements, Materiau materiau);

        // std::vector<raytracingUsefulInfo> Intersection(Vecteur vecteur);

    protected:
        std::vector<Triangle> elements; 
        Materiau materiau;
};

#endif
