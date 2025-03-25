#ifndef RAYTRACINGPHONGINFO_H
#define RAYTRACINGPHONGINFO_H

#include "Coordonnee.hpp"
#include "Vecteur.hpp"

class raytracingPhongInfo{
    
    public:
        RaytracingPhongInfo();
        RaytracingPhongInfo(int intersection, Vecteur normale, Vecteur lumiere_to_objet, Vecteur lumiere_to_objet_reflechi, Vecteur camera_to_objet);
    
        int intersection;
        Vecteur normale, lumiere_to_objet, lumiere_to_objet_reflechi, camera_to_objet;

};

#endif