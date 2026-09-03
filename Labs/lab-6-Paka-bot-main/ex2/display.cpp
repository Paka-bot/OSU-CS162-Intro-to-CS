#include <iostream>

#include "display.hpp"
#include "shop.hpp"

void display_menu() {
	std::cout << "Choose an option:" << std::endl;
	std::cout << "1. Buy a lemonade" << std::endl;
	std::cout << "2. Buy a cookie" << std::endl;
	std::cout << "3. Quit" << std::endl;
}

void menu_loop() {
	shop s;
	int option;
	// This loop should keep running until either
	// A. The user types "3",
	// OR
	// B. The shop runs out of lemonade and cookies
	do {
		s.display_info();
		display_menu();
		std::cin >> option;

		if (option == 1) {
			if (s.out_of_lemonades()) {
				std::cout << "Sorry! We're out of stock" << std::endl;
			} else {
				s.buy_lemonade();
			}
		} else if (option == 2) {
			if (s.out_of_cookies()) {
				std::cout << "Sorry! We're out of stock" << std::endl;
			} else {
				s.buy_cookie();
			}
		}
		std::cout << std::endl << std::endl;
	} while (option != 3 && !s.out_of_stock());
}
