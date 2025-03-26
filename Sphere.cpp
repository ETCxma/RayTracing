#include "Sphere.hpp"
#include "Coordonnee.hpp"
using namespace std;


// Constructor :
Sphere::Sphere(Coordonnee c, double r, Materiau m){
    centre = c;
    rayon = r;
    materiau = m;
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
}

RaytracingSimpleInfo Sphere::intersection(Rayon rayon, Coordonnee centre_camera){
    double t1, t2;
    
    
    Vecteur v = Vecteur(this->centre, centre_camera);
    double vdotd = v.produitScalaire(rayon);
    
    // std::cout << vdotd << std::endl;
    
    double delta = sqrt(vdotd*vdotd - (v.norme()*v.norme() - this->rayon*this->rayon));
    
    // std::cout << vdotd*vdotd - (v.norme()*v.norme() - this->rayon*this->rayon) << std::endl;
    // std::cout << delta << std::endl;
    
    if(delta > 0){
        Vecteur n;
        Vecteur y;
        Vecteur x;
        Vecteur r;
        
        t1 = -vdotd + delta;
        t2 = -vdotd - delta;

        // std::cout << t1 << std::endl;
        // std::cout << t2 << std::endl;
                
        if(t1 < t2){
            y = (rayon*t1 + centre_camera);
        }
        else{
            y = (rayon*t2 + centre_camera);
        }
        n = (y - this->centre).unitaire();
        r = rayon - (n*n.produitScalaire(rayon)*2);
        r = r.unitaire();


        // y.afficheVecteur("y");
        // n.afficheVecteur("n");
        // r.afficheVecteur("r");


        return 1;
    }
    else
        return 0;
}


RaytracingPhongInfo Sphere::intersectionPhong(Rayon rayon, Coordonnee centre_camera, Coordonnee position_lumiere){
    double t1, t2;
    RaytracingPhongInfo ret(false);
    
    
    Vecteur v = Vecteur(this->centre, centre_camera);
    double vdotd = v.produitScalaire(rayon);
    
    double delta = sqrt(vdotd*vdotd - (v.norme()*v.norme() - this->rayon*this->rayon));
    
    if(delta > 0){
        Vecteur n;
        Vecteur y;
        Vecteur x;
        Vecteur r;

        t1 = -vdotd + delta;
        t2 = -vdotd - delta;

        if(t1 < t2){
            y = (rayon*t1 + centre_camera);
        }
        else{
            y = (rayon*t2 + centre_camera);
        }
        n = (y - this->centre).unitaire();
        r = rayon - (n*n.produitScalaire(rayon)*2);
        r = r.unitaire();


        ret.intersection = true;
        ret.normale = n;
        ret.objet_to_camera = (-y).unitaire();
        ret.objet_to_lumiere = Vecteur(y.getVecteur(), position_lumiere).unitaire();
        ret.objet_to_lumiere_reflechi = -ret.objet_to_lumiere + (n*n.produitScalaire(ret.objet_to_lumiere)*2);

    }
    return ret;
}
