execute: main.o date.o name.o person.o
	g++ main.o date.o name.o person.o -o execute

main.o: main.cpp date.h name.h person.h
	g++ -c -g -Wall main.cpp

date.o: date.cpp date.h
	g++ -c -g -Wall date.cpp

name.o: name.cpp name.h
	g++ -c -g -Wall name.cpp

person.o: person.cpp person.h name.h date.h
	g++ -c -g -Wall person.cpp	

clean:
	rm -f *.o execute
