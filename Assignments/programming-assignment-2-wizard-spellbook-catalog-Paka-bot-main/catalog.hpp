/*
Author: Yunseong Cho
File description: This hpp file is a header file that declares three structures and function prototypes to be used in the program.
*/

#ifndef CATALOG_HPP
#define CATALOG_HPP

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

struct Wizard {
    string name;
    int id;
    string password;
    string position_title;
    float beard_length;
};

struct Spell {
    string name;
    float success_rate;
    string effect;
};

struct Spellbook {
    string title;
    string author;
    int num_pages;
    int edition;
    int num_spells;
    float avg_success_rate;
    Spell* spells;
};

// dynamic array function
Wizard* create_wizard(int size);
Spell* create_spells(int size);
Spellbook* create_spellbooks(int size);

// data load function
Wizard read_wizard_data(ifstream& file);
Spell read_spell_data(ifstream& file);
Spellbook read_spellbook_data(ifstream& file);

// Login functions
bool login(Wizard* wizards, int num_wizards, Wizard& logged_in_wizard);
void display_wizard_info(Wizard& wizard);

// searching and printing functions
void display_all_spellbooks(Spellbook* spellbooks, int num_spellbooks, Wizard& wizard);
void search_spellbook_by_name(Spellbook* spellbooks, int num_spellbooks);
void search_spells_by_effect(Spellbook* spellbooks, int num_spellbooks, Wizard& wizard);

// deleting dynamic array functions
void delete_wizards(Wizard*& wizards);
void delete_spells(Spell*& spells);
void delete_spellbooks(Spellbook*& spellbooks, int size);

#endif
