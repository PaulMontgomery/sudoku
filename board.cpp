#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>

#include "board.h"


Board::Board()
{
}

/*
Expect the board setup file to be named 'board.txt' and the format to be like:

53..7....
6..195...
.98....6.
8...6...3
4..8.3..1
7...2...6
.6....28.
...419..5
....8..79

(. means value is unknown, otherwise the number will be fixed in that location)
*/
bool Board::read(const char *file_name)
{
    std::ifstream in_file(file_name);
    if (!in_file) {
        std::cerr << "Unable to open " << file_name << " for input." << std::endl;
        exit(1);
    }
    int file_line = 0;
    while (in_file && (file_line < 9))
    {
        std::string in_str;
        std::getline(in_file, in_str);
        if (in_str.length() < 9)
        {
            std::cerr << "Invalid board.txt line: " << in_str << std::endl;
            exit(2);
        }

        const char *str = in_str.c_str();
        for (int pos = 0; pos < 9; pos++)
        {
            if (str[pos] != '.')
            {
                int fixed_val = str[pos] - '0';
                if ((fixed_val < 1) || (fixed_val > 9))
                {
                    std::cerr << "Invalid board value on line " << file_line << std::endl;
                    exit(3);
                }
                board[file_line][pos].set_final_val(fixed_val);
            }
        }
        file_line++;
    }
    return(true);
}

void Board::print()
{
    std::cout << std::endl;
    for (int row_count = 0; row_count < 9; row_count++)
    {
        if ((row_count == 3) || (row_count == 6))
        {
            std::cout << "-----------" << std::endl;
        }
        for (int col_count = 0; col_count < 9; col_count++)
        {
            if ((col_count == 3) || (col_count == 6)) {
                std::cout << "|";
            }
            if (board[row_count][col_count].is_final_val())
            {
                std::cout << board[row_count][col_count].get_first_val();
            } else
            {
                std::cout << ".";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Board::row_remove_val(const int &row_num, const int &val, const int &exception_loc)
{
    for (int col_count = 0; col_count < 9; col_count++)
    {
        if (col_count != exception_loc)
        {
            board[row_num][col_count].remove_val(val);
        }
    }
}

void Board::col_remove_val(const int &col_num, const int &val, const int &exception_loc)
{
    for (int row_count = 0; row_count < 9; row_count++)
    {
        if (row_count != exception_loc)
        {
            board[row_count][col_num].remove_val(val);
        }
    }
}

void Board::quad_remove_val(const int &exc_row, const int &exc_col, const int &val)
{
    int row_start, col_start;

    if (exc_row < 3)
    {
        row_start = 0;
    } else
    if (exc_row > 5)
    {
        row_start = 6;
    } else
    {
        row_start = 3;
    }

    if (exc_col < 3)
    {
        col_start = 0;
    } else
    if (exc_col > 5)
    {
        col_start = 6;
    } else
    {
        col_start = 3;
    }

    for (int r_count=row_start; r_count < (row_start+3); r_count++)
    {
        for (int c_count=col_start; c_count < (col_start+3); c_count++)
        {
            if ((r_count != exc_row) || (c_count != exc_col))
            {
                board[r_count][c_count].remove_val(val);
            }
        }
    }

}

/*
void Board::quad_remove_val(const int &quad_num, const int &val, const int &exception_loc)
{
    int row_start, col_start;

    switch(quad_num)
    {
        case 0:
            row_start = 0;
            col_start = 0;
            break;
        case 1:
            row_start = 0;
            col_start = 3;
            break;
        case 2:
            row_start = 0;
            col_start = 6;
            break;
        case 3:
            row_start = 3;
            col_start = 0;
            break;
        case 4:
            row_start = 3;
            col_start = 3;
            break;
        case 5:
            row_start = 3;
            col_start = 6;
            break;
        case 6:
            row_start = 6;
            col_start = 0;
            break;
        case 7:
            row_start = 6;
            col_start = 3;
            break;
        case 8:
            row_start = 6;
            col_start = 6;
            break;
    }
    int exc_count = 0;
    for (int r_count=row_start; r_count < (row_start+3); r_count++)
    {
        for (int c_count=col_start; c_count < (col_start+3); c_count++)
        {
            if (exc_count != exception_loc)
            {
                board[r_count][c_count].remove_val(val);
            }
            exc_count++;
        }
    }

}
*/

/* Tests, remove later
int main(int argc, char *argv[])
{
    Board board;

    board.read("board.txt");

    board.row_remove_val(0, 5, 0);
    board.row_remove_val(0, 3, 1);
    board.row_remove_val(0, 7, 4);
    board.row_remove_val(0, 1, 0);
    board.row_remove_val(0, 2, 0);
    board.row_remove_val(0, 4, 0);
    board.row_remove_val(0, 6, 0);
    board.row_remove_val(0, 8, 0);

    board.quad_remove_val(7, 3, 4);
    board.quad_remove_val(7, 4, 1);
    board.quad_remove_val(7, 5, 9);
    board.quad_remove_val(8, 4, 8);
    board.quad_remove_val(6, 3, 2);
    board.quad_remove_val(6, 3, 3);
    board.quad_remove_val(6, 3, 5);
    board.quad_remove_val(6, 3, 6);

    board.print();

    return(0);
}
*/
