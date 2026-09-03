/*
Author: Yunseong Cho

Program description: This program first gets the file name containing the wizard information 
from the user and the file name containing the spell information. It then takes the information 
from the file and creates a dynamic array of wizards, spells, and spell structures and stores them 
in the dynamic array. It then asks the user for an ID and password and compares the information in 
the wizard structure array to log in. It then gives the user four options. 1. Print all spell 
information to the terminal. 2. Ask the user to input a spellbook by name and print that spellbook 
to the terminal or a file. 3. Ask the user to input the effect of a spell and print all spells with 
that effect to the terminal or a file. Pressing 4 will terminate the program.
*/

#include <iostream>
#include <fstream>
#include <string>
#include "catalog.hpp"

using namespace std;

int main() {

    // Enter wizard_file
    string wizard_file;
    int num_wizards = 0;

    cout << "Enter the wizard info file name: ";
    cin >> wizard_file;

    ifstream wizard_input(wizard_file);

    if (!wizard_input.is_open()) {
        cout << "Could not fine file. Exit the program." << endl;
        return 0;
    }

    wizard_input >> num_wizards;
    Wizard* wizards = create_wizard(num_wizards);

    for (int i = 0; i < num_wizards; ++i) {
        wizards[i] = read_wizard_data(wizard_input);
    }

    wizard_input.close();

    // Enter spellbook_file
    string spellbook_file;
    int num_spellbooks = 0;

    cout << "Enter the spellbook info file name: ";
    cin >> spellbook_file;

    ifstream spellbook_input(spellbook_file);

    if (!spellbook_input.is_open()) {
        cout << "Could not fine file. Exit the program" << endl;
        return 0;
    }

    spellbook_input >> num_spellbooks;
    Spellbook* spellbooks = create_spellbooks(num_spellbooks);

    for (int i = 0; i < num_spellbooks; ++i) {
        spellbooks[i] = read_spellbook_data(spellbook_input);
    }

    spellbook_input.close();

    // Login
    Wizard logged_in_wizard;
    if (!login(wizards, num_wizards, logged_in_wizard)) {
        cout << "Login failed. Exit the program." << endl;
        delete_wizards(wizards);
        delete_spellbooks(spellbooks, num_spellbooks);
        
        return 0;
    }

    // Display wizard information
    display_wizard_info(logged_in_wizard);

    // Print spellbook information
    int choice;

    while (true) {
        cout << "1. Display all spellbooks\n2. Search spellbook by name\n3. Search spells by effect\n4. Quit\nYour Choice: ";
        cin >> choice;

        if (choice == 1) {
            display_all_spellbooks(spellbooks, num_spellbooks, logged_in_wizard);
        } else if (choice == 2) {
            search_spellbook_by_name(spellbooks, num_spellbooks);
        } else if (choice == 3) {
            search_spells_by_effect(spellbooks, num_spellbooks, logged_in_wizard);
        } else if (choice == 4) {
            cout << "Bye!" << endl;
            delete_wizards(wizards);
            delete_spellbooks(spellbooks, num_spellbooks);
            return 0;
        } else {
            cout << "Invalid input. Please try again." << endl;
        }
    }
}
