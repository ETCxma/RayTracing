/**
 * 
 * FICHIER TEST DES MÉTHODES DE Coordonnee.hpp
 * 
 */

#include "Vecteur.hpp"
using namespace std; 



int main(int argc, char* argv[]){

    Vecteur u; 
    Vecteur v(1, 2, 3); 
    Vecteur w(4, 5, 6); 
    Vecteur x(7, 8, 9); 
    Vecteur y(2, 4, 6);     // Lié à v car y=lambda*v, où lambda = 2. 

    u.afficheVecteur("u"); 
    cout << endl; 
    v.afficheVecteur("v"); 
    cout << endl; 
    w.afficheVecteur("w");
    cout << endl; 
    x.afficheVecteur("x");
    cout << endl; 
    y.afficheVecteur("y");
    cout << endl; 
    cout << endl; 


    // TEST DU CALCUL DE LA NORME
    cout << string(70, '-') << endl;
    cout << "Premier test: calcul des normes de u et v." << endl; 
    cout << "||u|| = " << u.norme() << "\t La norme de u vaut 0." << endl;
    cout << "||v|| = " << v.norme() << "\t La norme de v vaut 3.74." << endl;
    cout << string(70, '-') << endl; 
    cout << endl; 


    // TEST DU CALCUL DE VECTEUR UNITAIRE
    cout << string(70, '-') << endl; 
    cout << "Deuxième test: calcul des vecteurs unitaires de u et v." << endl; 
    (u.unitaire()).afficheVecteur("u_u"); 
    cout << "\t le vecteur unitaire de u est (0, 0, 0)." << endl; 
    (v.unitaire()).afficheVecteur("v_u"); 
    cout << "\t le vecteur unitaire de v est (0.26, 0.53, 0.80)." << endl;  
    cout << string(70, '-') << endl; 
    cout << endl; 


    // TEST DU PRODUIT SCALAIRE
    cout << string(70, '-') << endl; 
    cout << "Troisième test: produit scalaire." << endl; 
    cout << "-- COMMUTATIVITÉ:" << endl; 
    cout << "\t TEST: <v.w> = " << v.produitScalaire(w) << " et " << "<w.v> = " << w.produitScalaire(v) << endl; 
    cout << "\t VÉRIFICATION: le résultat doit êter 32" << endl; 

    cout << "-- DISTRIBUTIVITÉ:" << endl; 
    Vecteur s1 = w+x; 
    cout << "\t TEST: <v.(w+x)> = " << v.produitScalaire(s1) << " et " << "<v.w>+<v.x> = " << v.produitScalaire(w)+v.produitScalaire(x) << endl; 
    cout << "\t VÉRIFICATION: le résultat doit être 82" << endl; 

    cout << "-- SÉPARATION:" << endl; 
    cout << "\t TEST: <u.u> = " << u.produitScalaire(u) << endl; 
    cout << "\t VÉRIFICATION: le résultat doit être 0" << endl;  

    cout << "-- AVEC DES SCALAIRES:" << endl; 
    double lambda = 3.8;      // Arbitraire
    Vecteur p1 = w*lambda; 
    cout << "\t TEST: <(lambda*v).w> = " << (v*lambda).produitScalaire(w) << endl;
    cout << "\t TEST: <v.(lambda*w)> = " << v.produitScalaire(p1) << endl; 
    cout << "\t TEST: lambda*<v.w> = " << lambda*(v.produitScalaire(w)) << endl; 
    cout << "\t VÉRIFICATION: le résultat doit être 121.6" << endl;   
    cout << string(70, '-') << endl; 
    cout << endl; 


    // TEST DU PRODUIT VECTORIEL
    cout << string(70, '-') << endl; 
    cout << "Quatrième test: produit vectoriel." << endl; 
    cout << "-- ORTHOGONALITÉ:" << endl; 
    Vecteur res1 = v.produitVectoriel(y); 
    cout << "\t TEST: "; 
    res1.afficheVecteur("v^y");
    cout << endl; 
    cout << "\t VÉRIFICATION: le résultat doit être (0,0,0)" << endl; 

    cout << "-- ANTISYMÉTRIE:" << endl; 
    cout << "\t TEST: ";
    (v.produitVectoriel(w)).afficheVecteur("v^w"); 
    cout << endl;
    cout << "\t TEST: ";
    ((w.produitVectoriel(v))*(-1)).afficheVecteur("-(w^v)"); 
    cout << endl; 
    cout << "\t VÉRIFICATION: le résultat doit être (-3,6,-3)" << endl;

    cout << "-- BILINÉARITÉ:" << endl; 
    cout << "\t TEST: ";
    ((v+w).produitVectoriel(x)).afficheVecteur("(v+w)^x"); 
    cout << endl; 
    cout << "\t TEST: ";
    Vecteur op1 = v.produitVectoriel(x);
    Vecteur op2 = w.produitVectoriel(x);
    Vecteur res2 = op1+op2; 
    res2.afficheVecteur("v^x+w^x"); 
    cout << endl; 
    cout << "\t VÉRIFICATION: le résultat doit être (-9,18,-9)" << endl; 
    cout << string(70, '-') << endl; 
    cout << endl; 


    // TEST DU CHANGEMENT DE COORDONNÉES DE CARTÉSIEN À SPHÉRIQUE
    cout << string(70, '-') << endl; 
    cout << "Cinquième test: changement de coordonnées des cartésiennes aux sphériques." << endl; 
    cout << "\t TEST: ";
    v.afficheVecteur("v_cartésien");
    cout << "\t"; 
    (v.cartesienToSpherique()).afficheVecteur("v_spherique");
    (v.cartesienToSpherique().spheriqueToCartesien()).afficheVecteur("v_spherique_to_c");
    cout << endl; 
    cout << "\t VÉRIFICATION: le résultat doit être (3.74,0.64,1.10)" << endl; 
    cout << string(70, '-') << endl; 
    cout << endl; 

    // TEST ROTATION
    cout << string(70, '-') << endl; 
    cout << "Sixième test: Rotation de vecteur." << endl; 
    cout << "\t TEST: ";
    Vecteur v2(1,0,0);
    v2.afficheVecteur("v_initial");
    cout << "\t"; 
    v2.rotationPhi(M_PI);
    v2.afficheVecteur("v_rotated +pi (phi)");
    cout << "\t VÉRIFICATION: le résultat doit être (-1,0,0)" << endl; 
    cout << endl; 
    v2.rotationTheta(-M_PI_2);
    v2.afficheVecteur("v_rotated +pi/2 (theta)");
    cout << "\t VÉRIFICATION: le résultat doit être (0,0,1)" << endl; 
    cout << string(70, '-') << endl; 
    cout << endl; 
 


    return 0; 

}