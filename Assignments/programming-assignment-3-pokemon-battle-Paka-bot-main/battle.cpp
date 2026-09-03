/*
Author: Yunseong Cho
file description: This cpp file defines the functions for the Battle class, handling all battle mechanics between two Pokemon, including damage calculations and turn-based actions.
*/

#include "battle.hpp"
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>

using namespace std;

/*
Constructor: Battle (parameterized constructor)
Description: Initializes each trainer's Pokemon, turns, and healing potion usage.
Parameters: trainer1_pokemon (Pokemon*) - Pointer to Trainer 1's chosen Pokemon. 
            trainer2_pokemon (Pokemon*) - Pointer to Trainer 2's chosen Pokemon.
Returns: N/A
*/
Battle::Battle(Pokemon* trainer1_pokemon, Pokemon* trainer2_pokemon)
    : trainer1_pokemon(trainer1_pokemon), trainer2_pokemon(trainer2_pokemon), turn(true), trainer1_take_heal(false), trainer2_take_heal(false) {
}

/*
Function: calculate_damage
Description: Calculates the damage dealt by a move based on the attacker’s and defender’s stats and types.
Parameters: move (const Move&) - The move being used to attack.
            attacker (const Pokemon&) - The attacking Pokemon.
            defender (const Pokemon&) - The defending Pokemon.
Returns: double - The calculated damage after all modifiers.
*/
int Battle::calculate_damage(const Move& move, const Pokemon& attacker, const Pokemon& defender) {
    
    double type_interaction = 1.0;

    if ((move.type == "fire" && defender.type == "grass") ||
        (move.type == "water" && defender.type == "fire") ||
        (move.type == "grass" && defender.type == "water")) {

        type_interaction = 2.0;

    } else if ((move.type == "fire" && defender.type == "water") ||
               (move.type == "water" && defender.type == "grass") ||
               (move.type == "grass" && defender.type == "fire")) {

        type_interaction = 0.5;
    }

    double random_zero_to_one = static_cast<double>(rand()) / RAND_MAX;

    double random_multiplier = 0.8 + (random_zero_to_one * 0.4);

    double random_critical = (rand() % 10 == 0) ? 3.0 : 1.0;

    double damage = ceil((static_cast<double>(attacker.attack) / defender.defense) *
                              type_interaction * move.base_damage * random_multiplier * random_critical);

    cout << "Performing damage calculation...\n"
            << "Value of type_interaction: " << type_interaction << "\n"
            << "Value of random_multiplier: " << random_multiplier << "\n"
            << "Value of random_critical: " << random_critical << "\n"
            << "Value of damage: " << damage << "\n";

    return damage;
}

/*
Function: fainted
Description: Check if the given Pokemon has fainted.
Parameters: pokemon (const Pokemon&) - The Pokemon to check.
Returns: bool - True if fainted, otherwise false.
*/
bool Battle::fainted(const Pokemon& pokemon) {
    return pokemon.current_hp <= 0;
}

/*
Function: take_damage
Description: Reduces the Pokemon's hp by taking the damage calculated in calculate_damage as a parameter.
Parameters: pokemon (Pokemon&) - The Pokemon taking damage.
            damage (int) - The amount of damage to apply.
Returns: N/A
*/
void Battle::take_damage(Pokemon& pokemon, int damage) {
    pokemon.current_hp -= damage;
    if (pokemon.current_hp < 0) pokemon.current_hp = 0;
}

/*
Function: take_heal
Description: Heals Pokemon's hp by 10, ensuring it does not exceed max HP.
Parameters: pokemon (Pokemon&) - The Pokemon to heal.
Returns: N/A
*/
void Battle::take_heal(Pokemon& pokemon) {
    pokemon.current_hp += 10;
    if (pokemon.current_hp > pokemon.max_hp) pokemon.current_hp = pokemon.max_hp;
    cout << pokemon.name << " has healed by 10 HP!\n" << endl;
}

/*
Function: list_moves
Description: Lists available moves and their remaining uses for the given Pokemon.
Parameters: pokemon (const Pokemon&) - The Pokemon whose moves to list.
Returns: N/A
*/
void Battle::list_moves(const Pokemon& pokemon) {
    for (int i = 0; i < pokemon.num_moves; i++) {
        cout << i + 1 << ". " << pokemon.moves[i].name 
                  << " (" << pokemon.moves[i].uses << " uses remaining)\n";
    }
}

/*
Function: start
Description: Manages the turn-based battle loop between Trainer 1 and Trainer 2's Pokemon.
Outputs the progress and results of each turn until one Pokemon faints.
Parameters: N/A
Returns: N/A
*/
void Battle::start() {
    while (!fainted(*trainer1_pokemon) && !fainted(*trainer2_pokemon)) {
        cout << "It’s " << (turn ? "trainer 1’s" : "trainer 2’s") << " turn.\n";

        Pokemon& attacker = turn ? *trainer1_pokemon : *trainer2_pokemon;
        Pokemon& defender = turn ? *trainer2_pokemon : *trainer1_pokemon;

        bool& take_heal_used = turn ? trainer1_take_heal : trainer2_take_heal;

        cout << attacker.name << " has " << attacker.current_hp << "/" << attacker.max_hp << " HP remaining\n";
        cout << defender.name << " has " << defender.current_hp << "/" << defender.max_hp << " HP remaining\n" << endl;

        int choice;
        int move_choice;

        bool valid_action = false;

        while (!valid_action) {
            cout << "Would you like to 1) use a move, or 2) heal?: ";
            cin >> choice;

            if (choice == 1) {
                cout << endl << "Which move would you like to use?\n";
                list_moves(attacker);
                cout << endl << "Your choice: ";
                cin >> move_choice;

                if (move_choice > 0 && move_choice <= attacker.num_moves) {
                    Move& selected_move = attacker.moves[move_choice - 1];
                    if (selected_move.use_remain()) {
                        int damage = calculate_damage(selected_move, attacker, defender);
                        take_damage(defender, damage);
                        cout << endl;
                        selected_move.use_move();
                        valid_action = true;
                    } else {
                        cout << "Error: " << selected_move.name << " has no uses remaining!\n";
                    }
                } else {
                    cout << "Error: Invalid choice! Please choose again.\n";
                }

            } else if (choice == 2) {
                if (!take_heal_used) {
                    take_heal(attacker);
                    take_heal_used = true;
                    valid_action = true;
                } else {
                    cout << "Error: You don’t have any healing potions left!\n";
                }
            } else {
                cout << "Error: Invalid choice! Please choose again.\n";
            }
        }

        turn = !turn;
    }

    cout << (fainted(*trainer1_pokemon) ? "Trainer 2 wins!" : "Trainer 1 wins!") << "\n";
}
