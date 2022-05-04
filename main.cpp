#include <iostream>
#include "sudoku.h" 
using namespace std;

int main()
{
    sudoku sd;

    int sudokuGrid[SIZE][SIZE];
    int i = 0;
    int j = 0;

    cout << "The starting grid is" << endl;
    sd.printGrid(sudokuGrid);
    cout << endl << endl;

    if (sd.attemptSolve(sudokuGrid, 0, 0))
    {
        cout << "The solved grid is" << endl;
        sd.printGrid(sudokuGrid);
    }
    else
        cout << "Can't find a solution to given sudoku puzzle." << endl;

    return 0;
}