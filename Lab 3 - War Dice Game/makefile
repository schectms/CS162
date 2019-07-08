#Shifra Schectman
#Lab 3 Makefile
#April 22, 2018

all: WarDiceGame 

WarDiceGame: Source.o Game.o Die.hpp Menu.o
	g++ Source.o Game.o Die.hpp Menu.o -o WarDiceGame

Source.o: Source.cpp
	g++ -c Source.cpp

Game.o: Game.cpp
	g++ -c Game.cpp

Menu.o: Menu.cpp
	g++ -c Menu.cpp

clean:
	rm *o WarDiceGame

