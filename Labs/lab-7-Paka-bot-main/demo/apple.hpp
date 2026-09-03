#ifndef APPLE_HPP
#define APPLE_HPP

#include "fruit.hpp"

// An apple "is-a" kind of fruit
class apple : public fruit {
private:
	// Apples additionally "have-a" diameter
	double diameter;
public:
	// All apples are named "Apple", so we don't need a name parameter here.
	// But apples can come in various colors and diameters, so we do need
	// parameters for that data.
	apple(const std::string& color, double diameter);

	// Override print_info() function to additionally print diameter
	void print_info() const;
};

#endif
