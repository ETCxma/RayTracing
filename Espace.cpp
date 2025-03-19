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
    printf("ouais take picture let's go \n");
    rayTracing(camID);
    printf("ouais take picture let's go 2\n");
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
            printf("value : %d\n", value);
            img << r << " " << g << " " << b << "\n"; // Write RGB values
        }
    }

    img.close();
    system(("open " + path).c_str()); // Open the file
    printf("ouais End of take picture let's go \n");
    return;
}


// Fonction de la mort
void Espace::rayTracing(int camID){
    printf("ouais RayTracing let's go \n");
    int x = cameras.at(camID)->getResolution().getX();
    printf("ouais RayTracing let's go n°1.5\n");
    int y = cameras.at(camID)->getResolution().getY();
    printf("ouais RayTracing let's go n°2\n");
    Rayon r;
    Pixel p;
    printf("ouais RayTracing let's go n°3\n");

    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++){
            for (int o = 0; o < (int)objets.size(); o++){
                printf("Woooooooo %d / %d\n", i, j);
                // Envoyer un rayon
                r = cameras.at(camID)->getRayon(i, j);
                p = cameras.at(camID)->getPixel(i, j);
                // S'il y a intersection
                if (objets.at(o)->intersection(r, cameras.at(camID)->getPosition()) == 1){
                    printf("if");
                    p.setIntensite(255);
                    cameras.at(camID)->setPixel(i, j, p);
                }
                else{
                    printf("else");
                    p.setIntensite(100);
                    cameras.at(camID)->setPixel(i, j, p);
                }
            }
        }
    }
    printf("ouais End of RayTracing let's go \n");
    return;
}
