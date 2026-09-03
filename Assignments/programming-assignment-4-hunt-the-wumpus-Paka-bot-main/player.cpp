#include "player.hpp"

player::player()
    : x(0), y(0), arrows(0), gold(false), alive(true), confused(false) {}

void player::move_right() {
    x++;
}

void player::move_left() {
    x--;
}

void player::move_up() {
    y--;
}

void player::move_down() {
    y++;
}

int player::get_x() const {
    return x;
}

int player::get_y() const {
    return y;
}

void player::start_position(int start_x, int start_y) {
    x = start_x;
    y = start_y;
}

void player::add_arrows() {
    arrows += 3;
}

void player::use_arrows() {
    arrows--;
}

int player::check_arrows() const {
    return arrows;
}

void player::get_gold() {
    gold = true;
}

bool player::check_gold() const {
    return gold;
}

void player::kill_player() {
    alive = false;
}

bool player::check_alive() const {
    return alive;
}

void player::make_confused() {
    confused = true;
}

void player::reset_confused() {
    confused = false;
}

bool player::check_confused() {
    return confused;
}
