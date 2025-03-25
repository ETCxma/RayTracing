
#include "Sphere.hpp"



int main(){
    
    Sphere s = Sphere(Coordonnee(10,3,2), 4.0);
    Rayon r = Rayon(Coordonnee(0,0,0), Coordonnee(1,0,0.2));

    std::cout << s.intersection(r, Coordonnee(0,0,0)) << std::endl;
    
    return 0;

}