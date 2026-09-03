#ifndef WUMPUS_HPP
#define WUMPUS_HPP

#include <iostream>
#include <string>

#include "event.hpp"
#include "player.hpp"

using namespace std;

// TODO Wumpus interface (define the wumpus class and declare its member
// functions below)

class wumpus : public event {
public:
    void percept() const override;
    void encounter(player& p) const override;
    void print() const override;
    string get_event_name() const override;

    event* clone() const override;
};

#endif
