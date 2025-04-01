/**
 * 
 * FICHIER TEST DES MÉTHODES DE Espace.hpp
 * 
*/


#include "Espace.hpp"
#include <vector>
#include <string>
#include <fstream>
#include "Vecteur.hpp"
#include "Camera.hpp"
#include "Objet.hpp"
#include "Sphere.hpp"
#include "Materiau.hpp"

using namespace std; 


int main(int argc, char* argv[]){

    Espace Esp;

    Camera cam = Camera(Coordonnee(0, 0, 0), 1, 0, 0, Resolution (1024,1024));
    Esp.AjouterCamera(&cam);
    Lumiere lum = Lumiere(Couleur(1),Coordonnee(6,2,0),1,1,1    );  
    Esp.AjouterLumiere(&lum);
    Coordonnee c = Coordonnee(0,0,10);
    Materiau m1 = Materiau((double)100,(double)200,(double)50,(double)3);
    m1.afficheMateriau();
    Sphere Sph = Sphere(c, 1, m1);
    Sph.affichInfos();
    Esp.AjouterObjet(&Sph);
    Coordonnee c2 = Coordonnee(2,4,10);
    Sphere Sph2 = Sphere(c2, 4, m1);
    Sph2.affichInfos();
    Esp.AjouterObjet(&Sph2);

    // cout << cam.getResolution().getX() << "/" << cam.getResolution().getY() << endl;

    Esp.takePicture(0,string("IMAGE_POGGIES"));

    return 0; 

}   