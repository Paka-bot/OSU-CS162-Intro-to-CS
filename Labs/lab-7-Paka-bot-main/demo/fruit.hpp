#ifndef FRUIT_HPP
#define FRUIT_HPP

#include <string>

class fruit {
private:
	const std::string name;
	std::string color;
public:
	// Nondefault ctor
	fruit(const std::string& name, const std::string& color);

	// Prints the info about the fruit (name and color)
	void print_info() const;
};

#endif
