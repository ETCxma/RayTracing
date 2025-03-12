/**
 * 
 * IMPLÉMENTATION DES MÉTHODES DE Coordonnee.hpp 
 * 
 */

#include "Coordonnee.hpp"

using namespace std; 


// GETTERS

double Coordonnee::getX() const{
    return x; 
}
double Coordonnee::getY() const{
    return y; 
}
double Coordonnee::getZ() const{
    return z; 
}


// SETTERS

void Coordonnee::setX(double x){
    this->x = x; 
}
void Coordonnee::setY(double y){
    this->y = y; 
}
void Coordonnee::setZ(double z){
    this->z = z; 
}


// CONSTRUCTEURS 

Coordonnee::Coordonnee(){
    x = 0.0;
    y = 0.0;
    z = 0.0; 
}

Coordonnee::Coordonnee(double x, double y, double z){
    this->x = x;
    this->y = y; 
    this->z = z; 
}

// Copie
Coordonnee::Coordonnee(Coordonnee& coordonnee){
    this->x = coordonnee.x; 
    this->y = coordonnee.y;
    this->z = coordonnee.z;
}


//  MÉTHODES 

double Coordonnee::distance(Coordonnee c){
    // double dx = c.getX() - this->x; 
    // double dy = c.getY() - this->y;
    // double dz = c.getZ() - this->z;
    return sqrt(pow((c.getX() - this->x), 2) + pow((c.getY() - this->y), 2) + pow((c.getZ() - this->z), 2)); 
}