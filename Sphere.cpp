#include "Sphere.hpp"
#include "Coordonnee.hpp"
using namespace std;


// Constructor :
Sphere::Sphere(Coordonnee c, double r){
    centre = c;
    rayon = r;
}

// Getters
int Sphere::get_rayon(){
    return rayon;
}
Coordonnee Sphere::get_centre(){
    return centre;  
}

// Setters
void Sphere::set_rayon(double r){
    rayon = r;
}

void Sphere::set_centre(Coordonnee c){  
    centre = c;
}

// Afficher les informations d'une sphère
void Sphere::Affich_Infos(){
    cout << "Informations de la Sphere : " << endl << "rayon = " << rayon << " / " << "centre = (" << centre.getX() << ", " << centre.getY() << ", " << centre.getZ() << ")"<< endl; 
}
