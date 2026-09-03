#include <iostream>

#include "apple.hpp"

// When constructing an apple, pass in the color and diameter as arguments.
// The name "Apple" will be forwarded to the nondefault fruit ctor along with
// the given color. The diameter will be stored directly in the apple's diameter
// member variable.
apple::apple(const std::string& color, double diameter) :
		fruit("Apple", color), // Call base-class nondefault ctor
		diameter(diameter) {}

void apple::print_info() const {
	// First, print the apple's fruit-related data by calling its fruit
	// print_info() member function
	this->fruit::print_info();
	
	// Now print its apple-related info
	std::cout << "Diameter: " << this->diameter << std::endl;
}
