CC = g++ -g
exe_file = ex2

$(exe_file): display.o shop.o main.o
	$(CC) display.o shop.o main.o -o $(exe_file)

display.o: display.cpp display.hpp
	$(CC) -c display.cpp

shop.o: shop.cpp shop.hpp
	$(CC) -c shop.cpp

main.o: main.cpp
	$(CC) -c main.cpp

clean:
	rm -f *.o $(exe_file)
