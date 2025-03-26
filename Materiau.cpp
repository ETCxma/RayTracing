#include "Materiau.hpp"
using namespace std; 

Materiau::Materiau(){}

Materiau::Materiau(Materiau &materiau){

}

Materiau::Materiau(double i_s, double i_d, double i_a, double a){
    this->indice_specular = i_s;
    this->indice_diffuse = i_d;
    this->indice_ambient = i_a;
    this->alpha = a;
}

double Materiau::getIndiceSpecular(){
    return this->indice_specular;
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

void Materiau::afficheMateriau(){
    cout << "i_s = " << indice_specular << "/ i_d = " << indice_diffuse << "/ i_a = " << indice_ambient << "/ alpha = " << alpha << endl;
}