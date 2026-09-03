/*
Author: Yunseong Cho
file description: This cpp file defines the functions that will be used in the main function in run_wizard.cpp.
*/

#include "catalog.hpp"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/*
Function: create_wizard
Description: Create a dynamic array of wizard structure.
Parameters: size (int) - The number of wizards in the wizards.txt file.
Returns: Pointer to an array of wizard structures
*/
Wizard* create_wizard(int size) {
    return new Wizard[size];
}

/*
Function: read_wizard_data
Description: Saves the information contained in the file (file name) input by the user into the wizard's structure array.
Parameters: file (ifstream&) - The input file stream from which to read wizard data.
Returns: A Wizard structure containing the data read from the file.
*/
Wizard read_wizard_data(ifstream& file) {
    Wizard wizard_info;
    file >> wizard_info.name >> wizard_info.id >> wizard_info.password >> wizard_info.position_title >> wizard_info.beard_length;
    return wizard_info;
}

/*
Function: create_spells
Description: Create a dynamic array of Spell structure.
Parameters: size (int) - The number of spells in the spellbooks.txt file.
Returns: Pointer to an array of Spell structures.
*/
Spell* create_spells(int size) {
    return new Spell[size];
}

/*
Function: read_spell_data
Description: Saves the spell information in the file (file name) input by the user into the spell structure array.
Parameters: file (ifstream&) - The input file stream from which to read spell data.
Returns: A Spell structure containing the data read from the file.
*/
Spell read_spell_data(ifstream& file) {
    Spell spell_info;
    file >> spell_info.name >> spell_info.success_rate >> spell_info.effect;
    return spell_info;
}

/*
Function: create_spellbooks
Description: Creates a dynamic array of Spellbook structures.
Parameters: size (int) - The number of spellbooks to be stored in the array.
Returns: Pointer to an array of Spellbook structures.
*/
Spellbook* create_spellbooks(int size) {
    return new Spellbook[size];
}

/*
Function: read_spellbook_data
Description: Stores the information of spellbooks in the file (file name) input by the user into a structure array of spellbooks.
Parameters: file (ifstream&) - The input file stream from which to read spellbook data.
Returns: A Spellbook structure containing the data read from the file.
*/
Spellbook read_spellbook_data(ifstream& file) {
    Spellbook spellbook_info;
    file >> spellbook_info.title >> spellbook_info.author >> spellbook_info.num_pages >> spellbook_info.edition >> spellbook_info.num_spells;

    spellbook_info.spells = create_spells(spellbook_info.num_spells);
    for (int i = 0; i < spellbook_info.num_spells; ++i) {
        spellbook_info.spells[i] = read_spell_data(file);
    }
    return spellbook_info;
}

/*
Function: login
Description: Validates wizard login by checking ID and password. Allows up to 3 attempts.
Parameters: wizards (Wizard*) - Array of Wizard structures.
            num_wizards (int) - Number of wizards in the array.
            logged_in_wizard (Wizard&) - Reference to store the logged-in wizard's information.
Returns: true if login is successful, false if attempts are exhausted.
*/
bool login(Wizard* wizards, int num_wizards, Wizard& logged_in_wizard) {
    int attempts = 0;
    while (attempts < 3) {
        int id;
        string password;
        cout << "Please enter your ID: ";
        cin >> id;
        cout << "Please enter your password: ";
        cin >> password;

        for (int i = 0; i < num_wizards; ++i) {
            if (wizards[i].id == id && wizards[i].password == password) {
                logged_in_wizard = wizards[i];
                return true;
            }
        }
        cout << "Incorrect id or password. plaese try again." << endl;
        ++attempts;
    }
    return false;
}

/*
Function: display_wizard_info
Description: Displays the logged-in wizard's information.
Parameters: wizard (Wizard&) - Reference to the Wizard structure containing the logged-in wizard's information.
Returns: N/A
*/
void display_wizard_info(Wizard& wizard) {
    cout << "Welcome " << wizard.name << endl;
    cout << "ID: " << wizard.id << endl;
    cout << "Position: " << wizard.position_title << endl;
    cout << "Beard Length: " << wizard.beard_length << endl;
}

