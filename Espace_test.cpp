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

    Camera cam = Camera();
    Esp.setCameras(cam);
    cam.setResolution(512,512);
    cout << cam.getResolution().getX() << "/" << cam.getResolution().getY() << endl;

    Esp.takePicture(0,string("IMAGE_POGGIES"));

    return 0; 

}