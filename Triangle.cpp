#include "Triangle.hpp"

using namespace std; 

Triangle::Triangle(){
	for(int i=0; i<3; i++){
		this->points[i] = Point(); 
	}
}

// Triangle::Triangle(Point* points){

// }

// Triangle::Triangle(Triangle& t){

// }