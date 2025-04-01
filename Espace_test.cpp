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
    
    // On ajoute une camera et une lumiere
    Camera cam = Camera(Coordonnee(2, 2, 0), 1, 0, 0, Resolution (1024,1024));
    Esp.AjouterCamera(&cam);
    Lumiere lum = Lumiere(Couleur(1),Coordonnee(2,2,0),1,1,1);  
    Esp.AjouterLumiere(&lum);

    // Lumiere lum2 = Lumiere(Couleur(1),Coordonnee(-4,-4,0),1,1,1);  
    // Esp.AjouterLumiere(&lum2);
    
    // On cree le materiau des spheres
    Materiau m1 = Materiau((double)100,(double)200,(double)50,(double)1);
    m1.afficheMateriau();

    // Creation 1ere Sphere
    Coordonnee c = Coordonnee(2,2,4);
    Sphere Sph = Sphere(c, 1, m1);
    Sph.affichInfos();
    Esp.AjouterObjet(&Sph);

    //Creation 2eme Sphere
    Coordonnee c2 = Coordonnee(7,1,10);
    Sphere Sph2 = Sphere(c2, 4, m1);
    Sph2.affichInfos();
    Esp.AjouterObjet(&Sph2);

    // On prend une image de l'espace
    Esp.takePicture(0,string("IMAGE_POGGIES"));

    return 0; 

}   