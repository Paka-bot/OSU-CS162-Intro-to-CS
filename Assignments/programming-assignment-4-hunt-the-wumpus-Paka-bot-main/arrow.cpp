#include "arrow.hpp"

using namespace std;

// TODO Arrow implementation (define arrow member functions below)

void arrow::percept() const {
}

void arrow::encounter(player& p) const {
    cout << "You found arrows!" << endl;
    p.add_arrows();
}

void arrow::print() const {
    cout << "A";
}

string arrow::get_event_name() const {
    return "arrow";
}

event* arrow::clone() const {
    return new arrow(*this);
}