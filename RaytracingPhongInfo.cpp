#include "RaytracingPhongInfo.hpp"

RaytracingPhongInfo::RaytracingPhongInfo(){
    this->intersection = false;
    this->distance = MAXFLOAT;
    this->normale = Vecteur();
    this->objet_to_camera = Vecteur();
    this->objet_to_lumiere = Vecteur();
    this->objet_to_lumiere_reflechi = Vecteur();
}

RaytracingPhongInfo::RaytracingPhongInfo(bool intersection){
    this->intersection = intersection;
    this->distance = MAXFLOAT;
    this->normale = Vecteur();
    this->objet_to_camera = Vecteur();
    this->objet_to_lumiere = Vecteur();
    this->objet_to_lumiere_reflechi = Vecteur();
}

RaytracingPhongInfo::RaytracingPhongInfo(bool intersection, double distance, Vecteur normale, Vecteur objet_to_lumiere, Vecteur objet_to_lumiere_reflechi, Vecteur objet_to_camera){
    this->intersection = intersection;
    this->distance = distance;
    this->normale = normale;
    this->objet_to_camera = objet_to_camera;
    this->objet_to_lumiere = objet_to_lumiere;
    this->objet_to_lumiere_reflechi = objet_to_lumiere_reflechi;
}
