
# RayTracing Project
This project is part of our training at Polytech Sorbonne engineering school.

## Avant d'exécuter le projet

Il est important de noter que en principe, le projet fonctionnerait avec tous les systèmes qui compilent le C++. Cependant, nous n'avons pas trouvé de moyen de gérer les Makefile sous Windows (on pourrait compiler tous les fichiers à la main). Plus précisément, nous n'avons testé que sur Ubuntu 24.04, il est donc fonctionnel sous ce système.

**Liste des librairies utilisées** :
- `<cmath>`
- `<string>`
- `<iostream>`
- `<vector>`
- `<fstream>`
- `<utility>`
- `<array>`

**Compilateur :** g++ (version 13.3.0 sous Ubuntu 24)
**Format d'image :** Portable Pixel Map (.ppm). C'est format complètement dénué de toute compression.

## Fichiers du projet
```
nepal@444-nuits:/RayTracing$ ls
├── Camera.hpp  
│   └── Camera.cpp  
│       └── Camera_test.cpp  
├── Coordonnee.hpp  
│   └── Coordonnee.cpp  
│       └── Coordonnee_test.cpp  
├── Couleur.hpp  
│   └── Couleur.cpp  
├── Ecran.hpp  
│   └── Ecran.cpp  
├── Espace.hpp  
│   └── Espace.cpp  
│       └── Espace_test.cpp  
├── Lumiere.hpp  
│   └── Lumiere.cpp  
├── Materiau.hpp  
│   └── Materiau.cpp  
├── Objet.hpp  
│   └── Objet.cpp  
├── Pixel.hpp  
│   └── Pixel.cpp  
├── Plan.hpp  
│   └── Plan.cpp  
│       └── Plan_test.cpp  
├── Point.hpp  
│   └── Point.cpp  
├── Rayon.hpp  
│   └── Rayon.cpp  
├── RayTracingPhongInfo.hpp  
│   └── RayTracingPhongInfo.cpp  
├── Resolution.hpp  
│   └── Resolution.cpp  
├── Sphere.hpp  
│   └── Sphere.cpp  
│       └── Sphere_test.cpp  
├── Triangle.hpp  
│   └── Triangle.cpp  
│       └── Triangle_test.cpp  
└── Vecteur.hpp  
    └── Vecteur.cpp  
        └── Vecteur_test.cpp  
```

## Comment exécuter le projet

- **Différents fichiers du projet** :
  On a choisi de faire une paire de fichiers `.hpp` et `.cpp` pour chaque classe. Au besoin, on créée aussi un fichier `_test.cpp`. Certaines classes héritent d'autres classes (e.g. Lumière hérite de Coordonnée). Ainsi pour tester une partie clé du projet, il suffit de faire `make NomDeLaPartieCle`

- **Exécution du projet** :
Afin de tester le Raytracing, il faut exécuter la commande
  `make espace_test`
  Vous générerez alors une image représentatif de l'espace décrit dans `Espace_test.cpp`.
  Pour avoir la forme souhaité, il suffit de modifier directement les Objets, Lumières et positionnement de la Caméra dans `Espace_test.cpp`. Voilà une façon de s'y prendre :
  - dans un premier temps, créez un espace,
  - puis une caméra,
  - puis une source de lumière.
  - Ajoutez ces deux derniers à l'espace.
  - Ensuite, créez les objets que vous voulez aux coordonnées que vous voulez (e.g. des sphères).
  - Ajoutez les objets à l'espace.
  - Pour capturer l'image, utilisez la méthode takePicture() de l'espace que vous avez créé.
  - L'image est alors ajoutée aux fichiers (si vous exécutez simplement sans modifier `Espace_test.cpp`, ça sera `IMAGE_POGGIES.ppm` mais le nom peut être changé directement dans le fichier source).
 
## Miscellaneous
- **Diagramme de classes** : ![Diagramme UML](https://github.com/ETCxma/RayTracing/blob/main/uml_diagram.png?raw=true)
- **Modèle de Ray Tracing implémenté** : [Modèle de Phong](https://en.wikipedia.org/wiki/Phong_reflection_model)
- **Remerciements** : Merci à MM. Hilaire et Dorfsman pour nous avoir partagé leurs connaissances et pour nous avoir suivi tout au long de ce projet. Malgré toutes les galères (en particulier la gestion des branches git), vous nous avez apporté un savoir qui nous suivra tout au long de notre vie d'ingénieur (ou au moins d'informaticien du dimanche si dans le futur on checkout une autre branche de métiers...), en plus d'être un projet qui nous tient à cœur.

