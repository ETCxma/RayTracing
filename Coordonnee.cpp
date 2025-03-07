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

Coordonnee::Coordonnee(Coordonnee &c){
    this->x = move(c.getX()); 
    this->y = move(c.getY());
    this->z = move(c.getZ());
}

// Copie
Coordonnee::Coordonnee(Coordonnee& copie){
    copie.x = this->x; 
    copie.y = this->y;
    copie.z = this->z;
}


//  MÉTHODES 

double Coordonnee::distance(Coordonnee c){
    // double dx = c.getX() - this->x; 
    // double dy = c.getY() - this->y;
    // double dz = c.getZ() - this->z;
    return sqrt(pow((c.getX() - this->x), 2) + pow((c.getY() - this->y), 2) + pow((c.getZ() - this->z), 2)); 
}