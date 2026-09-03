/*
Author: Yunseong Cho
File Description: This cpp file defines the member functions for the game class, handling the game 
mechanics of the Wumpus game, including player movement, event triggering, and game state checking.
*/

#include <iostream>

#include "game.hpp"
#include "gold.hpp"
#include "bat_swarm.hpp"
#include "bottomless_pit.hpp"
#include "wumpus.hpp"
#include "escape_rope.hpp"
#include "arrow.hpp"

#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

// game implementation

/*
Function: move_wumpus_randomly
Description: Moves the Wumpus to a random empty room on the game board.
Parameters: N/A
Returns: N/A
*/
void game::move_wumpus_randomly() {
    // Remove the Wumpus from its current location
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            event* current_event = game_board[y][x].get_event();
            if (current_event && current_event->get_event_name() == "Wumpus") {
                game_board[y][x].remove_event();
            }
        }
    }

    // Place the Wumpus in a new random empty room
    int new_x, new_y;
    do {
        new_x = rand() % width;
        new_y = rand() % height;
    } while (game_board[new_y][new_x].get_event() != nullptr);

    game_board[new_y][new_x].set_event(new wumpus());
}

/*
Function: display_percepts
Description: Displays percepts of events in adjacent rooms to the player.
Parameters: N/A
Returns: N/A
*/
void game::display_percepts() const {
    int player_x = p.get_x();
    int player_y = p.get_y();

    cout << "Percepts around you: " << endl;

    // Check and trigger percepts in adjacent rooms
    if (player_y > 0) {
        game_board[player_y - 1][player_x].trigger_percept();
    }
    if (player_y < height - 1) {
        game_board[player_y + 1][player_x].trigger_percept();
    }
    if (player_x > 0) {
        game_board[player_y][player_x - 1].trigger_percept();
    }
    if (player_x < width - 1) {
        game_board[player_y][player_x + 1].trigger_percept();
    }
}

/*
Constructor: game (parameterized constructor)
Description: Initializes the game board, places events randomly, and sets the player's starting position.
Parameters:
    width (int) - Width of the game board.
    height (int) - Height of the game board.
    debug (bool) - Debug mode flag.
Returns: N/A
*/
game::game(int width, int height, bool debug) :
        width(width),
        height(height),
        debug(debug) {
    // TODO Create the game board: 2D vector of room objects
    game_board = vector<vector<Room>>(height, vector<Room>(width));

    // TODO Randomly insert events (2 bat_swarms, 2 bottomless_pits,
    // 1 wumpus, 1 gold, 2 arrows, 1 escape rope) into the board

    int player_x = rand() % width;
    int player_y = rand() % height;
    p.start_position(player_x, player_y);

    vector<event*> events = {
        new arrow(), new arrow(),
        new gold(), new wumpus(),
        new bat_swarm(), new bat_swarm(),
        new bottomless_pit(), new bottomless_pit()
    };

    game_board[player_y][player_x].set_event(new escape_rope());

    for (event* e : events) {
        int x;
        int y;
        do {
            x = rand() % width;
            y = rand() % height;
        } while (game_board[y][x].get_event() != nullptr);

        game_board[y][x].set_event(e);
    }
}

/*
Function: display_game
Description: Displays the current state of the game board, including player position and events (if in debug mode).
Parameters: N/A
Returns: N/A
*/
void game::display_game() const{
    std::cout << endl << std::endl;
    std::cout << "Arrows remaining: " << p.check_arrows() << std::endl;

    string row_border = "--";
    for (int i = 0; i < this->width; ++i) {
        row_border += "-------";
    }

    cout << row_border << endl;
    for (int y = 0; y < this->height; ++y) {
        cout << "||";
        for (int x = 0; x < this->width; ++x) {
            // The first char indicates whether there is a player in the room
            // at row index i, column index j. TODO If the room contains the
            // player, print an asterisk ("*")

            // TODO else, print a space (" ")

            // The next char indicates the event in the room.

            // TODO If debug mode is disabled OR the room at location <i, j>
            // does not have an event, print a space (" ")
            // For example:
            // if (!this->debug || <i, j> ROOM DOES NOT HAVE EVENT) {
            //  cout << " ";
            // }
            //
            // TODO else, print the room's debug symbol. There are a few ways to
            // do this. You can use polymorphism, or an event could have a
            // char debug_symbol member variable and some sort of
            // get_debug_symbol() member function that you could call here
            // to get the character and print it.

            if (p.get_x() == x && p.get_y() == y) {
                cout << " * ";
            } else {
                cout << "   ";
            }

            if (debug && game_board[y][x].get_event() != nullptr) {
                game_board[y][x].display_event();
            } else {
                cout << " ";
            }

            std::cout << " ||";
        }
        std::cout << endl;
        std::cout << row_border << endl;
    }
}

