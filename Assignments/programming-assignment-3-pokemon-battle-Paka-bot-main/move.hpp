#ifndef MOVE_HPP
#define MOVE_HPP

#include <string>

using namespace std;

class Move {
private:
    string name;	// Name of the move
    string type;	// Type of the move
    int base_damage;	// Base damage of the move
    int uses;	// uses of the move

public:
    Move();	// Default constructor
    Move(const string &name, const string &type, int base_damage, int uses);    // Parameterized constructor
	
    void use_move();	// Reduces uses by 1
    bool use_remain();	// Check if uses are remaining

    friend class Battle;	// Allows Battle class to access private members
    friend class Pokemon;	// Allows Pokemon class to access private members
};

#endif