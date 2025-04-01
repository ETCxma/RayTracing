#include <iostream>
#include "Camera.hpp"
using namespace std;

int main(int argc, char* argv[]){

    cout.precision(std::numeric_limits<double>::max_digits10-1);

    Camera c = Camera(Coordonnee(1,1,1), 1, M_PI_2 + M_1_PI, M_PI_2 + M_1_PI, Resolution(5, 5));

    for(int i = 0; i < c.getResolution().getX(); i++){
        for(int j = 0; j < c.getResolution().getY(); j++){
            cout << i << " " << j << "";
        }
    }
    return 0;
}
