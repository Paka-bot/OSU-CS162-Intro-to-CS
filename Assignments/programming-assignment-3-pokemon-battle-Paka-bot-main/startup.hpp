#ifndef STARTUP_HPP
#define STARTUP_HPP

/*
 * Function: prompt_first_pokemon
 * Description: Prompts trainer 1 for their pokemon of choice. Loops until
 * 	user supplies valid choice value.
 * Returns (int): Numeric code for trainer 1's pokemon of choice. Returns 1 if
 * 	the trainer chooses Charmander, 2 if the trainer chooses Squirtle, and
 * 	3 if the trainer chooses Bulbasaur.
 */
int prompt_first_pokemon();

/*
 * Function: prompt_second_pokemon
 * Description: Prompts trainer 2 for their pokemon of choice. Loops until
 * 	user supplies valid choice value. Does not allow user to choose
 * 	the blacklisted pokemon (which should be the numeric code for the
 * 	pokemon chosen by trainer 1)
 * Parameters:
 * 	blacklisted_pokemon (int): The numeric code of the pokemon that trainer
 * 		2 is NOT allowed to choose. This should be the numeric code
 * 		of the pokemon chosen by trainer 1, as returned by
 * 		prompt_first_pokemon(), which will prevent the two trainers
 * 		from choosing the same pokemon.
 * Returns (int): Numeric code for trainer 2's pokemon of choice. Returns 1 if
 * 	the trainer chooses Charmander, 2 if the trainer chooses Squirtle, and
 * 	3 if the trainer chooses Bulbasaur.
 */
int prompt_second_pokemon(int blacklisted_pokemon);

#endif