#include <iostream>
#include <fstream>

#include "ex1.hpp"


int main()
{
	//file stream object
	std::ifstream file;
	file.open("file.txt");


	//error opening the file
	if (!file.is_open()){
		std::cout << "Error opening the file!" << std::endl; 
		return 1;
	}

	//read info from file into Garage g
	Garage g;
	file >> g.num_cars;

	g.car_arr = create_cars(g.num_cars); // Car* car_arr -> g.car_arr

	populate_garage(g, file);
	
	print_garage(g);

	delete_garage(g);

	return 0;
}
