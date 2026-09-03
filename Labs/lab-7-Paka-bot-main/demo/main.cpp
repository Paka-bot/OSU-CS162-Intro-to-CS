#include <iostream>

#include "fruit.hpp"
#include "apple.hpp"

int main() {
	fruit f("Banana", "Yellow");
	f.print_info();

	std::cout << std::endl;

	apple a("Red", 3.5);
	a.print_info();
}
