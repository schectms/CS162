#Shifra Schectman
#May 5, 2018
#CS 162-Lab5
#Makefile

PROG=Lab5
CC = g++
LFLAGS = -Wall
CFLAGS = -c -Wall

SRC= Menu.o sum.o triangle.o reverse.o Source1.o 
OBJ=$(SRC:.cpp=.o)

$(PROG): $(OBJ) 
	$(CC) $(LFLAGS) $(SRC) -o  $@ 
.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
 		    
clean:
	rm -rf $(PROG) $(OBJ) core.*

