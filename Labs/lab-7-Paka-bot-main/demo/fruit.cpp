#include <iostream>

#include "fruit.hpp"

// Remember: name is a constant member variable, so it MUST be initialized
// by the member initializer list in the ctor. The color COULD be initialized
// in the ctor body, but we may as well use the initializer list for it as well.
fruit::fruit(const std::string& name, const std::string& color) :
		name(name),
		color(color) {}

void fruit::print_info() const {
	std::cout << "Name: " << this->name << std::endl <<
		"Color: " << this->color << std::endl;
}
