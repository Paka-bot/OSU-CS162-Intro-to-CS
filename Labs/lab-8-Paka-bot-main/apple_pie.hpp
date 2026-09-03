#ifndef APPLE_PIE_HPP
#define APPLE_PIE_HPP

#include "event.hpp"
#include "player.hpp"

// TODO Define the apple pie class and prototype its encounter() and print()
// functions
class apple_pie : public event {
public:
    bool encounter(player& p) override;
    void print() const override;
};

#endif
