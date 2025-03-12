CC = g++
CFLAGS = -Wall
LDLIBS =

TARGET = 
OBJ = 

TARGET_TEST = 

TARGET_ESPACE_TEST = espace_test
OBJ_ESPACE_TEST = Espace_test.o Camera.o Coordonnee.o Couleur.o Ecran.o Espace.o Pixel.o Vecteur.o Resolution.o Rayon.o

TARGET_CAMERA_TEST = camera_test
OBJ_CAMERA_TEST = Camera_test.o Resolution.o Camera.o Vecteur.o Rayon.o Ecran.o Coordonnee.o Couleur.o Ecran.o Pixel.o   

SRC = $(wildcard *.cpp)

all: $(TARGET)

test: $(TARGET_TEST)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^
	

$(TARGET_CAMERA_TEST): $(OBJ_CAMERA_TEST)
	$(CC) -o $@ $^

$(TARGET_ESPACE_TEST): $(OBJ_ESPACE_TEST)
	$(CC) -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $< 
	
again: clean all

remove:
	make clean
	-rm $(TARGET)

clean:
	rm -f *.o $(TARGET) 