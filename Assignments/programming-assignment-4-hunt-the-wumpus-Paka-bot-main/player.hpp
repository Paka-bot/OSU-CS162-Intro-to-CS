#ifndef PLAYER_HPP
#define PLAYER_HPP

class player {
private:
    int x, y;   // Current location
    int arrows; // Number of arrows
    bool gold;  // True if the player has gold, otherwise false
    bool alive; // True if player is alive, otherwise false
    bool confused;  // Changes to true when the player encounters a bat_swarm
 
public:
    // Constructor
    player();

    // Player Movement
    void move_right();  
    void move_left();   
    void move_up();   
    void move_down();

    // Get current player location
    int get_x() const;
    int get_y() const;

    // Set player start position
    void start_position(int start_x, int start_y);

    // Arrow functions
    void add_arrows();
    void use_arrows();
    int check_arrows() const;

    // Gold Functions
    void get_gold();
    bool check_gold() const;

    // Player alive management
    void kill_player();
    bool check_alive() const;

    // Player confused management
    void make_confused();
    void reset_confused();
    bool check_confused();
};

#endif
