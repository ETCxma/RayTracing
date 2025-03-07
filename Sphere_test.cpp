/**
 * 
 * FICHIER TEST DES MÉTHODES DE Sphere.hpp
 * 
*/

#include "Sphere.hpp"
#include "Coordonnee.hpp"
using namespace std;


int main(){

    Coordonnee coor1 (1, 1, 1);
    Sphere Henri (coor1, (double)10);
    Henri.affichInfos();

    Henri.setRayon(5);
    Coordonnee coor2 (3, 3, 4);
    Henri.setCentre(coor2);
    Henri.affichInfos();

    return 0;
}