/*
Function: display_all_spellbooks
Description: Displays information about all spellbooks, filtering certain effects if the wizard is a student.
Parameters: spellbooks (Spellbook*) - Array of Spellbook structures.
            num_spellbooks (int) - Number of spellbooks in the array.
            wizard (Wizard&) - Reference to the Wizard structure to check for access permissions.
Returns: N/A
*/
void display_all_spellbooks(Spellbook* spellbooks, int num_spellbooks, Wizard& wizard) {
    for (int i = 0; i < num_spellbooks; ++i) {
        cout << "Title: " << spellbooks[i].title << endl;
        cout << "Author: " << spellbooks[i].author << endl;
        cout << "Number of Pages: " << spellbooks[i].num_pages << endl;
        cout << "Edition: " << spellbooks[i].edition << endl;
        cout << "Number of spells: " << spellbooks[i].num_spells << endl;
        
        for (int j = 0; j < spellbooks[i].num_spells; ++j) {
            if ((wizard.position_title == "Student") &&
                (spellbooks[i].spells[j].effect == "death" || spellbooks[i].spells[j].effect == "poison")) {
                continue;
            }
            cout << "Spell Name: " << spellbooks[i].spells[j].name << " Success Rate: " << spellbooks[i].spells[j].success_rate << " Effect: " 
            << spellbooks[i].spells[j].effect << endl;
        }
    }
}

/*
Function: search_spellbook_by_name
Description: Searches for a spellbook by name and displays or saves its details based on user input.
Parameters: spellbooks (Spellbook*) - Array of Spellbook structures.
            num_spellbooks (int) - Number of spellbooks in the array.
Returns: N/A
*/
void search_spellbook_by_name(Spellbook* spellbooks, int num_spellbooks) {
    string spellbook_name;
    cout << "Enter the spellbook name: ";
    cin >> spellbook_name;

    // Find spellbooks
    for (int i = 0; i < num_spellbooks; ++i) {
        if (spellbooks[i].title == spellbook_name) {

            // Select how information is output
            int display_option;
            do {
                cout << "How would you like the information displayed?\n1. Print to screen (Press 1)\n2. Print to file (Press 2): ";
                cin >> display_option;
            } while (display_option != 1 && display_option != 2);

            // Output to terminal
            if (display_option == 1) {
                cout << "Spellbook Title: " << spellbooks[i].title << endl;
                cout << "Author: " << spellbooks[i].author << endl;
                cout << "Pages: " << spellbooks[i].num_pages << endl;
                cout << "Edition: " << spellbooks[i].edition << endl;
                cout << "Spells in this Spellbook:" << endl;
                for (int j = 0; j < spellbooks[i].num_spells; ++j) {
                    cout << "Spell Name: " << spellbooks[i].spells[j].name << " Effect: " << spellbooks[i].spells[j].effect
                         << " Success Rate: " << spellbooks[i].spells[j].success_rate << endl;
                }
            } 
            // Output to file
            else if (display_option == 2) {
                string output_filename;
                cout << "Enter the output file name: ";
                cin >> output_filename;

                ofstream output_file(output_filename);
                if (output_file.is_open()) {
                    output_file << "Spellbook Title: " << spellbooks[i].title << endl;
                    output_file << "Author: " << spellbooks[i].author << endl;
                    output_file << "Pages: " << spellbooks[i].num_pages << endl;
                    output_file << "Edition: " << spellbooks[i].edition << endl;
                    output_file << "Spells in this Spellbook:" << endl;
                    for (int j = 0; j < spellbooks[i].num_spells; ++j) {
                        output_file << "Spell Name: " << spellbooks[i].spells[j].name << " Effect: " << spellbooks[i].spells[j].effect
                                    << " Success Rate: " << spellbooks[i].spells[j].success_rate << endl;
                    }
                    output_file.close();
                }
            }
        }
    }
    cout << "Could not find the spellbook. Please try again." << endl;
}

