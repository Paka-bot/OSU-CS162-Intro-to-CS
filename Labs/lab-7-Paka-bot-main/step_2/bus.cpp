#include "bus.hpp"

#include <iostream>

using namespace std;

bus::bus(const string& brand, int year, double range, int seat_capacity)
    : vehicle(brand, year, range), seat_capacity(seat_capacity) {}

double bus::fuel_price() const {
    return 20.0 / range;
}

void bus::print_info() const {
    vehicle::print_info();
    cout << seat_capacity << endl;
    cout << bus::fuel_price() << endl;
}
