// TODO Write your name here: Yunseong Cho

#include <iostream>
#include <vector> // Standard library vector

#include "vector.hpp" // Your custom vector class

int main() {
	std::vector<std::string> std_vector; // Standard library vector
	vector<std::string> custom_vector; // Your custom vector class

	std_vector.push_back("World");
	custom_vector.push_back("World");

	std_vector.insert(std_vector.begin(), "Hello");
	custom_vector.insert(0, "Hello");

	// TODO Comment out the below print statement after finishing part 3
	/*
	std::cout << "Don't forget to comment / uncomment the appropriate " <<
		"lines after completing part 3 of the lab" << std::endl;
	*/
	

	// TODO Uncomment these lines after finishing part 3
	std::cout << "First element in standard vector: " << std_vector[0] <<
		std::endl;
	std::cout << "First element in your vector: " << custom_vector[0] <<
		std::endl;

	std::cout << "Second element in standard vector: " << std_vector[1] <<
		std::endl;
	std::cout << "Second element in your vector: " << custom_vector[1] <<
		std::endl;
	

	// Your vector copy constructor
	vector<std::string> new_custom_vector = custom_vector;
	
	// TODO Uncomment these lines after finishing part 3
	std::cout << "First element in your copy-constructed vector: " <<
		new_custom_vector[0] << std::endl;
	std::cout << "Second element in your copy-constructed vector: " <<
		new_custom_vector[1] << std::endl;
	

	// Your vector AOO
	new_custom_vector = custom_vector;
	
	// TODO Uncomment these lines after finishing part 3
	std::cout << "First element in your AOO-copied vector: " <<
		new_custom_vector[0] << std::endl;
	std::cout << "Second element in your AOO-copied vector: " <<
		new_custom_vector[1] << std::endl;

	// Test self-assignment
	custom_vector = custom_vector;
}
