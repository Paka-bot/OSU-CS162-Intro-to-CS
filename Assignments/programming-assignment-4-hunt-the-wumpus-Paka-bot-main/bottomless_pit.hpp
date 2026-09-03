#ifndef BOTTOMLESS_PIT_HPP
#define BOTTOMLESS_PIT_HPP

#include <iostream>
#include <cstdlib> 
#include <string>

#include "event.hpp"
#include "player.hpp"

using namespace std;

// TODO Bottomless Pit interface (define the bottomless_pit class and declare
// its member functions below)

class bottomless_pit : public event {
public:
    void percept() const override;
    void encounter(player& p) const override;
    void print() const override;
    string get_event_name() const override;

    event* clone() const override;
};

#endif
