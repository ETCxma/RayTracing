#include "Resolution.hpp"

Resolution::Resolution(){
    this->x = 0;
    this->y = 0;
}

Resolution::Resolution(int x, int y){
    this->x = x;
    this->y = y;
}

Resolution::Resolution(Resolution &resolution){
    this->x = resolution.x;
    this->y = resolution.y;
}

void Resolution::setResolution(int x, int y){
    this->x = x;
    this->y = y;    
}

int Resolution::getX(){
    return this->x;
}

int Resolution::getY(){
    return this->y;
}