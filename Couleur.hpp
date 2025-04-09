#ifndef COULEUR_H
#define COULEUR_H

class Couleur{

    public:
        Couleur();
        Couleur(Couleur &Couleur);
        Couleur(double intensité);

		// Getter
		double getIntensite();
		
        // Setters
        void setIntensite(double intensite);
        void addIntensite(double intensite);
    

    private:
        double intensite; // or r,g,b later

};

#endif
