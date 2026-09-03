#include "vehicle.hpp"

#include <iostream>

using namespace std;

vehicle::vehicle(const string& brand, int year, double range)
    : brand(brand), year(year), range(range) {}

double vehicle::fuel_price() const {
    return 0;
}

void vehicle::print_info() const {
    cout << brand << endl;
    cout << year << endl;
    cout << range << endl;
}
