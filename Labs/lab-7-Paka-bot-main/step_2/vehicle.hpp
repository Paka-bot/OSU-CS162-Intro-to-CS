#ifndef VEHICLE_HPP
#define VEHICLE_HPP

#include <string>

using namespace std;

class vehicle {
private:
    const string brand;
    int year;

protected:
    double range;
    
public:
    double fuel_price() const;
    void print_info() const;

    vehicle(const string& brand, int year, double range);
};

#endif
