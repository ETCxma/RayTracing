#include "iostream"
#ifndef MATERIAU_H
#define MATERIAU_H

class Materiau{

    public:
        Materiau();
        Materiau(Materiau &materiau);
        Materiau(double i_s, double i_d, double i_a, double a);

        double getIndiceSpecular();
        double getIndiceDiffuse();
        double getIndiceAmbient();
        double getAlpha();

        void afficheMateriau();

    private:
        double indice_specular;
        double indice_diffuse;
        double indice_ambient;
        double alpha;
        // TODO: Add more
};

#endif