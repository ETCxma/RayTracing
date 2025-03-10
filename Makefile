CC = g++
CFLAGS = -Wall
LDLIBS =

TARGET = 
OBJ = 

SRC = $(wildcard *.cpp)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^
	
%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $< 
	
again: clean all

remove:
	make clean
	-rm $(TARGET)

clean:
	rm -f *.o $(TARGET) 