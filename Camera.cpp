#include "Camera.hpp"
#include <cmath>
#include <bitset>

Camera::Camera():
    ecran()    
{
    this->position = Coordonnee(0, 0, 0);
    this->distance_ecran = 1;
    this->theta = 0;
    this->phi = 0;
}

Camera::Camera(Resolution resolution):
    ecran(resolution)
{
    this->position = Coordonnee(0, 0, 0);
    this->distance_ecran = 1;
    this->theta = 0;
    this->phi = 0;

    this->calculRayonsCoord();
}

Camera::Camera(Camera const &camera):
    ecran(getResolution())
{
    this->position = camera.position;
    this->distance_ecran = camera.distance_ecran;
    this->theta = camera.theta;
    this->phi = camera.phi;

    this->calculRayonsCoord();    
}

Camera::Camera(Coordonnee position, double distance_ecran, double theta, double phi, Resolution resolution):
    ecran(resolution)
{    
    this->position = position;
    this->distance_ecran = distance_ecran;
    this->theta = theta;
    this->phi = phi;

    calculRayonsCoord();
}

void Camera::calculRayonsCoord(){

    Vecteur centre_ecran = Vecteur(this->distance_ecran,theta,phi);
    Vecteur t = centre_ecran.spheriqueToCartesien();

    Vecteur v = t;
    v.rotationTheta(-M_PI_2);
    
    Vecteur b = t.produitVectoriel(v);
    
    Vecteur tn = t.unitaire();
    Vecteur bn = b.unitaire();
    Vecteur vn = v.unitaire();
    
    int k = this->getResolution().getX();
    int m = this->getResolution().getY();

    double gx = this->distance_ecran*tan(M_PI_4);
    double gy = gx*(double)(m-1)/(double)(k-1);
    
    Vecteur qx = bn*((double)2*gx/(double)(k-1));
    Vecteur qy = vn*((double)2*gy/(double)(m-1));

    Vecteur P1m = tn*distance_ecran - bn*gx - vn*gy;

    for(int i = 0; i < k; i++){
        for(int j = 0; j < m; j++){
            std::cout << i << j << std::endl;
            Vecteur pij = P1m + qx*i + qy*j;
            Vecteur pijn = pij.unitaire();
            Rayon rij = Rayon(pijn);
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

void Camera::addPixelIntensite(int x, int y, int intensite){
    this->ecran.addPixelIntensite(x, y, intensite);
}

void Camera::addRayonIntensite(int x, int y, double intensite){
    this->ecran.addRayonIntensite(x, y, intensite);
}

// void Camera::setPixel(int x, int y, Pixel pix){
//     this->ecran.SetPixel(x, y, pix);
// }

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

// Rayon Camera::getRayon(int x, int y){
//     return this->ecran.getRayon(x,y);
// }

// Pixel Camera::getPixel(int x, int y){
//     return this->ecran.getPixel(x,y);
// }

int Camera::getPixelIntensite(int x, int y){
    return this->ecran.getPixelIntensite(x, y);
}

void Camera::updatePixels(){
    this->ecran.updatePixels();
}
