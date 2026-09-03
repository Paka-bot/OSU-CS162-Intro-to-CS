#include "bottomless_pit.hpp"

using namespace std;

// TODO Bottomless Pit implementation (define bottomless_pit member functions
// below)

void bottomless_pit::percept() const {
    cout << "You feel a breeze." << endl;
}

void bottomless_pit::encounter(player& p) const {
    if (rand() % 2 == 0) {
        cout << "You fell into the pit and died!" << endl;
        p.kill_player();
    } else {
        cout << "You barely escaped the pit!" << endl;
    }
}

void bottomless_pit::print() const {
    cout << "P";
}

string bottomless_pit::get_event_name() const {
    return "bottomlesspit";
}

event* bottomless_pit::clone() const {
    return new bottomless_pit(*this);
}