#include "Plan.hpp"

using namespace std; 


// CONSTRUCTEURS

// Plan::Plan(){
//     this->origin = Coordonnee(0,0,0);
//     this->normal = Vecteur(1,1,1); 
// }

Plan::Plan(Vecteur n, Coordonnee origin){
    this->origin = origin; 
    this->normal = n; 
}

Plan::Plan(Plan& p){
    this->origin = p.getOrigin(); 
    this->normal = p.getNormal(); 
}


// GETTER

Coordonnee Plan::getOrigin(){
    return this->origin; 
}
Vecteur Plan::getNormal(){
    return this->normal;
}


// SETTER

void Plan::setOrigin(Coordonnee origin){
    this->origin = origin; 
}
void Plan::setNormal(Vecteur normal){
    this->normal = normal;
}


// MÉTHODES

double Plan::distance(){
    double d = 0.0; 
    d = (-1)*(((this->normal).getDX()*(this->origin).getX()) + ((this->normal).getDY()*(this->origin).getY()) + ((this->normal).getDZ()*(this->origin).getZ()));
    return d; 
}

void Plan::afficher(){
    cout << "Information du plan: " << endl; 
    cout << "\t"; 
    this->normal.afficheVecteur("N"); 
    cout << "\t Origine = (" << this->origin.getX() << ", " << this->origin.getY() << ", " << this->origin.getZ() << ")." << endl;  
}

Coordonnee Plan::intersectionPlan(Rayon r){
    double d = distance(); 

    // On détermine l'origine de rayon ainsi que sa direction
    Coordonnee origin_rayon = ; 
    Coordonnee direction_rayon = ; 

}
