#include "gold.hpp"

using namespace std;

// TODO Gold implementation (define gold member functions below)

void gold::percept() const {
    cout << "You stub your toe on something heavy." << endl;
}

void gold::encounter(player& p) const {
    cout << "You found the gold!" << endl;
    p.get_gold();
}

void gold::print() const {
    cout << "G";
}

string gold::get_event_name() const {
    return "gold";
}

event* gold::clone() const {
    return new gold(*this);
}