CC=g++  -g
exe1=ex1

all: $(exe1) 

$(exe1): ex1.o main.o
	$(CC) main.o ex1.o -o $(exe1)

main.o: main.cpp
	$(CC) -c main.cpp

ex1.o: ex1.hpp ex1.cpp
	$(CC) -c ex1.cpp


clean: 
	rm -f *.o $(exe1)
