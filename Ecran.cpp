#include "Ecran.hpp"

Ecran::Ecran(){
    this->resolution = Resolution(0, 0);

    // this->pixels.reserve(0);
    // this->rayons.reserve(0);
    // this->pixels = 
    // this->rayons = new Rayon[x*y];

    // this->centre_pixels = new Coordonnee[this->resolution.getX()*this->resolution.getY()];

    // for(int i = 0; i < x; i++){
    //     for (int j = 0; j < y; j++) {
    //         *(this->pixels + i*x + j) = Pixel(); 
    //         *(this->rayons + i*x + j) = Rayon(); 
    //         // *(this->centre_pixels + i*this->resolution.getX() + j) = Coordonnee();
    //     }
    // }
}

Ecran::Ecran(Resolution resolution){
    this->resolution = resolution;
    
    int x = this->getResolution().getX();
    int y = this->getResolution().getY();

    // this->rayons.reserve(100);
    // this->pixels.reserve(100);

    this->pixels.reserve(this->getResolution().getX()*this->getResolution().getY());
    this->rayons.reserve(this->getResolution().getX()*this->getResolution().getY());

    // std::cout << this->pixels.size() << std::endl;
    // // this->centre_pixels = new Coordonnee[this->resolution.getX()*this->resolution.getY()];

     for(int i = 0; i < x; i++){
         for (int j = 0; j < y; j++) {

            this->pixels.push_back(Pixel()); 
            this->rayons.push_back(Rayon()); 
             // *(this->centre_pixels + i*this->resolution.getX() + j) = Coordonnee();
         }
     }
}

// Ecran::~Ecran(){
//     delete[] this->pixels;
//     delete[] this->rayons;
// }

void Ecran::setResolution(int x, int y){
    return this->resolution.setResolution(x, y);
}

// Pixel Ecran::getPixel(int x, int y){
//     return this->pixels.at(x*this->getResolution().getX() + y);
// }

// Coordonnee Ecran::getCentrePixel(int x, int y){
//     return *(this->centre_pixels + x*this->resolution.getX() + y);
// }

// Rayon Ecran::getRayon(int x, int y){
//     return this->rayons.at(x*this->getResolution().getX() + y);
// }

Resolution Ecran::getResolution(){
    return this->resolution;
}

// void Ecran::SetPixel(int x, int y, Pixel &pixel){
//     this->pixels.at(x*this->getResolution().getX() + y) = pixel;
// }

// void Ecran::SetCentrePixel(int x, int y, Coordonnee &coordonnee){
//     *(this->centre_pixels + x*this->resolution.getX() + y) = coordonnee;
// }

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