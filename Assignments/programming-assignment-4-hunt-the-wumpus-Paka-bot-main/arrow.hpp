#ifndef ARROW_HPP
#define ARROW_HPP

#include <iostream>
#include <string>

#include "event.hpp"
#include "player.hpp"

using namespace std;

// TODO Arrow interface (define the arrow class and declare its member functions
// below)

class arrow : public event {
public:
    void percept() const override;
    void encounter(player& p) const override;
    void print() const override;
    string get_event_name() const override;

    event* clone() const override;
};

#endif
