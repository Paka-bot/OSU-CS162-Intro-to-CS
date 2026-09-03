#ifndef ESCAPE_ROPE_HPP
#define ESCAPE_ROPE_HPP

#include <iostream>
#include <string>

#include "event.hpp"
#include "player.hpp"

using namespace std;

// TODO Escape rope interface (define the escape_rope class and declare its
// member functions below)

class escape_rope : public event {
public:
    void percept() const override;
    void encounter(player& p) const override;
    void print() const override;
    string get_event_name() const override;

    event* clone() const override;
};

#endif
