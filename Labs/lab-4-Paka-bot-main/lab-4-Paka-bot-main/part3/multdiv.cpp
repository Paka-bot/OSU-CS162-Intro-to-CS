#include "multdiv.hpp"
#include <iostream>

using namespace std;

multdiv_entry** create_table(int row, int col) {
    multdiv_entry** table = new multdiv_entry*[row];
    for (int i = 0; i < row; i++) {
        table[i] = new multdiv_entry[col];
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            table[i][j].mult = (i + 1) * (j + 1);      
            table[i][j].div = static_cast<double>(i + 1) / (j + 1); 
        }
    }

    return table;
}

void print_table(multdiv_entry** table, int row, int col) {
    cout << "Multiplication Table:\n";
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << table[i][j].mult << "\t";
        }
        cout << endl;
    }

    cout << "Division Table:\n";
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << table[i][j].div << "\t";
        }
        cout << endl;
    }
}

void delete_table(multdiv_entry** table, int row) {
    for (int i = 0; i < row; i++) {
        delete[] table[i];
    }
    delete[] table;
}
