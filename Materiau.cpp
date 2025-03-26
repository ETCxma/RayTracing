#include "Materiau.hpp"

Materiau::Materiau(){}

Materiau::Materiau(Materiau &materiau){

}

Materiau::Materiau(double indice_spectular, double indice_diffuse, double indice_ambient, double alpha){
    this->indice_spectular = indice_spectular;
    this->indice_diffuse = indice_diffuse;
    this->indice_ambient = indice_ambient;
    this->alpha = alpha;
}

double Materiau::getIndiceSpectular(){
    return this->indice_spectular;
}

double Materiau::getIndiceDiffuse(){
    return this->indice_diffuse;
}

double Materiau::getIndiceAmbient(){
    return this->indice_ambient;
}

double Materiau::getAlpha(){
    return this->alpha;
}