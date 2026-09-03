#ifndef EVENT_HPP
#define EVENT_HPP

#include "player.hpp"

#include <string>

using namespace std;

// Event interface
class event {
private:
	// TODO private members, if relevant
protected:
	// TODO protected members, if relevant
public:
	// TODO public members

	/*
    Function: percept (Pure Virtual)
    Description: Displays a percept message to the player when near the event.
    Parameters: N/A
    Returns: N/A
    */
    virtual void percept() const = 0;

    /*
    Function: encounter (Pure Virtual)
    Description: Defines the behavior when the player encounters the event.
    Parameters:
        p (player&) - Reference to the player object interacting with the event.
    Returns: N/A
    */
    virtual void encounter(player& p) const = 0;

    /*
    Function: print (Pure Virtual)
    Description: Prints a debug symbol representing the event.
    Parameters: N/A
    Returns: N/A
    */
    virtual void print() const = 0;

    /*
    Function: get_event_name (Pure Virtual)
    Description: Retrieves the name of the event.
    Parameters: N/A
    Returns: string - The name of the event.
    */
    virtual string get_event_name() const = 0;

    /*
    Function: clone (Pure Virtual)
    Description: Creates a copy of the event object.
    Parameters: N/A
    Returns: event* - Pointer to the cloned event object.
    */
    virtual event* clone() const = 0;

    /*
    Destructor: ~event
    Description: Virtual destructor to ensure proper cleanup of derived class objects.
    Parameters: N/A
    Returns: N/A
    */
    virtual ~event();
};

#endif
