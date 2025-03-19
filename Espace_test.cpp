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
    Camera cam = Camera(Resolution (512,512));
    Esp.AjouterCamera(&cam);

    Coordonnee c (2,2,2);
    Sphere Sph (c, 1.5);

    Esp.AjouterObjet(&Sph);

    cout << cam.getResolution().getX() << "/" << cam.getResolution().getY() << endl;

    Esp.takePicture(0,string("IMAGE_POGGIES"));

    return 0; 

}   