#include "Triangle.hpp"
#define TOLERANCE 1e-6

using namespace std; 



// CONSTRUCTEURS

Triangle::Triangle(){
	for(int i=0; i<3; i++){
		(this->points)[i] = Point(); 
	}
	this->materiau = Materiau(); 
}

Triangle::Triangle(Point* points, Materiau mat){
	for(int i=0; i<3; i++){
		this->points[i] = *(points + i); 
	}
	this->materiau = Materiau(mat); 
}

Triangle::Triangle(Point A, Point B, Point C){
	(this->points[0]) = A;
	(this->points[1]) = B;
	(this->points[2]) = C;
	// Matériau de base
	this->materiau = Materiau();
	// cast Point A -> Coordonnee A (B,C idem)
	this->plan = Plan(Coordonnee(A), Coordonnee(B), Coordonnee(C));
}

Triangle::Triangle(Triangle& t){
	for(int i=0; i<3; i++){
		this->points[i] = t.points[i]; 
	}
}

Plan Triangle::getPlan(){
	//automatically set plan with points

	//return plan
	return this->plan;
};

Point Triangle::getPoint(int n){
	if ((n < 0) | (n > 2)){
		return;
	}
	else{
		return this->points[n]; 
	}
};

double Triangle::Aire(){
	return 1/2 * this->getPlan().vecteurNormal().norme();
};

bool Triangle::intersection(Rayon rayon){
	// P point d'intersection entre le rayon et le plan.
		// -> à faire
	Point P;
	// 3 vecteurs : AP BP CP
	// Points du triangle : A,B,C
	
	Vecteur AP = Vecteur(this->getPoint(0), P);
	Vecteur BP = Vecteur(this->getPoint(1), P);
	Vecteur CP = Vecteur(this->getPoint(2), P);

	// 3 triangles : PBC, PCA, PAB
	Triangle PBC = Triangle(P, this->getPoint(1), this->getPoint(2));
	Triangle PCA = Triangle(P, this->getPoint(2), this->getPoint(0));
	Triangle PAB = Triangle(P, this->getPoint(0), this->getPoint(1));

	double S_PBC = PBC.Aire();
	double S_PCA = PCA.Aire();
	double S_PAB = PAB.Aire();

	double alpha = S_PBC/this->Aire();
	double beta = S_PCA / this->Aire();
	double gamma = S_PAB / this->Aire();

	if ( // 1⩾α⩾0 ; 1⩾β⩾0 ; 1⩾γ⩾0  
		((1 >= alpha) && (alpha >= 0) &&
		(1 >= beta) && (beta >= 0) &&
		(1 >= gamma) && (gamma >= 0))
		&&
		// α+β+γ = 1 (à la tolérance près)
		((1.0+TOLERANCE >= alpha + beta + gamma) &&
		(alpha + beta + gamma >= 1.0-TOLERANCE))){
			return true;
	}
	else{
			return false;
	}
	
};