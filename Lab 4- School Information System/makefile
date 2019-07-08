#Shifra Schectman
#Lab 4 Makefile
#April 22, 2018



all: OSUInfo  

OSUInfo: Source.o Instructor.o Person.o Student.o University.o Building.o
	g++ Source.o Instructor.o Person.o Student.o University.o Building.o -o OSUInfo  

Source.o: Source.cpp
	g++ -c Source.cpp

Instructor.o: Instructor.cpp
	g++ -c Instructor.cpp

Person.o: Person.cpp
	g++ -c Person.cpp

Student.o: Student.cpp
	g++ -c Student.cpp

University.o: University.cpp
	g++ -c University.cpp

Building.o: Building.cpp
	g++ -c Building.cpp

clean:
	rm *o OSUInfo


