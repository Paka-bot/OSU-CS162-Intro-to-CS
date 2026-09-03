#include <iostream>

#include "rectangle.hpp"

int main() {
	// Using default constructor and setters
	rectangle r1;
	r1.set_width(10);
	r1.set_height(2.5);
	r1.print();
	std::cout << "r1's area: " << r1.area() << std::endl;

	// Using nondefault constructor
	rectangle r2(10, 2.5);
	r2.print();
	std::cout << "r2's area: " << r2.area() << std::endl;
}
