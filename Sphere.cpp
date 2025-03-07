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


// Pour tester le code
// int main(){

//     Coordonnee coor1 (1, 1, 1);
//     Sphere Henri ( coor1, (double)10);
//     Henri.Affich_Infos();
//     Henri.set_rayon(5);
//     Coordonnee coor2 (3, 3, 4);
//     Henri.set_centre(coor2);
//     Henri.Affich_Infos();

//     return 0;
// }
