#include "Triangle.hpp"

int main(int argc, char* argv[]){

	Point A = Point(Coordonnee(0, 0, 0), Couleur(1.0));
	Point B = Point(Coordonnee(1, 0, 0), Couleur(1.0));
	Point C = Point(Coordonnee(0, 1, 0), Couleur(1.0));
	Materiau mat = Materiau(0.5, 0.5, 0.5, 1.0);
	Point points[3] = {A, B, C};

	Triangle triangle = Triangle(points, mat);
	
	// Should be sqrt(2) 
	std::cout << "Aire du triangle: " << triangle.Aire() << std::endl;
	

	return 0;
}