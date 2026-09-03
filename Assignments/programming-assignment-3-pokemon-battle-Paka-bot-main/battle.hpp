#ifndef BATTLE_HPP
#define BATTLE_HPP

#include "pokemon.hpp"

class Battle {
private:
    Pokemon* trainer1_pokemon;	// Pointer to Trainer 1's Pokemon
    Pokemon* trainer2_pokemon;	// Pointer to Trainer 2's Pokemon

    bool turn;	// In the start function in battle.cpp, I implemented the player's turn by using the ternary operator to set player 1 to be the attacker and player 2 to be the defender when the value of turn is true, and set player 1 to be the defender and player 2 to be the attacker when the value is false.
    bool trainer1_take_heal;	// Check if trainer 1 used heal
    bool trainer2_take_heal;	// Check if trainer 2 used heal

    int calculate_damage(const Move& move, const Pokemon& attacker, const Pokemon& defender);	// Calculates damage

    bool fainted(const Pokemon& pokemon);	// Checks if a Pokemon has fainted
    void take_damage(Pokemon& pokemon, int damage);	// Reduces the Pokemon's hp by taking the damage calculated in calculate_damage as a parameter.
    void take_heal(Pokemon& pokemon);	// Heals Pokemon's hp by 10

    void list_moves(const Pokemon& pokemon);	// Prints the moves that the Pokemon has

public:
    Battle(Pokemon* trainer1_pokemon, Pokemon* trainer2_pokemon);	// Constructor to initialize battle with two Pokemon
    void start();	// Pokemon battle start
};

#endif