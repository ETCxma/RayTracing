#ifndef COORDONNEE_H
#define COORDONNEE_H

#include <iostream>
#include <cmath>

class Coordonnee{
    public:
        Coordonnee();
        Coordonnee(double x, double y, double z);
        Coordonnee(Coordonnee &c);

        // Constructeur de copie
        // Coordonnee(Coordonnee& copie); 

        double distance(Coordonnee c);

        // Getter
        double getX() const; 
        double getY() const; 
        double getZ() const; 

        // Setter
        void setX(double x);
        void setY(double y);
        void setZ(double z); 
    
    private:
        double x,y,z;
};



#endif