#Author: Group 39
# Date: 5/11/2018
# Description: makefile

PROG=GroupProject
CC = g++ -std=c++11
LFLAGS = -Wall
CFLAGS = -c -Wall

SRC= Menu.o main.o InputValidation.o Doodlebug.o Critter.o Board.o Ant.o

OBJ=$(SRC:.cpp=.o)

$(PROG):$(OBJ)
	$(CC) $(LFLAGS) $(SRC) -o  $@
.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(PROG) $(OBJ) core.*


