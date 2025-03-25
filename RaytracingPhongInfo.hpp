#ifndef RaytracingPhongInfo_H
#define RaytracingPhongInfo_H

#include "Coordonnee.hpp"
#include "Vecteur.hpp"

class RaytracingPhongInfo{
    
    public:
        RaytracingPhongInfo();
        RaytracingPhongInfo(bool intersection);
        RaytracingPhongInfo(bool intersection, Vecteur normale, Vecteur lumiere_to_objet, Vecteur lumiere_to_objet_reflechi, Vecteur camera_to_objet);
    
        bool intersection;
        Vecteur normale, lumiere_to_objet, lumiere_to_objet_reflechi, camera_to_objet;

};

#endif