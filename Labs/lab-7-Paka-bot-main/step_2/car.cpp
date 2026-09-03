#include "car.hpp"

#include <iostream>

using namespace std;

car::car(const string& brand, int year, double range, int num_door, bool electric)
    : vehicle(brand, year, range), num_door(num_door), electric(electric) {}

double car::fuel_price() const {
    return electric ? 1.5 / range : 2.0 / range;
}

void car::print_info() const {
    vehicle::print_info();
    cout << num_door << endl;
    cout << electric << endl;
    cout << car::fuel_price() << endl;
}
