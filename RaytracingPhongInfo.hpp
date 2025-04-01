#ifndef RaytracingPhongInfo_H
#define RaytracingPhongInfo_H

#include "Coordonnee.hpp"
#include "Vecteur.hpp"

// https://en.wikipedia.org/wiki/Phong_reflection_model
class RaytracingPhongInfo{
    
    public:
        RaytracingPhongInfo();
        RaytracingPhongInfo(bool intersection);
        RaytracingPhongInfo(bool intersection, Vecteur normale, Vecteur objet_to_lumiere, Vecteur objet_to_lumiere_reflechi, Vecteur objet_to_camera);
    
        bool intersection;
        Vecteur normale, objet_to_lumiere, objet_to_lumiere_reflechi, objet_to_camera;

};

#endif