#include "Point.hpp" 

using namespace std; 



// Constructeur 

Point::Point(): Coordonnee(){
    this->couleur = Couleur(); 
}

Point::Point(Coordonnee point, Couleur couleur): Coordonnee(point){
    this->couleur = couleur; 
}

Point::Point(Point& point): Coordonnee(point.getX(), point.getY(), point.getZ()){
    this->couleur = point.couleur; 
}

