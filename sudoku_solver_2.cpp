#include <vector>
using namespace std;

class Solution {
public:
    bool check(vector<vector<char>>& board, int row, int col, char num)
    {
        // Check row
        for (int j = 0; j < 9; j++)
        {
            if (board[row][j] == num)
                return false;
        }

        // Check column
        for (int i = 0; i < 9; i++)
        {
            if (board[i][col] == num)
                return false;
        }

        // Check 3x3 block
        int startrow = row - row % 3;
        int startcol = col - col % 3;

        for (int i = startrow; i < startrow + 3; i++)
        {
            for (int j = startcol; j < startcol + 3; j++)
            {
                if (board[i][j] == num)
                    return false;
            }
        }

        return true;
    }

    bool findStar(vector<vector<char>>& board, int &row, int &col)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    row = i;
                    col = j;
                    return true;
                }
            }
        }

        return false;
    }

    bool solve(vector<vector<char>>& board)
    {
        int row, col;

        // If no empty cell remains, Sudoku is solved
        if (!findStar(board, row, col))
            return true;

        // Try digits 1 to 9
        for (char num = '1'; num <= '9'; num++)
        {
            if (check(board, row, col, num))
            {
                board[row][col] = num;

                if (solve(board))
                    return true;

                // Backtracking
                board[row][col] = '.';
            }
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board)
    {
        solve(board);
    }
};