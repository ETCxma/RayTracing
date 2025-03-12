#include <iostream>
#include "Camera.hpp"

int main(int argc, char* argv[]){
    Camera c = Camera(Coordonnee(0,0,0), 1, 0, 0, Resolution(10, 10));

    for(int i = 0; i < c.getResolution().getX(); i++){
        for(int j = 0; j < c.getResolution().getY(); j++){
            std::cout << i << " " << j << ": ";
            c.getRayon(i, j).afficheVecteur("a");
            std::cout << std::endl;
        }
    }

    return 0;

}