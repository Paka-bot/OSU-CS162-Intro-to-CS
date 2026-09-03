#ifndef BASEBALL_PLAYER_HPP
#define BASEBALL_PLAYER_HPP

#include <fstream>

using namespace std;

struct baseball_player {
	string first_name;
	string last_name;
	double batting_average;
};

/*
 * Function: create_players
 * Description: Allocates a dynamic array of baseball player structs
 * 		of the given size
 * Parameters:
 * 		size (int): Number of baseball players to allocate in the array
 * Returns (baseball_player*): Pointer to base address of dynamically
 * 		allocated array
 * Post-conditions: Dynamic array of baseball players allocated. The
 * 		responsibility of freeing this array's memory falls to the function
 * 		caller.
 **/
baseball_player* create_players(int size);

/*
 * Function: print_player
 * Description: Prints the details of the given baseball player to the
 * 		terminal
 * Parameters:
 * 		player (const baseball_player&): The baseball player whose data
 * 		should be printed to the terminal
 */
void print_player(const baseball_player& player);

/*
 * Function: read_player_data
 * Description: Reads the data for the next baseball player from the given
 * 		file and return a baseball player containing that data
 * Parameters:
 * 	file (std::ifstream&): The file stream from which to read the player's
 * 		data (std::ifstream objects must be passed by reference). The
 * 		file stream must be "prepared" to read the next baseball
 * 		player's information (i.e., the next stream extraction operator
 * 		used on the file stream must read the next player's first name,
 * 		and so on).
 * Returns: A baseball_player structure containing the information of the data
 * 	read from the given file.
 */
baseball_player read_player_data(ifstream& file);

/*
 * Function: prompt_for_file_name
 * Description: Prompts the user for the data file name via the terminal
 * Returns (string): The file name supplied by the user
 */
string prompt_for_file_name();

/*
 * Function: delete_player_info
 * Description: Frees dynamic memory associated with baseball player array
 * Parameters:
 * 		players (baseball_player*): Pointer to base address of array to free
 * Post-conditions: The array pointed to by the given pointer is freed from
 * 		memory.
 */
void delete_player_info(baseball_player* players);

#endif
