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


// CONSTRUCTEURS

Vecteur::Vecteur(){
	dx = 0.0;
	dy = 0.0;
	dz = 0.0;
}

Vecteur::Vecteur(double dx=0.0, double dy=0.0, double dz=0.0){
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

double Vecteur::norme(){
	return sqrt(pow(this->getDX(), 2) + pow(this->getDY(), 2) + pow(this->getDZ(), 2)); 
}

Vecteur Vecteur::unitaire(){
	if(norme() == 0.0){
		throw runtime_error("Le vecteur nul ne peut pas être normalisé."); 
	}
	else{
		return (*this)*(1.0/norme()); 
	}
}

double Vecteur::produitScalaire(Vecteur &v){
	return ((this->dx)*(v.getDX()) + (this->dy)*(v.getDY()) + (this->dz)*(v.getDZ())); 
}

Vecteur Vecteur::produitVectoriel(Vecteur &v){
	Coordonnee v1 = vecteur();
	Coordonnee v2 = v.vecteur();
	// Si v1 et v2 sont colinéaires, le produit vectoriel est nul
	// On peut donc retourner un vecteur nul
	
	/* à la base c'était ça, mais ça ne marche que si les deux vecteurs ont EXACTEMENT les mêmes coordonnées */
	// if(v1.getX() == v2.getX() && v1.getY() == v2.getY() && v1.getZ() == v2.getZ()){ 
	//faudrait faire en sorte que ça marche -- en divisant systématiquement par la norme -- avec une sorte de "tolérance" pr les err de calcul
	double n1 = norme();
	double n2 = v.norme();
	
	/* Mtn faut implémenter les tolérances */
	// if( (v1.getX()/n1 == v2.getX()/n2)
	//  && (v1.getY()/n1 == v2.getY()/n2)
	//  && (v1.getZ()/n1 == v2.getZ()/n2)){

	/* Comme ça, ça devrait marcher. À TESTER */
	double tol = 1e-6;
	if (((v1.getX()/n1 - v2.getX()/n2) <= tol)
	 && ((v1.getY()/n1 - v2.getY()/n2) <= tol)
	 && ((v1.getZ()/n1 - v2.getZ()/n2) <= tol)){
		return Vecteur();
	}
	// Si v1 et v2 ne sont pas colinéaires, on peut calculer le produit vectoriel
	return Vecteur	(Coordonnee(x1.getX(), x1.getY(), x1.getZ()), //base aux coordonnées de base du vecteur 
					Coordonnee(	x1.getX() + v1.getY()*v2.getZ() - v1.getZ()*v2.getY(),
								x1.getY() + v1.getZ()*v2.getX() - v1.getX()*v2.getZ(), 
								x1.getZ() + v1.getX()*v2.getY() - v1.getY()*v2.getX()
					)
				);
}

double Vecteur::angle(Vecteur &v){
	return acos(produitScalaire(v)*(1.0/(norme()*v.norme())));
}

Vecteur Vecteur::cartesienToSpherique(){
	double r = 0.0;
	double theta = 0.0;
	double phi = 0.0;

	r = norme();
	theta = acos((this->dz)/r); 
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

