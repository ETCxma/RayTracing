#include <vector>
#include <string>
#include <fstream>
#include "Vecteur.hpp"
#include "Camera.hpp"
#include "Objet.hpp"
#include "Espace.hpp"
using namespace std;


// Constructor :
Espace::Espace(){
}

// Return camera ID
// int Espace::CreerCamera(Camera &camera){
//     cAM
//     cameras.push_back(camera);
//     return cameras.size() -1;
// }

int Espace::CreerCamera(Coordonnee position, double distance_ecran, double theta, double phi, Resolution res){
    Camera cam = Camera(position, distance_ecran, theta, phi, res);   
    cameras.push_back(cam);
    return cameras.size() -1;
}

void Espace::takePicture(int camID, string path) {
    rayTracing(camID);
    int x = cameras.at(camID).getResolution().getX();
    int y = cameras.at(camID).getResolution().getY();

    ofstream img(path);  // using "test.ppm" as test

    if (!img.is_open()) {
        cerr << "Error opening file: " << path << endl;
        return;
    }

    img << "P3\n" << x << " " << y << "\n255\n"; // PPM Header

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            Pixel p = cameras.at(camID).getPixel(i, j);
            int value = p.getIntensite();
            int r = value, g = value, b = value;
            img << r << " " << g << " " << b << "\n"; // Write RGB values
        }
    }

    img.close();
    system(("open " + path).c_str()); // Open the file
}

// Return Objet id
int Espace::CreerObjet(){
    return 0;
}

// Fonction de la mort
void Espace::rayTracing(int cameraID){  
    return;
}

vector<Camera> Espace::getCameras(){
    return cameras;
}