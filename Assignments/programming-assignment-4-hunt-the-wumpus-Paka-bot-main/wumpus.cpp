#include "wumpus.hpp"

using namespace std;

// TODO Wumpus implementation (define wumpus member functions below)

void wumpus::percept() const {
    cout << "The hairs stand up on the back of your neck." << endl;
}

void wumpus::encounter(player& p) const {
    cout << "Scary Wumpus killed you!, Game Over" << endl;
    p.kill_player();
}

void wumpus::print() const {
    cout << "W";
}

string wumpus::get_event_name() const {
    return "Wumpus";
}

event* wumpus::clone() const {
    return new wumpus(*this);
}