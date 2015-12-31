#ifndef SQUARE_H
#define SQUARE_H

#include <set>

// One square in a Sudoku game
class Square
{
private:
    std::set<int> possible_vals;

public:
    Square();
    bool is_val_possible(const int &val);
    void remove_val(const int &val);
    void set_final_val(const int &val);
    bool is_final_val();
    int get_first_val();
};

#endif
