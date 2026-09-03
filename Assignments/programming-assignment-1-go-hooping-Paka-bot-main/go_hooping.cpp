/*
Author: Yunseong Cho
Program description: Play a basketball shooting game for 2 players. 
The program takes the user's input of the location of the moneyball rack and the shooting ability. 
It then processes all the shots of player 1 and then the shots of player 2. 
After the shooting is over, it displays the winner and asks the user if he wants to play again.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

/*
Function: input_moneyball_rack
Description: Prompts the player to choose a rack (1-5) for the money-ball, 
ensures valid input between 1 and 5.
Parameters: player_number (int) - The number of the current player (1 or 2).
Returns: int - The rack number selected for the money-ball.
*/
int input_moneyball_rack(int player_number) {
    int user_moneyball_rack;

    do {
        cout << "Player " << player_number << ":" << endl;
        cout << "Where do you want to put your money-ball rack? Enter 1-5: ";
        cin >> user_moneyball_rack;

        if (user_moneyball_rack < 1 || user_moneyball_rack > 5) {
            cout << "Invalid input, Please try again." << endl;
        }
    } while (user_moneyball_rack < 1 || user_moneyball_rack > 5);

    return user_moneyball_rack;
}

/*
Function: input_shooting_capability
Description: Prompts the player to input their shooting capability (1-99), 
ensures valid input within range.
Parameters: player_number (int) - The number of the current player (1 or 2).
Returns: int - The player's shooting capability value.
*/
int input_shooting_capability(int player_number) {
    int user_capability;

    do {
        cout << "Player " << player_number << ", enter your shooting capability, from 1 to 99: ";
        cin >> user_capability;

        if (user_capability < 1 || user_capability > 99) {
            cout << "Invalid input. Please try again." << endl;
        }

    } while (user_capability < 1 || user_capability > 99);

    return user_capability;
}

/*
Function: generate_rack_array
Description: generate 5 arrays and create a 2d array that can hold 5 values ​​in each array. 
Then, create an array that can hold a starry ball between arrays 2 and 3 and arrays 3 and 4.
Parameters:
rack (char[5][5]) - 2D array representing shot success or failure.
rack_starry (char[2]) - Array for two additional "starry" shots.
rackscore (int[5]) - Array to store scores for each rack.
moneyBallRack (int) - The player's chosen money-ball rack.
capability (int) - The player's shooting capability.
*/
void generate_rack_array(char rack[5][5], char rack_starry[2], int rackscore[], int moneyBallRack, int capability) {
    int chance;

    for (int i = 0; i < 5; i++) {
        rackscore[i] = 0;
        for (int j = 0; j < 5; j++) {
            chance = rand() % 100 + 1;
            if (chance <= capability) {
                if (i == (moneyBallRack - 1)) {
                    rack[i][j] = 'M';
                    rackscore[i] += 2;
                } else {
                    if (j == 4) {
                        rack[i][j] = 'M';
                        rackscore[i] += 2;
                    } else {
                        rack[i][j] = 'X';
                        rackscore[i] += 1;
                    }
                }
            } else {
                rack[i][j] = '_';
            }
        }
    }

    for (int k = 0; k < 2; k++) {
        chance = rand() % 100 + 1;
        if (chance <= capability) {
            rack_starry[k] = 'S';
        } else {
            rack_starry[k] = '_';
        }
    }
}

/*
Function: calculate_and_display_rack_scores
Description: Calculates the total score for each rack and the starry shots and displays the results.
Parameters:
rack (char[5][5]) - The 5x5 shot result array.
rack_starry (char[2]) - The two starry shot results.
rack_score (int[5]) - The score for each rack.
rack_starry_score (int[2]) - The score for each starry shot.
total_score (int&) - The total score accumulated by the player.
*/
void calculate_and_display_rack_scores(char rack[5][5], char rack_starry[2], int rack_score[5], int rack_starry_score[2], int &total_score) {
   
    for (int c = 0; c < 2; c++) {
        if (rack_starry[c] == 'S') {
            rack_starry_score[c] = 3;
        } else {
            rack_starry_score[c] = 0;
        }
    }

    for (int i = 0; i < 5; i++) {
        cout << "Rack " << i + 1 << ": ";

        if (i == 1 || i == 2) {
            for (int k = 0; k < 5; k++) {
                cout << rack[i][k];
            }
            cout << " | " << rack_score[i] << " pts" << endl;
            cout << "Starry: " << rack_starry[i - 1] << " | " << rack_starry_score[i - 1] << " pts" << endl;

            total_score += rack_score[i];
            total_score += rack_starry_score[i - 1];
        } else { 
            for (int j = 0; j < 5; j++) {
                cout << rack[i][j];
            }
            cout << " | " << rack_score[i] << " pts" << endl;
            total_score += rack_score[i];
        }
    }
    cout << endl << "Total: " << total_score << " pts" << endl; 
}

/*
Function: playing_game
Description: Manages the game for one player, including input and score calculation.
Parameters: player_number (int) - The current player's number (1 or 2).
Returns: int - The total score for the player.
*/
int playing_game(int player_number) {
    char rack[5][5];
    char rack_starry[2];
    int rack_score[5];
    int rack_starry_score[2];
    int moneyball_rack = input_moneyball_rack(player_number);
    int capability = input_shooting_capability(player_number);
    int total_score = 0;

    generate_rack_array(rack, rack_starry, rack_score, moneyball_rack, capability);
    calculate_and_display_rack_scores(rack, rack_starry, rack_score, rack_starry_score, total_score);

    return total_score; 
}

/*
Function: compare
Description: Compares the scores of two players and declares the winner or if it's a tie.
Parameters: 
player1 (int) - The total score of player 1.
player2 (int) - The total score of player 2.
*/
void compare(int player1, int player2) {
    if (player1 > player2) {
        cout << "Player 1 is the winner!" << endl;
    } else if (player1 == player2) {
        cout << "It's a tie!" << endl;
    } else {
        cout << "Player 2 is the winner!" << endl;
    }
}

int main() {
    srand(time(0));
    int play_again;

    do {
        int score_player1 = playing_game(1);
        int score_player2 = playing_game(2);

        compare(score_player1, score_player2);

        do {
            cout << "Do you want to play again? (1-yes, 0-no): ";
            cin >> play_again;

            if (play_again != 1 && play_again != 0) {
                cout << "Invalid input. Please try again" << endl;
            }
        } while (play_again != 1 && play_again != 0);

    } while (play_again == 1);

    cout << "Bye!" << endl;

    return 0;
}
