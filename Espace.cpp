#include <vector>
#include <string>
#include <fstream>
#include <cmath>
#include "Vecteur.hpp"
#include "Camera.hpp"
#include "Objet.hpp"
#include "Espace.hpp"
#include "RaytracingPhongInfo.hpp"

using namespace std;


// Constructor :
Espace::Espace(){
}

// Getters
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

// Return Lumiere id
int Espace::AjouterLumiere (Lumiere *lum){
    lumieres.push_back(lum);
    return lumieres.size() - 1;
}

// Take a picture of space and save it at path
void Espace::takePicture(int camID, string path){
    rayTracingPhong(camID);
    int x = cameras.at(camID)->getResolution().getX();
    int y = cameras.at(camID)->getResolution().getY();
    ofstream img(path);

    if (!img.is_open()) {
        cerr << "Error opening file: " << path << endl;
        return;
    }
    // PPM Header (needed)
    img << "P3\n" << x << " " << y << "\n255\n";

    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++){
            int value = cameras.at(camID)->getPixelIntensite(i, j);
            int r = value, g = value, b = value;
            // Write RGB values
            img << r << " " << g << " " << b << "\n";
        }
    }

    img.close();
    // Open the file
    system(("open " + path).c_str());
    return;
}


// Fonction Simple de la mort : Affiche la présence d'objets dans l'espace
void Espace::rayTracingSimple(int camID){
    int x = cameras.at(camID)->getResolution().getX();
    int y = cameras.at(camID)->getResolution().getY();

    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++){
            for (int o = 0; o < (int)objets.size(); o++){
                // On envoie un Rayon et on check s'il y a intersection (pour chacun des pixels et chacun des objets)
                if (objets.at(o)->intersection(cameras.at(camID)->getRayon(i,j), cameras.at(camID)->getPosition()) == 1){
                    cameras.at(camID)->addPixelIntensite(i, j, 255);
                }
                else{   
                    cameras.at(camID)->addPixelIntensite(i, j, 0);
                }
            }
        }
    }
    return;
}

// Fonction de la mort v2.0 : On utilise la méthode de Phong afin de faire du RayTracing
void Espace::rayTracingPhong(int camID){
    int x = cameras.at(camID)->getResolution().getX();
    int y = cameras.at(camID)->getResolution().getY();
    RaytracingPhongInfo Phong_Vectors;

    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++){
            for (int o = 0; o < (int)objets.size(); o++){ 
                double k_a = 1;
                double k_d = 0.5;
                double k_s = 0.5;

                double i_a = objets.at(o)->getIndiceAmbient();
                double i_m_d = objets.at(o)->getIndiceDiffuse();
                double i_m_s = objets.at(o)->getIndiceSpecular();
                double alpha = objets.at(o)->getAlpha();;
                double calculus = k_a*i_a;

                // Decomment line for debug
                // cout << "i_a = " << i_a << "/ i_m_d = " << i_m_d << "/ i_m_s = " << i_m_s << "/ alpha = " << alpha << endl;

                // Pour chacun des pixel, des objets et des lumières, on va calculer l'éclairement 
                for (int l = 0; l < (int)lumieres.size(); l++){
                    // On utilise la méthode intersectionPhong afin d'obtenir les vecteurs nécessaires à la méthode de Phong
                    Phong_Vectors = objets.at(o)->intersectionPhong(cameras.at(camID)->getRayon(i, j), cameras.at(camID)->getPosition(), lumieres.at(l)->getPosition());

                    Vecteur vL_m = Phong_Vectors.objet_to_lumiere;
                    Vecteur vN = Phong_Vectors.normale;
                    Vecteur vR_m = Phong_Vectors.objet_to_lumiere_reflechi;
                    Vecteur vV = Phong_Vectors.objet_to_camera;

                    // Decomment lines for debug
                    // vL_m.afficheVecteur(string("vL_m"));
                    // vN.afficheVecteur(string("vN"));
                    // vR_m.afficheVecteur(string("vR_m"));
                    // vV.afficheVecteur(string("vV"));

                    calculus += abs(k_d*(vL_m.produitScalaire(vN))*i_m_d + k_s*(double)pow((vR_m.produitScalaire(vV)),alpha)*i_m_s);
                    calculus = (int)calculus;
                    cameras.at(camID)->addRayonIntensite(i, j, calculus);
                }
                // Decomment line for debug
                // cout << calculus <<endl;
            }
        }
    }
    cameras.at(camID)->updatePixels();
    return;
}
