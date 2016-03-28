
all:	main

main:	main.o System.o Envir.o  Indiv.o 
	g++  main.o System.o Envir.o  Indiv.o -o main -g -O4
	
main.o:	main.cpp System.h Envir.h Indiv.h
	g++	-c	main.cpp	-o	main.o	--std=c++11	-g -Wall -Wextra -O4
	
System.o: System.cpp System.h Envir.h Indiv.h 
	g++	-c	System.cpp	-o	System.o	--std=c++11	-g -Wall -Wextra -O4

Envir.o: Envir.cpp Envir.h 
	g++	-c	Envir.cpp	-o	Envir.o	--std=c++11	-g -Wall -Wextra -O4

Indiv.o: Indiv.cpp Indiv.h
	g++	-c	Indiv.cpp	-o	Indiv.o	--std=c++11	-g -Wall -Wextra -O4
	
	
	
clean:
	rm -f *.o
