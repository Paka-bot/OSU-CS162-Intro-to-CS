#include <iostream>
#include "multdiv.hpp"

using namespace std;

int main() {
    int row, col;

    cout << "Enter an integer greater than 0 for row: ";
    cin >> row;
    cout << "Enter an integer greater than 0 for col: ";
    cin >> col;

    multdiv_entry** table = create_table(row, col);

    print_table(table, row, col);

    delete_table(table, row);

    return 0;
}
