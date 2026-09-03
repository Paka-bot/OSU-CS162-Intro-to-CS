#ifndef CAR_HPP
#define CAR_HPP

#include <string>

#include "vehicle.hpp"

using namespace std;

class car : public vehicle {
private:
    int num_door;
    bool electric;

public:
    car(const string& brand, int year, double range, int num_door, bool electric);

    double fuel_price() const;
    void print_info() const;
};

#endif
