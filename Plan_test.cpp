#include "Plan.hpp"

using namespace std;

int main() {

    // Création d'un plan avec des coordonnées spécifiques
    Coordonnee origine(1, 1, 1);
    Coordonnee c1(2, 3, 4);
    Coordonnee c2(4, 5, 6);
    Coordonnee centre(2, 2, 2);

    Plan plan2(origine, c1, c2, centre);
    cout << "Plan 2 (coordonnées personnalisées): " << endl;
    plan2.afficher();
    cout << endl;

    // Test de la méthode vec()
    array<Vecteur, 2> vecteurs = plan2.vec();
    cout << "Vecteurs du Plan 2: " << endl;
    cout << "Vecteur 1: (" << vecteurs[0].getDX() << ", " << vecteurs[0].getDY() << ", " << vecteurs[0].getDZ() << ")" << endl;
    cout << "Vecteur 2: (" << vecteurs[1].getDX() << ", " << vecteurs[1].getDY() << ", " << vecteurs[1].getDZ() << ")" << endl;
    cout << endl;

    // Test du vecteur normal
    Vecteur normal = plan2.vecteurNormal();
    cout << "Vecteur normal du Plan 2: (" << normal.getDX() << ", " << normal.getDY() << ", " << normal.getDZ() << ")" << endl;
    cout << endl;

    // Test de la distance du plan à l'origine
    double d = plan2.distance();
    cout << "Distance du centre du Plan 2 à l'origine: " << d << endl;

    return 0;
}