#ifndef MATERIAU_H
#define MATERIAU_H

class Materiau{

    public:
        Materiau();
        Materiau(Materiau &materiau);
        Materiau(double indice_spectular, double indice_diffuse, double indice_ambient);

        double getIndiceSpectular();
        double getIndiceDiffuse();
        double getIndiceAmbient();
        double getAlpha();

    private:
        double indice_spectular;
        double indice_diffuse;
        double indice_ambient;
        double alpha;
        // TODO: Add more
};

#endif