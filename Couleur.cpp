#include "Couleur.hpp"

Couleur::Couleur(){
	this->intensité = 0;
};

Couleur::Couleur(Couleur &Couleur){
	this->intensité = Couleur.getIntensite();
};

Couleur::Couleur(double intensité): intensité(intensité){};

double Couleur::getIntensite(){
	return intensité;
}