/*
Function: search_spells_by_effect
Description: Searches for spells by effect and displays or saves their details based on user input.
Parameters: spellbooks (Spellbook*) - Array of Spellbook structures.
            num_spellbooks (int) - Number of spellbooks in the array.
            wizard (Wizard&) - Reference to the Wizard structure to check access permissions.
*/
void search_spells_by_effect(Spellbook* spellbooks, int num_spellbooks, Wizard& wizard) {
    string effect;

    // Enter order effect
    do {
        cout << "Enter spell effect: ";
        cin >> effect;

        if (effect == "fire" || effect == "bubble" || effect == "memory_loss") {
            break; // 유효한 주문 효과가 입력되면 루프 종료
        } else if ((effect == "death" || effect == "poison") && wizard.position_title != "Student") {
            break; // 'death'와 'poison' 효과는 Student가 아닌 경우에만 유효
        } else {
            cout << "Invalid input. Please try again." << endl;
        }
    } while (true);


    // Select how information is output
    int display_option;
    do {
        cout << "How would you like the information displayed?\n1. Print to screen (Press 1)\n2. Print to file (Press 2)";
        cin >> display_option;
    } while (display_option != 1 && display_option != 2);

    // Output to terminal
    if (display_option == 1) {
        for (int i = 0; i < num_spellbooks; ++i) {
            for (int j = 0; j < spellbooks[i].num_spells; ++j) {
                if (spellbooks[i].spells[j].effect == effect) {
                    cout << "Spell Name: " << spellbooks[i].spells[j].name << " Effect: " << spellbooks[i].spells[j].effect
                         << "Success Rate: " << spellbooks[i].spells[j].success_rate << endl;
                }
            }
        }
    } 
    // Output to file
    else if (display_option == 2) {
        string output_filename;
        cout << "Enter the output file name: ";
        cin >> output_filename;

        ofstream output_file(output_filename);
        if (output_file.is_open()) {
            for (int i = 0; i < num_spellbooks; ++i) {
                for (int j = 0; j < spellbooks[i].num_spells; ++j) {
                    if (spellbooks[i].spells[j].effect == effect) {
                        output_file << "Spell Name: " << spellbooks[i].spells[j].name << " Effect: " << spellbooks[i].spells[j].effect
                                    << "Success Rate: " << spellbooks[i].spells[j].success_rate << endl;
                    }
                }
            }
            output_file.close();
        }
    }
}

/*
Function: delete_wizards
Description: Deallocates the dynamic array of wizards and sets the pointer to nullptr.
Parameters: wizards (Wizard*&) - Reference to the pointer to the Wizard array to be deleted.
Returns: N/A
*/
void delete_wizards(Wizard*& wizards) {
    delete[] wizards;
    wizards = nullptr;
}

/*
Function: delete_spells
Description: Deallocates the dynamic array of spells and sets the pointer to nullptr.
Parameters: spells (Spell*&) - Reference to the pointer to the Spell array to be deleted.
Returns: N/A
*/
void delete_spells(Spell*& spells) {
    delete[] spells;
    spells = nullptr;
}

/*
Function: delete_spellbooks
Description: Deallocates the dynamic array of spellbooks, including each spellbook's spell array, and sets the pointer to nullptr.
Parameters: spellbooks (Spellbook*&) - Reference to the pointer to the Spellbook array to be deleted.
            size (int) - Number of spellbooks in the array.
Returns: N/A
*/
void delete_spellbooks(Spellbook*& spellbooks, int size) {
    for (int i = 0; i < size; ++i) {
        delete_spells(spellbooks[i].spells);
    }
    delete[] spellbooks;
    spellbooks = nullptr;
}
