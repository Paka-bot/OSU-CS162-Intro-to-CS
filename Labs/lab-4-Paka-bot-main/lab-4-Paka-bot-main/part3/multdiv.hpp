#ifndef MULTDIV_HPP
#define MULTDIV_HPP

struct multdiv_entry {
    int mult;
    double div;
};

multdiv_entry** create_table(int row, int col);
void print_table(multdiv_entry** table, int row, int col);
void delete_table(multdiv_entry** table, int row);

#endif
