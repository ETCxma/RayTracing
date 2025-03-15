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

Vecteur::Vecteur(Coordonnee x1, Coordonnee x2){
	this->dx = x2.getX() - x1.getX();
	this->dy = x2.getY() - x1.getY();
	this->dz = x2.getZ() - x1.getZ();
}


Vecteur::Vecteur(double dx, double dy, double dz){
	this->dx = dx;
	this->dy = dy;
	this->dz = dz; 
}

Vecteur::Vecteur(Vecteur &v){
	this->dx = v.dx;
	this->dy = v.dy;
	this->dz = v.dz;		
}


// SURCHARGES

/**
 * OPÉRATEUR "+" POUR DEUX VECTEURS EN COORDONNÉES CARTÉSIENNES
 */
// Vecteur operator+(Vecteur &v, Vecteur &v2){
// 	return Vecteur((v.dx + v2.getDX()), (v.dy + v2.getDY()), (v.dz + v2.getDZ()));
// }

Vecteur operator+(Vecteur v, Vecteur v2){
	return Vecteur((v.getDX() + v2.getDX()), (v.getDY() + v2.getDY()), (v.getDZ() + v2.getDZ()));
}

/**
 * OPÉRATEUR "-" POUR DEUX VECTEURS EN COORDONNÉES CARTÉSIENNES
 */
// Vecteur operator-(Vecteur &v, Vecteur &v2){
// 	return Vecteur((v.dx - v2.getDX()), (v.dy - v2.getDY()), (v.dz - v2.getDZ()));
// }

Vecteur operator-(Vecteur v, Vecteur v2){
	return Vecteur((v.getDX() - v2.getDX()), (v.getDY() - v2.getDY()), (v.getDZ() - v2.getDZ()));
}

/**
 * OPÉRATEUR "*" POUR UN VECTEUR ET UN SCALAIRE EN COORDONNÉES CARTÉSIENNES
 */
Vecteur operator*(Vecteur v, double scalaire){
	return Vecteur(scalaire*(v.dx), scalaire*(v.dy), scalaire*(v.dz)); 
}

/**
 * OPÉRATEUR "*" POUR UN VECTEUR ET UN SCALAIRE EN COORDONNÉES CARTÉSIENNES
 */
Vecteur operator*(Vecteur v, int scalaire){
	return Vecteur(scalaire*(v.dx), scalaire*(v.dy), scalaire*(v.dz)); 
}

/**
 * OPÉRATEUR "-" D'INVERSION
 */
Vecteur operator-(Vecteur &v){
	return Vecteur(-v.dx, -v.dy, -v.dz);
}


// MÉTHODES

void Vecteur::afficheVecteur(string nom){
	cout << nom << " = (" << this->dx << "," << this->dy << "," << this->dz << ")" << endl; 
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
	if(this->dy == 0.0)
		phi = 0; 
	else
		phi = copysign(1.0, this->dy)*acos((this->dx)/sqrt(this->dx*this->dx + this->dy*this->dy));

	return Vecteur(r, theta, phi); 
}

Vecteur Vecteur::spheriqueToCartesien(){
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;

	x = (this->dx)*sin(this->dy)*cos(this->dz);
	y = (this->dx)*sin(this->dy)*sin(this->dz); 
	z = (this->dx)*cos(this->dy);
	
	return Vecteur(x, y, z); 
}

void Vecteur::rotationTheta(double angle){
	Vecteur temp = cartesienToSpherique(); 
	temp.setDY(temp.getDY()+angle); 
	temp = temp.spheriqueToCartesien(); 
	setDX(temp.getDX());
	setDY(temp.getDY());
	setDZ(temp.getDZ());
}

void Vecteur::rotationPhi(double angle){
	Vecteur temp = cartesienToSpherique(); 
	temp.setDZ(temp.getDZ()+angle); 
	temp = temp.spheriqueToCartesien(); 
	setDX(temp.getDX());
	setDY(temp.getDY());
	setDZ(temp.getDZ());	
}

