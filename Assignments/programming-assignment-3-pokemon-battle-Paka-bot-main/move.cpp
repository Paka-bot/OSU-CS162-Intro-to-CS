/*
Author: Yunseong Cho
file description: This cpp file defines the functions related to the Move class, representing the moves a Pokemon can perform in the battle.
*/

#include "move.hpp"

using namespace std;

/*
Function: Move (default constructor)
Description: Initializes a Move object with default values.
Parameters: N/A
Returns: N/A
*/
Move::Move() : name(""), type(""), base_damage(0), uses(0) {}

/*
Function: Move (parameterized constructor)
Description: Initializes a Move object with specific name, type, base damage, and remaining uses.
Parameters: name (const string&) - The name of the move.
            type (const string&) - The type of the move.
            base_damage (int) - The base damage of the move.
            uses (int) - The number of times the move can be used.
Returns: N/A
*/
Move::Move(const string &name, const string &type, int base_damage, int uses)
    : name(name), type(type), base_damage(base_damage), uses(uses) {}

/*
Function: use_remain
Description: Check if there are remaining uses for the move.
Parameters: N/A
Returns: true if the move has remaining uses, false otherwise.
*/
bool Move::use_remain() {
    return uses > 0;
}

/*
Function: use_move
Description: Decreases the remaining uses of the move by 1, if there are uses left.
Parameters: N/A
Returns: N/A
*/
void Move::use_move() {
    if (uses > 0) {
        uses--;
    }
}