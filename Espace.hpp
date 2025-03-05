#ifndef ESPACE_H
#define ESPACE_H

#include <vector>
#include <string>

#include "Vecteur.hpp"
#include "Camera.hpp"
#include "Objet.hpp"


class Espace{

    public:
        Espace();
        Espace(Espace &espace);
        

        // Return camera id
        int CreerCamera(Camera &Camera);
        int CreerCamera(Coordonnee position, double distance_ecran, double theta, double phi);
        
        void takePicture(int id, std::string path);
        // TODO : implement for all X : void ModifyCameraX(int id, XType newX);
        
        
        // Return Objet id
        int CreerObjet();
        // TODO : implement for all X : void ModifyObjetX(int id, XType newX);


    private:
        void rayTracing(int id);


        Coordonnee origine; // not 0,0,0 by default ??
        Vecteur v[3]; // not defined by default ??
        std::vector<Objet> objets;
        std::vector<Camera> cameras;

};

#endif

