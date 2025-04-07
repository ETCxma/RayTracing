#include "Triangle.hpp"

//Can't test, waiting for NB to finish Plan

int main(int argc, char* argv[]){

	Point A = Point(Coordonnee(0, 0, 0), Couleur(1.0));
	Point B = Point(Coordonnee(1, 0, 0), Couleur(1.0));
	Point C = Point(Coordonnee(0, 1, 0), Couleur(1.0));
	Materiau mat = Materiau(0.5, 0.5, 0.5, 1.0);
	Point points[3] = {A, B, C};

	Triangle triangle = Triangle(points, mat);
	
	//should be 0 0 0
	std::cout << "Coordonnée du point 1 du triangle : " << "X : " << triangle.getPoint(0).getX() << "; Y : " << triangle.getPoint(0).getY() << "; Z : " << triangle.getPoint(0).getZ() << std::endl;
	//should be 1 0 0
	std::cout << "Coordonnée du point 2 du triangle : " << "X : " << triangle.getPoint(1).getX() << "; Y : " << triangle.getPoint(1).getY() << "; Z : " << triangle.getPoint(1).getZ() << std::endl;
	//should be 0 1 0
	std::cout << "Coordonnée du point 3 du triangle : " << "X : " << triangle.getPoint(2).getX() << "; Y : " << triangle.getPoint(2).getY() << "; Z : " << triangle.getPoint(2).getZ() << std::endl;

	// Should be sqrt(2) 
	std::cout << "Aire du triangle: " << triangle.Aire() << std::endl;
	

	return 0;
}