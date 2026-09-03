#include <fstream>
#include <iostream>

#include "ex1.hpp"

//allocate an array of cars
Car* create_cars(int size){
	return new Car [size];
}

//populate a single car object
void populate_car (Car& c, std::ifstream& fin){
	fin >> c.brand >> c.num_passenger;
}

//populate the garage object
void populate_garage(Garage& g, std::ifstream& fin){
	
	//loop through number of cars
	for (int i = 0; i < g.num_cars; ++i)
	{
		populate_car(g.car_arr[i], fin); // overflow g.num_cars -> i
	}
}

//print the garage object
void print_garage (Garage& g) {
	
	for (int i = 0; i < g.num_cars; ++i)
	{
		std::cout << "Brand: " << g.car_arr[i].brand << std::endl;
		std::cout << "Num: " << g.car_arr[i].num_passenger << std::endl;
		std::cout << std::endl;
	}
}


//delete function to free memory allocated in g
void delete_garage(Garage& g){
	delete [] g.car_arr;
	g.car_arr = nullptr;
}
