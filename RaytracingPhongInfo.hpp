#ifndef RaytracingSimpleInfo_H
#define RaytracingSimpleInfo_H

#include "Coordonnee.hpp"
#include "Vecteur.hpp"

class RaytracingSimpleInfo{
    
    public:
        RaytracingSimpleInfo();
        RaytracingSimpleInfo(bool intersection);
        RaytracingSimpleInfo(bool intersection, Vecteur normale, Vecteur lumiere_to_objet, Vecteur lumiere_to_objet_reflechi, Vecteur camera_to_objet);
    
        bool intersection;
        Vecteur normale, lumiere_to_objet, lumiere_to_objet_reflechi, camera_to_objet;

};

#endif