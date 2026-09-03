#ifndef EX1_H
#define EX1_H 

struct Car
{
	std::string brand;
	int num_passenger;
};

struct Garage
{
	int num_cars; //keep track of the size of the car array
	Car* car_arr;
};

Car* create_cars(int size);
void populate_car (Car& c, std::ifstream& fin);
void populate_garage(Garage& g, std::ifstream& fin);
void print_garage(Garage& g);
void delete_garage(Garage& g);



#endif
