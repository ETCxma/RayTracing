#ifndef MATERIAU_H
#define MATERIAU_H

class Materiau{

    public:
        Materiau();
        Materiau(Materiau &materiau);
        Materiau(double indice_spectular, double indice_diffuse, double indice_ambient);

    private:
        double indice_spectular;
        double indice_diffuse;
        double indice_ambient;
        // TODO: Add more
};

#endif