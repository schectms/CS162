#Shifra Schectman
#May 13, 2018
#CS162-Lab6
#makefile

PROG=Lab7
CC = g++ -std=c++11
LFLAGS = -Wall
CFLAGS = -c -Wall

SRC= Menu.o Source.o DynIntQueue.o

OBJ=$(SRC:.cpp=.o)

$(PROG):$(OBJ)
	$(CC) $(LFLAGS) $(SRC) -o  $@
.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(PROG) $(OBJ) core.*


