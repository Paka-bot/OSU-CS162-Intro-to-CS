/*
Author: Yunseong Cho
File Description: This cpp file defines the member functions for the Room class, 
managing the events within a room, including setting, checking, triggering, and removing events.
*/

#include "room.hpp"

#include <iostream>

using namespace std;

// TODO Room implementation (define room member functions below)

/*
Constructor: Room (default constructor)
Description: Initializes a Room object with no event.
Parameters: N/A
Returns: N/A
*/
Room::Room()
    : events(nullptr) {}

/*
Function: set_event
Description: Assigns a new event to the room.
Parameters: new_events (event*) - Pointer to the new event to be set in the room.
Returns: N/A
*/
void Room::set_event(event* new_events) {
    events = new_events;
}

/*
Function: check_event
Description: Checks if the room currently has an event.
Parameters: N/A
Returns: bool - True if the room has no event, false otherwise.
*/
bool Room::check_event() const {
    if (events == nullptr) {
        return true;
    }
    else {
        return false;
    }
}

/*
Function: remove_event
Description: Removes the event from the room.
Parameters: N/A
Returns: N/A
*/
void Room::remove_event() {
    if (events) {
        delete events;
        events = nullptr;
    }
}

/*
Function: display_event
Description: Displays the event symbol in the room.
Parameters: N/A
Returns: N/A
*/
void Room::display_event() const {
    if (events) {
        events->print();
    } else {
        cout << " ";
    }
}

/*
Function: trigger_percept
Description: If an event is present in the room, triggers its percept.
Parameters: N/A
Returns: N/A
*/
void Room::trigger_percept() const {
    if (events) {
        events->percept();
    }
}

/*
Function: trigger_event
Description: When a player encounters an event, it triggers the event and affects the player's state.
Parameters: p (player&) - Reference to the player object affected by the event.
Returns: N/A
*/
void Room::trigger_event(player& p) {
    if (events) {
        events->encounter(p);

        string event_name = events->get_event_name();
        if (event_name == "gold" || event_name == "arrow") {
            remove_event();
        }
    }
}

/*
Function: get_event
Description: Returns a pointer to the event currently in the room.
Parameters: N/A
Returns: event* - Pointer to the event in the room.
*/
event* Room::get_event() const {
    return events;
}

/*
Destructor: ~Room
Description: Deallocates any dynamic memory associated with the room's event.
Parameters: N/A
Returns: N/A
*/
Room::~Room() {
    if (events) {
        delete events;
    }
}
