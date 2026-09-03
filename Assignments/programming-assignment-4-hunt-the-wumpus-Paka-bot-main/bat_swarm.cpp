#include "bat_swarm.hpp"

using namespace std;

// TODO Bat Swarm implementation (define bat_swarm member functions below)

void bat_swarm::percept() const {
    cout << "You hear screeching." << endl;
}

void bat_swarm::encounter(player& p) const {
    cout << "A swarm of bats has confused you!" << endl;
    p.make_confused();
}

void bat_swarm::print() const {
    cout << "B";
}

string bat_swarm::get_event_name() const {
    return "batswarm";
}

event* bat_swarm::clone() const {
    return new bat_swarm(*this);
}