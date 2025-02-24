#ifndef COULEUR_H
#define COULEUR_H

class Couleur{

    public:
        Couleur();
        Couleur(Couleur &Couleur);
        Couleur(double intensité);
    

    private:
        double intensité; // or r,g,b/spectrogram/...

};

#endif
