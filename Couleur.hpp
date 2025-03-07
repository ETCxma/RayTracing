#ifndef COULEUR_H
#define COULEUR_H

class Couleur{

    public:
        Couleur();
        Couleur(Couleur &Couleur);
        Couleur(double intensité);

		//getteur
		double getIntensite();
    

    private:
        double intensité; // or r,g,b/spectrogram/...

};

#endif
