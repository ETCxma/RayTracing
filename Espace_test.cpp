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
#include "Materiau.hpp"

using namespace std; 


int main(int argc, char* argv[]){

    Espace Esp;

    // On crée les matériaux des sphères
    // specular, diffuse, ambient, alpha
    Materiau m1 = Materiau((double)100,(double)200,(double)50,(double)0);
    Materiau m2 = Materiau((double)100,(double)200,(double)50,(double)1);
    Materiau m3 = Materiau((double)100,(double)200,(double)50,(double)3);
    Materiau m4 = Materiau((double)100,(double)200,(double)50,(double)4);
    Materiau m5 = Materiau((double)0,(double)200,(double)50,(double)3);
    Materiau m6 = Materiau((double)50,(double)200,(double)50,(double)3);
    Materiau m7 = Materiau((double)100,(double)200,(double)50,(double)3);
    Materiau m8 = Materiau((double)200,(double)200,(double)50,(double)3);
    Materiau m9 = Materiau((double)100,(double)0,(double)50,(double)3);
    Materiau m10 = Materiau((double)100,(double)50,(double)50,(double)3);
    Materiau m11 = Materiau((double)100,(double)100,(double)50,(double)3);
    Materiau m12 = Materiau((double)100,(double)200,(double)50,(double)3);
    Materiau m13 = Materiau((double)100,(double)200,(double)0,(double)3);
    Materiau m14 = Materiau((double)100,(double)200,(double)50,(double)3);
    Materiau m15 = Materiau((double)100,(double)200,(double)100,(double)3);
    Materiau m16 = Materiau((double)100,(double)200,(double)200,(double)3);

    // On crée les coordonnées
    Coordonnee c1 = Coordonnee(4,4,15);
    Coordonnee c2 = Coordonnee(4,8,15);
    Coordonnee c3 = Coordonnee(4,12,15);
    Coordonnee c4 = Coordonnee(4,16,15);
    Coordonnee c5 = Coordonnee(8,4,15);
    Coordonnee c6 = Coordonnee(8,8,15);
    Coordonnee c7 = Coordonnee(8,12,15);
    Coordonnee c8 = Coordonnee(8,16,15);
    Coordonnee c9 = Coordonnee(12,4,15);
    Coordonnee c10 = Coordonnee(12,8,15);
    Coordonnee c11 = Coordonnee(12,12,15);
    Coordonnee c12 = Coordonnee(12,16,15);
    Coordonnee c13 = Coordonnee(16,4,15);
    Coordonnee c14 = Coordonnee(16,8,15);
    Coordonnee c15 = Coordonnee(16,12,15);
    Coordonnee c16 = Coordonnee(16,16,15);

    // On crée les sphères
    Sphere Sph1 = Sphere(c1, 1.5, m1);
    Sphere Sph2 = Sphere(c2, 1.5, m2);
    Sphere Sph3 = Sphere(c3, 1.5, m3);
    Sphere Sph4 = Sphere(c4, 1.5, m4);
    Sphere Sph5 = Sphere(c5, 1.5, m5);
    Sphere Sph6 = Sphere(c6, 1.5, m6);
    Sphere Sph7 = Sphere(c7, 1.5, m7);
    Sphere Sph8 = Sphere(c8, 1.5, m8);
    Sphere Sph9 = Sphere(c9, 1.5, m9);
    Sphere Sph10 = Sphere(c10, 1.5, m10);
    Sphere Sph11 = Sphere(c11, 1.5, m11);
    Sphere Sph12 = Sphere(c12, 1.5, m12);
    Sphere Sph13 = Sphere(c13, 1.5, m13);
    Sphere Sph14 = Sphere(c14, 1.5, m14);
    Sphere Sph15 = Sphere(c15, 1.5, m15);
    Sphere Sph16 = Sphere(c16, 1.5, m16);

    // on les ajoute à l'espace
    Esp.AjouterObjet(&Sph1);
    Esp.AjouterObjet(&Sph2);
    Esp.AjouterObjet(&Sph3);
    Esp.AjouterObjet(&Sph4);
    Esp.AjouterObjet(&Sph5);
    Esp.AjouterObjet(&Sph6);
    Esp.AjouterObjet(&Sph7);
    Esp.AjouterObjet(&Sph8);
    Esp.AjouterObjet(&Sph9);
    Esp.AjouterObjet(&Sph10);
    Esp.AjouterObjet(&Sph11);
    Esp.AjouterObjet(&Sph12);
    Esp.AjouterObjet(&Sph13);
    Esp.AjouterObjet(&Sph14);
    Esp.AjouterObjet(&Sph15);
    Esp.AjouterObjet(&Sph16);
    
    // On ajoute une camera et une lumiere
    Camera cam = Camera(Coordonnee(10, 10, 3), 2, 0, 0, Resolution (1536,1536));
    Esp.AjouterCamera(&cam);
    Lumiere lum = Lumiere(Couleur(1),Coordonnee(10,10,-100),1,1,1);  
    //Esp.AjouterLumiere(&lum);

    Lumiere lum2 = Lumiere(Couleur(1),Coordonnee(20,20,5),1,1,1);  
    Esp.AjouterLumiere(&lum2);

    // On prend une image de l'espace
    Esp.takePicture(0,string("IMAGE_POGGIES"));

    return 0; 
}   