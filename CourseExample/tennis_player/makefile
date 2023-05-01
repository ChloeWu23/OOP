execute: main.o date.o name.o person.o
		g++ main.o date.o name.o person.o -o execute

main.o: main.cpp date.h name.h person.h
		g++ -c -g main.cpp 

date.o: date.cpp date.h 
		g++ -c -g date.cpp

name.o: name.cpp name.h
		g++ -c -g name.cpp

person.o: person.cpp person.h
		g++ -c -g person.cpp
