/**
 * 
 * IMPLÉMENTATION DES MÉTHODES DE Vecteur.hpp 
 * 
 */

 #include "Lumiere.hpp"


using namespace std; 


// GETTERS 

Couleur Lumiere::getIntensite(){
    return this->intensite; 
}

Coordonnee Lumiere::getPosition(){
    return Coordonnee(this->getX(), this->getY(), this->getZ()); 
}

float Lumiere::getIS(){
	return this->i_s;
}

float Lumiere::getID(){
	return this->i_d;
}

float Lumiere::getIA(){
	return this->i_a;
}

// Setteurs.
void Lumiere::setIntensite(Couleur intensite){
	this->intensite = intensite;
}

void Lumiere::setPosition(Coordonnee source){
	this->setX(source.getX());
	this->setY(source.getY());
	this->setZ(source.getZ());
}

void Lumiere::setIS(float i_s){
	this->i_s = i_s;
}

void Lumiere::setID(float i_d){
	this->i_d = i_d;
}

void Lumiere::setIA(float i_a){
	this->i_a = i_a;
}


// Constructeurs.

Lumiere::Lumiere() : Coordonnee(){
    this->intensite = 0.0;
}

Lumiere::Lumiere(Couleur intensite, Coordonnee source, float i_s, float i_d, float i_a): Coordonnee(source){
    this->intensite = intensite;
}

Lumiere::Lumiere(Lumiere &l): Coordonnee(l.getX(), l.getY(), l.getZ()){
    this->intensite = move(l.getIntensite());	
}


void Lumiere::afficheLumiere(){
    cout << "intensité: " << endl;
    
}