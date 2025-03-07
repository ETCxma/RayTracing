#include "Triangle.hpp"

/*
	va pu servir, l'implémentation sert à r...
*/

Triangle::Triangle(){
	this->c[0] = Coordonnee(0,0,0);
	this->c[1] = Coordonnee(0,0,0);
	this->c[2] = Coordonnee(0,0,0);
};

Triangle::Triangle(Coordonnee c1, Coordonnee c2, Coordonnee c3){
	this->c[0] = c1;
	this->c[1] = c2;
	this->c[2] = c3;
};