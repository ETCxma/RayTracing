#include "Pixel.hpp"


Pixel::Pixel(){
    this->intensite = 0;
}

Pixel::Pixel(int intensite){
    this->intensite = intensite;
}

Pixel::Pixel(Pixel &pixel){
    this->intensite = pixel.intensite;
}

int Pixel::getIntensite(){
    return this->intensite;
}

void Pixel::setIntensite(int value){
    intensite = value;
}

void Pixel::addIntensite(int value){
    intensite |= value;
}
