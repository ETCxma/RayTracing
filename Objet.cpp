#include "Objet.hpp"


// Objet::Objet(){}

// Getters
double Objet::getIndiceSpecular(){
    return this->materiau.getIndiceSpecular();
}

double Objet::getIndiceDiffuse(){
    return this->materiau.getIndiceDiffuse();
}

double Objet::getIndiceAmbient(){
    return this->materiau.getIndiceAmbient();
}
double Objet::getAlpha(){
    return this->materiau.getAlpha();
}

void Objet::setMateriau(const Materiau& mat){
    this->materiau = mat;
}