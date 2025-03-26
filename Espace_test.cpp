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

using namespace std; 


int main(int argc, char* argv[]){

    Espace Esp;

    Camera cam = Camera(Coordonnee(0, 0, 0), 1, 0, 0, Resolution (512,512));
    Esp.AjouterCamera(&cam);
    Lumiere lum = Lumiere(Couleur(1),Coordonnee(5,0,0),1,1,1);
    Esp.AjouterLumiere(&lum);
    Coordonnee c (0,0,10);
    Sphere Sph (c, 1);
    Esp.AjouterObjet(&Sph);
    Coordonnee c2 (2,4,10);
    Sphere Sph2 (c2, 4);
    Esp.AjouterObjet(&Sph2);

    // cout << cam.getResolution().getX() << "/" << cam.getResolution().getY() << endl;

    Esp.takePicture(0,string("IMAGE_POGGIES"));

    return 0; 

}   