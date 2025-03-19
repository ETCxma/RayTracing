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
        
        void takePicture(int id, std::string path);
        // TODO : implement for all X : void ModifyCameraX(int id, XType newX);
        
        
        // Return Objet id
        int AjouterObjet(Objet *obj);
        // Return Camera id
        int AjouterCamera(Camera *cam);
        // TODO : implement for all X : void ModifyObjetX(int id, XType newX);

        std::vector<Camera *> &getCameras();
        std::vector<Objet *> &getObjects();    
        
    private:
        void rayTracing(int id);

        Vecteur v[3]; // not defined by default ??
        std::vector<Objet*> objets;
        std::vector<Camera*> cameras;

};

#endif

