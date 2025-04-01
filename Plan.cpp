#include "Plan.hpp"

using namespace std; 


// CONSTRUCTEURS

Plan::Plan(){
    this->origin = Coordonnee(0,0,0);
    this->c1 = Coordonnee(1,0,0);
    this->c2 = Coordonnee(0,1,0); 
    this->centre = Coordonnee(0,0,0); 
}

Plan::Plan(Coordonnee origin, Coordonnee c1, Coordonnee c2, Coordonnee centre){
    this->origin = origin; 
    this->c1 = c1;
    this->c2 = c2;
    this->centre = centre; 
}

Plan::Plan(Plan& p){
    this->origin = p.getOrigin(); 
    this->c1 = p.getC1(); 
    this->c2 = p.getC2();
    this->centre = p.getCentre(); 
}


// GETTER

Coordonnee Plan::getOrigin(){
    return this->origin; 
}
Coordonnee Plan::getC1(){
    return this->c1;
}
Coordonnee Plan::getC2(){
    return this->c2;
}
Coordonnee Plan::getCentre(){
    return this->centre; 
}


// SETTER

void Plan::setOrigin(Coordonnee origin){
    this->origin = origin; 
}
void Plan::setC1(Coordonnee c){
    this->c1 = c;
}
void Plan::setC2(Coordonnee c){
    this->c2 = c; 
}
void Plan::setCentre(Coordonnee centre){
    this->centre = centre; 
}


// MÉTHODES

vector<Vecteur> Plan::vec(){
    vector<Vecteur> vecs = {}; 
    vecs.push_back(move(Vecteur(this->origin, this->c1))); 
    vecs.push_back(move(Vecteur(this->origin, this->c2))); 
    return vecs; 
}

Vecteur Plan::vecteurNormal(){
    Vecteur n; 
    Vecteur v1 = Vecteur(this->origin, this->c1);
    Vecteur v2 = Vecteur(this->origin, this->c2); 
    n = v1.produitVectoriel(v2); 
    return n;  
}

double Plan::distance(){
    return (Vecteur(this->centre)).norme(); 
}

void Plan::afficher(){
    cout << "Origine des deux vecteurs du plan: (" << (this->origin).getX() << ", " <<  (this->origin).getY() << ", " << (this->origin).getZ() << ")" << endl; 
    cout << "vecteur 1: " << (this->c1).getX() << ", " <<  (this->c1).getY() << ", " << (this->c1).getZ() << ")" << endl;
    cout << "vecteur 2: " << (this->c2).getX() << ", " <<  (this->c2).getY() << ", " << (this->c2).getZ() << ")" << endl;
    
}
