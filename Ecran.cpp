#include "Ecran.hpp"

Ecran::Ecran(){
    this->resolution = Resolution(0, 0);
}

Ecran::Ecran(Resolution resolution){
    this->resolution = resolution;
    
    int x = this->getResolution().getX();
    int y = this->getResolution().getY();

    this->pixels.reserve(this->getResolution().getX()*this->getResolution().getY());
    this->rayons.reserve(this->getResolution().getX()*this->getResolution().getY());

    for(int i = 0; i < x; i++){
        for (int j = 0; j < y; j++) {

        this->pixels.push_back(Pixel()); 
        this->rayons.push_back(Rayon()); 
        }
    }
}

void Ecran::setResolution(int x, int y){
    return this->resolution.setResolution(x, y);
}

// Pixel Ecran::getPixel(int x, int y){
//     return this->pixels.at(x*this->getResolution().getX() + y);
// }

Rayon Ecran::getRayon(int x, int y){
    return this->rayons.at(x*this->getResolution().getX() + y);
}

Resolution Ecran::getResolution(){
    return this->resolution;
}

void Ecran::SetRayon(int x, int y, Rayon &rayon){
    this->rayons.at(x*this->getResolution().getX() + y).setVecteur(rayon.getVecteur());
}

void Ecran::addPixelIntensite(int x, int y, int intensite){
    this->pixels.at(x*this->getResolution().getX() + y).addIntensite(intensite);
}

void Ecran::setPixelIntensite(int x, int y, int intensite){
    this->pixels.at(x*this->getResolution().getX() + y).setIntensite(intensite);
}

int Ecran::getPixelIntensite(int x, int y){
    return this->pixels.at(x*this->getResolution().getX() + y).getIntensite();
}

double Ecran::getRayonIntensite(int x, int y){
    return this->rayons.at(x*this->getResolution().getX() + y).getIntensite();
}

void Ecran::addRayonIntensite(int x, int y, double intensite){
    this->rayons.at(x*this->getResolution().getX() + y).addIntensite(intensite);
}

// Scale Couleur of rayons to pixels (0 to 255)   
void Ecran::updatePixels(){
    double intensite_max = 0;

    int x = this->getResolution().getX();
    int y = this->getResolution().getY();

    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            double intensite = this->getRayonIntensite(i, j);
            intensite_max = intensite_max > intensite ? intensite_max : intensite; 
        }
    }

    if(intensite_max == 0) return;

    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            double intensite = this->getRayonIntensite(i, j);
            this->setPixelIntensite(i, j, (255*intensite)/intensite_max);
        }
    }

}