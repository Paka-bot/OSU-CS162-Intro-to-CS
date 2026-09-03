#ifndef POKEMON_HPP
#define POKEMON_HPP

#include "move.hpp"
#include <string>

using namespace std;

class Pokemon {
private:
    string name;	// Name of the Pokemon
    string type;	// Type of the Pokemon
    int max_hp; // Pokemon's base health
    int current_hp;	// Current health points
    int attack; // Attack stat
    int defense;    // Defense stat
    Move* moves;	// Array of moves assigned to the Pokemon
    int num_moves;	// Number of moves Pokemon has

public:
    Pokemon(const string &name, const string &type, int hp, int attack, int defense, Move* moves, int num_moves);  // Parameterized constructor
    ~Pokemon();  // Destructor to free move array
    Pokemon(const Pokemon& other);  // Copy constructor for deep copying a Pokemon
    Pokemon& operator=(const Pokemon& other);  // Copy assignment operator for deep copying a Pokemon

    static Pokemon create_pokemon(int choice);  // Function that creates a specific Pokemon based on your choice

    friend class Battle;  // Allows Battle to access private members
};

#endif