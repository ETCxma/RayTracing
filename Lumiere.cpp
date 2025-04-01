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

double Lumiere::getIntensiteSpecular(){
	return this->intensite_specular;
}

double Lumiere::getIntensiteDiffuse(){
	return this->intensite_diffuse;
}

double Lumiere::getIntensiteAmbient(){
	return this->intensite_ambient;
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

void Lumiere::setIntensiteSpecular(double intensite_specular){
	this->intensite_specular = intensite_specular;
}

void Lumiere::setIntensiteDiffuse(double intensite_diffuse){
	this->intensite_diffuse = intensite_diffuse;
}

void Lumiere::setIntensiteAmbient(double intensite_ambient){
	this->intensite_ambient = intensite_ambient;
}


// Constructeurs.

Lumiere::Lumiere() : Coordonnee(){
    this->intensite = 0.0;
}

Lumiere::Lumiere(Couleur intensite, Coordonnee source, double intensite_s, double intensite_d, double intensite_a): Coordonnee(source){
    this->intensite = intensite;
    this->intensite_ambient = intensite_a;
    this->intensite_diffuse = intensite_d;
    this->intensite_specular = intensite_s;
}

Lumiere::Lumiere(Lumiere &l): Coordonnee(l.getX(), l.getY(), l.getZ()){
    this->intensite = move(l.getIntensite());	
}


void Lumiere::afficheLumiere(){
    cout << "intensité: " << endl;
    
}