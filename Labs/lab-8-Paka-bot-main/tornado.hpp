#ifndef TORNADO_HPP
#define TORNADO_HPP

#include "event.hpp"
#include "player.hpp"

// TODO Define the tornado class and prototype its encounter() and print()
// functions
class tornado : public event {
public:
    bool encounter(player& p) override;
    void print() const override;
};

#endif