/*
Function: check_win
Description: Checks if the player has met the conditions to win the game.
Parameters: N/A
Returns: bool - True if the player has won, false otherwise.
*/
bool game::check_win() const {

    if (p.check_gold()) {
        int player_x = p.get_x();
        int player_y = p.get_y();

        const Room& current_room = game_board[player_y][player_x];
        event* current_event = current_room.get_event();

        if (current_event && current_event->get_event_name() == "escaperope") {
            return true;
        }
    }

    if (!wumpus_alive) {
        return true;
    }

    return false;
}

/*
Function: check_lose
Description: Checks if the player has met the conditions to lose the game.
Parameters: N/A
Returns: bool - True if the player has lost, false otherwise.
*/
bool game::check_lose() const{
    // TODO Delete the below placeholder code. Return true if the player
    // has lost the game. Return false otherwise.

    if (!p.check_alive()) {
        return true;
    }
    return false;
}

/*
Function: is_direction
Description: Checks if the provided character is a valid movement direction.
Parameters: c (char) - The character to check.
Returns: bool - True if the character is a valid direction, false otherwise.
*/
bool game::is_direction(char c) {
    return c == 'w' ||
        c == 'a' ||
        c == 's' ||
        c == 'd';
}

/*
Function: to_lower
Description: Converts an uppercase character to lowercase.
Parameters: direction (char) - The character to convert.
Returns: char - The lowercase version of the character.
*/
char game::to_lower(char direction) {
    if (direction >= 'A' && direction <= 'Z') {
        return direction + ('a' - 'A');
    }
    return direction;
}

/*
Function: can_move_in_direction
Description: Checks if the player can move in the given direction without moving off the grid.
Parameters: direction (char) - The direction to check ('w', 'a', 's', 'd').
Returns: bool - True if the player can move in that direction, false otherwise.
*/
bool game::can_move_in_direction(char direction) {
    // TODO Delete the below placeholder code. Return true if the player can
    // move in the given direction ('w' for up, 'a' for left, 's' for down,
    // 'd' for right). Return false otherwise. The player can move in the
    // given direction so long as it wouldn't cause them to move off the
    // grid.

    int player_x = p.get_x();
    int player_y = p.get_y();

    switch (direction) {
        case 'w':
            return player_y > 0;
        case 'a':
            return player_x > 0;
        case 's':
            return player_y < height - 1;
        case 'd':
            return player_x < width - 1;
        default:
            return false;
    }
}

/*
Function: is_valid_action
Description: Determines if the player's action is valid (movement or firing an arrow).
Parameters: action (char) - The action character input by the player.
Returns: bool - True if the action is valid, false otherwise.
*/
bool game::is_valid_action(char action) {
    if (this->is_direction(action)) {
        char direction = action;
        return this->can_move_in_direction(direction);
    } else if (action == 'f') {
        return p.check_arrows() > 0;
    }
    return false;
}

/*
Function: print_action_error
Description: Prints an error message based on the invalid action the player attempted.
Parameters: action (char) - The invalid action character.
Returns: N/A
*/
void game::print_action_error(char action) {
    if (this->is_direction(action)) {
        std::cout << "You can't move in that direction!" << std::endl <<
            std::endl;
    } else if (action == 'f') {
        std::cout << "You're out of arrows!" << std::endl << std::endl;
    } else {
        std::cout << std::endl << "That's an invalid input!" << std::endl
            << std::endl;
    }
}

