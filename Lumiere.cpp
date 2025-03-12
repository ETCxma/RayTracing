/**
 * 
 * IMPLÉMENTATION DES MÉTHODES DE Vecteur.hpp 
 * 
 */

 #include "Lumiere.hpp"


using namespace std; 


// GETTERS 

int Lumiere::getIntensite(){
    return this->intensite; 
}

Coordonnee Lumiere::getSource(){
    return this->source; 
}


Lumiere::Lumiere(){
    this->intensite = 0;
    (this->source).setX(0.0);
    (this->source).setY(0.0);
    (this->source).setZ(0.0);
}

Lumiere::Lumiere(int intensite, Coordonnee source){
    this->intensite = intensite;
    this->source = source; 
}

Lumiere::Lumiere(Lumiere &l){
    this->intensite = move(l.getIntensite()); 
    this->source = move(l.getSource()); 
}