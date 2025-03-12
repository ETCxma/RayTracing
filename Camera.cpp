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
    
    double x = this->distance_ecran*sin(this->theta)*cos(this->phi);
    double y = this->distance_ecran*sin(this->theta)*sin(this->phi);
    double z = this->distance_ecran*cos(this->theta);

    Coordonnee centre_ecran = Coordonnee(x,y,z);

    Vecteur t = Vecteur(this->position, centre_ecran);
    
    Vecteur v = t;
    v.rotationPhi(-M_PI_2);
    
    Vecteur b = t;
    b = b.produitVectoriel(v);
    
    
    Vecteur tn = t.unitaire();
    Vecteur bn = b.unitaire();
    Vecteur vn = v.unitaire();



    int k = this->getResolution().getX();
    int m = this->getResolution().getY();

    double gx = this->distance_ecran*tan(M_PI);
    double gy = gx*(m-1)/(k-1);
    
    Vecteur qx = bn*((double)2*gx/(double)(k-1));
    Vecteur qy = vn*((double)2*gy/(double)(m-1));

    Vecteur P1m = tn*distance_ecran - bn*gx - vn*gy;

    for(int i = 0; i < k; i++){
        for(int j = 0; j < m; j++){
            Vecteur pij = P1m + qx*i + qy*j;
            Vecteur pijn = pij.unitaire();
            Rayon rij = Rayon(pijn);
            // this->ecran.SetCentrePixel(i, j,);
            this->ecran.SetRayon(i, j, rij);
        }
    }

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

Rayon Camera::getRayon(int x, int y){
    return this->ecran.getRayon(x,y);
}

Pixel Camera::getPixel(int x, int y){
    return this->ecran.getPixel(x,y);
}