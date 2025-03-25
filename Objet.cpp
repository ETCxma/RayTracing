#include "Objet.hpp"

Objet::Objet(){}

double Objet::getIndiceSpectular(){
    return this->materiau.getIndiceSpectular();
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
