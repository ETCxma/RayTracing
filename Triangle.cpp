#include "Triangle.hpp"

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
		*(this->points + i) = *(points + i); 
	}
	this->materiau = Materiau(mat); 
}

Triangle::Triangle(Triangle& t){
	for(int i=0; i<3; i++){
		*(this->points + i) = *(t.points + i); 
	}
}