/*
Function: get_player_action
Description: Prompts the player for their next action and validates it.
Parameters: N/A
Returns: char - The valid action input by the player.
*/
char game::get_player_action() {
    char action;
    bool first = true;
    do {
        if (!first) {
            char previous_action = action;
            this->print_action_error(previous_action);
        }
        first = false;

        std::cout << std::endl << std::endl << "What would you like to do?" <<
            std::endl << std::endl;
        std::cout << "w: move up" << std::endl;
        std::cout << "a: move left" << std::endl;
        std::cout << "s: move down" << std::endl;
        std::cout << "d: move right" << std::endl;
        std::cout << "f: fire an arrow" << std::endl;

        std::cin >> action;
        action = this->to_lower(action);
    } while (!this->is_valid_action(action));

    return action;
}

/*
Function: get_arrow_fire_direction
Description: Prompts the player for the direction to fire an arrow.
Parameters: N/A
Returns: char - The valid direction input by the player.
*/
char game::get_arrow_fire_direction() {
    char direction;
    bool first = true;
    do {
        if (!first) {
            std::cout << std::endl << "That's an invalid input!" <<
                std::endl << std::endl;
        }
        first = false;

        std::cout << std::endl << std::endl <<
            "What direction would you like to fire the arrow?" << std::endl <<
            std::endl;
        std::cout << "w: up" << std::endl;
        std::cout << "a: left" << std::endl;
        std::cout << "s: down" << std::endl;
        std::cout << "d: right" << std::endl;

        std::cin >> direction;
        direction = this->to_lower(direction);
    } while (!this->is_direction(direction));

    return direction;
}

/*
Function: move_up
Description: Moves the player up one space on the grid.
Parameters: N/A
Returns: N/A
*/
void game::move_up() {
    // TODO Delete the below placeholder code. Move the player up one
    // space in the grid, however you choose to do that.

    if (can_move_in_direction('w')) {
        p.move_up();
    }
}

/*
Function: move_down
Description: Moves the player down one space on the grid.
Parameters: N/A
Returns: N/A
*/
void game::move_down() {
    // TODO Delete the below placeholder code. Move the player down one
    // space in the grid, however you choose to do that.

    if (can_move_in_direction('s')) {
        p.move_down();
    }
}

/*
Function: move_left
Description: Moves the player left one space on the grid.
Parameters: N/A
Returns: N/A
*/
void game::move_left() {
    // TODO Delete the below placeholder code. Move the player left one
    // space in the grid, however you choose to do that.

    if (can_move_in_direction('a')) {
        p.move_left();
    }
}

/*
Function: move_right
Description: Moves the player right one space on the grid.
Parameters: N/A
Returns: N/A
*/
void game::move_right() {
    // TODO Delete the below placeholder code. Move the player right one
    // space in the grid, however you choose to do that.

    if (can_move_in_direction('d')) {
        p.move_right();
    }
}

/*
Function: move
Description: Moves the player in the specified direction, accounting for confusion status.
Parameters: direction (char) - The direction to move ('w', 'a', 's', 'd').
Returns: N/A
*/
void game::move(char direction) {
    if (p.check_confused()) {
        p.reset_confused();

        int random_num = rand() % 4;

        switch (random_num) {
            case 0:
                this->move_up();
                break;
            case 1:
                this->move_left();
                break;
            case 2:
                this->move_down();
                break;
            default:
                this->move_right();
                break;
        }
    } else {
        if (direction == 'w') {
            this->move_up();
        } else if (direction == 'a') {
            this->move_left();
        } else if (direction == 's') {
            this->move_down();
        } else {
            this->move_right();
        }
    }
}

