#include <iostream>
#include "sudoku.h" 
using namespace std;

int main()
{
    sudoku sd;
    int sudokuGrid[SIZE][SIZE];
    int i = 0;
    int j = 0;
    int numZero = 0;
<<<<<<< Updated upstream
 
=======


>>>>>>> Stashed changes
    cout << "Enter sudoku puzzle.\nNote: each new line represents going right in the column\nNote: Enter a 0 for a spot that is unknown.\n\n";
    cout << "The layout below will help you understand on how to place your inputs and the zeros:\n\n";

    cout << "          Column          \n"
            "  1   2   3    4   5   6  \n"
            "|___|___|___||___|___|___|\n"
            "|   |   |   ||   |   |   | First row\n"
            "|---|---|---||---|---|---|\n"
            "|   |   |   ||   |   |   | Second row\n"
            "|___|___|___||___|___|___|\n"
            "|   |   |   ||   |   |   | Third row\n"
            "|---|---|---||---|---|---|\n"
            "|   |   |   ||   |   |   | Fourth row\n"
            "|___|___|___||___|___|___|\n"
            "|   |   |   ||   |   |   | Fifth row\n"
            "|---|---|---||---|---|---|\n"
            "|   |   |   ||   |   |   | Sixth row\n"
            "|___|___|___||___|___|___|\n\n";

    while (i < SIZE)
    {
        cout << "Enter row: " << i + 1 << endl;
        do
        {
            int num = 0;
            cin >> num;
            if (num == 0)
                numZero++;
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

    if (numZero == 0)
    {
        cout << "No Zeros entered, can't find a solution." << endl;
        return 0;
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