#include "Ecran.hpp"

Ecran::Ecran(){
    this->resolution = Resolution(100, 100);
    
    int x = this->getResolution().getX();
    int y = this->getResolution().getY();

    this->pixels = new Pixel[x*y];
    this->rayons = new Rayon[x*y];
    // this->centre_pixels = new Coordonnee[this->resolution.getX()*this->resolution.getY()];

    for(int i = 0; i < x; i++){
        for (int j = 0; j < y; j++) {
            *(this->pixels + i*x + j) = Pixel(); 
            *(this->rayons + i*x + j) = Rayon(); 
            // *(this->centre_pixels + i*this->resolution.getX() + j) = Coordonnee();
        }
    }
}

Ecran::Ecran(Resolution resolution){
    this->resolution = resolution;
    
    int x = this->getResolution().getX();
    int y = this->getResolution().getY();

    this->pixels = new Pixel[x*y];
    this->rayons = new Rayon[x*y];
    // this->centre_pixels = new Coordonnee[this->resolution.getX()*this->resolution.getY()];

    for(int i = 0; i < x; i++){
        for (int j = 0; j < y; j++) {
            *(this->pixels + i*x + j) = Pixel(); 
            *(this->rayons + i*x + j) = Rayon(); 
            // *(this->centre_pixels + i*this->resolution.getX() + j) = Coordonnee();
        }
    }
}

Ecran::~Ecran(){
    delete[] this->pixels;
    delete[] this->rayons;
}

void Ecran::setResolution(int x, int y){
    return this->resolution.setResolution(x, y);
}

Pixel Ecran::getPixel(int x, int y){
    return *(this->pixels + x*this->resolution.getX() + y);
}

// Coordonnee Ecran::getCentrePixel(int x, int y){
//     return *(this->centre_pixels + x*this->resolution.getX() + y);
// }

Rayon Ecran::getRayon(int x, int y){
    return *(this->rayons + x*this->resolution.getX() + y);
}

Resolution Ecran::getResolution(){
    return this->resolution;
}

void Ecran::SetPixel(int x, int y, Pixel &pixel){
    *(this->pixels + x*this->resolution.getX() + y) = pixel;
}

// void Ecran::SetCentrePixel(int x, int y, Coordonnee &coordonnee){
//     *(this->centre_pixels + x*this->resolution.getX() + y) = coordonnee;
// }

void Ecran::SetRayon(int x, int y, Rayon &rayon){
    *(this->rayons + x*this->resolution.getX() + y) = rayon;
}
