#include "sudoku.h"
#include <iostream>

using namespace std;

int sudoku::getBoxHeight()
{
    int boxRowHeight = 0;

    if (SIZE == 6)
    {
        return 2;
    }
    else if (SIZE == 9)
    {
        return 3;
    }
}

int sudoku::getBoxWidth()
{
    int boxRowWidth = 0;

    if (SIZE == 6)
    {
        return 3;
    }
    else if (SIZE == 9)
    {
        return 3;
    }
}

void sudoku::getInput(int sudokuGrid[SIZE][SIZE])
{
    int numZero = 0;
    string input;
    for (int i = 0; i < SIZE; i++)
    {
        int num = 0;
            REPEAT:do
            {
                if (num >= 1)
                    cout << "\n\nInvalid number of inputs, please enter " << SIZE << " digits.\n\n";
                cout << "\nEnter Row: " << i + 1 << endl;
                cin >> input;
                num++;
            } while (input.length() != SIZE);  // if user didn't input the correct amount of digits, redo

            for (int j = 0; j < SIZE; j++)
            {
                int num = input[j] - '0';
                cout << num << " ";
                if (num == 0)   // used to check if user entered any 0s, if none will be used to throw error.
                    numZero++;
                // test
                if (num < 0 || num > SIZE)
                {
                    cout << "\n\nError, insert a number between 0 and " << SIZE << "." << endl << endl; // makes sure the user inputs valid digits
                    goto REPEAT;
                }
                else
                    sudokuGrid[i][j] = num;
            }
            cout << "Successfully inputted Row " << i + 1 << endl;
    }
    if (numZero == 0)   // if user didn't input any 0s, output
    {
        cout << "\nNo Zeros entered, can't find a solution.\n";
    }
}

void sudoku::printGrid(int arr[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            cout << arr[i][j] << " "; // print out the sudoku grid
        }
        cout << endl;
    }
}

bool sudoku::isSafe(int sudokuGrid[SIZE][SIZE], int row, int col, int num)
{
    for (int x = 0; x <= SIZE - 1; x++)
    {
        if (sudokuGrid[row][x] == num) // check row for the same number
        {
            return false;
        }
    }

    for (int x = 0; x <= SIZE - 1; x++)
    {
        if (sudokuGrid[x][col] == num) // check column for the same number
        {
            return false;
        }
    }

    int startRow = row - row % getBoxHeight();
    int startCol = col - col % getBoxWidth();

    for (int i = 0; i < getBoxHeight(); i++)
        for (int j = 0; j < getBoxWidth(); j++)
        {
            if (sudokuGrid[i + startRow][j + startCol] == num) // checks the respective box to see if the number already exists
            {
                return false;
            }
        }

    return true;
}

bool sudoku::attemptSolve(int sudokuGrid[SIZE][SIZE], int row, int col)
{
    if (row == SIZE - 1 && col == SIZE)
    {
        return true;
    }

    if (col == SIZE) // if end of column reached go to next row and return the column to the beginning
    {
        row++;
        col = 0;
    }

    if (sudokuGrid[row][col] > 0) // if the current postion contains a 0, iterate to next column
    {
        return attemptSolve(sudokuGrid, row, col + 1);
    }

    for (int num = 1; num <= SIZE; num++)
    {
        if (isSafe(sudokuGrid, row, col, num))
        {
            sudokuGrid[row][col] = num; // if safe to place number then place number in current spot

            if (attemptSolve(sudokuGrid, row, col + 1)) // since the first number was correct, check to see if the next column is safe to place a number
                return true;
        }
        sudokuGrid[row][col] = 0; // if wrong then return current spot to a 0
    }
    return false;
}