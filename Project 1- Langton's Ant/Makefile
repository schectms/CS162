all: antSim 

output: main.o Ant.o Menu.o
	g++ main.o Ant.o Menu.o -o output

main.o: main.cpp
	g++ -c main.cpp

Ant.o: Ant.cpp
	g++ -c Ant.cpp

Menu.o: Menu.cpp
	g++ -c Menu.cpp

clean:
	rm *o antSim
