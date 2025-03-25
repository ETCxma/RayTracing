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

vector<Camera *> &Espace::getCameras(){
    return cameras;
}


vector<Objet *> &Espace::getObjects(){
    return objets;
}

// Return Objet id
int Espace::AjouterObjet(Objet* obj){
    objets.push_back(obj);
    return objets.size() - 1;
}

// Return Camera id
int Espace::AjouterCamera(Camera *cam){
    cameras.push_back(cam);
    return cameras.size() - 1;
}


void Espace::takePicture(int camID, string path) {
    rayTracing(camID);
    int x = cameras.at(camID)->getResolution().getX();
    int y = cameras.at(camID)->getResolution().getY();
    
    ofstream img(path);  // using "test.ppm" as test

    if (!img.is_open()) {
        cerr << "Error opening file: " << path << endl;
        return;
    }

    img << "P3\n" << x << " " << y << "\n255\n"; // PPM Header
    Pixel p;

    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++){
            p = cameras.at(camID)->getPixel(i, j);
            int value = p.getIntensite();
            int r = value, g = value, b = value;
            img << r << " " << g << " " << b << "\n"; // Write RGB values
        }
    }

    img.close();
    system(("open " + path).c_str()); // Open the file
    return;
}


// Fonction de la mort
void Espace::rayTracing(int camID){
    int x = cameras.at(camID)->getResolution().getX();
    int y = cameras.at(camID)->getResolution().getY();
    Rayon r;
    Pixel p;

    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++){
            for (int o = 0; o < (int)objets.size(); o++){
                // Envoyer un rayon
                r = cameras.at(camID)->getRayon(i, j);
                p = cameras.at(camID)->getPixel(i, j);
                // S'il y a intersection
                if (objets.at(o)->intersection(r, cameras.at(camID)->getPosition()) == 1){
                    p.addIntensite(255);
                    cameras.at(camID)->setPixel(i, j, p);
                }
                else{
                    p.addIntensite(0);
                    cameras.at(camID)->setPixel(i, j, p);
                }
            }
        }
    }
    return;
}
