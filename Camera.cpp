#include "Camera.hpp"
#include <cmath>

Camera::Camera(Resolution resolution){
    this->position = Coordonnee(0, 0, 0);
    this->distance_ecran = 1;
    this->theta = 0;
    this->phi = 0;

    this->ecran = Ecran();
}

Camera::Camera(Resolution resolution){
    this->position = Coordonnee(0, 0, 0);
    this->distance_ecran = 1;
    this->theta = 0;
    this->phi = 0;

    this->ecran = Ecran(resolution);
    this->calculateScreenCoords();
}

Camera::Camera(Camera &camera){
    this->position = camera.getPosition();
    this->distance_ecran = camera.getDistanceEcran();
    this->theta = camera.getTheta();
    this->phi = camera.getPhi();

    this->ecran = Ecran(getResolution());
    this->calculateScreenCoords();
}

Camera::Camera(Coordonnee position, double distance_ecran, double theta, double phi, Resolution resolution){    
    this->position = position;
    this->distance_ecran = distance_ecran;
    this->theta = theta;
    this->phi = phi;

    this->ecran = Ecran(resolution);
    calculateScreenCoords();
}

void Camera::calculateScreenCoords(){
    
    // double x = this->distance_ecran*sin(this->theta)*cos(this->phi);
    // double y = this->distance_ecran*sin(this->theta)*sin(this->phi);
    // double z = this->distance_ecran*cos(this->theta);

    // Coordonnee centre_ecran = Coordonnee(x,y,z);

    // Vecteur t = Vecteur(this->position, centre_ecran);
    
    // Vecteur v = Vecteur(t);
    // // v.rotation(-M_PI_2,2)
    // Vecteur b = Vecteur(t);
    // b = b.produitVectoriel(v);

    // int k = this->getResolution().x;
    // int m = this->getResolution().y;

    // double gx = this->distance_ecran*tan(M_PI);
    // double gy = gx*(m-1)/(k-1);
    
    // Vecteur qx = Vecteur(b.unitaire(), 2*gx/(k-1));
    // Vecteur qy = Vecteur(v.unitaire(), 2*gy/(m-1));

    // Vecteur P1m = distance_ecran*t.unitaire() - gx*b.unitaire() - gy*v.unitaire();




}



void Camera::setPosition(Coordonnee position){
    this->position = position;
}

void Camera::setDistanceEcran(double distance_ecran){
    this->distance_ecran = distance_ecran;
}

void Camera::setTheta(double theta){
    this->theta = theta;
}

void Camera::setPhi(double phi){
    this->phi = phi;
}

Coordonnee Camera::getPosition(){
    return this->position;
}

double Camera::getDistanceEcran(){
    return this->distance_ecran;
}

double Camera::getTheta(){
    return this->theta;
}

double Camera::getPhi(){
    return this->phi;
}

Resolution Camera::getResolution(){
    return this->ecran.getResolution();
}