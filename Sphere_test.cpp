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
<<<<<<< HEAD
    Henri.affichInfos();

    Henri.setRayon(5);
    Coordonnee coor2 (3, 3, 4);
    Henri.setCentre(coor2);
    Henri.affichInfos();
=======
    Henri.Affich_Infos();

    Henri.set_rayon(5);
    Coordonnee coor2 (3, 3, 4);
    Henri.set_centre(coor2);
    Henri.Affich_Infos();
>>>>>>> main

    return 0;
}
