#ifndef ESPACE_H
#define ESPACE_H

#include <vector>
#include <string>

#include "Vecteur.hpp"
#include "Camera.hpp"
#include "Objet.hpp"
#include "Lumiere.hpp"


class Espace{

    public:
        Espace();
        Espace(Espace &espace);
        
        void takePicture(int id, std::string path);
        
        
        int AjouterObjet(Objet *obj);
        int AjouterCamera(Camera *cam);
        int AjouterLumiere (Lumiere *lum);

        std::vector<Camera *> &getCameras();
        std::vector<Objet *> &getObjects();
        std::vector<Lumiere*> &getLumieres();
        
    private:
        // Methods to make rayTracing
        void rayTracingSimple(int id);
        void rayTracingPhong(int id);
        
        double calcIntesiteAmbient();

        std::vector<Objet*> objets;
        std::vector<Camera*> cameras;
        std::vector<Lumiere*> lumieres;

};

#endif

