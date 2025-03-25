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
Coordonnee Vecteur::getVecteur(){
	return this->vecteur;
}

double Vecteur::getDX(){
	return this->vecteur.getX(); 
}
double Vecteur::getDY(){
	return this->vecteur.getY(); 
}
double Vecteur::getDZ(){
	return this->vecteur.getZ(); 
} 

// SETTERS
void Vecteur::setDX(double x){
	this->vecteur.setX(x);
}
void Vecteur::setDY(double y){
	this->vecteur.setY(y);
}
void Vecteur::setDZ(double z){
	this->vecteur.setZ(z);
}


// CONSTRUCTEURS

Vecteur::Vecteur(){
	this->vecteur = Coordonnee(0,0,0);
}

Vecteur::Vecteur(Coordonnee coordonnee){
	this->vecteur = Coordonnee(coordonnee.getX(), coordonnee.getY(), coordonnee.getZ());
}

Vecteur::Vecteur(Coordonnee x1, Coordonnee x2){
	this->vecteur = Coordonnee(x2.getX() - x1.getX(),
							   x2.getY() - x1.getY(),
		 					   x2.getZ() - x1.getZ());
}


Vecteur::Vecteur(double dx, double dy, double dz){
	this->vecteur = Coordonnee(dx, dy, dz);
}

Vecteur::Vecteur(Vecteur &v){
	this->vecteur = v.getVecteur();
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
	return Vecteur(scalaire*(v.getDX()), scalaire*(v.getDY()), scalaire*(v.getDZ())); 
}

/**
 * OPÉRATEUR "*" POUR UN VECTEUR ET UN SCALAIRE EN COORDONNÉES CARTÉSIENNES
 */
Vecteur operator*(Vecteur v, int scalaire){
	return Vecteur(scalaire*(v.getDX()), scalaire*(v.getDY()), scalaire*(v.getDZ())); 
}

/**
 * OPÉRATEUR "-" D'INVERSION
 */
Vecteur operator-(Vecteur &v){
	return Vecteur(-v.getDX(), -v.getDY(), -v.getDY());
}

/**
 * OPÉRATEUR "+" ENTRE UN VECTEUR ET UNE COORDONNÉE
 */
Vecteur operator+(Vecteur v, Coordonnee c){
	return Vecteur((v.getDX()+c.getX()), (v.getDY()+c.getY()), (v.getDZ()+c.getZ()));
}

// Vecteur operator+(Vecteur &v, Coordonnee &c){
// 	return Vecteur((v.dx+c.getX()), (v.dy+c.getY()), (v.dz+c.getZ()));
// }

/**
 * OPÉRATEUR "-" ENTRE UN VECTEUR ET UNE COORDONNÉE
 */
Vecteur operator-(Vecteur v, Coordonnee c){
	return Vecteur((v.getDX()-c.getX()), (v.getDY()-c.getY()), (v.getDZ()-c.getZ()));
}

// Vecteur operator-(Vecteur &v, Coordonnee &c){
// 	return Vecteur((v.dx-c.getX()), (v.dy-c.getY()), (v.dz-c.getZ()));
// }


// MÉTHODES

void Vecteur::afficheVecteur(string nom){
	cout << nom << " = (" << this->getDX() << "," << this->getDY() << "," << this->getDZ() << ")" << endl; 
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
	return ((this->getDX())*(v.getDX()) + (this->getDY())*(v.getDY()) + (this->getDZ())*(v.getDZ())); 
}

Vecteur Vecteur::produitVectoriel(Vecteur &v){
	return Vecteur(((this->getDY())*v.getDZ() - v.getDY()*(this->getDZ())), 
					((this->getDZ())*v.getDX() - v.getDZ()*(this->getDX())),
					((this->getDX())*v.getDY() - v.getDX()*(this->getDY()))); 
}

Vecteur Vecteur::cartesienToSpherique(){
	double r = 0.0;
	double theta = 0.0;
	double phi = 0.0;

	r = norme();
	theta = acos(((this->getDZ()))/r); 
	if(this->getDY() == 0.0)
		phi = 0; 
	else
		phi = copysign(1.0, this->getDY())*acos((this->getDX())/sqrt(this->getDX()*this->getDX() + this->getDY()*this->getDY()));

	return Vecteur(r, theta, phi); 
}

Vecteur Vecteur::spheriqueToCartesien(){
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;

	x = (this->getDX())*sin(this->getDY())*cos(this->getDZ());
	y = (this->getDX())*sin(this->getDY())*sin(this->getDZ()); 
	z = (this->getDX())*cos(this->getDY());
	
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


