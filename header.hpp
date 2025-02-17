#include <iostream>
#include <vector>



class Pixel{

    // Méthodes
    public:
        Pixel();

    // Attributs
    private:
        int intensite; 

};


class Resolution{

    // Méthodes
    public:
        Resolution();

    // Attributs
    private:
        int x;
        int y;

};


class PlanFini{

    // Méthodes
    public:
        PlanFini(); 

    // Attributs
    private:
        Coordonnee origine;
        Vecteur plan[2];
        Coordonnee centre; 
        double hx;
        double hy; 

};


class Ecran{

    // Méthodes
    public:
        Ecran(); 

    // Attributs
    private:
        Resolution res;
        Pixel pixels[][]; 
        Coordonnee centre_pixels[][]; 

};


class Coordonnee{

    // Méthodes
    public:
        Coordonnee();
        double distance(Coordonnee c);

    // Attributs
    private:
        double x;
        double y; 
        double z; 

};


class Vecteur{

    // Méthodes
    public:
        Vecteur();
        double produitScalaire(Vecteur vec);
        Vecteur produitVectoriel(Vecteur vec);
        double norme();
        double unitaire();                      // Renvoie son vecteur unitaire
        bool intersection(Triangle trig);

    // Attributs
    private:
        Coordonnee x1;
        Coordonnee x2;
        double norme; 
        Coordonnee vecteur_distance_origine; 

};


class Triangle{

    // Méthodes
    public:
        Triangle(); 
        bool intersection(Vecteur vec); 

    // Attributs
    private:
        Coordonnee c[3]; 
        double intensite; 

};


class Rayon{

    // Méthodes:
    public:
        Rayon(); 

    // Attributs
    private:
        double intensite; 

};


class Volume{

    // Méthodes
    public:
        Volume();
        bool intersection(Vecteur vec);

    // Attributs
    private:
        std::vector<Triangle> elements; 

};


class Camera{

    // Méthodes
    public:
        Camera();
        // Rayon RayTracing(); 

    // Attributs
    private:
        Ecran screen;
        Coordonnee position;
        double distance_ecran;
        // Vecteur pixel_shifting_vector_x;
        // Vecteur pixel_shifting_vector_y;    
        double champ_vision; 
        Vecteur vertical_vector; 
        Rayon Ray[][]; 

};


class Image{

    // Méthodes
    public:
        Image();   
        // drawImage();
        // saveImage(); 

    // Attributs
    private:
        Camera camera; 

};


class Espace{

    // Méthodes
    public: 
        Espace();
        bool isEspace();
        // addVolume(); 

    // Attributs
    private: 
        Coordonnee origin;
        Vecteur vec[3];
        std::vector<Volume> volume; 
        std::vector<Camera> cameras;

};