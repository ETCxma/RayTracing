/**
 * 
 * IMPLÉMENTATION DES MÉTHODES DE Vecteur.hpp 
 * 
 */

#include "Vecteur.hpp"
/*
TODO: 
	- Coodonnee &Intersection(Objet &o); (see header)
	- tests du produit vectoriel
*/

using namespace std; 


// GETTERS
double Vecteur::getDX(){
	return this->dx; 
}
double Vecteur::getDY(){
	return this->dy; 
}
double Vecteur::getDZ(){
	return this->dz; 
} 

// SETTERS
void Vecteur::setDX(double x){
	this->dx = x;
}
void Vecteur::setDY(double y){
	this->dy = y;
}
void Vecteur::setDZ(double z){
	this->dz = z;
}


// CONSTRUCTEURS

Vecteur::Vecteur(){
	dx = 0.0;
	dy = 0.0;
	dz = 0.0;
}

Vecteur::Vecteur(double dx, double dy, double dz){
	this->dx = dx;
	this->dy = dy;
	this->dz = dz; 
}

Vecteur::Vecteur(Vecteur &v){
	this->dx = move(v.getDX());
	this->dy = move(v.getDY());
	this->dz = move(v.getDZ());		
}


// SURCHARGES

/**
 * OPÉRATEUR "+" POUR DEUX VECTEURS EN COORDONNÉES CARTÉSIENNES
 */
Vecteur Vecteur::operator+(Vecteur &v){
	return Vecteur((this->dx + v.getDX()), (this->dy + v.getDY()), (this->dz + v.getDZ()));
}

/**
 * OPÉRATEUR "*" POUR UN VECTEUR ET UN SCALAIRE EN COORDONNÉES CARTÉSIENNES
 */
Vecteur Vecteur::operator*(double scalaire){
	return Vecteur(scalaire*(this->dx), scalaire*(this->dy), scalaire*(this->dz)); 
}



// MÉTHODES

void Vecteur::afficheVecteur(string nom){
	cout << nom << " = (" << this->dx << "," << this->dy << "," << this->dz << ")"; 
}

double Vecteur::norme(){
	return sqrt(pow(this->getDX(), 2) + pow(this->getDY(), 2) + pow(this->getDZ(), 2)); 
}

Vecteur Vecteur::unitaire(){
	if(norme() == 0.0){
		return Vecteur(0.0, 0.0, 0.0); 
	}
	else{
		return (*this)*(1.0/norme()); 
	}
}

double Vecteur::produitScalaire(Vecteur &v){
	return ((this->dx)*(v.getDX()) + (this->dy)*(v.getDY()) + (this->dz)*(v.getDZ())); 
}

Vecteur Vecteur::produitVectoriel(Vecteur &v){
	return Vecteur(((this->dy)*v.getDZ() - v.getDY()*(this->dz)), 
					((this->dz)*v.getDX() - v.getDZ()*(this->dx)),
					((this->dx)*v.getDY() - v.getDX()*(this->dy))); 
}

Vecteur Vecteur::cartesienToSpherique(){
	double r = 0.0;
	double theta = 0.0;
	double phi = 0.0;

	r = norme();
	theta = acos(((this->dz))/r); 
	phi = asin((this->dy)/(r*sin(theta))); 

	return Vecteur(r, theta, phi); 
}

Vecteur Vecteur::spheriqueToCartesien(){
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;

	x = (this->dx)*cos(this->dy)*sin(this->dz);
	y = (this->dx)*sin(this->dy)*sin(this->dz); 
	z = (this->dx)*cos(this->dz);
	
	return Vecteur(x, y, z); 
}

void Vecteur::rotationTheta(double angle){
	Vecteur temp = cartesienToSpherique(); 
	temp.setDY(temp.getDY()+angle); 
	setDX(temp.getDX());
	setDY(temp.getDY());
	setDZ(temp.getDZ());
}

void Vecteur::rotationPhi(double angle){
	Vecteur temp = cartesienToSpherique(); 
	temp.setDZ(temp.getDZ()+angle); 
	setDX(temp.getDX());
	setDY(temp.getDY());
	setDZ(temp.getDZ());	
}

