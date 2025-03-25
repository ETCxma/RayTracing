#include "Couleur.hpp"

Couleur::Couleur(){
	this->intensite = 0;
};

Couleur::Couleur(Couleur &Couleur){
	this->intensite = Couleur.getIntensite();
};

Couleur::Couleur(double intensite): intensite(intensite){};

double Couleur::getIntensite(){
	return this->intensite;
}

void Couleur::setIntensite(double intensite){
	this->intensite = intensite;
}

void Couleur::addIntensite(double intensite){
	this->intensite += intensite;
}
