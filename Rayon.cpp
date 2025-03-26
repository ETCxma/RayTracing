#include "Rayon.hpp"
#include "Couleur.hpp"
#include "Vecteur.hpp"

Rayon::Rayon(){
    Vecteur();
    this->couleur = Couleur();
}

Rayon::Rayon(Coordonnee x1, Coordonnee x2, Couleur couleur):
    Vecteur(x1, x2){
    this->couleur = couleur;
}

Rayon::Rayon(Vecteur &vecteur, Couleur couleur):
    Vecteur(vecteur) {
    this->couleur = couleur;
}

Rayon::Rayon(Rayon &rayon):
    Vecteur(rayon) {
    this->couleur = couleur;
}

double Rayon::getIntensite(){
    return this->couleur.getIntensite();
}

void Rayon::addIntensite(double intensite){
    this->couleur.addIntensite(intensite);
}