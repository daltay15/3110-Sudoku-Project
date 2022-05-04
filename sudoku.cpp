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