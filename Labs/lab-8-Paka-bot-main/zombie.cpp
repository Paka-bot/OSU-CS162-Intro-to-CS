#include <iostream>

#include "zombie.hpp"

using namespace std;

// TODO Implement the zombie's encounter() function override to damage the
// player by 2 HP and return false to indicate that it shouldn't be removed
// from the board.
bool zombie::encounter(player& p) {
    p.take_damage(2);
    return false;
}

// TODO Implement the zombie's print() function override to print "Z"
// to the terminal
void zombie::print() const {
    cout << "Z";
}
