#include <iostream>

#include "tornado.hpp"

using namespace std;

// TODO Implement the tornado's encounter() function override to confuse the
// player for 1 turn by calling the confuse() function on the player, and return
// true to indicate that the tornado should be removed from the board.
bool tornado::encounter(player& p) {
    p.confuse();
    return true;
}

// TODO Implement the tornado's print() function override to print "T"
// to the terminal (do NOT print std::endl after the "T")
void tornado::print() const {
    cout << "T";
}