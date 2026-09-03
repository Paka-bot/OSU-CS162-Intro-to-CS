#include "bot.hpp"

#include <iostream>

using namespace std;

delivery_bot::delivery_bot(const string& brand, int year, double range, int num_door)
    : car(brand, year, range, num_door, true) {}

void delivery_bot::print_info() const {
    car::print_info();
}