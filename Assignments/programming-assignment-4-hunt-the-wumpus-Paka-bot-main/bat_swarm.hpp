#ifndef BAT_SWARM_HPP
#define BAT_SWARM_HPP

#include <iostream>
#include <cstdlib> 
#include <string>

#include "event.hpp"
#include "player.hpp"

using namespace std;

// TODO Bat Swarm interface (define the bat_swarm class and declare its member
// functions below)

class bat_swarm : public event {
public:
    void percept() const override;
    void encounter(player& p) const override;
    void print() const override;
    string get_event_name() const override;

    event* clone() const override;
};

#endif
