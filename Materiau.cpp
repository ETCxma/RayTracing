#include "Materiau.hpp"

Materiau::Materiau(){}

Materiau::Materiau(Materiau &materiau){

}

Materiau::Materiau(double indice_spectular, double indice_diffuse, double indice_ambient){
    this->indice_spectular = indice_spectular;
    this->indice_diffuse = indice_diffuse;
    this->indice_ambient = indice_ambient;
}
