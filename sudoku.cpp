#include "sudoku.h"
#include <iostream>
using namespace std;

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
     for (int x = 0; x < SIZE - 1; x++)
     {
          if (sudokuGrid[row][x] == num) // check row for the same number
          {
               return false;
          }
     }

     for (int x = 0; x < SIZE - 1; x++)
     {
          if (sudokuGrid[x][col] == num) // check column for the same number
          {
               return false;
          }
     }

     int startRow = row - row % boxRowSize;
     int startCol = col - col % boxColSize;

     for (int i = 0; i < boxRowSize; i++)
          for (int j = 0; j < boxColSize; j++)
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