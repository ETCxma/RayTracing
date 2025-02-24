#ifndef COORDONNEE_H
#define COORDONNEE_H

class Coordonnee{
    public:
        Coordonnee();
        Coordonnee(double x, double y, double z);
        Coordonnee(Coordonnee &c);

        double distance(Coordonnee c);
    
    private:
        double x,y,z;
};



#endif