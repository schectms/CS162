all: output

output: main.o Matrix.o Determinant.o
	g++ main.o Matrix.o Determinant.o -o output

main.o: main.cpp
	g++ -c main.cpp

Matrix.o: Matrix.cpp
	g++ -c Matrix.cpp

Determinant.o: Determinant.cpp
	g++ -c Determinant.cpp

clean:
	rm *o output

