PROG=Lab9
CC = g++
LFLAGS = -Wall
CFLAGS = -c -Wall

SRC= Menu.o Source.o 

OBJ=$(SRC:.cpp=.o)

$(PROG):$(OBJ)
	$(CC) $(LFLAGS) $(SRC) -o  $@
.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(PROG) $(OBJ) core.*

