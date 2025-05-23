CC = g++
CFLAGS = -Wall
LDLIBS =

TARGET = 
OBJ = 

TARGET_TEST = $(TARGET_ESPACE_TEST) $(TARGET_CAMERA_TEST) $(TARGET_VECTEUR_TEST) $(TARGET_SPHERE_TEST) $(TARGET_COORDONNEE_TEST)

TARGET_ESPACE_TEST = espace_test
OBJ_ESPACE_TEST = Espace_test.o Camera.o Coordonnee.o Couleur.o Ecran.o Espace.o Pixel.o Vecteur.o Resolution.o Rayon.o Sphere.o Materiau.o Objet.o RaytracingPhongInfo.o Lumiere.o

TARGET_CAMERA_TEST = camera_test
OBJ_CAMERA_TEST = Camera_test.o Resolution.o Camera.o Vecteur.o Rayon.o Ecran.o Coordonnee.o Couleur.o Ecran.o Pixel.o   

TARGET_SPHERE_TEST = sphere_test
OBJ_SPHERE_TEST = Sphere_test.o Sphere.o Couleur.o Objet.o Materiau.o Rayon.o Vecteur.o Coordonnee.o    

TARGET_VECTEUR_TEST = vecteur_test
OBJ_VECTEUR_TEST = Vecteur_test.o Vecteur.o Coordonnee.o

TARGET_COORDONNEE_TEST = coordonnee_test
OBJ_COORDONNEE_TEST = Coordonnee_test.o Coordonnee.o

SRC = $(wildcard *.cpp)

all: $(TARGET)

test: $(TARGET_TEST)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^
	

$(TARGET_CAMERA_TEST): $(OBJ_CAMERA_TEST)
	$(CC) -o $@ $^

$(TARGET_ESPACE_TEST): $(OBJ_ESPACE_TEST)
	$(CC) -o $@ $^

$(TARGET_VECTEUR_TEST): $(OBJ_VECTEUR_TEST)
	$(CC) -o $@ $^

$(TARGET_SPHERE_TEST): $(OBJ_SPHERE_TEST)
	$(CC) -o $@ $^

$(TARGET_COORDONNEE_TEST): $(OBJ_COORDONNEE_TEST)
	$(CC) -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $< 
	
again: clean all

remove:
	make clean
	-rm $(TARGET)

clean:
	rm -f *.o $(TARGET) $(TARGET_TEST) 