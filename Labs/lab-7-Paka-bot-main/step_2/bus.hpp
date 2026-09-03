#ifndef BUS_HPP
#define BUS_HPP

#include <string>

#include "vehicle.hpp"

using namespace std;

class bus : public vehicle {
private:
    int seat_capacity;

public:
    bus(const string& brand, int year, double range, int seat_capacity);

    double fuel_price() const;
    void print_info() const;
};

#endif
