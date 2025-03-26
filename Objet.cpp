#include "Objet.hpp"


// Objet::Objet(){}

double Objet::getIndiceSpecular(){
    return this->materiau.getIndiceSpecular();
}

double Objet::getIndiceDiffuse(){
    return this->materiau.getIndiceDiffuse();
}

double Objet::getIndiceAmbient(){
    return this->materiau.getIndiceDiffuse();
}
double Objet::getAlpha(){
    return this->materiau.getAlpha();
}

void Objet::setMateriau(const Materiau& mat){
    this->materiau = mat;
}