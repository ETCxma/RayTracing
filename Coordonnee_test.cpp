/**
 * 
 * FICHIER TEST DES MÉTHODES DE Coordonnee.hpp
 * 
 */


#include "Coordonnee.hpp"

using namespace std; 


int main(int argc, char* argv[]){

    Coordonnee a; 
    Coordonnee b(1, 2, 3); 
    Coordonnee c(4, 5, 6);
    Coordonnee d(c); 

    cout << "A(" << a.getX() << ", " << a.getY() << ", " << a.getZ() << ")" << endl; 
    cout << "B(" << b.getX() << ", " << b.getY() << ", " << b.getZ() << ")" << endl;
    cout << "C(" << c.getX() << ", " << c.getY() << ", " << c.getZ() << ")" << endl; 
    cout << "D(" << d.getX() << ", " << d.getY() << ", " << d.getZ() << ")" << endl; 

    cout << "d(A, B) = " << a.distance(b) << " = " << b.distance(a) << endl; 
    cout << "d(C, B) = " << c.distance(b) << " = " << b.distance(c) << endl; 

    return 0; 

}