/*
Author: Yunseong Cho

Program description: This program is a simplified Pokemon battle. There are two players, 
and each chooses a different Pokemon to start the battle. The trainer can use the Pokemon's 
skills or use a recovery potion to heal the Pokemon during his turn. The battle ends when one of the Pokemon faints.
*/

#include <iostream>

#include "startup.hpp"
#include "pokemon.hpp"
#include "battle.hpp"

#include <ctime>

int main() {
	srand(time(0));

	int trainer_1_pokemon_choice = prompt_first_pokemon();
	int trainer_2_pokemon_choice = prompt_second_pokemon(
		trainer_1_pokemon_choice
	);

	Pokemon trainer1_pokemon = Pokemon::create_pokemon(trainer_1_pokemon_choice);
    Pokemon trainer2_pokemon = Pokemon::create_pokemon(trainer_2_pokemon_choice);

    Battle battle(&trainer1_pokemon, &trainer2_pokemon);
    battle.start();

    return 0;
}