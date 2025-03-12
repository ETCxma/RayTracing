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
using namespace std; 


int main(int argc, char* argv[]){

    Espace Esp; 
    Coordonnee b(1, 2, 3);
    Resolution res(512,512);

    Camera cam = Camera();
    Esp.setCameras(cam);

    Esp.takePicture(0,string("IMAGE_POGGIES"));

    return 0; 

}