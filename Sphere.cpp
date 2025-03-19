#include "Sphere.hpp"
#include "Coordonnee.hpp"
using namespace std;


// Constructor :
Sphere::Sphere(Coordonnee c, double r){
    centre = c;
    rayon = r;
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

raytracingUsefulInfo Sphere::intersection(Rayon rayon, Coordonnee centre_camera){
    double t1, t2;
    
    
    Vecteur v = Vecteur(this->centre - centre_camera);
    double vdotd = v.produitScalaire(rayon);
    
    double delta = sqrt(vdotd*vdotd - (v*v - this->centre*this->centre));
    
    if(delta >= 0.0){
        Vecteur n1, n2;
        Vecteur y1, y2;
        Vecteur x1, x2;

        Vecteur r;
        
        t1 = -(vdotd) + delta;
        t2 = -(vdotd) - delta;
        y1 = rayon*t1 + centre_camera;
        y2 = rayon*t2 + centre_camera;

        n1 = y1 - this->centre;
        n2 = y2 - this->centre;

        double n1angle = rayon.angle(n1);

        if(n1angle <= 90 || n1angle > 270)
            r = rayon - (n1*n1.produitScalaire(rayon)*2);
        else
            r = rayon - (n2*n2.produitScalaire(rayon)*2);

        

        return 1;
    }
    else
        return 0;
}
