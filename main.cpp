#include "sudoku.h"
#include <iostream>
#include <chrono>
#include <time.h>
#include <string>

using namespace std;

int main()
{
    sudoku sd;
    int sudokuGrid[SIZE][SIZE];
    cout << "Enter sudoku puzzle.\nNote: each new line represents going right in the column\nNote: Enter a 0 for a spot that is unknown.\n\n";
    cout << "The layout below will help you understand on how to place your inputs and the zeros:\n\n";
    if (SIZE == 6)
    {
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
    }
    else if (SIZE == 9)
    {
        cout << "                 Column                \n"
                "  1   2   3    4   5   6    7   8   9  \n"
                "|___|___|___||___|___|___||___|___|___|\n"
                "|   |   |   ||   |   |   ||   |   |   | First Row\n"
                "|___|___|___||___|___|___||___|___|___|\n"
                "|   |   |   ||   |   |   ||   |   |   | Second Row\n"
                "|___|___|___||___|___|___||___|___|___|\n"
                "|   |   |   ||   |   |   ||   |   |   | Third Row\n"
                "|___|___|___||___|___|___||___|___|___|\n"
                "|   |   |   ||   |   |   ||   |   |   | Fourth Row\n"
                "|___|___|___||___|___|___||___|___|___|\n"
                "|   |   |   ||   |   |   ||   |   |   | Fifth Row\n"
                "|___|___|___||___|___|___||___|___|___|\n"
                "|   |   |   ||   |   |   ||   |   |   | Sixth Row\n"
                "|___|___|___||___|___|___||___|___|___|\n"
                "|   |   |   ||   |   |   ||   |   |   | Seventh Row\n"
                "|___|___|___||___|___|___||___|___|___|\n"
                "|   |   |   ||   |   |   ||   |   |   | Eighth Row\n"
                "|___|___|___||___|___|___||___|___|___|\n"
                "|   |   |   ||   |   |   ||   |   |   | Ninth Row\n"
                "|___|___|___||___|___|___||___|___|___|\n\n";
    }


    sd.getInput(sudokuGrid);    // gets user input

    cout << "The starting grid is" << endl;
    sd.printGrid(sudokuGrid);
    cout << endl << endl;

    auto t1 = chrono::high_resolution_clock::now(); // start clock
    if (sd.attemptSolve(sudokuGrid, 0, 0))
    {
        cout << "The solved grid is" << endl;
        sd.printGrid(sudokuGrid);
    }
    else
        cout << "Can't find a solution to given sudoku puzzle." << endl; // if puzzle unsolvable, output
    auto t2 = chrono::high_resolution_clock::now(); // stop clock
    cout << "\nTime to solve puzzle: " << chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count() << " ms\n";
    return 0;
}