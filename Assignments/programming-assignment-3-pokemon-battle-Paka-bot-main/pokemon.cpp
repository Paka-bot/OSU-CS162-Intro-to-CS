/*
Author: Yunseong Cho
file description: This cpp file defines the functions for the Pokemon class, which represents each Pokemon with its specific stats, type, and moves in the battle.
*/

#include "pokemon.hpp"
#include <iostream>

using namespace std;

/*
Function: Pokemon (parameterized constructor)
Description: Initializes a Pokemon object with specified values.
Parameters: name (const string&) - The name of the Pokemon.
            type (const string&) - The type of the Pokemon.
            hp (int) - The maximum health points of the Pokemon.
            attack (int) - The attack stat of the Pokemon.
            defense (int) - The defense stat of the Pokemon.
            moves (Move*) - A dynamic array of Move objects assigned to the Pokemon.
            num_moves (int) - The number of moves assigned to the Pokemon.
Returns: N/A
*/
Pokemon::Pokemon(const string &name, const string &type, int hp, int attack, int defense, Move* moves, int num_moves)
    : name(name), type(type), max_hp(hp), current_hp(hp), attack(attack), defense(defense), num_moves(num_moves) {
    this->moves = new Move[num_moves];
    for (int i = 0; i < num_moves; i++) {
        this->moves[i] = moves[i];
    }
}

/*
Function: ~Pokemon (destructor)
Description: Frees the dynamic array of Move objects.
Parameters: N/A
Returns: N/A
*/
Pokemon::~Pokemon() {
    delete[] moves;
}

/*
Function: Pokemon (copy constructor)
Description: Initializes a new Pokemon object as a copy of an existing Pokemon object.
Parameters: other (const Pokemon&) - The Pokemon object to copy.
Returns: N/A
*/
Pokemon::Pokemon(const Pokemon& other)
    : name(other.name), type(other.type), max_hp(other.max_hp), current_hp(other.current_hp), attack(other.attack), defense(other.defense), num_moves(other.num_moves) {
    moves = new Move[num_moves];
    for (int i = 0; i < num_moves; ++i) {
        moves[i] = other.moves[i];
    }
}

/*
Function: operator= (assignment operator)
Description: Assigns a value from an existing Pokemon object to another Pokemon object.
Parameters: other (const Pokemon&) - The Pokemon object to assign from.
Returns: A reference to the updated Pokemon object.
*/
Pokemon& Pokemon::operator=(const Pokemon& other) {
    if (this != &other) {
        delete[] moves;

        name = other.name;
        type = other.type;
        max_hp = other.max_hp;
        current_hp = other.current_hp;
        attack = other.attack;
        defense = other.defense;
        num_moves = other.num_moves;

        moves = new Move[num_moves];
        for (int i = 0; i < num_moves; ++i) {
            moves[i] = other.moves[i];
        }
    }
    return *this;
}

/*
Function: create_pokemon (static member function)
Description: Creates a specific Pokemon object based on a choice parameter.
Parameters: choice (int) - The choice representing which Pokemon to create (1 for Charmander, 2 for Squirtle, 3 for Bulbasaur).
Returns: A Pokemon object corresponding to the choice.
*/
Pokemon Pokemon::create_pokemon(int choice) {
    if (choice == 1) {
        Move charmander_moves[] = {Move("Scratch", "normal", 3, 10000), Move("Ember", "fire", 5, 3)};
        return Pokemon("Charmander", "fire", 18, 6, 4, charmander_moves, 2);
    } else if (choice == 2) {
        Move squirtle_moves[] = {Move("Scratch", "normal", 3, 10000), Move("Water Gun", "water", 5, 3)};
        return Pokemon("Squirtle", "water", 22, 4, 6, squirtle_moves, 2);
    } else {
        Move bulbasaur_moves[] = {Move("Scratch", "normal", 3, 10000), Move("Vine Whip", "grass", 5, 3)};
        return Pokemon("Bulbasaur", "grass", 20, 5, 5, bulbasaur_moves, 2);
    }
}