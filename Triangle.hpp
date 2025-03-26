#ifndef TRIANGLE_H
#define TRIANGLE_H


#include "Point.hpp"
#include "Vecteur.hpp"

class Triangle{

    public:
        // Constructeur
        Triangle(); 
        Triangle(Point* points);        // On lui donne une référence vers un tableau de Points
        Triangle(Triangle& t); 

    private:
        Point points[3]; 
};



#endif