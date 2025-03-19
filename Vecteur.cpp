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
	this->dx = move(v.getDX());
	this->dy = move(v.getDY());
	this->dz = move(v.getDZ());		
}


// SURCHARGES

/**
 * OPÉRATEUR "+" POUR DEUX VECTEURS EN COORDONNÉES CARTÉSIENNES
 */
Vecteur operator+(Vecteur &v, Vecteur &v2){
	return Vecteur((v.dx + v2.getDX()), (v.dy + v2.getDY()), (v.dz + v2.getDZ()));
}

Vecteur operator+(Vecteur v, Vecteur v2){
	return Vecteur((v.getDX() + v2.getDX()), (v.getDY() + v2.getDY()), (v.getDZ() + v2.getDZ()));
}

/**
 * OPÉRATEUR "-" POUR DEUX VECTEURS EN COORDONNÉES CARTÉSIENNES
 */
Vecteur operator-(Vecteur &v, Vecteur &v2){
	return Vecteur((v.dx - v2.getDX()), (v.dy - v2.getDY()), (v.dz - v2.getDZ()));
}

Vecteur operator-(Vecteur v, Vecteur v2){
	return Vecteur((v.getDX() - v2.getDX()), (v.getDY() - v2.getDY()), (v.getDZ() - v2.getDZ()));
}

/**
 * OPÉRATEUR "*" POUR UN VECTEUR ET UN SCALAIRE EN COORDONNÉES CARTÉSIENNES
 */
Vecteur operator*(Vecteur &v, double scalaire){
	return Vecteur(scalaire*(v.dx), scalaire*(v.dy), scalaire*(v.dz)); 
}

/**
 * OPÉRATEUR "*" POUR UN VECTEUR ET UN SCALAIRE EN COORDONNÉES CARTÉSIENNES
 */
Vecteur operator*(Vecteur &v, int scalaire){
	return Vecteur(scalaire*(v.dx), scalaire*(v.dy), scalaire*(v.dz)); 
}

/**
 * OPÉRATEUR "-" POUR DEUX VECTEURS EN COORDONNÉES CARTÉSIENNES
 */
Vecteur operator-(Vecteur &v){
	return Vecteur(-v.dx, -v.dy, -v.dz);
}

/**
 * OPÉRATEUR "*" ENTRE DEUX VECTEURS
 */
Vecteur operator*(Vecteur v1, Vecteur v2){
	return Vecteur((v1.getDX()*v2.getDX()), (v1.getDY()*v2.getDY()), (v1.getDZ()*v2.getDZ()));
}

Vecteur operator*(Vecteur &v1, Vecteur &v2){
	return Vecteur((v1.dx*v2.getDX()), (v1.dy*v2.getDY()), (v1.dz*v2.getDZ()));
}

/**
 * OPÉRATEUR "*" ENTRE UN VECTEUR ET UNE COORDONNÉE
 */
Vecteur operator*(Vecteur v, Coordonnee c){
	return Vecteur((v.getDX()*c.getX()), (v.getDY()*c.getY()), (v.getDZ()*c.getZ()));
}

Vecteur operator*(Vecteur &v, Coordonnee &c){
	return Vecteur((v.dx*c.getX()), (v.dy*c.getY()), (v.dz*c.getZ()));
}

/**
 * OPÉRATEUR "+" ENTRE UN VECTEUR ET UNE COORDONNÉE
 */
Vecteur operator+(Vecteur v, Coordonnee c){
	return Vecteur((v.getDX()+c.getX()), (v.getDY()+c.getY()), (v.getDZ()+c.getZ()));
}

Vecteur operator+(Vecteur &v, Coordonnee &c){
	return Vecteur((v.dx+c.getX()), (v.dy+c.getY()), (v.dz+c.getZ()));
}

/**
 * OPÉRATEUR "-" ENTRE UN VECTEUR ET UNE COORDONNÉE
 */
Vecteur operator-(Vecteur v, Coordonnee c){
	return Vecteur((v.getDX()-c.getX()), (v.getDY()-c.getY()), (v.getDZ()-c.getZ()));
}

Vecteur operator-(Vecteur &v, Coordonnee &c){
	return Vecteur((v.dx-c.getX()), (v.dy-c.getY()), (v.dz-c.getZ()));
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

double Vecteur::angle(Vecteur &v){
	return acos(produitScalaire(v)/(norme()*v.norme())); 
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
	z = (this->dx)*cos(this->dy);
	
	return Vecteur(x, y, z); 
}

void Vecteur::rotationTheta(double angle){
	Vecteur temp = cartesienToSpherique(); 
	temp.setDY(temp.getDY()+angle); 
	temp.spheriqueToCartesien(); 
	setDX(temp.getDX());
	setDY(temp.getDY());
	setDZ(temp.getDZ());
}

void Vecteur::rotationPhi(double angle){
	Vecteur temp = cartesienToSpherique(); 
	temp.setDZ(temp.getDZ()+angle); 
	temp.spheriqueToCartesien(); 
	setDX(temp.getDX());
	setDY(temp.getDY());
	setDZ(temp.getDZ());	
}


