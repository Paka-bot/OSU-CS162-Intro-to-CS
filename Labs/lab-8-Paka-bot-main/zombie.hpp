#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include "event.hpp"
#include "player.hpp"

// TODO Define the zombie class and prototype its encounter() and print()
// functions
class zombie : public event {
public:
    bool encounter(player& p) override;
    void print() const override;
};

#endif
