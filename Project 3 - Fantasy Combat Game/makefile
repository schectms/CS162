#Shifra Schectman
#May 13, 2018
#CS 162-Project3
#Makefile

PROG=Project3
CC = g++
LFLAGS = -Wall
CFLAGS = -c -Wall

SRC= Menu.o Game.o Source.o Character.o Vampire.o Barbarian.o BlueMen.o Medusa.o HarryPotter.o

OBJ=$(SRC:.cpp=.o)

$(PROG):$(OBJ)
	$(CC) $(LFLAGS) $(SRC) -o  $@
.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(PROG) $(OBJ) core.*

