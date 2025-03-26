#include <vector>
#include <string>
#include <fstream>
#include<cmath>
#include "Vecteur.hpp"
#include "Camera.hpp"
#include "Objet.hpp"
#include "Espace.hpp"
#include "RaytracingPhongInfo.hpp"

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

std::vector<Lumiere*> &Espace::getLumieres(){
    return lumieres;
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

int Espace::AjouterLumiere (Lumiere *lum){
    lumieres.push_back(lum);
    return lumieres.size() - 1;
}


void Espace::takePicture(int camID, string path) {
    rayTracingPhong(camID);
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
void Espace::rayTracingSimple(int camID){
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

// Fonction de la mort v2.0
void Espace::rayTracingPhong(int camID){
    int x = cameras.at(camID)->getResolution().getX();
    int y = cameras.at(camID)->getResolution().getY();
    Rayon r;
    Pixel p;
    RaytracingPhongInfo Phong_Vectors;

    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++){
            for (int o = 0; o < (int)objets.size(); o++){
                // Envoyer un rayon
                r = cameras.at(camID)->getRayon(i, j);
                p = cameras.at(camID)->getPixel(i, j);

                int k_a = 1;
                int k_d = 0.5;
                int k_s = 0.5;

                int i_a = objets.at(o)->getIndiceAmbient();
                int i_m_d = objets.at(o)->getIndiceDiffuse();
                int alpha = objets.at(o)->getAlpha();;
                int i_m_s = objets.at(o)->getIndiceSpectular();
                int calculus = k_a*i_a;

                for (int l = 0; l < (int)lumieres.size(); l++){
                    // On utilise la méthode de Maxime afin d'obtenir les vecteurs nécessaires à la méthode de Phong
                    Phong_Vectors = objets.at(o)->intersectionPhong(r, cameras.at(camID)->getPosition(), lumieres.at(l)->getPosition());

                    Vecteur vL_m = Phong_Vectors.objet_to_lumiere;
                    Vecteur vN = Phong_Vectors.normale;
                    Vecteur vR_m = Phong_Vectors.objet_to_lumiere_reflechi;
                    Vecteur vV = Phong_Vectors.objet_to_camera;

                    calculus += k_d*(vL_m.produitScalaire(vN))*i_m_d + k_s*(int)pow((vR_m.produitScalaire(vV)),alpha)*i_m_s;
                    // plutôt que de modifier l'intensité du pixel, on va modifier l'intensité de la couleur associée au rayon
                    // On fera ensuite une autre méthode qui permet de transformer les rayons en pixel afin d'avoir leur intensité et all gud
                    p.addIntensite(calculus);
                    cameras.at(camID)->setPixel(i, j, p);
                }
            }
        }
    }
    return;
}
