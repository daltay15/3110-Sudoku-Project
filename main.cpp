#include <iostream>
#include "sudoku.h" 
using namespace std;

int main()
{
    sudoku sd;

    int sudokuGrid[SIZE][SIZE];
    int i = 0;
    int j = 0;

    while (i < SIZE)
    {
        cout << "Enter row: " << i + 1 << endl;
        do
        {
            int num = 0;
            cin >> num;
            if (num < 0 || num > SIZE)
                cout << "Error, insert a number between 0 and " << SIZE << "." << endl;
            else
            {
                sudokuGrid[i][j] = num;
                j++;
            }
        } while (j < SIZE);
        i++;
        j = 0;
    }

    cout << "The starting grid is" << endl;
    sd.printGrid(sudokuGrid);
    cout << endl << endl;
    
    if (sd.attemptSolve(sudokuGrid, 0, 0))
    {
        cout << "The solved grid is" << endl;
        sd.printGrid(sudokuGrid);
    }
    else
        cout << "Can't find a solution to given sudoku puzzle." << endl;    // if puzzle unsolvable, output

    return 0;
}