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

Coordonnee Vecteur::getX1(){
	return x1; 
}
Coordonnee Vecteur::getX2(){
	return x2; 
}


// CONSTRUCTEURS

Vecteur::Vecteur(){
	this->x1 = Coordonnee(0,0,0);
	this->x2 = Coordonnee(0,0,0);
}

Vecteur::Vecteur(Coordonnee x1, Coordonnee x2): x1(x1), x2(x2){}

Vecteur::Vecteur(Vecteur &v){
	this->x1 = move(v.getX1());
	this->x2 = move(v.getX2());
}


// MÉTHODES

Coordonnee Vecteur::vecteur(){
	return Coordonnee((x2.getX()-x1.getX()), (x2.getY()-x1.getY()), (x2.getZ()-x1.getZ()));
}

double Vecteur::norme(){
	Coordonnee v = vecteur();
	return sqrt(v.getX()*v.getX() + v.getY()*v.getY() + v.getZ()*v.getZ());
}

Vecteur Vecteur::unitaire(){
	Coordonnee v = vecteur(); // donne la direction du vecteur
	double nrm = norme(); // ce par quoi on va diviser les coords
	return Vecteur(Coordonnee(x1.getX(), x1.getY(), x1.getZ()), 
					Coordonnee	(x1.getX() + v.getX()/nrm, 
								x1.getY() + v.getY()/nrm, 
								x1.getZ() + v.getZ()/nrm)
					);
};


double Vecteur::produitScalaire(Vecteur &v){
	Coordonnee v1 = vecteur();
	Coordonnee v2 = v.vecteur();
	return 	v1.getX()*v2.getX() + 
			v1.getY()*v2.getY() + 
			v1.getZ()*v2.getZ();
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
	return std::acos(produitScalaire(v)/    // <u,v> /
				(norme()*v.norme()));  		// ||u||*||v||
}

