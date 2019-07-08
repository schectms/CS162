#Shifra Schectman
#CS162-Lab10
#June 10, 2018
#Makefile
PROG=Lab10
CC=g++ -std=c++11 
CFLAGS = -c 

SRC= FibonacciR.o FibonacciNR.o Source.o

OBJ=$(SRC:.cpp=.o)

$(PROG):$(OBJ)
	$(CC) $(LFLAGS) $(SRC) -o  $@
.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(PROG) $(OBJ) core.*


