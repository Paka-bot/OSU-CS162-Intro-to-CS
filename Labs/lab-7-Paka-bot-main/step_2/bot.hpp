#ifndef BOT_HPP
#define BOT_HPP

#include <string>

#include "car.hpp"

using namespace std;

class delivery_bot : public car {
public:
    delivery_bot(const string& brand, int year, double range, int num_door);

    void print_info() const;

};

#endif