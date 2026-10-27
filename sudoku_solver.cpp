#include <iostream>
using namespace std;

int grid[9][9] = {
    {5, 3, 0, 0, 7, 0, 0, 0, 0},
    {6, 0, 0, 1, 9, 5, 0, 0, 0},
    {0, 9, 8, 0, 0, 0, 0, 6, 0},
    {8, 0, 0, 0, 6, 0, 0, 0, 3},
    {4, 0, 0, 8, 0, 3, 0, 0, 1},
    {7, 0, 0, 0, 2, 0, 0, 0, 6},
    {0, 6, 0, 0, 0, 0, 2, 8, 0},
    {0, 0, 0, 4, 1, 9, 0, 0, 5},
    {0, 0, 0, 0, 8, 0, 0, 7, 9}
};

bool check(int row, int col, int num)
{
    // Check row
    for (int j = 0; j < 9; j++)
    {
        if (grid[row][j] == num)
            return false;
    }

    // Check column
    for (int i = 0; i < 9; i++)
    {
        if (grid[i][col] == num)
            return false;
    }

    // Find starting position of 3x3 block
    int startrow = row - row % 3;
    int startcol = col - col % 3;

    // Check 3x3 block
    for (int i = startrow; i < startrow + 3; i++)
    {
        for (int j = startcol; j < startcol + 3; j++)
        {
            if (grid[i][j] == num)
                return false;
        }
    }

    return true;
}

bool findStar(int &row, int &col)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (grid[i][j] == 0)
            {
                row = i;
                col = j;
                return true;
            }
        }
    }

    return false;
}

bool solveSudoku()
{
    int row, col;

    // If no empty cell remains, Sudoku is solved
    if (!findStar(row, col))
        return true;

    // Try numbers from 1 to 9
    for (int num = 1; num <= 9; num++)
    {
        if (check(row, col, num))
        {
            grid[row][col] = num;

            if (solveSudoku())
                return true;

            // Backtrack
            grid[row][col] = 0;
        }
    }

    return false;
}

void printGrid()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    if (solveSudoku())
    {
        cout << "Solved Sudoku:\n";
        printGrid();
    }
    else
    {
        cout << "No solution exists";
    }

    return 0;
}