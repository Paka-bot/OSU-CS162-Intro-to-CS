#include <iostream>

#include "startup.hpp"

int prompt_first_pokemon() {
	int choice;
	do {
		std::cout << "Trainer 1: Which pokemon would you like?" <<
			std::endl;
		std::cout << "1. Charmander" << std::endl;
		std::cout << "2. Squirtle" << std::endl;
		std::cout << "3. Bulbasaur" << std::endl;
		std::cout << std::endl << "Your choice: ";
		std::cin >> choice;

		std::cout << std::endl;

		if (choice < 1 || choice > 3) {
			std::cout << "Invalid option!" <<
				std::endl << std::endl;
		}
	} while(choice < 1 || choice > 3);
	return choice;
}

int prompt_second_pokemon(int blacklisted_pokemon) {
	int choice;
	do {
		std::cout << "Trainer 2: Which pokemon would you like?" <<
			std::endl;

		if (blacklisted_pokemon == 1) {
			std::cout << "1. Squirtle" << std::endl;
			std::cout << "2. Bulbasaur" << std::endl;
		} else if (blacklisted_pokemon == 2) {
			std::cout << "1. Charmander" << std::endl;
			std::cout << "2. Bulbasaur" << std::endl;
		} else {
			std::cout << "1. Charmander" << std::endl;
			std::cout << "2. Squirtle" << std::endl;
		}

		std::cout << std::endl << "Your choice: ";
		std::cin >> choice;

		std::cout << std::endl;

		if (choice < 1 || choice > 2) {
			std::cout << "Invalid option!" <<
				std::endl << std::endl;
		}
	} while(choice < 1 || choice > 2);

	// Convert their entered choice to the following legend:
	// 1 = Charmander
	// 2 = Squirtle
	// 3 = Bulbasaur
	if (blacklisted_pokemon == 1) {
		choice = choice + 1;
	} else if (blacklisted_pokemon == 2) {
		if (choice == 2) {
			choice = 3;
		}
	}
	return choice;
}