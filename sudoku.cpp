#include <iostream>

#include "board.h"


void solve(const char *board_name)
{
    Board board;

    board.read(board_name);

    for (int count=0; count<50; count++)
    {
        for (int row=0; row<9; row++)
        {
            for (int col=0; col<9; col++)
            {
                if (board.board[row][col].is_final_val())
                {
                    int remove_val = board.board[row][col].get_first_val();
                    board.row_remove_val(row, remove_val, col);
                    board.col_remove_val(col, remove_val, row);
                    board.quad_remove_val(row, col, remove_val);
                }
            }
        }
    }

    board.print();
}


int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        solve(argv[1]);
    } else
    {
        solve("board.txt");
    }

    return(0);
}
