/*
TODO : 
- Complete Function Tree
- Figure out "Couleur"
- Pick model reflection model
- Make appropriate Getters/Setters
- Write triangle generation algorithm for various types of objects (Sphere, Cube, ...)
- Explore potential models for transparency/diffration



SETUP:
    Create space 
    Create Objects (and fill them with triangles)
    Create cameras (with parameters)
    
    Raytracing:

    TakePicture()
        - raytracing()
            - Check intersection with every triangle of object for each ray of the screen (via Space)
                - Calculate each ray position (via Camera and Screen)
                - For each triangle of each object check intersection (and get "usefulInfo" (tbd)) (via Screen into Object (not Triangle))
            - Calculate intensity (or r,g,b,...) via sum (e.g. Ambient + diffusion + specular)
                ?
            - convert to pixelValues 
                EZ if "Color" well-defined

        - writePixelBufferToPath()


*/