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