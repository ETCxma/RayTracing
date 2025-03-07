#include <vector>
#include <string>
#include "Vecteur.hpp"
#include "Camera.hpp"
#include "Objet.hpp"
#include "Espace.hpp"
using namespace std;


// Constructor :
Espace::Espace(){
}

// Return camera ID
int Espace::CreerCamera(Camera &Camera){
    cameras.push_back(Camera);
    return cameras.size() -1;
}

int Espace::CreerCamera(Coordonnee position, double distance_ecran, double theta, double phi){
    Camera cam(position, distance_ecran, theta, phi, resolution);
    cameras.push_back(cam);
    return cameras.size() -1;
}

void Espace::takePicture(int camID, string path){
    rayTracing(camID);
    int x = cameras.at(camID).getResolution().getX();
    int y = cameras.at(camID).getResolution().getY();
    Pixel p;
    int value;

    for (int i = 0; i < x; i++){
        for (int j = 0; i < y; j++){
            p = cameras.at(camID).getPixel();
            value = p.getIntensity();
            // Now we create an Image youhouuuuuuuuuu (JPG I guess)
        }
    }

}

// Return Objet id
int Espace::CreerObjet(double r){
    
}

// Fonction de la mort
void Espace::rayTracing(int cameraID){  
    
}

