/**
 * 
 * IMPLÉMENTATION DES MÉTHODES DE Coordonnee.hpp 
 * 
 */

#include "Coordonnee.hpp"

using namespace std; 

// Constructor 
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

// Getters
double Coordonnee::getX(){
    return x; 
}
double Coordonnee::getY(){
    return y; 
}
double Coordonnee::getZ(){
    return z; 
}


// Setters
void Coordonnee::setX(double x){
    this->x = x; 
}
void Coordonnee::setY(double y){
    this->y = y; 
}
void Coordonnee::setZ(double z){
    this->z = z; 
}


// Surcharges
/**
 * OPÉRATEUR "-" POUR DEUX COORDONNÉES
 */
Coordonnee operator-(Coordonnee c1, Coordonnee c2){
    return Coordonnee((c1.getX()-c2.getX()), (c1.getY()-c2.getY()), c1.getZ()-c2.getZ()); 
}

//  Methodes
double Coordonnee::distance(Coordonnee c){
    return sqrt(pow((c.getX() - this->x), 2) + pow((c.getY() - this->y), 2) + pow((c.getZ() - this->z), 2)); 
}