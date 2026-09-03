#ifndef ROOM_HPP
#define ROOM_HPP

#include "event.hpp"

// Room interface
class Room {
private: 
	// TODO private members

	event* events; // Pointer to the event present in the room. Used to store which event is in the room.

public:
	// TODO public members

	Room();	// Constructor for Room, initializes the room without any event.

	bool check_event() const; // Checks if there is an event in the current room. If the event is nullptr, returns true.
	
	void set_event(event* new_events); // Sets a new event pointed to in the room.

	void remove_event(); // If there is an event in the room, remove the event.

	void display_event() const;	// If there is an event in the room, print the event's symbol, otherwise print a blank " ".

	void trigger_percept() const; // If there is an event in the room, it outputs the percepts of that event.

	void trigger_event(player& p); // Triggers an event when an event is encountered.

	event* get_event() const; // Returns a pointer to the event present in the room.

	~Room(); // Destructor for Room.
};

#endif