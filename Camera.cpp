#include "Camera.hpp"
#include <cmath>

Camera::Camera(){
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
    this->calculRayonsCoord();
}

Camera::Camera(Camera &camera){
    this->position = camera.getPosition();
    this->distance_ecran = camera.getDistanceEcran();
    this->theta = camera.getTheta();
    this->phi = camera.getPhi();

    this->ecran = Ecran(getResolution());
    this->calculRayonsCoord();
}

Camera::Camera(Coordonnee position, double distance_ecran, double theta, double phi, Resolution resolution){    
    this->position = position;
    this->distance_ecran = distance_ecran;
    this->theta = theta;
    this->phi = phi;

    this->ecran = Ecran(resolution);
    calculRayonsCoord();
}

void Camera::calculRayonsCoord(){
    
    // double x = this->distance_ecran*sin(this->theta)*cos(this->phi);
    // double y = this->distance_ecran*sin(this->theta)*sin(this->phi);
    // double z = this->distance_ecran*cos(this->theta);

    // Coordonnee centre_ecran = Coordonnee(x,y,z);

    // Vecteur t = Vecteur(this->position, centre_ecran);
    
    // Vecteur v = t;
    // // v.rotation(-M_PI_2,2)
    
    // Vecteur b = t;
    // b = b.produitVectoriel(v);

    // int k = this->getResolution().x;
    // int m = this->getResolution().y;

    // double gx = this->distance_ecran*tan(M_PI);
    // double gy = gx*(m-1)/(k-1);
    
    // Vecteur qx = b.unitaire()*2*gx/(k-1);
    // Vecteur qy = v.unitaire()*2*gy/(m-1);

    // Vecteur P1m = distance_ecran*t.unitaire() - gx*b.unitaire() - gy*v.unitaire();

    // for(int i = 0; i < k; i++){
    //     for(int j = 0; j < m; j++){
    //         Vecteur pij = P1m + qx*i + qy*j;
    //         Rayon rij = Rayon(pij.unitaire());
    //         // this->ecran.SetCentrePixel(i, j,);
    //         this->ecran.SetRayon(i, j, rij);
    //     }
    // }

}



void Camera::setPosition(Coordonnee position){
    this->position = position;
    this->calculRayonsCoord();
}

void Camera::setDistanceEcran(double distance_ecran){
    this->distance_ecran = distance_ecran;
    this->calculRayonsCoord();
}

void Camera::setTheta(double theta){
    this->theta = theta;
    this->calculRayonsCoord();
}

void Camera::setPhi(double phi){
    this->phi = phi;
    this->calculRayonsCoord();
}

void Camera::setResolution(int x, int y){
    this->ecran.setResolution(x, y);
    this->calculRayonsCoord();
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

pixels Camera::getPixels(){
    Resolution res = this->ecran.getResolution().x;
    this->ecran.getResolution().y;

}