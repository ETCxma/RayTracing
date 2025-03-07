#include "Ecran.hpp"

Ecran::Ecran(){
    this->resolution = Resolution(100, 100);
    
    this->pixels = new Pixel[this->resolution.getX()*this->resolution.getY()];
    this->rayons = new Rayon[this->resolution.getX()*this->resolution.getY()];
    // this->centre_pixels = new Coordonnee[this->resolution.getX()*this->resolution.getY()];

    for(int i = 0; i < this->resolution.getX(); i++){
        for (int j = 0; j < this->resolution.getX(); j++) {
            *(this->pixels + i*this->resolution.getX() + j) = Pixel(); 
            *(this->rayons + i*this->resolution.getX() + j) = Rayon(); 
            // *(this->centre_pixels + i*this->resolution.getX() + j) = Coordonnee();
        }
    }
}

Ecran::Ecran(Resolution resolution){
    this->resolution = resolution;
    
    this->pixels = new Pixel[this->resolution.getX()*this->resolution.getY()];
    this->rayons = new Rayon[this->resolution.getX()*this->resolution.getY()];
    // this->centre_pixels = new Coordonnee[this->resolution.getX()*this->resolution.getY()];

    for(int i = 0; i < this->resolution.getX(); i++){
        for (int j = 0; j < this->resolution.getX(); j++) {
            *(this->pixels + i*this->resolution.getX() + j) = Pixel(); 
            *(this->rayons + i*this->resolution.getX() + j) = Rayon(); 
            // *(this->centre_pixels + i*this->resolution.getX() + j) = Coordonnee();
        }
    }
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
