COMPILER = g++

CFLAGS = -g -Wall

exe_file = run

$(exe_file): run_wizard.o catalog.o
	$(COMPILER) $(CFLAGS) run_wizard.o catalog.o -o $(exe_file)

run_wizard.o: run_wizard.cpp catalog.hpp
	$(COMPILER) $(CFLAGS) -c run_wizard.cpp -o run_wizard.o

catalog.o: catalog.cpp catalog.hpp
	$(COMPILER) $(CFLAGS) -c catalog.cpp -o catalog.o

clean:
	rm -f *.o $(exe_file)
