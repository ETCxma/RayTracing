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

    RaytracingPhongInfo phong_vectors, phong_vectors_min;
    int id_min = 0;
    double t_min = MAXFLOAT;
    double i_a = this->calcIntesiteAmbient();

    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++){
            // Pour chaque pixel, on reset les valeurs
            t_min = MAXFLOAT;
            // On détermine l'objet le plus proche de la caméra (on ne verra pas les objets derrière lui)
            for (int o = 0; o < (int)objets.size(); o++){ 
                phong_vectors = objets.at(o)->intersectionPhong(cameras.at(camID)->getRayon(i, j), cameras.at(camID)->getPosition(), Coordonnee(0,0,0));
                if(phong_vectors.distance < t_min){
                    phong_vectors_min = phong_vectors;
                    t_min = phong_vectors.distance;
                    id_min = o;
                }
            }

            // Au moins un objet trouvé 
            if(t_min != MAXFLOAT){
                // std::cout << t_min << std::endl;
                double k_a = objets.at(id_min)->getIndiceAmbient();
                double k_d = objets.at(id_min)->getIndiceDiffuse();
                double k_s = objets.at(id_min)->getIndiceSpecular();
                double alpha = objets.at(id_min)->getAlpha();

                for (int l = 0; l < (int)lumieres.size(); l++){
                
                    phong_vectors = objets.at(id_min)->intersectionPhong(cameras.at(camID)->getRayon(i, j), cameras.at(camID)->getPosition(), lumieres.at(l)->getPosition());
                    double i_m_d = lumieres.at(l)->getIntensiteDiffuse();
                    double i_m_s = lumieres.at(l)->getIntensiteSpecular();

                    Vecteur vL_m = phong_vectors.objet_to_lumiere;
                    Vecteur vN = phong_vectors.normale;
                    Vecteur vR_m = phong_vectors.objet_to_lumiere_reflechi;
                    Vecteur vV = phong_vectors.objet_to_camera;

                    double calculus = 0;

                    // Decomment lines for debug
                    // vL_m.afficheVecteur(string("vL_m"));
                    // vN.afficheVecteur(string("vN"));
                    // vR_m.afficheVecteur(string("vR_m"));
                    // vV.afficheVecteur(string("vV"));

                    // Decomment line for debug
                    // cout << "i_a = " << i_a << "/ i_m_d = " << i_m_d << "/ i_m_s = " << i_m_s << "/ alpha = " << alpha << endl;

                    // La partie multiplié par 1 déconne quand l'objet intersecté a un y < 0, on ne sait pas pourquoi
                    calculus = k_a*i_a + k_d*(vL_m.produitScalaire(vN))*i_m_d + 1*(k_s*(double)pow((vR_m.produitScalaire(vV)),alpha)*i_m_s);
                    // cout << calculus <<endl;
                    cameras.at(camID)->addRayonIntensite(i, j, calculus);
                }
            }
            // Pas d'objet 
            else{
                cameras.at(camID)->addRayonIntensite(i, j, 0); // Useless
            }
        }
    }
    cameras.at(camID)->updatePixels();
    return;
}

double Espace::calcIntesiteAmbient(){
    double i_a = 0;
    for (int l = 0; l < (int)lumieres.size(); l++){
        i_a += lumieres.at(l)->getIntensiteAmbient();
    }
    return i_a;
}