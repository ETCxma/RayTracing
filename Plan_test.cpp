#include "Plan.hpp"

using namespace std;

int main() {
    // Création de plusieurs plans pour tester différents cas

    // Test 1: Plan avec un vecteur normal simple
    Plan plan1(Vecteur(1, 0, 0), Coordonnee(3, 0, 0));
    cout << "Test 1 - Plan 1 :" << endl;
    plan1.afficher();
    cout << "Distance du Plan 1 à l'origine: " << plan1.distance() << endl;
    cout << "----------------------------------------" << endl;

    // Test 2: Plan avec un autre vecteur normal
    Plan plan2(Vecteur(0, 1, 0), Coordonnee(0, 4, 0));
    cout << "Test 2 - Plan 2 :" << endl;
    plan2.afficher();
    cout << "Distance du Plan 2 à l'origine: " << plan2.distance() << endl;
    cout << "----------------------------------------" << endl;

    // Test 3: Plan avec un vecteur normal en diagonale
    Plan plan3(Vecteur(1, 1, 1), Coordonnee(2, 2, 2));
    cout << "Test 3 - Plan 3 :" << endl;
    plan3.afficher();
    cout << "Distance du Plan 3 à l'origine: " << plan3.distance() << endl;
    cout << "----------------------------------------" << endl;

    // Test 4: Modifier un plan avec les setters et vérifier
    Plan plan4;
    cout << "Test 4 - Plan 4 (modification avec setters) :" << endl;
    plan4.setNormal(Vecteur(0, 0, 1));
    plan4.setOrigin(Coordonnee(0, 0, 5));
    plan4.afficher();
    cout << "Distance du Plan 4 à l'origine: " << plan4.distance() << endl;
    cout << "----------------------------------------" << endl;

    return 0;
}