#ifndef MATERIAU_H
#define MATERIAU_H

class Materiau{

    public:
        Materiau();
        Materiau(Materiau &materiau);
        Materiau(double indice_interne);

    private:
        double indice_interne;
        // TODO: Add more
};

#endif