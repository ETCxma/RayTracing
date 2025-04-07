#include "Sphere.hpp"
#include "Coordonnee.hpp"
using namespace std;


// Constructor :
Sphere::Sphere(Coordonnee c, double r,const  Materiau& m){
    centre = c;
    rayon = r;
    this->setMateriau(m);
}

// Getters
int Sphere::getRayon(){
    return rayon;
}
Coordonnee Sphere::getCentre(){
    return centre;  
}

// Setters
void Sphere::setRayon(double r){
    rayon = r;
}

void Sphere::setCentre(Coordonnee c){  
    centre = c;
}

// Afficher les informations d'une sphère
void Sphere::affichInfos(){
    cout << "Informations de la Sphere : " << endl << "rayon = " << rayon << " / " << "centre = (" << centre.getX() << ", " << centre.getY() << ", " << centre.getZ() << ")"<< endl; 
    cout << "Materiau : alpha = " << this->getAlpha() << "/ i_s = " <<this->getIndiceSpecular() << "/ i_d = " << this->getIndiceDiffuse() << "/ i_a = " << this->getIndiceAmbient() << endl; 
}

// https://en.wikipedia.org/wiki/Ray_tracing_(graphics)#Example
RaytracingSimpleInfo Sphere::intersection(Rayon rayon, Coordonnee centre_camera){
    double t1, t2;
    
    
    Vecteur v = Vecteur(this->centre, centre_camera);
    double vdotd = v.produitScalaire(rayon);
    
    double delta = sqrt(vdotd*vdotd - (v.norme()*v.norme() - this->rayon*this->rayon));
    
    if(delta > 0){
        Vecteur normale; // Normale
        Vecteur intersect; // Vecteur d'intersection
        Vecteur reflected; // Rayon réfléchi
        
        t1 = -vdotd + delta;
        t2 = -vdotd - delta;

        // std::cout << t1 << std::endl;
        // std::cout << t2 << std::endl;
                
        if(t1 < t2){
            intersect = (rayon*t1 + centre_camera);
        }
        else{
            intersect = (rayon*t2 + centre_camera);
        }
        normale = (intersect - this->centre).unitaire();
        reflected = rayon - (normale*normale.produitScalaire(rayon)*2);
        reflected = reflected.unitaire();

        return 1;
    }
    else
        return 0;
}

// https://en.wikipedia.org/wiki/Phong_reflection_model
RaytracingPhongInfo Sphere::intersectionPhong(Rayon rayon, Coordonnee centre_camera, Coordonnee position_lumiere){
    double t1, t2;
    RaytracingPhongInfo ret(false);
    
    
    Vecteur v = Vecteur(this->centre, centre_camera);
    double vdotd = v.produitScalaire(rayon);
    
    double delta = sqrt(vdotd*vdotd - (v.norme()*v.norme() - this->rayon*this->rayon));
    
    if(delta > 0){
        ret.intersection = true;

        Vecteur normale; // Normale
        Vecteur intersect; // Vecteur d'intersection
        Vecteur reflected; // Rayon réfléchi

        t1 = -vdotd + delta;
        t2 = -vdotd - delta;

        if(t1 < t2){
            intersect = (rayon*t1 + centre_camera);
            ret.distance = t1;
        }
        else{
            intersect = (rayon*t2 + centre_camera);
            ret.distance = t2;
        }
        normale = (intersect - this->centre).unitaire();
        reflected = rayon - (normale*normale.produitScalaire(rayon)*2);
        reflected = reflected.unitaire();


        ret.normale = normale;
        ret.objet_to_camera = (-intersect).unitaire();
        ret.objet_to_lumiere = Vecteur(intersect.getVecteur(), position_lumiere).unitaire();
        ret.objet_to_lumiere_reflechi = -ret.objet_to_lumiere + (normale*normale.produitScalaire(ret.objet_to_lumiere)*2);

    }
    return ret;
}
