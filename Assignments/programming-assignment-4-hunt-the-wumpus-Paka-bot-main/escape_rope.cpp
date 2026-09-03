#include "escape_rope.hpp"

using namespace std;

// TODO Escape rope implementation (define escape_rope member functions below)

void escape_rope::percept() const {
}

void escape_rope::encounter(player& p) const {
    cout << "You found the escape rope!" << endl;

    if (p.check_gold()) {
        cout << "You have the gold! You successfully escape the cave. You win!" << endl;
    } else {
        cout << "You can't escape without the gold!" << endl;
    }
}

void escape_rope::print() const {
    cout << "R";
}

string escape_rope::get_event_name() const {
    return "escaperope";
}

event* escape_rope::clone() const {
    return new escape_rope(*this);
}