#ifndef POINT_H
#define POINT_H

#include "Couleur.hpp"
#include "Coordonnee.cpp"


class Point: public Coordonnee{
    
    private: 
        Couleur couleur; 

    public: 
        // Constructeur
        Point(); 
        Point(Coordonnee point, Couleur couleur); 
        Point(Point& point); 

        // Getter
        Couleur getCouleur() const; 

};




#endif