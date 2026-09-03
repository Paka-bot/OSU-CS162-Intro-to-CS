#include <iostream>

#include "rectangle.hpp"

rectangle::rectangle() {
	// Empty. Member variables are initialized to their default values
	// (or garbage if they don't have defaults). Alternatively, you could
	// declare rectangle() = default; in .hpp file. That's equivalent to
	// defining an empty body here.
}

// Set this->width = width parameter, and this->height = height parameter, by
// using a member initializer list.
rectangle::rectangle(double width, double height) :
		width(width),
		height(height) {
	// Empty body. All of the work is done by the member initializer list
	// above. That's very common for most basic constructors
}

double rectangle::get_width() const {
	return this->width;
	// or simply `return width;`
}

double rectangle::get_height() const {
	return this->height;
	// or simply `return height;`
}

void rectangle::set_width(double width) {
	this->width = width;
}

void rectangle::set_height(double height) {
	this->height = height;
}

void rectangle::print() const {
	std::cout << "My width is " << this->width << std::endl;
	std::cout << "My height is " << this->height << std::endl;
}

double rectangle::area() const {
	return this->width * this->height;
}
