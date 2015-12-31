#ifndef BOARD_H
#define BOARD_H

#include <array>

#include "square.h"


class Board
{
public:
    std::array<std::array<Square, 9>, 9> board;

    Board();
    bool read(const char *file_name);
    void print();
    void row_remove_val(const int &row_num, const int &val, const int &exception_loc);
    void col_remove_val(const int &col_num, const int &val, const int &exception_loc);
    void quad_remove_val(const int &exc_row, const int &exc_col, const int &val);
};

#endif
