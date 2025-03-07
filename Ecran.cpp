#include "Ecran.hpp"

Ecran::Ecran(){
    this->resolution = Resolution(100, 100);
    
    this->pixels = new Pixel[this->resolution.x*this->resolution.y];
    this->rayons = new Rayon[this->resolution.x*this->resolution.y];
    this->centre_pixels = new Coordonnee[this->resolution.x*this->resolution.y];

    for(int i = 0; i < this->resolution.x; i++){
        for (int j = 0; j < this->resolution.x; j++) {
            *(this->pixels + i*this->resolution.x + j) = Pixel(); 
            *(this->rayons + i*this->resolution.x + j) = Rayon(); 
            *(this->centre_pixels + i*this->resolution.x + j) = Coordonnee();
        }
    }
}

Ecran::Ecran(Resolution resolution){
    this->resolution = resolution;
    
    this->pixels = new Pixel[this->resolution.x*this->resolution.y];
    this->rayons = new Rayon[this->resolution.x*this->resolution.y];
    this->centre_pixels = new Coordonnee[this->resolution.x*this->resolution.y];

    for(int i = 0; i < this->resolution.x; i++){
        for (int j = 0; j < this->resolution.x; j++) {
            *(this->pixels + i*this->resolution.x + j) = Pixel(); 
            *(this->rayons + i*this->resolution.x + j) = Rayon(); 
            *(this->centre_pixels + i*this->resolution.x + j) = Coordonnee();
        }
    }
}

Pixel Ecran::getPixel(int x, int y){
    return *(this->pixels + x*this->resolution.x + y);
}

Coordonnee Ecran::getCentrePixel(int x, int y){
    return *(this->centre_pixels + x*this->resolution.x + y);
}

Rayon Ecran::getRayon(int x, int y){
    return *(this->rayons + x*this->resolution.x + y);
}

Resolution Ecran::getResolution(){
    return this->resolution;
}

void Ecran::SetPixel(int x, int y, Pixel &pixel){
    *(this->pixels + x*this->resolution.x + y) = pixel;
}

void Ecran::SetCentrePixel(int x, int y, Coordonnee &coordonnee){
    *(this->centre_pixels + x*this->resolution.x + y) = coordonnee;
}

void Ecran::SetRayon(int x, int y, Rayon &rayon){
    *(this->rayons + x*this->resolution.x + y) = rayon;
}
