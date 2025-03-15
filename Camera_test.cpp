#include <iostream>
#include "Camera.hpp"

int main(int argc, char* argv[]){

    std::cout.precision(std::numeric_limits<double>::max_digits10-1);

    Camera c = Camera(Coordonnee(1,1,1), 1, M_PI_2, 0, Resolution(5, 5));

    for(int i = 0; i < c.getResolution().getX(); i++){
        for(int j = 0; j < c.getResolution().getY(); j++){
            std::cout << i << " " << j << "";
            c.getRayon(i, j).afficheVecteur("");
        }
    }

    return 0;

}