/*
Function: fire_arrow_up
Description: Fires an arrow upwards and checks for hitting the Wumpus.
Parameters: N/A
Returns: N/A
*/
void game::fire_arrow_up() {
    int player_x = p.get_x();
    int player_y = p.get_y();

    for (int i = 1; i <= 3 && player_y - i >= 0; ++i) {
        int y = player_y - i;

        event* current_event = game_board[y][player_x].get_event();
        if (current_event && current_event->get_event_name() == "Wumpus") {
            cout << "You kill the Wumpus!" << endl;
            wumpus_alive = false;
            game_board[y][player_x].remove_event();
            return;
        }
    }

    cout << "The arrow missed!" << endl;

    if (wumpus_alive) {
        move_wumpus_randomly();
    }
}

/*
Function: fire_arrow_down
Description: Fires an arrow downwards and checks for hitting the Wumpus.
Parameters: N/A
Returns: N/A
*/
void game::fire_arrow_down() {
    int player_x = p.get_x();
    int player_y = p.get_y();

    for (int i = 1; i <= 3 && player_y + i < height; ++i) {
        int y = player_y + i;

        event* current_event = game_board[y][player_x].get_event();
        if (current_event && current_event->get_event_name() == "Wumpus") {
            cout << "You hit the Wumpus!" << endl;
            wumpus_alive = false;
            game_board[y][player_x].remove_event();
            return;
        }
    }

    cout << "The arrow missed!" << endl;

    if (wumpus_alive) {
        move_wumpus_randomly();
    }
}

/*
Function: fire_arrow_left
Description: Fires an arrow to the left and checks for hitting the Wumpus.
Parameters: N/A
Returns: N/A
*/
void game::fire_arrow_left() {
    int player_x = p.get_x();
    int player_y = p.get_y();

    for (int i = 1; i <= 3 && player_x - i >= 0; ++i) {
        int x = player_x - i;

        event* current_event = game_board[player_y][x].get_event();
        if (current_event && current_event->get_event_name() == "Wumpus") {
            cout << "You hit the Wumpus!" << endl;
            wumpus_alive = false;
            game_board[player_y][x].remove_event();
            return;
        }
    }

    cout << "The arrow missed!" << endl;

    if (wumpus_alive) {
        move_wumpus_randomly();
    }
}

/*
Function: fire_arrow_right
Description: Fires an arrow to the right and checks for hitting the Wumpus.
Parameters: N/A
Returns: N/A
*/
void game::fire_arrow_right() {
    int player_x = p.get_x();
    int player_y = p.get_y();

    for (int i = 1; i <= 3 && player_x + i < width; ++i) {
        int x = player_x + i;

        event* current_event = game_board[player_y][x].get_event();
        if (current_event && current_event->get_event_name() == "Wumpus") {
            cout << "You hit the Wumpus!" << endl;
            wumpus_alive = false;
            game_board[player_y][x].remove_event();
            return;
        }
    }

    cout << "The arrow missed!" << endl;

    if (wumpus_alive) {
        move_wumpus_randomly();
    }
}

/*
Function: fire_arrow
Description: Fires an arrow in the specified direction.
Parameters: direction (char) - The direction to fire the arrow ('w', 'a', 's', 'd').
Returns: N/A
*/
void game::fire_arrow(char direction) {
    if (direction == 'w') {
        this->fire_arrow_up();
    } else if (direction == 'a') {
        this->fire_arrow_left();
    } else if (direction == 's') {
        this->fire_arrow_down();
    } else {
        this->fire_arrow_right();
    }

    p.use_arrows();
}

/*
Function: play_game
Description: Main game loop that continues until the player wins or loses.
Parameters: N/A
Returns: N/A
*/
void game::play_game() {
    while (!this->check_win() && !this->check_lose()) {
        // Print game board
        this->display_game();

        // TODO Display percepts around player's location
        this->display_percepts();

        // Ask player for their action
        char action = this->get_player_action();

        // Process action
        if (this->is_direction(action)) {
            // W/A/S/D = move player
            char direction = action;
            this->move(action);
        } else {
            // F = prompt for arrow fire direction and fire arrow
            char direction = this->get_arrow_fire_direction();
            this->fire_arrow(direction);
        }

        // TODO If the user is on a space with an event, trigger its encounter
        game_board[p.get_y()][p.get_x()].trigger_event(p);

    }
}
