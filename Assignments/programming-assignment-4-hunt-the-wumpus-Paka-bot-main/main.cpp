/*
Author: Yunseong Cho

Program description: This program is a game where the player enters the Wumpus's cave 
and must find gold and escape or kill the Wumpus with arrows. In this game, the Wumpus' cave 
is a 2D array. Each room can contain at most one event or no events. Each turn, the player 
can move to one of the rooms (East, West, South, North) adjacent to the current room. The player 
starts at a random location in the 2D array of caves and there is a rope to escape from the starting location. 
There are two conditions for the player to lose in this game. The first is entering a room with a Wumpus, or 
entering a room with a bottomless_pit event, and there is a 50% chance of dying.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "game.hpp"

/*
 * Function: get_width
 * Description: Prompts the user for the game board width (# of columns)
 * Returns (int): Valid width supplied by user
 */
int get_width() {
	int width;
	bool first = true;
	do {
		if (!first) {
			std::cout << std::endl << "Invalid width!" << std::endl <<
				std::endl;
		}
		first = false;
		std::cout << "Enter the game board width between 4 and 30: ";
		std::cin >> width;
	} while(width < 4 || width > 30);
	return width;
}

/*
 * Function: get_height
 * Description: Prompts the user for the game board height (# of columns)
 * Returns (int): Valid height supplied by user
 */
int get_height() {
	int height;
	bool first = true;
	do {
		if (!first) {
			std::cout << std::endl << "Invalid height!" << std::endl <<
				std::endl;
		}
		first = false;
		std::cout << "Enter the game board height between 4 and 30: ";
		std::cin >> height;
	} while(height < 4 || height > 30);
	return height;
}

/*
 * Function: get_debug
 * Description: Prompts the user whether they want to play in debug mode
 * Returns (bool): True if the user wants to play in debug mode. False
 * 		otherwise.
 */
bool get_debug() {
	int debug_input;
	bool first = true;
	do {
		if (!first) {
			std::cout << std::endl << "Invalid input!" << std::endl <<
				std::endl;
		}
		first = false;
		std::cout << "Would you like to play in debug mode? (1-yes, 0-no): ";
		std::cin >> debug_input;
	} while(debug_input != 0 && debug_input != 1);
	return debug_input == 1;
}

int main()
{
	// Set the random seed
	srand(time(nullptr));
	
	// Ask user for width and height of game board
	int width = get_width();
	int height = get_height();

	// Ask user whether they want debug mode
	bool debug = get_debug();

	// Construct game object
	game g(width, height, debug);

	//Play game
	g.play_game();

	return 0;
}
