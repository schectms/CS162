PROG=Project4
CC = g++ -std=c++0x

SRC= Menu.o Game.o Source.o Character.o Vampire.o Barbarian.o BlueMen.o Medusa.o HarryPotter.o DynIntQueue.o

OBJ=$(SRC:.cpp=.o)

$(PROG):$(OBJ)
	$(CC) $(LFLAGS) $(SRC) -o  $@
.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(PROG) $(OBJ) core.*

